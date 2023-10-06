SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stdre_ROM_START = __romPos;
    stdre_VRAM = ADDR(.stdre);
    .stdre 0x80180000 : AT(stdre_ROM_START) SUBALIGN(4)
    {
        stdre_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/dre/data/0.data.s.o(.data);
        _590_data__s = .;
        build/us/asm/us/st/dre/data/590.data.s.o(.data);
        _610_data__s = .;
        build/us/asm/us/st/dre/data/610.data.s.o(.data);
        _630_data__s = .;
        build/us/asm/us/st/dre/data/630.data.s.o(.data);
        _640_data__s = .;
        build/us/asm/us/st/dre/data/640.data.s.o(.data);
        _650_data__s = .;
        build/us/asm/us/st/dre/data/650.data.s.o(.data);
        _660_data__s = .;
        build/us/asm/us/st/dre/data/660.data.s.o(.data);
        _770_data__s = .;
        build/us/asm/us/st/dre/data/770.data.s.o(.data);
        entity_relic_orb_c = .;
        build/us/src/st/dre/entity_relic_orb.c.o(.data);
        _12D4_data__s = .;
        build/us/asm/us/st/dre/data/12D4.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/dre/g_Rooms.o(.data);
        _14AC_data__s = .;
        build/us/asm/us/st/dre/data/14AC.data.s.o(.data);
        _16C0_data__s = .;
        build/us/asm/us/st/dre/data/16C0.data.s.o(.data);
        stdre_DATA_END = .;
        stdre_DATA_SIZE = ABSOLUTE(stdre_DATA_END - stdre_DATA_START);
        stdre_RODATA_START = .;
        build/us/src/st/dre/11A64.c.o(.rodata);
        build/us/src/st/dre/succubus.c.o(.rodata);
        build/us/src/st/dre/13B3C.c.o(.rodata);
        build/us/src/st/dre/14774.c.o(.rodata);
        build/us/asm/us/st/dre/data/1181C.rodata.s.o(.rodata);
        build/us/asm/us/st/dre/data/118D0.rodata.s.o(.rodata);
        build/us/src/st/dre/1697C.c.o(.rodata);
        build/us/asm/us/st/dre/data/1193C.rodata.s.o(.rodata);
        build/us/src/st/dre/1C7DC.c.o(.rodata);
        build/us/src/st/dre/entity_relic_orb.c.o(.rodata);
        build/us/src/st/dre/entity_message_box.c.o(.rodata);
        build/us/asm/us/st/dre/data/11A28.rodata.s.o(.rodata);
        stdre_RODATA_END = .;
        stdre_RODATA_SIZE = ABSOLUTE(stdre_RODATA_END - stdre_RODATA_START);
        stdre_TEXT_START = .;
        build/us/src/st/dre/11A64.c.o(.text);
        build/us/src/st/dre/succubus.c.o(.text);
        build/us/src/st/dre/13B3C.c.o(.text);
        build/us/src/st/dre/14774.c.o(.text);
        build/us/src/st/dre/1697C.c.o(.text);
        build/us/src/st/dre/random.c.o(.text);
        build/us/src/st/dre/update.c.o(.text);
        build/us/src/st/dre/update_stage_entities.c.o(.text);
        build/us/src/st/dre/173C4.c.o(.text);
        build/us/src/st/dre/1C7DC.c.o(.text);
        build/us/src/st/dre/entity_relic_orb.c.o(.text);
        build/us/src/st/dre/entity_heart_drop.c.o(.text);
        build/us/src/st/dre/entity_message_box.c.o(.text);
        build/us/src/st/dre/1E1C8.c.o(.text);
        stdre_TEXT_END = .;
        stdre_TEXT_SIZE = ABSOLUTE(stdre_TEXT_END - stdre_TEXT_START);
        build/us/asm/us/st/dre/data/23260.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.stdre);
    __romPos = ALIGN(__romPos, 16);
    stdre_ROM_END = __romPos;
    stdre_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
