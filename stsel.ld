SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stsel_ROM_START = __romPos;
    stsel_VRAM = ADDR(.stsel);
    .stsel 0x80180000 : AT(stsel_ROM_START) SUBALIGN(4)
    {
        stsel_DATA_START = .;
        _2C048_c = .;
        build/us/src/st/sel/2C048.c.o(.data);
        _40_data__s = .;
        build/us/asm/us/st/sel/data/40.data.s.o(.data);
        save_mgr_c = .;
        build/us/src/st/sel/save_mgr.c.o(.data);
        _2584_data__s = .;
        build/us/asm/us/st/sel/data/2584.data.s.o(.data);
        D5D4_c = .;
        build/us/src/st/sel/D5D4.c.o(.data);
        DBD4_data__s = .;
        build/us/asm/us/st/sel/data/DBD4.data.s.o(.data);
        stsel_DATA_END = .;
        stsel_DATA_SIZE = ABSOLUTE(stsel_DATA_END - stsel_DATA_START);
        stsel_RODATA_START = .;
        build/us/asm/us/st/sel/data/176C0.rodata.s.o(.rodata);
        build/us/src/st/sel/2D260.c.o(.rodata);
        build/us/asm/us/st/sel/data/276F0.rodata.s.o(.rodata);
        build/us/src/st/sel/2EED8.c.o(.rodata);
        build/us/asm/us/st/sel/data/27AE4.rodata.s.o(.rodata);
        build/us/asm/us/st/sel/data/27B14.rodata.s.o(.rodata);
        build/us/asm/us/st/sel/data/27B4C.rodata.s.o(.rodata);
        build/us/src/st/sel/3410C.c.o(.rodata);
        build/us/src/st/sel/3410C.c.o(.rodata);
        build/us/src/st/sel/3585C.c.o(.rodata);
        build/us/asm/us/st/sel/data/27CD4.rodata.s.o(.rodata);
        build/us/asm/us/st/sel/data/27CF4.rodata.s.o(.rodata);
        build/us/src/st/sel/save_mgr.c.o(.rodata);
        build/us/asm/us/st/sel/data/28040.rodata.s.o(.rodata);
        build/us/src/st/sel/stream.c.o(.rodata);
        stsel_RODATA_END = .;
        stsel_RODATA_SIZE = ABSOLUTE(stsel_RODATA_END - stsel_RODATA_START);
        stsel_TEXT_START = .;
        build/us/src/st/sel/2C048.c.o(.text);
        build/us/src/st/sel/2D260.c.o(.text);
        build/us/src/st/sel/2EED8.c.o(.text);
        build/us/src/st/sel/3410C.c.o(.text);
        build/us/src/st/sel/3585C.c.o(.text);
        build/us/src/st/sel/3642C.c.o(.text);
        build/us/src/st/sel/save_mgr.c.o(.text);
        build/us/src/st/sel/stream.c.o(.text);
        stsel_TEXT_END = .;
        stsel_TEXT_SIZE = ABSOLUTE(stsel_TEXT_END - stsel_TEXT_START);
        build/us/asm/us/st/sel/data/3AEE4.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.stsel);
    __romPos = ALIGN(__romPos, 16);
    stsel_ROM_END = __romPos;
    stsel_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
