# Allows modification of an extracted palette which lives in the assets directory

import tkinter as tk
from tkinter import filedialog as tkfd
import zlib
import matplotlib.pyplot as plt
import numpy as np

def hexdump(d):
    for i in range(0, len(d), 16):
        h = [f"{b:02x}" for b in d[i:i+16]]
        l, r = " ".join(h[:8]), " ".join(h[8:])
        a = "".join(chr(b) if 31 < b < 127 else "." for b in d[i:i+16])
        print(f"{i:02x}: {l:<23}  {r:<23}  |{a}|")

def png_header_good(databytes):
    if databytes[0:8] == bytes([0x89, 0x50, 0x4E, 0x47, 0xD, 0xA, 0x1A, 0xA]):
        return True
    else:
        print("Header error!")
        print([hex(x) for x in databytes[0:8]])
        
        return False
    
class Chunk():
    def __init__(self, all_data):
        self.raw = all_data
        self.len = int.from_bytes(all_data[:4],byteorder='big')
        self.type = all_data[4:8].decode()
        self.payload = all_data[8:8+self.len]
        self.crc = all_data[8+self.len:12+self.len]
        
        calculated_crc = zlib.crc32(self.raw[4:-4]).to_bytes(4)
        assert(calculated_crc == self.crc)

class PNGParse():
    def __init__(self, chunkset):
        self.chunks = chunkset
        self.img_data = []
        for chunk in self.chunks:
            match chunk.type:
                case 'IHDR':
                    self.process_header()
                case 'PLTE':
                    self.load_palette(chunk)
                case 'tRNS':
                    self.apply_alpha_to_palette(chunk)
                case 'IDAT':
                    self.parse_idat(chunk)
                case 'IEND': # end chunk holds no data
                    self.parse_end(chunk)
                case _:
                    print("Unimplemented chunk", chunk.type)
        
    def process_header(self):
        assert self.chunks[0].type == 'IHDR'
        header_chunk = self.chunks[0].payload
        self.width = int.from_bytes(header_chunk[:4],byteorder='big')
        self.height = int.from_bytes(header_chunk[4:8],byteorder='big')
        self.bit_depth = header_chunk[8]
        self.color_type = header_chunk[9]
        self.compression_method = header_chunk[10]
        self.filter_method = header_chunk[11]
        self.interlace_method = header_chunk[12]
    def load_palette(self,palette_chunk):
        data = palette_chunk.payload
        palette_size = len(data) // 3
        self.palette = [[int(x) for x in data[i:i+3]] for i in range(0, palette_size*3, 3)]
    def apply_alpha_to_palette(self, trns_chunk):
        data = trns_chunk.payload
        assert len(data) == len(self.palette)
        for i in range(len(data)):
            self.palette[i].append(data[i])
    def parse_idat(self,idat_chunk):
        decompressed = zlib.decompress(idat_chunk.payload)
        filter_type = decompressed[0]
        #nofilter
        if filter_type == 0:
            self.img_data.append(decompressed[1:])
    def parse_end(self, end_chunk):
        pass
def load_png_chunks(databytes):
    assert png_header_good(databytes)
    data_idx = 8
    chunks = []
    while(data_idx < len(databytes)):
        chunk_len = int.from_bytes(databytes[data_idx:data_idx+4],byteorder='big')
        # That tells us payload size. Full chunk size is those 4 bytes,
        # plus 4 type-bytes, the payload, and a 4-byte CRC. Total of 12
        # extra bytes.
        chunk_end = data_idx+chunk_len+12
        all_chunk_data = databytes[data_idx:chunk_end]
        chunks.append(Chunk(all_chunk_data))
        data_idx = chunk_end
    return chunks

def load_sotn_palette(filebytes):
    chunks = load_png_chunks(filebytes)
    orig_img = PNGParse(chunks)
    # for sotn palette, need these params to hold:
    assert orig_img.width == 16
    assert orig_img.height == 1
    assert orig_img.bit_depth == 8 # 1 byte per pixel
    assert orig_img.color_type == 3 # indexed color, uses PLTE chunk
    assert orig_img.compression_method == 0 # fixed value for png. always 0, meaning deflate.
    assert orig_img.filter_method == 0 #also fixed at 0
    assert orig_img.interlace_method == 0 # no interlacing
    assert orig_img.img_data == [bytes(range(16))] # sotn palette image should just be indices 0-16
    
    orig_palette = np.array(orig_img.palette,dtype='uint8').reshape(16,4)
    return orig_palette

# Convert a 3-element array of colors to a web-style #RRGGBB format
def rgb_to_web(rgb):
    r,g,b = rgb
    return f"#{r:02X}{g:02X}{b:02X}"

