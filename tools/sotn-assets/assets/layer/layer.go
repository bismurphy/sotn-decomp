package layer

import (
	"encoding/binary"
	"encoding/json"
	"fmt"
	"github.com/xeeynamo/sotn-decomp/tools/sotn-assets/assets/tiledef"
	"io"
	"os"
	"path/filepath"
	"slices"
	"strings"
	"unsafe"

	"github.com/xeeynamo/sotn-decomp/tools/sotn-assets/datarange"
	"github.com/xeeynamo/sotn-decomp/tools/sotn-assets/psx"
	"github.com/xeeynamo/sotn-decomp/tools/sotn-assets/util"
	"golang.org/x/sync/errgroup"
)

type layerDef struct {
	Data       psx.Addr
	Tiledef    psx.Addr
	PackedInfo uint32
	ZPriority  uint16
	Flags      uint16
}

type layerUnpacked struct {
	Data          string `json:"data"`
	Tiledef       string `json:"tiledef"`
	Left          int    `json:"left"`
	Top           int    `json:"top"`
	Right         int    `json:"right"`
	Bottom        int    `json:"bottom"`
	ScrollMode    int    `json:"scrollMode"`
	HideOnMap     bool   `json:"hideOnMap"`
	IsSaveRoom    bool   `json:"isSaveRoom"`
	IsLoadingRoom bool   `json:"isLoadingRoom"`
	UnusedFlag    bool   `json:"unusedFlag"`
	ZPriority     int    `json:"zPriority"`
	Flags         int    `json:"flags"`
}

type roomLayers struct {
	fg *layerDef
	bg *layerDef
}

func (l *layerDef) tilemapFileSize() int {
	sx := int((l.PackedInfo >> 0) & 0x3F)
	sy := int((l.PackedInfo >> 6) & 0x3F)
	ex := int((l.PackedInfo >> 12) & 0x3F)
	ey := int((l.PackedInfo >> 18) & 0x3F)
	w := ex - sx + 1
	h := ey - sy + 1
	return w * h * 512
}

func (l *layerDef) unpack(ovl string, addrPool map[psx.Addr]int) layerUnpacked {
	return layerUnpacked{
		Data:          tilemapFileName(ovl, addrPool[l.Data]),
		Tiledef:       tiledefFileName(ovl, addrPool[l.Tiledef]),
		Left:          int((l.PackedInfo >> 0) & 0x3F),
		Top:           int((l.PackedInfo >> 6) & 0x3F),
		Right:         int((l.PackedInfo >> 12) & 0x3F),
		Bottom:        int((l.PackedInfo >> 18) & 0x3F),
		ScrollMode:    int((l.PackedInfo >> 24) & 0xF),
		HideOnMap:     int((l.PackedInfo>>24)&0x10) != 0,
		IsSaveRoom:    int((l.PackedInfo>>24)&0x20) != 0,
		IsLoadingRoom: int((l.PackedInfo>>24)&0x40) != 0,
		UnusedFlag:    int((l.PackedInfo>>24)&0x80) != 0,
		ZPriority:     int(l.ZPriority),
		Flags:         int(l.Flags),
	}
}

