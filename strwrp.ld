SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    strwrp_ROM_START = __romPos;
    strwrp_VRAM = ADDR(.strwrp);
    .strwrp 0x80180000 : AT(strwrp_ROM_START) SUBALIGN(4)
    {
        strwrp_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/rwrp/data/0.data.s.o(.data);
        _4E0_data__s = .;
        build/us/asm/us/st/rwrp/data/4E0.data.s.o(.data);
        _5E0_data__s = .;
        build/us/asm/us/st/rwrp/data/5E0.data.s.o(.data);
        entity_relic_orb_c = .;
        build/us/src/st/rwrp/entity_relic_orb.c.o(.data);
        FE8_data__s = .;
        build/us/asm/us/st/rwrp/data/FE8.data.s.o(.data);
        _10A0_data__s = .;
        build/us/asm/us/st/rwrp/data/10A0.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/rwrp/g_Rooms.o(.data);
        _1228_data__s = .;
        build/us/asm/us/st/rwrp/data/1228.data.s.o(.data);
        strwrp_DATA_END = .;
        strwrp_DATA_SIZE = ABSOLUTE(strwrp_DATA_END - strwrp_DATA_START);
        strwrp_RODATA_START = .;
        build/us/asm/us/st/rwrp/data/8C88.rodata.s.o(.rodata);
        build/us/src/st/rwrp/entity_relic_orb.c.o(.rodata);
        build/us/src/st/rwrp/entity_message_box.c.o(.rodata);
        build/us/asm/us/st/rwrp/data/8DB4.rodata.s.o(.rodata);
        strwrp_RODATA_END = .;
        strwrp_RODATA_SIZE = ABSOLUTE(strwrp_RODATA_END - strwrp_RODATA_START);
        strwrp_TEXT_START = .;
        build/us/src/st/rwrp/8DF0.c.o(.text);
        build/us/src/st/rwrp/random.c.o(.text);
        build/us/src/st/rwrp/update.c.o(.text);
        build/us/src/st/rwrp/update_stage_entities.c.o(.text);
        build/us/src/st/rwrp/A59C.c.o(.text);
        build/us/src/st/rwrp/entity_relic_orb.c.o(.text);
        build/us/src/st/rwrp/entity_heart_drop.c.o(.text);
        build/us/src/st/rwrp/entity_message_box.c.o(.text);
        build/us/src/st/rwrp/113A0.c.o(.text);
        build/us/src/st/rwrp/14590.c.o(.text);
        strwrp_TEXT_END = .;
        strwrp_TEXT_SIZE = ABSOLUTE(strwrp_TEXT_END - strwrp_TEXT_START);
        build/us/asm/us/st/rwrp/data/15A20.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.strwrp);
    __romPos = ALIGN(__romPos, 16);
    strwrp_ROM_END = __romPos;
    strwrp_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