class EditorGUI:
    def __init__(self, root, pal_orig):
        self.root = root
        self.root.title("SOTN Palette Editor")
        self.palette = pal_orig
        self.selected_idx = None

        self.color_buttons = []
        for i in range(len(self.palette)):
            # Convert RGB to Hex for Tkinter
            color_hex = rgb_to_web(self.palette[i][:3])
            # Create invisible frame by setting background to window background.
            # Frame will turn red when the button is selected.
            frame = tk.Frame(self.root, bg=self.root['bg'], padx=2, pady=2)
            frame.grid(row=0, column=i, padx=2)

            btn = tk.Button(frame, fg='white', bg=color_hex, width=4, height=2,
                            command=lambda idx=i: self.select_color(idx))
            # Indicate the transparency flag by showing a little tile icon
            if not self.palette[i][3] & 0x80:
                btn.config(text="◩")
            btn.pack()

            self.color_buttons.append(btn)

        self.sliders = []
        for i, color in enumerate("RGB"):
            tk.Label(text=color).grid(row=i+1, column=0)
            s = tk.Scale(self.root, from_=0, to=255, orient='horizontal', 
                        length=300, command=self.update_color)
            s.grid(row=i+1, column=1, columnspan = 5)
            self.sliders.append(s)

        self.transparency_check = tk.BooleanVar(value=False)
        transparency_checkbox = tk.Checkbutton(self.root, text="Transparency", var=self.transparency_check, command=self.set_transparency)
        transparency_checkbox.grid(row=5, column=0, columnspan = 5)
        
        # Clicking the save button actually just closes the window. We then continue into a save routine.
        # For a fun example of a somewhat comparable hack, look up "Thank you for playing Wing Commander"
        self.save_button = tk.Button(self.root, text='Save Palette', command=self.root.destroy)
        self.save_button.grid(row=5, column=12, columnspan=4)
        
    def set_transparency(self):
        if self.selected_idx is None:
            return
        transp = self.transparency_check.get()
        self.palette[self.selected_idx][3] = 0x7F | (0 if transp else 0x80)
        self.color_buttons[self.selected_idx].config(text=("◩" if transp else ""))

    def select_color(self, chosen_button): 
        # un-select the frame of the previously selected idx
        if self.selected_idx is not None:
            self.color_buttons[self.selected_idx].master.config(bg=self.root['bg'])
        self.color_buttons[chosen_button].master.config(bg='red')

        # Log the button as selected
        self.selected_idx = chosen_button

        # Move the sliders to our button color
        for i, slider in enumerate(self.sliders):
            slider.set(self.palette[chosen_button][i])
        # Set transparency checkbox to match the chosen button
        self.transparency_check.set(not self.palette[chosen_button][3] & 0x80)
        
    # Gets called when any slider is moved.
    def update_color(self, slider_changed):
        if self.selected_idx is None:
            return
        legal_values = np.array([int(x * 255 / 31) for x in range(32)])
        for slider in self.sliders:
            val = slider.get()
            if val not in legal_values:
                closest_legal = int(np.argmin(abs(legal_values - val)) * 255 / 31)
                slider.set(closest_legal)
        newColor = [s.get() for s in self.sliders]
        for i in range(3):
            self.palette[self.selected_idx][i] = newColor[i]
            self.color_buttons[self.selected_idx].config(bg=rgb_to_web(self.palette[self.selected_idx][:3]))
        

if __name__ == '__main__':
    #https://stackoverflow.com/questions/3579568/choosing-a-file-in-python-with-simple-dialog
    filename = tkfd.askopenfilename() # show an "Open" dialog box and return the path to the selected file
    with open(filename, 'rb') as f:
        orig_filebytes = f.read()
    pal_start = load_sotn_palette(orig_filebytes)
    root = tk.Tk()
    app = EditorGUI(root, pal_start)
    root.mainloop()

    save_file = tkfd.asksaveasfilename(defaultextension='.png')
    with open(save_file,'wb') as f:
        # create a (mutable) bytearray object to be able to substitute in our new bytes
        # Use the original file as a base since most of the PNG boilerplate is unchanged.
        outbytes = bytearray(orig_filebytes)

        # Take the original file's palette and replace it.
        newpal_bytes = bytearray(app.palette[:, 0:3].tobytes())
        newpal_bytes.extend(zlib.crc32(b'PLTE'+newpal_bytes).to_bytes(4))
        outbytes[0x29:0x29 + len(newpal_bytes)] = newpal_bytes
        # Do the same with the transparency layer.
        alphas = bytearray(app.palette[:,3].tobytes())
        alphas.extend(zlib.crc32(b'tRNS' + alphas).to_bytes(4))
        outbytes[0x65:0x65 + len(alphas)] = alphas

        f.write(outbytes)
