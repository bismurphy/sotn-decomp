SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    stno3_ROM_START = __romPos;
    stno3_VRAM = ADDR(.stno3);
    .stno3 0x80180000 : AT(stno3_ROM_START) SUBALIGN(4)
    {
        stno3_DATA_START = .;
        _0_data__s = .;
        build/us/asm/us/st/no3/data/0.data.s.o(.data);
        _920_data__s = .;
        build/us/asm/us/st/no3/data/920.data.s.o(.data);
        AAC_data__s = .;
        build/us/asm/us/st/no3/data/AAC.data.s.o(.data);
        DC0_data__s = .;
        build/us/asm/us/st/no3/data/DC0.data.s.o(.data);
        DD0_data__s = .;
        build/us/asm/us/st/no3/data/DD0.data.s.o(.data);
        E50_data__s = .;
        build/us/asm/us/st/no3/data/E50.data.s.o(.data);
        E70_data__s = .;
        build/us/asm/us/st/no3/data/E70.data.s.o(.data);
        E80_data__s = .;
        build/us/asm/us/st/no3/data/E80.data.s.o(.data);
        E90_data__s = .;
        build/us/asm/us/st/no3/data/E90.data.s.o(.data);
        EA0_data__s = .;
        build/us/asm/us/st/no3/data/EA0.data.s.o(.data);
        _11F0_data__s = .;
        build/us/asm/us/st/no3/data/11F0.data.s.o(.data);
        _1B40_data__s = .;
        build/us/asm/us/st/no3/data/1B40.data.s.o(.data);
        entity_relic_orb_c = .;
        build/us/src/st/no3/entity_relic_orb.c.o(.data);
        _2618_data__s = .;
        build/us/asm/us/st/no3/data/2618.data.s.o(.data);
        _3180_data__s = .;
        build/us/asm/us/st/no3/data/3180.data.s.o(.data);
        _39A0_data__s = .;
        build/us/asm/us/st/no3/data/39A0.data.s.o(.data);
        _3AC0_data__s = .;
        build/us/asm/us/st/no3/data/3AC0.data.s.o(.data);
        _3AF0_data__s = .;
        build/us/asm/us/st/no3/data/3AF0.data.s.o(.data);
        _3B30_data__s = .;
        build/us/asm/us/st/no3/data/3B30.data.s.o(.data);
        g_Rooms = .;
        build/us/assets/st/no3/g_Rooms.o(.data);
        _3DC8_data__s = .;
        build/us/asm/us/st/no3/data/3DC8.data.s.o(.data);
        _4CE0_data__s = .;
        build/us/asm/us/st/no3/data/4CE0.data.s.o(.data);
        _373E0_data__s = .;
        build/us/asm/us/st/no3/data/373E0.data.s.o(.data);
        stno3_DATA_END = .;
        stno3_DATA_SIZE = ABSOLUTE(stno3_DATA_END - stno3_DATA_START);
        stno3_RODATA_START = .;
        build/us/src/st/no3/377D4.c.o(.rodata);
        build/us/src/st/no3/377D4.c.o(.rodata);
        build/us/src/st/no3/3C4EC.c.o(.rodata);
        build/us/src/st/no3/3E134.c.o(.rodata);
        build/us/asm/us/st/no3/data/37440.rodata.s.o(.rodata);
        build/us/asm/us/st/no3/data/37458.rodata.s.o(.rodata);
        build/us/src/st/no3/3FF00.c.o(.rodata);
        build/us/src/st/no3/3FF00.c.o(.rodata);
        build/us/src/st/no3/3FF00.c.o(.rodata);
        build/us/src/st/no3/3FF00.c.o(.rodata);
        build/us/asm/us/st/no3/data/37578.rodata.s.o(.rodata);
        build/us/src/st/no3/46684.c.o(.rodata);
        build/us/src/st/no3/46684.c.o(.rodata);
        build/us/src/st/no3/entity_relic_orb.c.o(.rodata);
        build/us/src/st/no3/entity_message_box.c.o(.rodata);
        build/us/asm/us/st/no3/data/37664.rodata.s.o(.rodata);
        build/us/asm/us/st/no3/data/376E8.rodata.s.o(.rodata);
        build/us/src/st/no3/56264.c.o(.rodata);
        build/us/src/st/no3/564B0.c.o(.rodata);
        stno3_RODATA_END = .;
        stno3_RODATA_SIZE = ABSOLUTE(stno3_RODATA_END - stno3_RODATA_START);
        stno3_TEXT_START = .;
        build/us/src/st/no3/377D4.c.o(.text);
        build/us/src/st/no3/3C4EC.c.o(.text);
        build/us/src/st/no3/3E134.c.o(.text);
        build/us/src/st/no3/3FF00.c.o(.text);
        build/us/src/st/no3/random.c.o(.text);
        build/us/src/st/no3/update.c.o(.text);
        build/us/src/st/no3/update_stage_entities.c.o(.text);
        build/us/src/st/no3/41C80.c.o(.text);
        build/us/src/st/no3/46684.c.o(.text);
        build/us/src/st/no3/entity_relic_orb.c.o(.text);
        build/us/src/st/no3/entity_heart_drop.c.o(.text);
        build/us/src/st/no3/entity_message_box.c.o(.text);
        build/us/src/st/no3/48A84.c.o(.text);
        build/us/src/st/no3/56264.c.o(.text);
        build/us/src/st/no3/564B0.c.o(.text);
        stno3_TEXT_END = .;
        stno3_TEXT_SIZE = ABSOLUTE(stno3_TEXT_END - stno3_TEXT_START);
        build/us/asm/us/st/no3/data/570B0.sbss.s.o(.sbss);
    }
    __romPos += SIZEOF(.stno3);
    __romPos = ALIGN(__romPos, 16);
    stno3_ROM_END = __romPos;
    stno3_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
