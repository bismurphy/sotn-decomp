#!/usr/bin/python3

import json
import os
import sys
from typing import Optional
from pathlib import Path

sys.path.append(f"{os.getcwd()}/tools/n64splat")
sys.path.append(f"{os.getcwd()}/tools/splat_ext")
from util import options, log
from segtypes.n64.segment import N64Segment
import utils

item_size = 0x34  # sizeof(Equipment)

def get_serializer(dataType: str):
    match dataType:
        case "str_ptr":
            return utils.from_ptr_str
        case "s16":
            return utils.from_16
        case "s8":
            return utils.from_s8
        case "u32":
            return utils.from_u32
        case _:
            print(f"Failed to find serializer for {dataType}")
def serialize_asset(content: str, asset_config:str) -> bytearray:
    obj = json.loads(content)
    config = json.loads(asset_config)
    item_count = len(obj)
    serialized_data = bytearray()
    for i in range(0, item_count):
        item = obj[i]
        for entry, entryType in config.items():
            serializer = get_serializer(entryType)
            serialized_data += serializer(item[entry])
    print(serialized_data)
    expected_data_size = item_count * item_size
    assert len(serialized_data) == expected_data_size

    return serialized_data


class PSXSegAssets(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, args, yaml),

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / self.name

    def src_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.json"

    def split(self, rom_bytes):
        path = self.src_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        data = self.parse_asset(rom_bytes[self.rom_start : self.rom_end], rom_bytes)
        with open(path, "w") as f:
            f.write(json.dumps(data, indent=4))

    def parse_asset(self, data: bytearray, rom: bytearray) -> list:
        def get_ptr_data(src_ptr_data):
            return rom[
                utils.to_u32(src_ptr_data) - (self.vram_start - self.rom_start) :
            ]

        count = int(len(data) / item_size)
        expected_data_size = count * item_size
        if len(data) != expected_data_size:
            log.write(
                f"data for '{self.name}' is {expected_data_size - len(data)} too long. Data might look incorrect.",
                status="warn",
            )

        items = []
        for i in range(0, count):
            item_data = data[i * item_size :][:item_size]
            item = {
                # debugging stuff
                "id": i,
                "id_hex": hex(i)[2:].upper(),
                "ram_addr": hex(self.vram_start + i * item_size)[2:].upper(),
                "name_resolved": utils.sotn_menu_name_to_str(
                    get_ptr_data(item_data[0x00:])
                ),
                "desc_resolved": utils.sotn_menu_desc_to_str(
                    get_ptr_data(item_data[0x04:])
                ),
                # debugging stuff ends
                "name_addr": utils.to_ptr_str(item_data[0x00:]),
                "desc_addr": utils.to_ptr_str(item_data[0x04:]),
                "attack": utils.to_s16(item_data[0x08:]),
                "defense": utils.to_s16(item_data[0x0A:]),
                "element": utils.to_u16(item_data[0x0C:]),
                "itemCategory": utils.to_u8(item_data[0x0E:]),
                "weaponId": utils.to_u8(item_data[0x0F:]),
                "palette": utils.to_u8(item_data[0x10:]),
                "unk11": utils.to_u8(item_data[0x11:]),
                "playerAnim": utils.to_u8(item_data[0x12:]),
                "unk13": utils.to_u8(item_data[0x13:]),
                "unk14": utils.to_u8(item_data[0x14:]),
                "lockDuration": utils.to_u8(item_data[0x15:]),
                "chainLimit": utils.to_u8(item_data[0x16:]),
                "unk17": utils.to_u8(item_data[0x17:]),
                "specialMove": utils.to_u8(item_data[0x18:]),
                "isConsumable": utils.to_bool(item_data[0x19:]),
                "enemyInvincibilityFrames": utils.to_u8(item_data[0x1A:]),
                "unk1B": utils.to_u8(item_data[0x1B:]),
                "unk1C": utils.to_u32(item_data[0x1C:]),
                "unk20": utils.to_u32(item_data[0x20:]),
                "mpUsage": utils.to_u16(item_data[0x24:]),
                "stunFrames": utils.to_u16(item_data[0x26:]),
                "hitType": utils.to_u16(item_data[0x28:]),
                "hitEffect": utils.to_u16(item_data[0x2A:]),
                "icon": utils.to_u16(item_data[0x2C:]),
                "iconPalette": utils.to_u16(item_data[0x2E:]),
                "criticalRate": utils.to_u16(item_data[0x30:]),
                "unk32": utils.to_u16(item_data[0x32:]),
            }
            items.append(item)
        return items


if __name__ == "__main__":
    input_file_name = sys.argv[1]
    output_file_name = sys.argv[2]
    print(f"BOOYAH {input_file_name} WITH {output_file_name}")
    config_file_name = input_file_name.replace(".json","_config.json")
    config_file_name = config_file_name.replace("assets/dra","tools/splat_ext")
    with open(config_file_name,"r") as config_in:
        config_json = config_in.read()

    with open(input_file_name, "r") as f_in:
        data = serialize_asset(f_in.read(), config_json)
        with open(output_file_name, "wb") as f_out:
            f_out.write(data)
