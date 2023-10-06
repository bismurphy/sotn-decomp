SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    ric_ROM_START = __romPos;
    ric_VRAM = ADDR(.ric);
    .ric 0x8013C000 : AT(ric_ROM_START) SUBALIGN(4)
    {
        ric_RODATA_START = .;
        build/us/asm/us/ric/data/0.rodata.s.o(.rodata);
        ric_DATA_START = .;
        richter = .;
        build/us/assets/ric/richter.o(.data);
        build/us/asm/us/ric/data/170AC.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/194B0.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/19B50.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/19BE0.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/19C70.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/19EE0.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/1A454.rodata.s.o(.rodata);
        build/us/src/ric/1AC60.c.o(.rodata);
        build/us/asm/us/ric/data/1A5F0.rodata.s.o(.rodata);
        build/us/src/ric/1F348.c.o(.rodata);
        build/us/src/ric/1FCD0.c.o(.rodata);
        build/us/src/ric/202A8.c.o(.rodata);
        build/us/src/ric/20920.c.o(.rodata);
        build/us/src/ric/21250.c.o(.rodata);
        build/us/asm/us/ric/data/1A874.rodata.s.o(.rodata);
        build/us/src/ric/22380.c.o(.rodata);
        build/us/asm/us/ric/data/1A908.rodata.s.o(.rodata);
        build/us/src/ric/26C84.c.o(.rodata);
        build/us/asm/us/ric/data/1A9E8.rodata.s.o(.rodata);
        build/us/asm/us/ric/data/1AB04.rodata.s.o(.rodata);
        build/us/src/ric/32324.c.o(.rodata);
        build/us/asm/us/ric/data/1AB88.rodata.s.o(.rodata);
        build/us/src/ric/345EC.c.o(.rodata);
        build/us/asm/us/ric/data/1ABF0.rodata.s.o(.rodata);
        ric_RODATA_END = .;
        ric_RODATA_SIZE = ABSOLUTE(ric_RODATA_END - ric_RODATA_START);
        ric_TEXT_START = .;
        build/us/src/ric/1AC60.c.o(.text);
        build/us/src/ric/1F348.c.o(.text);
        build/us/src/ric/1FCD0.c.o(.text);
        build/us/src/ric/202A8.c.o(.text);
        build/us/src/ric/20920.c.o(.text);
        build/us/src/ric/21250.c.o(.text);
        build/us/src/ric/22380.c.o(.text);
        build/us/src/ric/26C84.c.o(.text);
        build/us/src/ric/32324.c.o(.text);
        build/us/src/ric/345EC.c.o(.text);
        ric_TEXT_END = .;
        ric_TEXT_SIZE = ABSOLUTE(ric_TEXT_END - ric_TEXT_START);
        _37B60_data__s = .;
        build/us/asm/us/ric/data/37B60.data.s.o(.data);
        ric_DATA_END = .;
        ric_DATA_SIZE = ABSOLUTE(ric_DATA_END - ric_DATA_START);
    }
    __romPos += SIZEOF(.ric);
    __romPos = ALIGN(__romPos, 16);
    ric_ROM_END = __romPos;
    ric_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
