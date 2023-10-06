SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stcen_ROM_START = __romPos;
    stcen_VRAM = ADDR(.stcen);
    .stcen 0x80180000 : AT(stcen_ROM_START) SUBALIGN(2)
    {
        stcen_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/cen/data/0.data.s.o(.data);
        entity_relic_orb_c = .;
        build/us/src/st/cen/entity_relic_orb.c.o(.data);
        _1110_data__s = .;
        build/us/asm/us/st/cen/data/1110.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/cen/g_Rooms.o(.data);
        _1300_data__s = .;
        build/us/asm/us/st/cen/data/1300.data.s.o(.data);
        stcen_DATA_END = .;
        stcen_DATA_SIZE = ABSOLUTE(stcen_DATA_END - stcen_DATA_START);
        stcen_RODATA_START = .;
        build/us/asm/us/st/cen/data/D42C.rodata.s.o(.rodata);
        build/us/src/st/cen/D600.c.o(.rodata);
        build/us/asm/us/st/cen/data/D4D8.rodata.s.o(.rodata);
        build/us/src/st/cen/entity_relic_orb.c.o(.rodata);
        build/us/src/st/cen/entity_message_box.c.o(.rodata);
        build/us/asm/us/st/cen/data/D5C4.rodata.s.o(.rodata);
        stcen_TEXT_START = .;
        build/us/src/st/cen/D600.c.o(.text);
        build/us/src/st/cen/random.c.o(.text);
        build/us/src/st/cen/update.c.o(.text);
        build/us/src/st/cen/update_stage_entities.c.o(.text);
        build/us/src/st/cen/11280.c.o(.text);
        build/us/src/st/cen/entity_relic_orb.c.o(.text);
        build/us/src/st/cen/entity_heart_drop.c.o(.text);
        build/us/src/st/cen/entity_message_box.c.o(.text);
        build/us/src/st/cen/18084.c.o(.text);
        build/us/src/st/cen/1B274.c.o(.text);
        stcen_TEXT_END = .;
        stcen_TEXT_SIZE = ABSOLUTE(stcen_TEXT_END - stcen_TEXT_START);
        build/us/asm/us/st/cen/data/1C704.rodata.s.o(.rodata);
        build/us/asm/us/st/cen/data/1C764.rodata.s.o(.rodata);
        build/us/asm/us/st/cen/data/1D374.rodata.s.o(.rodata);
        build/us/asm/us/st/cen/data/1D424.rodata.s.o(.rodata);
        stcen_RODATA_END = .;
        stcen_RODATA_SIZE = ABSOLUTE(stcen_RODATA_END - stcen_RODATA_START);
    }
    __romPos += SIZEOF(.stcen);
    __romPos = ALIGN(__romPos, 16);
    stcen_ROM_END = __romPos;
    stcen_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