func readLayers(r io.ReadSeeker, off, baseAddr psx.Addr) ([]roomLayers, datarange.DataRange, error) {
	if off == 0 {
		return nil, datarange.DataRange{}, nil
	}
	if err := off.MoveFile(r, baseAddr); err != nil {
		return nil, datarange.DataRange{}, err
	}

	// when the data starts to no longer makes sense, we can assume we reached the end of the array
	var layerOffsets []psx.Addr
	layersOff := make([]psx.Addr, 2)
	for {
		if err := binary.Read(r, binary.LittleEndian, layersOff); err != nil {
			return nil, datarange.DataRange{}, err
		}
		// we do not check for `layersOff[1] >= off`, as on PSP this falls to BSS
		if layersOff[0] <= baseAddr || layersOff[0] >= off ||
			layersOff[1] <= baseAddr {
			break
		}
		layerOffsets = append(layerOffsets, layersOff...)
	}

	// Creates a map of layers, so we can re-use them when a layer is used by multiple rooms
	pool := map[psx.Addr]*layerDef{}
	pool[psx.Addr(0)] = nil
	for _, layerOffset := range layerOffsets {
		if _, exists := pool[layerOffset]; exists {
			continue
		}

		if layerOffset >= off {
			// assumes this is a layer_empty falling to BSS
			pool[layerOffset] = nil
			continue
		}
		if err := layerOffset.MoveFile(r, baseAddr); err != nil {
			return nil, datarange.DataRange{}, err
		}
		var l layerDef
		if err := binary.Read(r, binary.LittleEndian, &l); err != nil {
			return nil, datarange.DataRange{}, err
		}
		if l.Data != psx.RamNull || l.Tiledef != psx.RamNull || l.PackedInfo != 0 {
			pool[layerOffset] = &l
		} else {
			pool[layerOffset] = nil
		}
	}

	// creates the real array with all the layers mapped
	count := len(layerOffsets) >> 1
	roomsLayers := make([]roomLayers, count)
	for i := 0; i < count; i++ {
		roomsLayers[i].fg = pool[layerOffsets[i*2+0]]
		roomsLayers[i].bg = pool[layerOffsets[i*2+1]]
	}
	return roomsLayers, datarange.New(slices.Min(layerOffsets), off.Sum(count*8)), nil
}

func buildLayers(inputDir, fileName, outputDir, ovlName string) error {
	getHash := func(l layerUnpacked) string {
		return fmt.Sprintf("%s-%s-%d-%d-%d-%d", l.Data, l.Tiledef, l.Left, l.Top, l.Right, l.Bottom)
	}
	pack := func(l layerUnpacked) map[string]interface{} {
		return map[string]interface{}{
			"data":      makeSymbolFromFileName(l.Data),
			"tiledef":   makeSymbolFromFileName(l.Tiledef),
			"left":      l.Left,
			"top":       l.Top,
			"right":     l.Right,
			"bottom":    l.Bottom,
			"params":    (l.ScrollMode) | (util.Btoi(l.HideOnMap) << 4) | (util.Btoi(l.IsSaveRoom) << 5) | (util.Btoi(l.IsLoadingRoom) << 6) | (util.Btoi(l.UnusedFlag) << 7),
			"zPriority": l.ZPriority,
			"flags":     l.Flags,
		}
	}

	data, err := os.ReadFile(fileName)
	if err != nil {
		return err
	}

	var roomsLayers []map[string]*layerUnpacked
	if err := json.Unmarshal(data, &roomsLayers); err != nil {
		return err
	}

	tilemaps := map[string]struct{}{}
	tiledefs := map[string]struct{}{}
	for _, room := range roomsLayers {
		// the split on '.' is to remove the extension
		if layer, found := room["fg"]; found {
			tilemaps[layer.Data] = struct{}{}
			tiledefs[layer.Tiledef] = struct{}{}
		}
		if layer, found := room["bg"]; found {
			tilemaps[layer.Data] = struct{}{}
			tiledefs[layer.Tiledef] = struct{}{}
		}
	}

	eg := errgroup.Group{}
	for name := range tilemaps {
		fullPath := filepath.Join(filepath.Dir(fileName), name)
		symbol := makeSymbolFromFileName(name)
		eg.Go(func() error {
			return buildGenericU16(fullPath, symbol, outputDir)
		})
	}
	for name := range tiledefs {
		fullPath := filepath.Join(filepath.Dir(fileName), name)
		symbol := makeSymbolFromFileName(name)
		eg.Go(func() error {
			return tiledef.Build(fullPath, symbol, outputDir)
		})
	}
	if err := eg.Wait(); err != nil {
		return err
	}

	var layers []map[string]interface{} // first layer is always empty
	layers = append(layers, map[string]interface{}{})
	roomLayersId := make([]int, len(roomsLayers)*2)
	pool := map[string]int{}
	pool[""] = 0
	for _, rl := range roomsLayers {
		if l, fgFound := rl["fg"]; fgFound {
			hash := getHash(*l)
			if index, found := pool[hash]; !found {
				pool[hash] = len(layers)
				roomLayersId = append(roomLayersId, len(layers))
				layers = append(layers, pack(*l))
			} else {
				roomLayersId = append(roomLayersId, index)
			}
		} else {
			roomLayersId = append(roomLayersId, 0)
		}
		if l, bgFound := rl["bg"]; bgFound {
			hash := getHash(*l)
			if index, found := pool[hash]; !found {
				pool[hash] = len(layers)
				roomLayersId = append(roomLayersId, len(layers))
				layers = append(layers, pack(*l))
			} else {
				roomLayersId = append(roomLayersId, index)
			}
		} else {
			roomLayersId = append(roomLayersId, 0)
		}
	}

	sb := strings.Builder{}
	sb.WriteString("// clang-format off\n")
	for name := range tilemaps {
		symbol := makeSymbolFromFileName(name)
		sb.WriteString(fmt.Sprintf("extern u16 %s[];\n", symbol))
	}
	for name := range tiledefs {
		symbol := makeSymbolFromFileName(name)
		sb.WriteString(fmt.Sprintf("extern TileDefinition %s[];\n", symbol))
	}

	sb.WriteString("static LayerDef layer_empty = { NULL, NULL, 0, 0, 0 };\n")
	sb.WriteString("static LayerDef layers[] = {\n")
	for _, l := range layers[1:] {
		sb.WriteString(fmt.Sprintf("    { %s, %s, {%d, %d, %d, %d, 0x%02X}, 0x%02X, 0x%04X},\n",
			makeSymbolFromFileName(l["data"].(string)),
			makeSymbolFromFileName(l["tiledef"].(string)),
			l["left"],
			l["top"],
			l["right"],
			l["bottom"],
			l["params"],
			l["zPriority"],
			l["flags"],
		))
	}
	sb.WriteString("};\n")

	sb.WriteString("RoomDef OVL_EXPORT(rooms_layers)[] = {\n")
	for _, rl := range roomsLayers {
		if l, found := rl["fg"]; found {
			sb.WriteString(fmt.Sprintf("    { &layers[%d], ", pool[getHash(*l)]-1))
		} else {
			sb.WriteString(fmt.Sprintf("    { &layer_empty, "))
		}
		if l, found := rl["bg"]; found {
			sb.WriteString(fmt.Sprintf("&layers[%d] },\n", pool[getHash(*l)]-1))
		} else {
			sb.WriteString(fmt.Sprintf("&layer_empty },\n"))
		}
	}
	sb.WriteString("};\n")
	return util.WriteFile(filepath.Join(outputDir, "gen/layers.h"), []byte(sb.String()))
}

