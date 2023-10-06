SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    tt_000_ROM_START = __romPos;
    tt_000_VRAM = ADDR(.tt_000);
    .tt_000 0x80170000 : AT(tt_000_ROM_START) SUBALIGN(2)
    {
        tt_000_DATA_START = .;
        _10E8_c = .;
        build/us/src/servant/tt_000/10E8.c.o(.data);
        spriteparts_c = .;
        build/us/src/servant/tt_000/spriteparts.c.o(.data);
        _448_c = .;
        build/us/src/servant/tt_000/448.c.o(.data);
        _4A8_c = .;
        build/us/src/servant/tt_000/4A8.c.o(.data);
        _608_c = .;
        build/us/src/servant/tt_000/608.c.o(.data);
        tt_000_DATA_END = .;
        tt_000_DATA_SIZE = ABSOLUTE(tt_000_DATA_END - tt_000_DATA_START);
        tt_000_RODATA_START = .;
        build/us/asm/us/servant/tt_000/data/10AC.rodata.s.o(.rodata);
        build/us/src/servant/tt_000/10E8.c.o(.rodata);
        tt_000_RODATA_END = .;
        tt_000_RODATA_SIZE = ABSOLUTE(tt_000_RODATA_END - tt_000_RODATA_START);
        tt_000_TEXT_START = .;
        build/us/src/servant/tt_000/10E8.c.o(.text);
        tt_000_TEXT_END = .;
        tt_000_TEXT_SIZE = ABSOLUTE(tt_000_TEXT_END - tt_000_TEXT_START);
        build/us/asm/us/servant/tt_000/data/48D8.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.tt_000);
    __romPos = ALIGN(__romPos, 16);
    tt_000_ROM_END = __romPos;
    tt_000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
