SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stmad_ROM_START = __romPos;
    stmad_VRAM = ADDR(.stmad);
    .stmad 0x80180000 : AT(stmad_ROM_START) SUBALIGN(2)
    {
        stmad_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/mad/data/0.data.s.o(.data);
        E40_data__s = .;
        build/us/asm/us/st/mad/data/E40.data.s.o(.data);
        entity_relic_orb_c = .;
        build/us/src/st/mad/entity_relic_orb.c.o(.data);
        F5C_data__s = .;
        build/us/asm/us/st/mad/data/F5C.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/mad/g_Rooms.o(.data);
        _11D4_data__s = .;
        build/us/asm/us/st/mad/data/11D4.data.s.o(.data);
        _1404_data__s = .;
        build/us/asm/us/st/mad/data/1404.data.s.o(.data);
        _1774_data__s = .;
        build/us/asm/us/st/mad/data/1774.data.s.o(.data);
        _19A4_data__s = .;
        build/us/asm/us/st/mad/data/19A4.data.s.o(.data);
        _1D14_data__s = .;
        build/us/asm/us/st/mad/data/1D14.data.s.o(.data);
        stmad_DATA_END = .;
        stmad_DATA_SIZE = ABSOLUTE(stmad_DATA_END - stmad_DATA_START);
        stmad_RODATA_START = .;
        build/us/asm/us/st/mad/data/D794.rodata.s.o(.rodata);
        build/us/src/st/mad/139E0.c.o(.rodata);
        build/us/asm/us/st/mad/data/D85C.rodata.s.o(.rodata);
        build/us/src/st/mad/entity_relic_orb.c.o(.rodata);
        build/us/asm/us/st/mad/data/D8AC.rodata.s.o(.rodata);
        stmad_RODATA_END = .;
        stmad_RODATA_SIZE = ABSOLUTE(stmad_RODATA_END - stmad_RODATA_START);
        stmad_TEXT_START = .;
        build/us/src/st/mad/D8C8.c.o(.text);
        build/us/src/st/mad/random.c.o(.text);
        build/us/src/st/mad/update.c.o(.text);
        build/us/src/st/mad/CollectGold.c.o(.text);
        build/us/src/st/mad/EDB8.c.o(.text);
        build/us/src/st/mad/139E0.c.o(.text);
        build/us/src/st/mad/entity_relic_orb.c.o(.text);
        build/us/src/st/mad/15520.c.o(.text);
        stmad_TEXT_END = .;
        stmad_TEXT_SIZE = ABSOLUTE(stmad_TEXT_END - stmad_TEXT_START);
        build/us/asm/us/st/mad/data/197D8.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.stmad);
    __romPos = ALIGN(__romPos, 16);
    stmad_ROM_END = __romPos;
    stmad_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