func makeSymbolFromFileName(fileName string) string {
	return strings.Split(filepath.Base(fileName), ".")[0]
}

func writeStaticU8(w io.Writer, fileName string, symbol string) error {
	data, err := os.ReadFile(fileName)
	if err != nil {
		return err
	}

	var sb strings.Builder
	sb.WriteString("// clang-format off\n")
	sb.WriteString(fmt.Sprintf("static unsigned char %s[] = {\n", symbol))
	for i := 0; i < len(data); i++ {
		sb.WriteString(fmt.Sprintf("0x%02X,", data[i]))
		if (i & 15) == 15 {
			sb.WriteString("\n")
		}
	}
	sb.WriteString("};\n")

	_, err = w.Write([]byte(sb.String()))
	return err
}

func buildGenericU16(fileName string, symbol string, outputDir string) error {
	data, err := os.ReadFile(fileName)
	if err != nil {
		return err
	}

	var sb strings.Builder
	sb.WriteString("// clang-format off\n")
	sb.WriteString(fmt.Sprintf("u16 %s[] = {\n", symbol))
	u16Data := (*[1 << 30]uint16)(unsafe.Pointer(&data[0]))[:len(data)/2]
	util.WriteWordsAsHex(&sb, u16Data)
	sb.WriteString("};\n")

	return util.WriteFile(filepath.Join(outputDir, fmt.Sprintf("gen/%s.h", symbol)), []byte(sb.String()))
}
