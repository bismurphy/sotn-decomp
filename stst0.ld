SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stst0_ROM_START = __romPos;
    stst0_VRAM = ADDR(.stst0);
    .stst0 0x80180000 : AT(stst0_ROM_START) SUBALIGN(4)
    {
        stst0_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/st0/data/0.data.s.o(.data);
        _580_data__s = .;
        build/us/asm/us/st/st0/data/580.data.s.o(.data);
        _770_data__s = .;
        build/us/asm/us/st/st0/data/770.data.s.o(.data);
        _990_data__s = .;
        build/us/asm/us/st/st0/data/990.data.s.o(.data);
        AB0_data__s = .;
        build/us/asm/us/st/st0/data/AB0.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/st0/g_Rooms.o(.data);
        _2084_data__s = .;
        build/us/asm/us/st/st0/data/2084.data.s.o(.data);
        _487C_data__s = .;
        build/us/asm/us/st/st0/data/487C.data.s.o(.data);
        _187BC_data__s = .;
        build/us/asm/us/st/st0/data/187BC.data.s.o(.data);
        _1A750_data__s = .;
        build/us/asm/us/st/st0/data/1A750.data.s.o(.data);
        stst0_DATA_END = .;
        stst0_DATA_SIZE = ABSOLUTE(stst0_DATA_END - stst0_DATA_START);
        stst0_RODATA_START = .;
        build/us/src/st/st0/27D64.c.o(.rodata);
        build/us/asm/us/st/st0/data/279E8.rodata.s.o(.rodata);
        build/us/src/st/st0/28BF8.c.o(.rodata);
        build/us/src/st/st0/2A8DC.c.o(.rodata);
        build/us/src/st/st0/2A8DC.c.o(.rodata);
        build/us/src/st/st0/2B0C8.c.o(.rodata);
        build/us/src/st/st0/2B0C8.c.o(.rodata);
        build/us/asm/us/st/st0/data/27B18.rodata.s.o(.rodata);
        build/us/src/st/st0/2C564.c.o(.rodata);
        build/us/asm/us/st/st0/data/27B7C.rodata.s.o(.rodata);
        build/us/asm/us/st/st0/data/27BFC.rodata.s.o(.rodata);
        build/us/src/st/st0/36358.c.o(.rodata);
        build/us/asm/us/st/st0/data/27CAC.rodata.s.o(.rodata);
        build/us/asm/us/st/st0/data/27CC4.rodata.s.o(.rodata);
        stst0_RODATA_END = .;
        stst0_RODATA_SIZE = ABSOLUTE(stst0_RODATA_END - stst0_RODATA_START);
        stst0_TEXT_START = .;
        build/us/src/st/st0/27D64.c.o(.text);
        build/us/src/st/st0/28BF8.c.o(.text);
        build/us/src/st/st0/2A8DC.c.o(.text);
        build/us/src/st/st0/2B0C8.c.o(.text);
        build/us/src/st/st0/2C564.c.o(.text);
        build/us/src/st/st0/30030.c.o(.text);
        build/us/src/st/st0/random.c.o(.text);
        build/us/src/st/st0/update.c.o(.text);
        build/us/src/st/st0/update_stage_entities.c.o(.text);
        build/us/src/st/st0/31CA0.c.o(.text);
        build/us/src/st/st0/36358.c.o(.text);
        stst0_TEXT_END = .;
        stst0_TEXT_SIZE = ABSOLUTE(stst0_TEXT_END - stst0_TEXT_START);
        build/us/asm/us/st/st0/data/3EB00.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.stst0);
    __romPos = ALIGN(__romPos, 16);
    stst0_ROM_END = __romPos;
    stst0_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
