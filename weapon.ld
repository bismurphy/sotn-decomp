SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    f_000_ROM_START = __romPos;
    f_000_VRAM = ADDR(.f_000);
    .f_000 0x0 : AT(f_000_ROM_START) SUBALIGN(16)
    {
        f_000_DATA_START = .;
        f_000_png = .;
        build/us/assets/weapon/f_000.png.o(.data);
        f_000_DATA_END = .;
        f_000_DATA_SIZE = ABSOLUTE(f_000_DATA_END - f_000_DATA_START);
    }
    __romPos += SIZEOF(.f_000);
    f_000_ROM_END = __romPos;
    f_000_VRAM_END = .;

    _4000_ROM_START = __romPos;
    _4000_VRAM = ADDR(._4000);
    ._4000 0x8017A000 : AT(_4000_ROM_START) SUBALIGN(4)
    {
        _4000_DATA_START = .;
        w_000_1 = .;
        build/us/assets/weapon/w_000_1.o(.data);
        w_000_2 = .;
        build/us/assets/weapon/w_000_2.o(.data);
        w_000_data__s = .;
        build/us/asm/us/weapon/data/w_000.data.s.o(.data);
        w_000_c = .;
        build/us/src/weapon/w_000.c.o(.data);
        _4000_DATA_END = .;
        _4000_DATA_SIZE = ABSOLUTE(_4000_DATA_END - _4000_DATA_START);
        _4000_TEXT_START = .;
        build/us/src/weapon/w_000.c.o(.text);
        _4000_TEXT_END = .;
        _4000_TEXT_SIZE = ABSOLUTE(_4000_TEXT_END - _4000_TEXT_START);
        build/us/asm/us/weapon/data/w_000.sbss.s.o(.sbss);
        _4000_RODATA_START = .;
        build/us/src/weapon/w_000.c.o(.rodata);
        _4000_RODATA_END = .;
        _4000_RODATA_SIZE = ABSOLUTE(_4000_RODATA_END - _4000_RODATA_START);
    }
    _4000_bss_VRAM = ADDR(._4000_bss);
    ._4000_bss (NOLOAD) : SUBALIGN(4)
    {
        _4000_BSS_START = .;
        build/us/src/weapon/w_000.c.o(.bss);
        _4000_BSS_END = .;
        _4000_BSS_SIZE = ABSOLUTE(_4000_BSS_END - _4000_BSS_START);
    }
    __romPos += SIZEOF(._4000);
    __romPos = ALIGN(__romPos, 16);
    _4000_ROM_END = __romPos;
    _4000_VRAM_END = .;

    f_001_ROM_START = __romPos;
    f_001_VRAM = ADDR(.f_001);
    .f_001 0x0 : AT(f_001_ROM_START) SUBALIGN(16)
    {
        f_001_DATA_START = .;
        f_001_png = .;
        build/us/assets/weapon/f_001.png.o(.data);
        f_001_DATA_END = .;
        f_001_DATA_SIZE = ABSOLUTE(f_001_DATA_END - f_001_DATA_START);
    }
    __romPos += SIZEOF(.f_001);
    f_001_ROM_END = __romPos;
    f_001_VRAM_END = .;

    B000_ROM_START = __romPos;
    B000_VRAM = ADDR(.B000);
    .B000 0x8017A000 : AT(B000_ROM_START) SUBALIGN(4)
    {
        B000_DATA_START = .;
        w_001_1 = .;
        build/us/assets/weapon/w_001_1.o(.data);
        w_001_2 = .;
        build/us/assets/weapon/w_001_2.o(.data);
        w_001_data__s = .;
        build/us/asm/us/weapon/data/w_001.data.s.o(.data);
        B000_DATA_END = .;
        B000_DATA_SIZE = ABSOLUTE(B000_DATA_END - B000_DATA_START);
        B000_TEXT_START = .;
        build/us/src/weapon/w_001.c.o(.text);
        B000_TEXT_END = .;
        B000_TEXT_SIZE = ABSOLUTE(B000_TEXT_END - B000_TEXT_START);
        build/us/asm/us/weapon/data/w_001.sbss.s.o(.sbss);
        B000_RODATA_START = .;
        build/us/src/weapon/w_001.c.o(.rodata);
        B000_RODATA_END = .;
        B000_RODATA_SIZE = ABSOLUTE(B000_RODATA_END - B000_RODATA_START);
    }
    B000_bss_VRAM = ADDR(.B000_bss);
    .B000_bss (NOLOAD) : SUBALIGN(4)
    {
        B000_BSS_START = .;
        build/us/src/weapon/w_001.c.o(.bss);
        B000_BSS_END = .;
        B000_BSS_SIZE = ABSOLUTE(B000_BSS_END - B000_BSS_START);
    }
    __romPos += SIZEOF(.B000);
    __romPos = ALIGN(__romPos, 16);
    B000_ROM_END = __romPos;
    B000_VRAM_END = .;

    f_002_ROM_START = __romPos;
    f_002_VRAM = ADDR(.f_002);
    .f_002 0x0 : AT(f_002_ROM_START) SUBALIGN(16)
    {
        f_002_DATA_START = .;
        f_002_png = .;
        build/us/assets/weapon/f_002.png.o(.data);
        f_002_DATA_END = .;
        f_002_DATA_SIZE = ABSOLUTE(f_002_DATA_END - f_002_DATA_START);
    }
    __romPos += SIZEOF(.f_002);
    f_002_ROM_END = __romPos;
    f_002_VRAM_END = .;

    _12000_ROM_START = __romPos;
    _12000_VRAM = ADDR(._12000);
    ._12000 0x8017A000 : AT(_12000_ROM_START) SUBALIGN(4)
    {
        _12000_DATA_START = .;
        w_002_1 = .;
        build/us/assets/weapon/w_002_1.o(.data);
        w_002_2 = .;
        build/us/assets/weapon/w_002_2.o(.data);
        w_002_data__s = .;
        build/us/asm/us/weapon/data/w_002.data.s.o(.data);
        _12000_DATA_END = .;
        _12000_DATA_SIZE = ABSOLUTE(_12000_DATA_END - _12000_DATA_START);
        _12000_TEXT_START = .;
        build/us/src/weapon/w_002.c.o(.text);
        _12000_TEXT_END = .;
        _12000_TEXT_SIZE = ABSOLUTE(_12000_TEXT_END - _12000_TEXT_START);
        build/us/asm/us/weapon/data/w_002.sbss.s.o(.sbss);
        _12000_RODATA_START = .;
        build/us/src/weapon/w_002.c.o(.rodata);
        _12000_RODATA_END = .;
        _12000_RODATA_SIZE = ABSOLUTE(_12000_RODATA_END - _12000_RODATA_START);
    }
    _12000_bss_VRAM = ADDR(._12000_bss);
    ._12000_bss (NOLOAD) : SUBALIGN(4)
    {
        _12000_BSS_START = .;
        build/us/src/weapon/w_002.c.o(.bss);
        _12000_BSS_END = .;
        _12000_BSS_SIZE = ABSOLUTE(_12000_BSS_END - _12000_BSS_START);
    }
    __romPos += SIZEOF(._12000);
    __romPos = ALIGN(__romPos, 16);
    _12000_ROM_END = __romPos;
    _12000_VRAM_END = .;

    f_003_ROM_START = __romPos;
    f_003_VRAM = ADDR(.f_003);
    .f_003 0x0 : AT(f_003_ROM_START) SUBALIGN(16)
    {
        f_003_DATA_START = .;
        f_003_png = .;
        build/us/assets/weapon/f_003.png.o(.data);
        f_003_DATA_END = .;
        f_003_DATA_SIZE = ABSOLUTE(f_003_DATA_END - f_003_DATA_START);
    }
    __romPos += SIZEOF(.f_003);
    f_003_ROM_END = __romPos;
    f_003_VRAM_END = .;

    _19000_ROM_START = __romPos;
    _19000_VRAM = ADDR(._19000);
    ._19000 0x8017A000 : AT(_19000_ROM_START) SUBALIGN(4)
    {
        _19000_DATA_START = .;
        w_003_1 = .;
        build/us/assets/weapon/w_003_1.o(.data);
        w_003_2 = .;
        build/us/assets/weapon/w_003_2.o(.data);
        w_003_data__s = .;
        build/us/asm/us/weapon/data/w_003.data.s.o(.data);
        _19000_DATA_END = .;
        _19000_DATA_SIZE = ABSOLUTE(_19000_DATA_END - _19000_DATA_START);
        _19000_TEXT_START = .;
        build/us/src/weapon/w_003.c.o(.text);
        _19000_TEXT_END = .;
        _19000_TEXT_SIZE = ABSOLUTE(_19000_TEXT_END - _19000_TEXT_START);
        build/us/asm/us/weapon/data/w_003.sbss.s.o(.sbss);
        _19000_RODATA_START = .;
        build/us/src/weapon/w_003.c.o(.rodata);
        _19000_RODATA_END = .;
        _19000_RODATA_SIZE = ABSOLUTE(_19000_RODATA_END - _19000_RODATA_START);
    }
    _19000_bss_VRAM = ADDR(._19000_bss);
    ._19000_bss (NOLOAD) : SUBALIGN(4)
    {
        _19000_BSS_START = .;
        build/us/src/weapon/w_003.c.o(.bss);
        _19000_BSS_END = .;
        _19000_BSS_SIZE = ABSOLUTE(_19000_BSS_END - _19000_BSS_START);
    }
    __romPos += SIZEOF(._19000);
    __romPos = ALIGN(__romPos, 16);
    _19000_ROM_END = __romPos;
    _19000_VRAM_END = .;

    f_004_ROM_START = __romPos;
    f_004_VRAM = ADDR(.f_004);
    .f_004 0x0 : AT(f_004_ROM_START) SUBALIGN(16)
    {
        f_004_DATA_START = .;
        f_004_png = .;
        build/us/assets/weapon/f_004.png.o(.data);
        f_004_DATA_END = .;
        f_004_DATA_SIZE = ABSOLUTE(f_004_DATA_END - f_004_DATA_START);
    }
    __romPos += SIZEOF(.f_004);
    f_004_ROM_END = __romPos;
    f_004_VRAM_END = .;

    _20000_ROM_START = __romPos;
    _20000_VRAM = ADDR(._20000);
    ._20000 0x8017A000 : AT(_20000_ROM_START) SUBALIGN(4)
    {
        _20000_DATA_START = .;
        w_004_1 = .;
        build/us/assets/weapon/w_004_1.o(.data);
        w_004_2 = .;
        build/us/assets/weapon/w_004_2.o(.data);
        w_004_data__s = .;
        build/us/asm/us/weapon/data/w_004.data.s.o(.data);
        _20000_DATA_END = .;
        _20000_DATA_SIZE = ABSOLUTE(_20000_DATA_END - _20000_DATA_START);
        _20000_TEXT_START = .;
        build/us/src/weapon/w_004.c.o(.text);
        _20000_TEXT_END = .;
        _20000_TEXT_SIZE = ABSOLUTE(_20000_TEXT_END - _20000_TEXT_START);
        build/us/asm/us/weapon/data/w_004.sbss.s.o(.sbss);
        _20000_RODATA_START = .;
        build/us/src/weapon/w_004.c.o(.rodata);
        _20000_RODATA_END = .;
        _20000_RODATA_SIZE = ABSOLUTE(_20000_RODATA_END - _20000_RODATA_START);
    }
    _20000_bss_VRAM = ADDR(._20000_bss);
    ._20000_bss (NOLOAD) : SUBALIGN(4)
    {
        _20000_BSS_START = .;
        build/us/src/weapon/w_004.c.o(.bss);
        _20000_BSS_END = .;
        _20000_BSS_SIZE = ABSOLUTE(_20000_BSS_END - _20000_BSS_START);
    }
    __romPos += SIZEOF(._20000);
    __romPos = ALIGN(__romPos, 16);
    _20000_ROM_END = __romPos;
    _20000_VRAM_END = .;

    f_005_ROM_START = __romPos;
    f_005_VRAM = ADDR(.f_005);
    .f_005 0x0 : AT(f_005_ROM_START) SUBALIGN(16)
    {
        f_005_DATA_START = .;
        f_005_png = .;
        build/us/assets/weapon/f_005.png.o(.data);
        f_005_DATA_END = .;
        f_005_DATA_SIZE = ABSOLUTE(f_005_DATA_END - f_005_DATA_START);
    }
    __romPos += SIZEOF(.f_005);
    f_005_ROM_END = __romPos;
    f_005_VRAM_END = .;

    _27000_ROM_START = __romPos;
    _27000_VRAM = ADDR(._27000);
    ._27000 0x8017A000 : AT(_27000_ROM_START) SUBALIGN(4)
    {
        _27000_DATA_START = .;
        w_005_1 = .;
        build/us/assets/weapon/w_005_1.o(.data);
        w_005_2 = .;
        build/us/assets/weapon/w_005_2.o(.data);
        w_005_data__s = .;
        build/us/asm/us/weapon/data/w_005.data.s.o(.data);
        _27000_DATA_END = .;
        _27000_DATA_SIZE = ABSOLUTE(_27000_DATA_END - _27000_DATA_START);
        _27000_TEXT_START = .;
        build/us/src/weapon/w_005.c.o(.text);
        _27000_TEXT_END = .;
        _27000_TEXT_SIZE = ABSOLUTE(_27000_TEXT_END - _27000_TEXT_START);
        build/us/asm/us/weapon/data/w_005.sbss.s.o(.sbss);
        _27000_RODATA_START = .;
        build/us/src/weapon/w_005.c.o(.rodata);
        _27000_RODATA_END = .;
        _27000_RODATA_SIZE = ABSOLUTE(_27000_RODATA_END - _27000_RODATA_START);
    }
    _27000_bss_VRAM = ADDR(._27000_bss);
    ._27000_bss (NOLOAD) : SUBALIGN(4)
    {
        _27000_BSS_START = .;
        build/us/src/weapon/w_005.c.o(.bss);
        _27000_BSS_END = .;
        _27000_BSS_SIZE = ABSOLUTE(_27000_BSS_END - _27000_BSS_START);
    }
    __romPos += SIZEOF(._27000);
    __romPos = ALIGN(__romPos, 16);
    _27000_ROM_END = __romPos;
    _27000_VRAM_END = .;

    f_006_ROM_START = __romPos;
    f_006_VRAM = ADDR(.f_006);
    .f_006 0x0 : AT(f_006_ROM_START) SUBALIGN(16)
    {
        f_006_DATA_START = .;
        f_006_png = .;
        build/us/assets/weapon/f_006.png.o(.data);
        f_006_DATA_END = .;
        f_006_DATA_SIZE = ABSOLUTE(f_006_DATA_END - f_006_DATA_START);
    }
    __romPos += SIZEOF(.f_006);
    f_006_ROM_END = __romPos;
    f_006_VRAM_END = .;

    _2E000_ROM_START = __romPos;
    _2E000_VRAM = ADDR(._2E000);
    ._2E000 0x8017A000 : AT(_2E000_ROM_START) SUBALIGN(4)
    {
        _2E000_DATA_START = .;
        w_006_1 = .;
        build/us/assets/weapon/w_006_1.o(.data);
        w_006_2 = .;
        build/us/assets/weapon/w_006_2.o(.data);
        w_006_data__s = .;
        build/us/asm/us/weapon/data/w_006.data.s.o(.data);
        _2E000_DATA_END = .;
        _2E000_DATA_SIZE = ABSOLUTE(_2E000_DATA_END - _2E000_DATA_START);
        _2E000_TEXT_START = .;
        build/us/src/weapon/w_006.c.o(.text);
        _2E000_TEXT_END = .;
        _2E000_TEXT_SIZE = ABSOLUTE(_2E000_TEXT_END - _2E000_TEXT_START);
        build/us/asm/us/weapon/data/w_006.sbss.s.o(.sbss);
        _2E000_RODATA_START = .;
        build/us/src/weapon/w_006.c.o(.rodata);
        _2E000_RODATA_END = .;
        _2E000_RODATA_SIZE = ABSOLUTE(_2E000_RODATA_END - _2E000_RODATA_START);
    }
    _2E000_bss_VRAM = ADDR(._2E000_bss);
    ._2E000_bss (NOLOAD) : SUBALIGN(4)
    {
        _2E000_BSS_START = .;
        build/us/src/weapon/w_006.c.o(.bss);
        _2E000_BSS_END = .;
        _2E000_BSS_SIZE = ABSOLUTE(_2E000_BSS_END - _2E000_BSS_START);
    }
    __romPos += SIZEOF(._2E000);
    __romPos = ALIGN(__romPos, 16);
    _2E000_ROM_END = __romPos;
    _2E000_VRAM_END = .;

    f_007_ROM_START = __romPos;
    f_007_VRAM = ADDR(.f_007);
    .f_007 0x0 : AT(f_007_ROM_START) SUBALIGN(16)
    {
        f_007_DATA_START = .;
        f_007_png = .;
        build/us/assets/weapon/f_007.png.o(.data);
        f_007_DATA_END = .;
        f_007_DATA_SIZE = ABSOLUTE(f_007_DATA_END - f_007_DATA_START);
    }
    __romPos += SIZEOF(.f_007);
    f_007_ROM_END = __romPos;
    f_007_VRAM_END = .;

    _35000_ROM_START = __romPos;
    _35000_VRAM = ADDR(._35000);
    ._35000 0x8017A000 : AT(_35000_ROM_START) SUBALIGN(4)
    {
        _35000_DATA_START = .;
        w_007_1 = .;
        build/us/assets/weapon/w_007_1.o(.data);
        w_007_2 = .;
        build/us/assets/weapon/w_007_2.o(.data);
        w_007_data__s = .;
        build/us/asm/us/weapon/data/w_007.data.s.o(.data);
        _35000_DATA_END = .;
        _35000_DATA_SIZE = ABSOLUTE(_35000_DATA_END - _35000_DATA_START);
        _35000_TEXT_START = .;
        build/us/src/weapon/w_007.c.o(.text);
        _35000_TEXT_END = .;
        _35000_TEXT_SIZE = ABSOLUTE(_35000_TEXT_END - _35000_TEXT_START);
        build/us/asm/us/weapon/data/w_007.sbss.s.o(.sbss);
        _35000_RODATA_START = .;
        build/us/src/weapon/w_007.c.o(.rodata);
        _35000_RODATA_END = .;
        _35000_RODATA_SIZE = ABSOLUTE(_35000_RODATA_END - _35000_RODATA_START);
    }
    _35000_bss_VRAM = ADDR(._35000_bss);
    ._35000_bss (NOLOAD) : SUBALIGN(4)
    {
        _35000_BSS_START = .;
        build/us/src/weapon/w_007.c.o(.bss);
        _35000_BSS_END = .;
        _35000_BSS_SIZE = ABSOLUTE(_35000_BSS_END - _35000_BSS_START);
    }
    __romPos += SIZEOF(._35000);
    __romPos = ALIGN(__romPos, 16);
    _35000_ROM_END = __romPos;
    _35000_VRAM_END = .;

    f_008_ROM_START = __romPos;
    f_008_VRAM = ADDR(.f_008);
    .f_008 0x0 : AT(f_008_ROM_START) SUBALIGN(16)
    {
        f_008_DATA_START = .;
        f_008_png = .;
        build/us/assets/weapon/f_008.png.o(.data);
        f_008_DATA_END = .;
        f_008_DATA_SIZE = ABSOLUTE(f_008_DATA_END - f_008_DATA_START);
    }
    __romPos += SIZEOF(.f_008);
    f_008_ROM_END = __romPos;
    f_008_VRAM_END = .;

    _3C000_ROM_START = __romPos;
    _3C000_VRAM = ADDR(._3C000);
    ._3C000 0x8017A000 : AT(_3C000_ROM_START) SUBALIGN(4)
    {
        _3C000_DATA_START = .;
        w_008_1 = .;
        build/us/assets/weapon/w_008_1.o(.data);
        w_008_2 = .;
        build/us/assets/weapon/w_008_2.o(.data);
        w_008_data__s = .;
        build/us/asm/us/weapon/data/w_008.data.s.o(.data);
        _3C000_DATA_END = .;
        _3C000_DATA_SIZE = ABSOLUTE(_3C000_DATA_END - _3C000_DATA_START);
        _3C000_TEXT_START = .;
        build/us/src/weapon/w_008.c.o(.text);
        _3C000_TEXT_END = .;
        _3C000_TEXT_SIZE = ABSOLUTE(_3C000_TEXT_END - _3C000_TEXT_START);
        build/us/asm/us/weapon/data/w_008.sbss.s.o(.sbss);
        _3C000_RODATA_START = .;
        build/us/src/weapon/w_008.c.o(.rodata);
        _3C000_RODATA_END = .;
        _3C000_RODATA_SIZE = ABSOLUTE(_3C000_RODATA_END - _3C000_RODATA_START);
    }
    _3C000_bss_VRAM = ADDR(._3C000_bss);
    ._3C000_bss (NOLOAD) : SUBALIGN(4)
    {
        _3C000_BSS_START = .;
        build/us/src/weapon/w_008.c.o(.bss);
        _3C000_BSS_END = .;
        _3C000_BSS_SIZE = ABSOLUTE(_3C000_BSS_END - _3C000_BSS_START);
    }
    __romPos += SIZEOF(._3C000);
    __romPos = ALIGN(__romPos, 16);
    _3C000_ROM_END = __romPos;
    _3C000_VRAM_END = .;

    f_009_ROM_START = __romPos;
    f_009_VRAM = ADDR(.f_009);
    .f_009 0x0 : AT(f_009_ROM_START) SUBALIGN(16)
    {
        f_009_DATA_START = .;
        f_009_png = .;
        build/us/assets/weapon/f_009.png.o(.data);
        f_009_DATA_END = .;
        f_009_DATA_SIZE = ABSOLUTE(f_009_DATA_END - f_009_DATA_START);
    }
    __romPos += SIZEOF(.f_009);
    f_009_ROM_END = __romPos;
    f_009_VRAM_END = .;

    _43000_ROM_START = __romPos;
    _43000_VRAM = ADDR(._43000);
    ._43000 0x8017A000 : AT(_43000_ROM_START) SUBALIGN(4)
    {
        _43000_DATA_START = .;
        w_009_1 = .;
        build/us/assets/weapon/w_009_1.o(.data);
        w_009_2 = .;
        build/us/assets/weapon/w_009_2.o(.data);
        w_009_data__s = .;
        build/us/asm/us/weapon/data/w_009.data.s.o(.data);
        _43000_DATA_END = .;
        _43000_DATA_SIZE = ABSOLUTE(_43000_DATA_END - _43000_DATA_START);
        _43000_TEXT_START = .;
        build/us/src/weapon/w_009.c.o(.text);
        _43000_TEXT_END = .;
        _43000_TEXT_SIZE = ABSOLUTE(_43000_TEXT_END - _43000_TEXT_START);
        build/us/asm/us/weapon/data/w_009.sbss.s.o(.sbss);
        _43000_RODATA_START = .;
        build/us/src/weapon/w_009.c.o(.rodata);
        _43000_RODATA_END = .;
        _43000_RODATA_SIZE = ABSOLUTE(_43000_RODATA_END - _43000_RODATA_START);
    }
    _43000_bss_VRAM = ADDR(._43000_bss);
    ._43000_bss (NOLOAD) : SUBALIGN(4)
    {
        _43000_BSS_START = .;
        build/us/src/weapon/w_009.c.o(.bss);
        _43000_BSS_END = .;
        _43000_BSS_SIZE = ABSOLUTE(_43000_BSS_END - _43000_BSS_START);
    }
    __romPos += SIZEOF(._43000);
    __romPos = ALIGN(__romPos, 16);
    _43000_ROM_END = __romPos;
    _43000_VRAM_END = .;

    f_010_ROM_START = __romPos;
    f_010_VRAM = ADDR(.f_010);
    .f_010 0x0 : AT(f_010_ROM_START) SUBALIGN(16)
    {
        f_010_DATA_START = .;
        f_010_png = .;
        build/us/assets/weapon/f_010.png.o(.data);
        f_010_DATA_END = .;
        f_010_DATA_SIZE = ABSOLUTE(f_010_DATA_END - f_010_DATA_START);
    }
    __romPos += SIZEOF(.f_010);
    f_010_ROM_END = __romPos;
    f_010_VRAM_END = .;

    _4A000_ROM_START = __romPos;
    _4A000_VRAM = ADDR(._4A000);
    ._4A000 0x8017A000 : AT(_4A000_ROM_START) SUBALIGN(4)
    {
        _4A000_DATA_START = .;
        w_010_1 = .;
        build/us/assets/weapon/w_010_1.o(.data);
        w_010_2 = .;
        build/us/assets/weapon/w_010_2.o(.data);
        w_010_data__s = .;
        build/us/asm/us/weapon/data/w_010.data.s.o(.data);
        _4A000_DATA_END = .;
        _4A000_DATA_SIZE = ABSOLUTE(_4A000_DATA_END - _4A000_DATA_START);
        _4A000_TEXT_START = .;
        build/us/src/weapon/w_010.c.o(.text);
        _4A000_TEXT_END = .;
        _4A000_TEXT_SIZE = ABSOLUTE(_4A000_TEXT_END - _4A000_TEXT_START);
        build/us/asm/us/weapon/data/w_010.sbss.s.o(.sbss);
        _4A000_RODATA_START = .;
        build/us/src/weapon/w_010.c.o(.rodata);
        _4A000_RODATA_END = .;
        _4A000_RODATA_SIZE = ABSOLUTE(_4A000_RODATA_END - _4A000_RODATA_START);
    }
    _4A000_bss_VRAM = ADDR(._4A000_bss);
    ._4A000_bss (NOLOAD) : SUBALIGN(4)
    {
        _4A000_BSS_START = .;
        build/us/src/weapon/w_010.c.o(.bss);
        _4A000_BSS_END = .;
        _4A000_BSS_SIZE = ABSOLUTE(_4A000_BSS_END - _4A000_BSS_START);
    }
    __romPos += SIZEOF(._4A000);
    __romPos = ALIGN(__romPos, 16);
    _4A000_ROM_END = __romPos;
    _4A000_VRAM_END = .;

    f_011_ROM_START = __romPos;
    f_011_VRAM = ADDR(.f_011);
    .f_011 0x0 : AT(f_011_ROM_START) SUBALIGN(16)
    {
        f_011_DATA_START = .;
        f_011_png = .;
        build/us/assets/weapon/f_011.png.o(.data);
        f_011_DATA_END = .;
        f_011_DATA_SIZE = ABSOLUTE(f_011_DATA_END - f_011_DATA_START);
    }
    __romPos += SIZEOF(.f_011);
    f_011_ROM_END = __romPos;
    f_011_VRAM_END = .;

    _51000_ROM_START = __romPos;
    _51000_VRAM = ADDR(._51000);
    ._51000 0x8017A000 : AT(_51000_ROM_START) SUBALIGN(4)
    {
        _51000_DATA_START = .;
        w_011_1 = .;
        build/us/assets/weapon/w_011_1.o(.data);
        w_011_2 = .;
        build/us/assets/weapon/w_011_2.o(.data);
        w_011_data__s = .;
        build/us/asm/us/weapon/data/w_011.data.s.o(.data);
        _51000_DATA_END = .;
        _51000_DATA_SIZE = ABSOLUTE(_51000_DATA_END - _51000_DATA_START);
        _51000_TEXT_START = .;
        build/us/src/weapon/w_011.c.o(.text);
        _51000_TEXT_END = .;
        _51000_TEXT_SIZE = ABSOLUTE(_51000_TEXT_END - _51000_TEXT_START);
        build/us/asm/us/weapon/data/w_011.sbss.s.o(.sbss);
        _51000_RODATA_START = .;
        build/us/src/weapon/w_011.c.o(.rodata);
        _51000_RODATA_END = .;
        _51000_RODATA_SIZE = ABSOLUTE(_51000_RODATA_END - _51000_RODATA_START);
    }
    _51000_bss_VRAM = ADDR(._51000_bss);
    ._51000_bss (NOLOAD) : SUBALIGN(4)
    {
        _51000_BSS_START = .;
        build/us/src/weapon/w_011.c.o(.bss);
        _51000_BSS_END = .;
        _51000_BSS_SIZE = ABSOLUTE(_51000_BSS_END - _51000_BSS_START);
    }
    __romPos += SIZEOF(._51000);
    __romPos = ALIGN(__romPos, 16);
    _51000_ROM_END = __romPos;
    _51000_VRAM_END = .;

    f_012_ROM_START = __romPos;
    f_012_VRAM = ADDR(.f_012);
    .f_012 0x0 : AT(f_012_ROM_START) SUBALIGN(16)
    {
        f_012_DATA_START = .;
        f_012_png = .;
        build/us/assets/weapon/f_012.png.o(.data);
        f_012_DATA_END = .;
        f_012_DATA_SIZE = ABSOLUTE(f_012_DATA_END - f_012_DATA_START);
    }
    __romPos += SIZEOF(.f_012);
    f_012_ROM_END = __romPos;
    f_012_VRAM_END = .;

    _58000_ROM_START = __romPos;
    _58000_VRAM = ADDR(._58000);
    ._58000 0x8017A000 : AT(_58000_ROM_START) SUBALIGN(4)
    {
        _58000_DATA_START = .;
        w_012_1 = .;
        build/us/assets/weapon/w_012_1.o(.data);
        w_012_2 = .;
        build/us/assets/weapon/w_012_2.o(.data);
        w_012_data__s = .;
        build/us/asm/us/weapon/data/w_012.data.s.o(.data);
        _58000_DATA_END = .;
        _58000_DATA_SIZE = ABSOLUTE(_58000_DATA_END - _58000_DATA_START);
        _58000_TEXT_START = .;
        build/us/src/weapon/w_012.c.o(.text);
        _58000_TEXT_END = .;
        _58000_TEXT_SIZE = ABSOLUTE(_58000_TEXT_END - _58000_TEXT_START);
        build/us/asm/us/weapon/data/w_012.sbss.s.o(.sbss);
        _58000_RODATA_START = .;
        build/us/src/weapon/w_012.c.o(.rodata);
        _58000_RODATA_END = .;
        _58000_RODATA_SIZE = ABSOLUTE(_58000_RODATA_END - _58000_RODATA_START);
    }
    _58000_bss_VRAM = ADDR(._58000_bss);
    ._58000_bss (NOLOAD) : SUBALIGN(4)
    {
        _58000_BSS_START = .;
        build/us/src/weapon/w_012.c.o(.bss);
        _58000_BSS_END = .;
        _58000_BSS_SIZE = ABSOLUTE(_58000_BSS_END - _58000_BSS_START);
    }
    __romPos += SIZEOF(._58000);
    __romPos = ALIGN(__romPos, 16);
    _58000_ROM_END = __romPos;
    _58000_VRAM_END = .;

    f_013_ROM_START = __romPos;
    f_013_VRAM = ADDR(.f_013);
    .f_013 0x0 : AT(f_013_ROM_START) SUBALIGN(16)
    {
        f_013_DATA_START = .;
        f_013_png = .;
        build/us/assets/weapon/f_013.png.o(.data);
        f_013_DATA_END = .;
        f_013_DATA_SIZE = ABSOLUTE(f_013_DATA_END - f_013_DATA_START);
    }
    __romPos += SIZEOF(.f_013);
    f_013_ROM_END = __romPos;
    f_013_VRAM_END = .;

    _5F000_ROM_START = __romPos;
    _5F000_VRAM = ADDR(._5F000);
    ._5F000 0x8017A000 : AT(_5F000_ROM_START) SUBALIGN(4)
    {
        _5F000_DATA_START = .;
        w_013_1 = .;
        build/us/assets/weapon/w_013_1.o(.data);
        w_013_2 = .;
        build/us/assets/weapon/w_013_2.o(.data);
        w_013_data__s = .;
        build/us/asm/us/weapon/data/w_013.data.s.o(.data);
        _5F000_DATA_END = .;
        _5F000_DATA_SIZE = ABSOLUTE(_5F000_DATA_END - _5F000_DATA_START);
        _5F000_TEXT_START = .;
        build/us/src/weapon/w_013.c.o(.text);
        _5F000_TEXT_END = .;
        _5F000_TEXT_SIZE = ABSOLUTE(_5F000_TEXT_END - _5F000_TEXT_START);
        build/us/asm/us/weapon/data/w_013.sbss.s.o(.sbss);
        _5F000_RODATA_START = .;
        build/us/src/weapon/w_013.c.o(.rodata);
        _5F000_RODATA_END = .;
        _5F000_RODATA_SIZE = ABSOLUTE(_5F000_RODATA_END - _5F000_RODATA_START);
    }
    _5F000_bss_VRAM = ADDR(._5F000_bss);
    ._5F000_bss (NOLOAD) : SUBALIGN(4)
    {
        _5F000_BSS_START = .;
        build/us/src/weapon/w_013.c.o(.bss);
        _5F000_BSS_END = .;
        _5F000_BSS_SIZE = ABSOLUTE(_5F000_BSS_END - _5F000_BSS_START);
    }
    __romPos += SIZEOF(._5F000);
    __romPos = ALIGN(__romPos, 16);
    _5F000_ROM_END = __romPos;
    _5F000_VRAM_END = .;

    f_014_ROM_START = __romPos;
    f_014_VRAM = ADDR(.f_014);
    .f_014 0x0 : AT(f_014_ROM_START) SUBALIGN(16)
    {
        f_014_DATA_START = .;
        f_014_png = .;
        build/us/assets/weapon/f_014.png.o(.data);
        f_014_DATA_END = .;
        f_014_DATA_SIZE = ABSOLUTE(f_014_DATA_END - f_014_DATA_START);
    }
    __romPos += SIZEOF(.f_014);
    f_014_ROM_END = __romPos;
    f_014_VRAM_END = .;

    _66000_ROM_START = __romPos;
    _66000_VRAM = ADDR(._66000);
    ._66000 0x8017A000 : AT(_66000_ROM_START) SUBALIGN(4)
    {
        _66000_DATA_START = .;
        w_014_1 = .;
        build/us/assets/weapon/w_014_1.o(.data);
        w_014_2 = .;
        build/us/assets/weapon/w_014_2.o(.data);
        w_014_data__s = .;
        build/us/asm/us/weapon/data/w_014.data.s.o(.data);
        _66000_DATA_END = .;
        _66000_DATA_SIZE = ABSOLUTE(_66000_DATA_END - _66000_DATA_START);
        _66000_TEXT_START = .;
        build/us/src/weapon/w_014.c.o(.text);
        _66000_TEXT_END = .;
        _66000_TEXT_SIZE = ABSOLUTE(_66000_TEXT_END - _66000_TEXT_START);
        build/us/asm/us/weapon/data/w_014.sbss.s.o(.sbss);
        _66000_RODATA_START = .;
        build/us/src/weapon/w_014.c.o(.rodata);
        _66000_RODATA_END = .;
        _66000_RODATA_SIZE = ABSOLUTE(_66000_RODATA_END - _66000_RODATA_START);
    }
    _66000_bss_VRAM = ADDR(._66000_bss);
    ._66000_bss (NOLOAD) : SUBALIGN(4)
    {
        _66000_BSS_START = .;
        build/us/src/weapon/w_014.c.o(.bss);
        _66000_BSS_END = .;
        _66000_BSS_SIZE = ABSOLUTE(_66000_BSS_END - _66000_BSS_START);
    }
    __romPos += SIZEOF(._66000);
    __romPos = ALIGN(__romPos, 16);
    _66000_ROM_END = __romPos;
    _66000_VRAM_END = .;

    f_015_ROM_START = __romPos;
    f_015_VRAM = ADDR(.f_015);
    .f_015 0x0 : AT(f_015_ROM_START) SUBALIGN(16)
    {
        f_015_DATA_START = .;
        f_015_png = .;
        build/us/assets/weapon/f_015.png.o(.data);
        f_015_DATA_END = .;
        f_015_DATA_SIZE = ABSOLUTE(f_015_DATA_END - f_015_DATA_START);
    }
    __romPos += SIZEOF(.f_015);
    f_015_ROM_END = __romPos;
    f_015_VRAM_END = .;

    _6D000_ROM_START = __romPos;
    _6D000_VRAM = ADDR(._6D000);
    ._6D000 0x8017A000 : AT(_6D000_ROM_START) SUBALIGN(4)
    {
        _6D000_DATA_START = .;
        w_015_1 = .;
        build/us/assets/weapon/w_015_1.o(.data);
        w_015_2 = .;
        build/us/assets/weapon/w_015_2.o(.data);
        w_015_data__s = .;
        build/us/asm/us/weapon/data/w_015.data.s.o(.data);
        _6D000_DATA_END = .;
        _6D000_DATA_SIZE = ABSOLUTE(_6D000_DATA_END - _6D000_DATA_START);
        _6D000_TEXT_START = .;
        build/us/src/weapon/w_015.c.o(.text);
        _6D000_TEXT_END = .;
        _6D000_TEXT_SIZE = ABSOLUTE(_6D000_TEXT_END - _6D000_TEXT_START);
        build/us/asm/us/weapon/data/w_015.sbss.s.o(.sbss);
        _6D000_RODATA_START = .;
        build/us/src/weapon/w_015.c.o(.rodata);
        _6D000_RODATA_END = .;
        _6D000_RODATA_SIZE = ABSOLUTE(_6D000_RODATA_END - _6D000_RODATA_START);
    }
    _6D000_bss_VRAM = ADDR(._6D000_bss);
    ._6D000_bss (NOLOAD) : SUBALIGN(4)
    {
        _6D000_BSS_START = .;
        build/us/src/weapon/w_015.c.o(.bss);
        _6D000_BSS_END = .;
        _6D000_BSS_SIZE = ABSOLUTE(_6D000_BSS_END - _6D000_BSS_START);
    }
    __romPos += SIZEOF(._6D000);
    __romPos = ALIGN(__romPos, 16);
    _6D000_ROM_END = __romPos;
    _6D000_VRAM_END = .;

    f_016_ROM_START = __romPos;
    f_016_VRAM = ADDR(.f_016);
    .f_016 0x0 : AT(f_016_ROM_START) SUBALIGN(16)
    {
        f_016_DATA_START = .;
        f_016_png = .;
        build/us/assets/weapon/f_016.png.o(.data);
        f_016_DATA_END = .;
        f_016_DATA_SIZE = ABSOLUTE(f_016_DATA_END - f_016_DATA_START);
    }
    __romPos += SIZEOF(.f_016);
    f_016_ROM_END = __romPos;
    f_016_VRAM_END = .;

    _74000_ROM_START = __romPos;
    _74000_VRAM = ADDR(._74000);
    ._74000 0x8017A000 : AT(_74000_ROM_START) SUBALIGN(4)
    {
        _74000_DATA_START = .;
        w_016_1 = .;
        build/us/assets/weapon/w_016_1.o(.data);
        w_016_2 = .;
        build/us/assets/weapon/w_016_2.o(.data);
        w_016_data__s = .;
        build/us/asm/us/weapon/data/w_016.data.s.o(.data);
        _74000_DATA_END = .;
        _74000_DATA_SIZE = ABSOLUTE(_74000_DATA_END - _74000_DATA_START);
        _74000_TEXT_START = .;
        build/us/src/weapon/w_016.c.o(.text);
        _74000_TEXT_END = .;
        _74000_TEXT_SIZE = ABSOLUTE(_74000_TEXT_END - _74000_TEXT_START);
        build/us/asm/us/weapon/data/w_016.sbss.s.o(.sbss);
        _74000_RODATA_START = .;
        build/us/src/weapon/w_016.c.o(.rodata);
        _74000_RODATA_END = .;
        _74000_RODATA_SIZE = ABSOLUTE(_74000_RODATA_END - _74000_RODATA_START);
    }
    _74000_bss_VRAM = ADDR(._74000_bss);
    ._74000_bss (NOLOAD) : SUBALIGN(4)
    {
        _74000_BSS_START = .;
        build/us/src/weapon/w_016.c.o(.bss);
        _74000_BSS_END = .;
        _74000_BSS_SIZE = ABSOLUTE(_74000_BSS_END - _74000_BSS_START);
    }
    __romPos += SIZEOF(._74000);
    __romPos = ALIGN(__romPos, 16);
    _74000_ROM_END = __romPos;
    _74000_VRAM_END = .;

    f_017_ROM_START = __romPos;
    f_017_VRAM = ADDR(.f_017);
    .f_017 0x0 : AT(f_017_ROM_START) SUBALIGN(16)
    {
        f_017_DATA_START = .;
        f_017_png = .;
        build/us/assets/weapon/f_017.png.o(.data);
        f_017_DATA_END = .;
        f_017_DATA_SIZE = ABSOLUTE(f_017_DATA_END - f_017_DATA_START);
    }
    __romPos += SIZEOF(.f_017);
    f_017_ROM_END = __romPos;
    f_017_VRAM_END = .;

    _7B000_ROM_START = __romPos;
    _7B000_VRAM = ADDR(._7B000);
    ._7B000 0x8017A000 : AT(_7B000_ROM_START) SUBALIGN(4)
    {
        _7B000_DATA_START = .;
        w_017_1 = .;
        build/us/assets/weapon/w_017_1.o(.data);
        w_017_2 = .;
        build/us/assets/weapon/w_017_2.o(.data);
        w_017_data__s = .;
        build/us/asm/us/weapon/data/w_017.data.s.o(.data);
        _7B000_DATA_END = .;
        _7B000_DATA_SIZE = ABSOLUTE(_7B000_DATA_END - _7B000_DATA_START);
        _7B000_TEXT_START = .;
        build/us/src/weapon/w_017.c.o(.text);
        _7B000_TEXT_END = .;
        _7B000_TEXT_SIZE = ABSOLUTE(_7B000_TEXT_END - _7B000_TEXT_START);
        build/us/asm/us/weapon/data/w_017.sbss.s.o(.sbss);
        _7B000_RODATA_START = .;
        build/us/src/weapon/w_017.c.o(.rodata);
        _7B000_RODATA_END = .;
        _7B000_RODATA_SIZE = ABSOLUTE(_7B000_RODATA_END - _7B000_RODATA_START);
    }
    _7B000_bss_VRAM = ADDR(._7B000_bss);
    ._7B000_bss (NOLOAD) : SUBALIGN(4)
    {
        _7B000_BSS_START = .;
        build/us/src/weapon/w_017.c.o(.bss);
        _7B000_BSS_END = .;
        _7B000_BSS_SIZE = ABSOLUTE(_7B000_BSS_END - _7B000_BSS_START);
    }
    __romPos += SIZEOF(._7B000);
    __romPos = ALIGN(__romPos, 16);
    _7B000_ROM_END = __romPos;
    _7B000_VRAM_END = .;

    f_018_ROM_START = __romPos;
    f_018_VRAM = ADDR(.f_018);
    .f_018 0x0 : AT(f_018_ROM_START) SUBALIGN(16)
    {
        f_018_DATA_START = .;
        f_018_png = .;
        build/us/assets/weapon/f_018.png.o(.data);
        f_018_DATA_END = .;
        f_018_DATA_SIZE = ABSOLUTE(f_018_DATA_END - f_018_DATA_START);
    }
    __romPos += SIZEOF(.f_018);
    f_018_ROM_END = __romPos;
    f_018_VRAM_END = .;

    _82000_ROM_START = __romPos;
    _82000_VRAM = ADDR(._82000);
    ._82000 0x8017A000 : AT(_82000_ROM_START) SUBALIGN(4)
    {
        _82000_DATA_START = .;
        w_018_1 = .;
        build/us/assets/weapon/w_018_1.o(.data);
        w_018_2 = .;
        build/us/assets/weapon/w_018_2.o(.data);
        w_018_data__s = .;
        build/us/asm/us/weapon/data/w_018.data.s.o(.data);
        _82000_DATA_END = .;
        _82000_DATA_SIZE = ABSOLUTE(_82000_DATA_END - _82000_DATA_START);
        _82000_TEXT_START = .;
        build/us/src/weapon/w_018.c.o(.text);
        _82000_TEXT_END = .;
        _82000_TEXT_SIZE = ABSOLUTE(_82000_TEXT_END - _82000_TEXT_START);
        build/us/asm/us/weapon/data/w_018.sbss.s.o(.sbss);
        _82000_RODATA_START = .;
        build/us/src/weapon/w_018.c.o(.rodata);
        _82000_RODATA_END = .;
        _82000_RODATA_SIZE = ABSOLUTE(_82000_RODATA_END - _82000_RODATA_START);
    }
    _82000_bss_VRAM = ADDR(._82000_bss);
    ._82000_bss (NOLOAD) : SUBALIGN(4)
    {
        _82000_BSS_START = .;
        build/us/src/weapon/w_018.c.o(.bss);
        _82000_BSS_END = .;
        _82000_BSS_SIZE = ABSOLUTE(_82000_BSS_END - _82000_BSS_START);
    }
    __romPos += SIZEOF(._82000);
    __romPos = ALIGN(__romPos, 16);
    _82000_ROM_END = __romPos;
    _82000_VRAM_END = .;

    f_019_ROM_START = __romPos;
    f_019_VRAM = ADDR(.f_019);
    .f_019 0x0 : AT(f_019_ROM_START) SUBALIGN(16)
    {
        f_019_DATA_START = .;
        f_019_png = .;
        build/us/assets/weapon/f_019.png.o(.data);
        f_019_DATA_END = .;
        f_019_DATA_SIZE = ABSOLUTE(f_019_DATA_END - f_019_DATA_START);
    }
    __romPos += SIZEOF(.f_019);
    f_019_ROM_END = __romPos;
    f_019_VRAM_END = .;

    _89000_ROM_START = __romPos;
    _89000_VRAM = ADDR(._89000);
    ._89000 0x8017A000 : AT(_89000_ROM_START) SUBALIGN(4)
    {
        _89000_DATA_START = .;
        w_019_1 = .;
        build/us/assets/weapon/w_019_1.o(.data);
        w_019_2 = .;
        build/us/assets/weapon/w_019_2.o(.data);
        w_019_data__s = .;
        build/us/asm/us/weapon/data/w_019.data.s.o(.data);
        _89000_DATA_END = .;
        _89000_DATA_SIZE = ABSOLUTE(_89000_DATA_END - _89000_DATA_START);
        _89000_TEXT_START = .;
        build/us/src/weapon/w_019.c.o(.text);
        _89000_TEXT_END = .;
        _89000_TEXT_SIZE = ABSOLUTE(_89000_TEXT_END - _89000_TEXT_START);
        build/us/asm/us/weapon/data/w_019.sbss.s.o(.sbss);
        _89000_RODATA_START = .;
        build/us/src/weapon/w_019.c.o(.rodata);
        _89000_RODATA_END = .;
        _89000_RODATA_SIZE = ABSOLUTE(_89000_RODATA_END - _89000_RODATA_START);
    }
    _89000_bss_VRAM = ADDR(._89000_bss);
    ._89000_bss (NOLOAD) : SUBALIGN(4)
    {
        _89000_BSS_START = .;
        build/us/src/weapon/w_019.c.o(.bss);
        _89000_BSS_END = .;
        _89000_BSS_SIZE = ABSOLUTE(_89000_BSS_END - _89000_BSS_START);
    }
    __romPos += SIZEOF(._89000);
    __romPos = ALIGN(__romPos, 16);
    _89000_ROM_END = __romPos;
    _89000_VRAM_END = .;

    f_020_ROM_START = __romPos;
    f_020_VRAM = ADDR(.f_020);
    .f_020 0x0 : AT(f_020_ROM_START) SUBALIGN(16)
    {
        f_020_DATA_START = .;
        f_020_png = .;
        build/us/assets/weapon/f_020.png.o(.data);
        f_020_DATA_END = .;
        f_020_DATA_SIZE = ABSOLUTE(f_020_DATA_END - f_020_DATA_START);
    }
    __romPos += SIZEOF(.f_020);
    f_020_ROM_END = __romPos;
    f_020_VRAM_END = .;

    _90000_ROM_START = __romPos;
    _90000_VRAM = ADDR(._90000);
    ._90000 0x8017A000 : AT(_90000_ROM_START) SUBALIGN(4)
    {
        _90000_DATA_START = .;
        w_020_1 = .;
        build/us/assets/weapon/w_020_1.o(.data);
        w_020_2 = .;
        build/us/assets/weapon/w_020_2.o(.data);
        w_020_data__s = .;
        build/us/asm/us/weapon/data/w_020.data.s.o(.data);
        _90000_DATA_END = .;
        _90000_DATA_SIZE = ABSOLUTE(_90000_DATA_END - _90000_DATA_START);
        _90000_TEXT_START = .;
        build/us/src/weapon/w_020.c.o(.text);
        _90000_TEXT_END = .;
        _90000_TEXT_SIZE = ABSOLUTE(_90000_TEXT_END - _90000_TEXT_START);
        build/us/asm/us/weapon/data/w_020.sbss.s.o(.sbss);
        _90000_RODATA_START = .;
        build/us/src/weapon/w_020.c.o(.rodata);
        _90000_RODATA_END = .;
        _90000_RODATA_SIZE = ABSOLUTE(_90000_RODATA_END - _90000_RODATA_START);
    }
    _90000_bss_VRAM = ADDR(._90000_bss);
    ._90000_bss (NOLOAD) : SUBALIGN(4)
    {
        _90000_BSS_START = .;
        build/us/src/weapon/w_020.c.o(.bss);
        _90000_BSS_END = .;
        _90000_BSS_SIZE = ABSOLUTE(_90000_BSS_END - _90000_BSS_START);
    }
    __romPos += SIZEOF(._90000);
    __romPos = ALIGN(__romPos, 16);
    _90000_ROM_END = __romPos;
    _90000_VRAM_END = .;

    f_021_ROM_START = __romPos;
    f_021_VRAM = ADDR(.f_021);
    .f_021 0x0 : AT(f_021_ROM_START) SUBALIGN(16)
    {
        f_021_DATA_START = .;
        f_021_png = .;
        build/us/assets/weapon/f_021.png.o(.data);
        f_021_DATA_END = .;
        f_021_DATA_SIZE = ABSOLUTE(f_021_DATA_END - f_021_DATA_START);
    }
    __romPos += SIZEOF(.f_021);
    f_021_ROM_END = __romPos;
    f_021_VRAM_END = .;

    _97000_ROM_START = __romPos;
    _97000_VRAM = ADDR(._97000);
    ._97000 0x8017A000 : AT(_97000_ROM_START) SUBALIGN(4)
    {
        _97000_DATA_START = .;
        w_021_1 = .;
        build/us/assets/weapon/w_021_1.o(.data);
        w_021_2 = .;
        build/us/assets/weapon/w_021_2.o(.data);
        w_021_data__s = .;
        build/us/asm/us/weapon/data/w_021.data.s.o(.data);
        _97000_DATA_END = .;
        _97000_DATA_SIZE = ABSOLUTE(_97000_DATA_END - _97000_DATA_START);
        _97000_TEXT_START = .;
        build/us/src/weapon/w_021.c.o(.text);
        _97000_TEXT_END = .;
        _97000_TEXT_SIZE = ABSOLUTE(_97000_TEXT_END - _97000_TEXT_START);
        build/us/asm/us/weapon/data/w_021.sbss.s.o(.sbss);
        _97000_RODATA_START = .;
        build/us/src/weapon/w_021.c.o(.rodata);
        _97000_RODATA_END = .;
        _97000_RODATA_SIZE = ABSOLUTE(_97000_RODATA_END - _97000_RODATA_START);
    }
    _97000_bss_VRAM = ADDR(._97000_bss);
    ._97000_bss (NOLOAD) : SUBALIGN(4)
    {
        _97000_BSS_START = .;
        build/us/src/weapon/w_021.c.o(.bss);
        _97000_BSS_END = .;
        _97000_BSS_SIZE = ABSOLUTE(_97000_BSS_END - _97000_BSS_START);
    }
    __romPos += SIZEOF(._97000);
    __romPos = ALIGN(__romPos, 16);
    _97000_ROM_END = __romPos;
    _97000_VRAM_END = .;

    f_022_ROM_START = __romPos;
    f_022_VRAM = ADDR(.f_022);
    .f_022 0x0 : AT(f_022_ROM_START) SUBALIGN(16)
    {
        f_022_DATA_START = .;
        f_022_png = .;
        build/us/assets/weapon/f_022.png.o(.data);
        f_022_DATA_END = .;
        f_022_DATA_SIZE = ABSOLUTE(f_022_DATA_END - f_022_DATA_START);
    }
    __romPos += SIZEOF(.f_022);
    f_022_ROM_END = __romPos;
    f_022_VRAM_END = .;

    _9E000_ROM_START = __romPos;
    _9E000_VRAM = ADDR(._9E000);
    ._9E000 0x8017A000 : AT(_9E000_ROM_START) SUBALIGN(4)
    {
        _9E000_DATA_START = .;
        w_022_1 = .;
        build/us/assets/weapon/w_022_1.o(.data);
        w_022_2 = .;
        build/us/assets/weapon/w_022_2.o(.data);
        w_022_data__s = .;
        build/us/asm/us/weapon/data/w_022.data.s.o(.data);
        _9E000_DATA_END = .;
        _9E000_DATA_SIZE = ABSOLUTE(_9E000_DATA_END - _9E000_DATA_START);
        _9E000_TEXT_START = .;
        build/us/src/weapon/w_022.c.o(.text);
        _9E000_TEXT_END = .;
        _9E000_TEXT_SIZE = ABSOLUTE(_9E000_TEXT_END - _9E000_TEXT_START);
        build/us/asm/us/weapon/data/w_022.sbss.s.o(.sbss);
        _9E000_RODATA_START = .;
        build/us/src/weapon/w_022.c.o(.rodata);
        _9E000_RODATA_END = .;
        _9E000_RODATA_SIZE = ABSOLUTE(_9E000_RODATA_END - _9E000_RODATA_START);
    }
    _9E000_bss_VRAM = ADDR(._9E000_bss);
    ._9E000_bss (NOLOAD) : SUBALIGN(4)
    {
        _9E000_BSS_START = .;
        build/us/src/weapon/w_022.c.o(.bss);
        _9E000_BSS_END = .;
        _9E000_BSS_SIZE = ABSOLUTE(_9E000_BSS_END - _9E000_BSS_START);
    }
    __romPos += SIZEOF(._9E000);
    __romPos = ALIGN(__romPos, 16);
    _9E000_ROM_END = __romPos;
    _9E000_VRAM_END = .;

    f_023_ROM_START = __romPos;
    f_023_VRAM = ADDR(.f_023);
    .f_023 0x0 : AT(f_023_ROM_START) SUBALIGN(16)
    {
        f_023_DATA_START = .;
        f_023_png = .;
        build/us/assets/weapon/f_023.png.o(.data);
        f_023_DATA_END = .;
        f_023_DATA_SIZE = ABSOLUTE(f_023_DATA_END - f_023_DATA_START);
    }
    __romPos += SIZEOF(.f_023);
    f_023_ROM_END = __romPos;
    f_023_VRAM_END = .;

    A5000_ROM_START = __romPos;
    A5000_VRAM = ADDR(.A5000);
    .A5000 0x8017A000 : AT(A5000_ROM_START) SUBALIGN(4)
    {
        A5000_DATA_START = .;
        w_023_1 = .;
        build/us/assets/weapon/w_023_1.o(.data);
        w_023_2 = .;
        build/us/assets/weapon/w_023_2.o(.data);
        w_023_data__s = .;
        build/us/asm/us/weapon/data/w_023.data.s.o(.data);
        A5000_DATA_END = .;
        A5000_DATA_SIZE = ABSOLUTE(A5000_DATA_END - A5000_DATA_START);
        A5000_TEXT_START = .;
        build/us/src/weapon/w_023.c.o(.text);
        A5000_TEXT_END = .;
        A5000_TEXT_SIZE = ABSOLUTE(A5000_TEXT_END - A5000_TEXT_START);
        build/us/asm/us/weapon/data/w_023.sbss.s.o(.sbss);
        A5000_RODATA_START = .;
        build/us/src/weapon/w_023.c.o(.rodata);
        A5000_RODATA_END = .;
        A5000_RODATA_SIZE = ABSOLUTE(A5000_RODATA_END - A5000_RODATA_START);
    }
    A5000_bss_VRAM = ADDR(.A5000_bss);
    .A5000_bss (NOLOAD) : SUBALIGN(4)
    {
        A5000_BSS_START = .;
        build/us/src/weapon/w_023.c.o(.bss);
        A5000_BSS_END = .;
        A5000_BSS_SIZE = ABSOLUTE(A5000_BSS_END - A5000_BSS_START);
    }
    __romPos += SIZEOF(.A5000);
    __romPos = ALIGN(__romPos, 16);
    A5000_ROM_END = __romPos;
    A5000_VRAM_END = .;

    f_024_ROM_START = __romPos;
    f_024_VRAM = ADDR(.f_024);
    .f_024 0x0 : AT(f_024_ROM_START) SUBALIGN(16)
    {
        f_024_DATA_START = .;
        f_024_png = .;
        build/us/assets/weapon/f_024.png.o(.data);
        f_024_DATA_END = .;
        f_024_DATA_SIZE = ABSOLUTE(f_024_DATA_END - f_024_DATA_START);
    }
    __romPos += SIZEOF(.f_024);
    f_024_ROM_END = __romPos;
    f_024_VRAM_END = .;

    AC000_ROM_START = __romPos;
    AC000_VRAM = ADDR(.AC000);
    .AC000 0x8017A000 : AT(AC000_ROM_START) SUBALIGN(4)
    {
        AC000_DATA_START = .;
        w_024_1 = .;
        build/us/assets/weapon/w_024_1.o(.data);
        w_024_2 = .;
        build/us/assets/weapon/w_024_2.o(.data);
        w_024_data__s = .;
        build/us/asm/us/weapon/data/w_024.data.s.o(.data);
        AC000_DATA_END = .;
        AC000_DATA_SIZE = ABSOLUTE(AC000_DATA_END - AC000_DATA_START);
        AC000_TEXT_START = .;
        build/us/src/weapon/w_024.c.o(.text);
        AC000_TEXT_END = .;
        AC000_TEXT_SIZE = ABSOLUTE(AC000_TEXT_END - AC000_TEXT_START);
        build/us/asm/us/weapon/data/w_024.sbss.s.o(.sbss);
        AC000_RODATA_START = .;
        build/us/src/weapon/w_024.c.o(.rodata);
        AC000_RODATA_END = .;
        AC000_RODATA_SIZE = ABSOLUTE(AC000_RODATA_END - AC000_RODATA_START);
    }
    AC000_bss_VRAM = ADDR(.AC000_bss);
    .AC000_bss (NOLOAD) : SUBALIGN(4)
    {
        AC000_BSS_START = .;
        build/us/src/weapon/w_024.c.o(.bss);
        AC000_BSS_END = .;
        AC000_BSS_SIZE = ABSOLUTE(AC000_BSS_END - AC000_BSS_START);
    }
    __romPos += SIZEOF(.AC000);
    __romPos = ALIGN(__romPos, 16);
    AC000_ROM_END = __romPos;
    AC000_VRAM_END = .;

    f_025_ROM_START = __romPos;
    f_025_VRAM = ADDR(.f_025);
    .f_025 0x0 : AT(f_025_ROM_START) SUBALIGN(16)
    {
        f_025_DATA_START = .;
        f_025_png = .;
        build/us/assets/weapon/f_025.png.o(.data);
        f_025_DATA_END = .;
        f_025_DATA_SIZE = ABSOLUTE(f_025_DATA_END - f_025_DATA_START);
    }
    __romPos += SIZEOF(.f_025);
    f_025_ROM_END = __romPos;
    f_025_VRAM_END = .;

    B3000_ROM_START = __romPos;
    B3000_VRAM = ADDR(.B3000);
    .B3000 0x8017A000 : AT(B3000_ROM_START) SUBALIGN(4)
    {
        B3000_DATA_START = .;
        w_025_1 = .;
        build/us/assets/weapon/w_025_1.o(.data);
        w_025_2 = .;
        build/us/assets/weapon/w_025_2.o(.data);
        w_025_data__s = .;
        build/us/asm/us/weapon/data/w_025.data.s.o(.data);
        B3000_DATA_END = .;
        B3000_DATA_SIZE = ABSOLUTE(B3000_DATA_END - B3000_DATA_START);
        B3000_TEXT_START = .;
        build/us/src/weapon/w_025.c.o(.text);
        B3000_TEXT_END = .;
        B3000_TEXT_SIZE = ABSOLUTE(B3000_TEXT_END - B3000_TEXT_START);
        build/us/asm/us/weapon/data/w_025.sbss.s.o(.sbss);
        B3000_RODATA_START = .;
        build/us/src/weapon/w_025.c.o(.rodata);
        B3000_RODATA_END = .;
        B3000_RODATA_SIZE = ABSOLUTE(B3000_RODATA_END - B3000_RODATA_START);
    }
    B3000_bss_VRAM = ADDR(.B3000_bss);
    .B3000_bss (NOLOAD) : SUBALIGN(4)
    {
        B3000_BSS_START = .;
        build/us/src/weapon/w_025.c.o(.bss);
        B3000_BSS_END = .;
        B3000_BSS_SIZE = ABSOLUTE(B3000_BSS_END - B3000_BSS_START);
    }
    __romPos += SIZEOF(.B3000);
    __romPos = ALIGN(__romPos, 16);
    B3000_ROM_END = __romPos;
    B3000_VRAM_END = .;

    f_026_ROM_START = __romPos;
    f_026_VRAM = ADDR(.f_026);
    .f_026 0x0 : AT(f_026_ROM_START) SUBALIGN(16)
    {
        f_026_DATA_START = .;
        f_026_png = .;
        build/us/assets/weapon/f_026.png.o(.data);
        f_026_DATA_END = .;
        f_026_DATA_SIZE = ABSOLUTE(f_026_DATA_END - f_026_DATA_START);
    }
    __romPos += SIZEOF(.f_026);
    f_026_ROM_END = __romPos;
    f_026_VRAM_END = .;

    BA000_ROM_START = __romPos;
    BA000_VRAM = ADDR(.BA000);
    .BA000 0x8017A000 : AT(BA000_ROM_START) SUBALIGN(4)
    {
        BA000_DATA_START = .;
        w_026_1 = .;
        build/us/assets/weapon/w_026_1.o(.data);
        w_026_2 = .;
        build/us/assets/weapon/w_026_2.o(.data);
        w_026_data__s = .;
        build/us/asm/us/weapon/data/w_026.data.s.o(.data);
        BA000_DATA_END = .;
        BA000_DATA_SIZE = ABSOLUTE(BA000_DATA_END - BA000_DATA_START);
        BA000_TEXT_START = .;
        build/us/src/weapon/w_026.c.o(.text);
        BA000_TEXT_END = .;
        BA000_TEXT_SIZE = ABSOLUTE(BA000_TEXT_END - BA000_TEXT_START);
        build/us/asm/us/weapon/data/w_026.sbss.s.o(.sbss);
        BA000_RODATA_START = .;
        build/us/src/weapon/w_026.c.o(.rodata);
        BA000_RODATA_END = .;
        BA000_RODATA_SIZE = ABSOLUTE(BA000_RODATA_END - BA000_RODATA_START);
    }
    BA000_bss_VRAM = ADDR(.BA000_bss);
    .BA000_bss (NOLOAD) : SUBALIGN(4)
    {
        BA000_BSS_START = .;
        build/us/src/weapon/w_026.c.o(.bss);
        BA000_BSS_END = .;
        BA000_BSS_SIZE = ABSOLUTE(BA000_BSS_END - BA000_BSS_START);
    }
    __romPos += SIZEOF(.BA000);
    __romPos = ALIGN(__romPos, 16);
    BA000_ROM_END = __romPos;
    BA000_VRAM_END = .;

    f_027_ROM_START = __romPos;
    f_027_VRAM = ADDR(.f_027);
    .f_027 0x0 : AT(f_027_ROM_START) SUBALIGN(16)
    {
        f_027_DATA_START = .;
        f_027_png = .;
        build/us/assets/weapon/f_027.png.o(.data);
        f_027_DATA_END = .;
        f_027_DATA_SIZE = ABSOLUTE(f_027_DATA_END - f_027_DATA_START);
    }
    __romPos += SIZEOF(.f_027);
    f_027_ROM_END = __romPos;
    f_027_VRAM_END = .;

    C1000_ROM_START = __romPos;
    C1000_VRAM = ADDR(.C1000);
    .C1000 0x8017A000 : AT(C1000_ROM_START) SUBALIGN(4)
    {
        C1000_DATA_START = .;
        w_027_1 = .;
        build/us/assets/weapon/w_027_1.o(.data);
        w_027_2 = .;
        build/us/assets/weapon/w_027_2.o(.data);
        w_027_data__s = .;
        build/us/asm/us/weapon/data/w_027.data.s.o(.data);
        C1000_DATA_END = .;
        C1000_DATA_SIZE = ABSOLUTE(C1000_DATA_END - C1000_DATA_START);
        C1000_TEXT_START = .;
        build/us/src/weapon/w_027.c.o(.text);
        C1000_TEXT_END = .;
        C1000_TEXT_SIZE = ABSOLUTE(C1000_TEXT_END - C1000_TEXT_START);
        build/us/asm/us/weapon/data/w_027.sbss.s.o(.sbss);
        C1000_RODATA_START = .;
        build/us/src/weapon/w_027.c.o(.rodata);
        C1000_RODATA_END = .;
        C1000_RODATA_SIZE = ABSOLUTE(C1000_RODATA_END - C1000_RODATA_START);
    }
    C1000_bss_VRAM = ADDR(.C1000_bss);
    .C1000_bss (NOLOAD) : SUBALIGN(4)
    {
        C1000_BSS_START = .;
        build/us/src/weapon/w_027.c.o(.bss);
        C1000_BSS_END = .;
        C1000_BSS_SIZE = ABSOLUTE(C1000_BSS_END - C1000_BSS_START);
    }
    __romPos += SIZEOF(.C1000);
    __romPos = ALIGN(__romPos, 16);
    C1000_ROM_END = __romPos;
    C1000_VRAM_END = .;

    f_028_ROM_START = __romPos;
    f_028_VRAM = ADDR(.f_028);
    .f_028 0x0 : AT(f_028_ROM_START) SUBALIGN(16)
    {
        f_028_DATA_START = .;
        f_028_png = .;
        build/us/assets/weapon/f_028.png.o(.data);
        f_028_DATA_END = .;
        f_028_DATA_SIZE = ABSOLUTE(f_028_DATA_END - f_028_DATA_START);
    }
    __romPos += SIZEOF(.f_028);
    f_028_ROM_END = __romPos;
    f_028_VRAM_END = .;

    C8000_ROM_START = __romPos;
    C8000_VRAM = ADDR(.C8000);
    .C8000 0x8017A000 : AT(C8000_ROM_START) SUBALIGN(4)
    {
        C8000_DATA_START = .;
        w_028_1 = .;
        build/us/assets/weapon/w_028_1.o(.data);
        w_028_2 = .;
        build/us/assets/weapon/w_028_2.o(.data);
        w_028_data__s = .;
        build/us/asm/us/weapon/data/w_028.data.s.o(.data);
        C8000_DATA_END = .;
        C8000_DATA_SIZE = ABSOLUTE(C8000_DATA_END - C8000_DATA_START);
        C8000_TEXT_START = .;
        build/us/src/weapon/w_028.c.o(.text);
        C8000_TEXT_END = .;
        C8000_TEXT_SIZE = ABSOLUTE(C8000_TEXT_END - C8000_TEXT_START);
        build/us/asm/us/weapon/data/w_028.sbss.s.o(.sbss);
        C8000_RODATA_START = .;
        build/us/src/weapon/w_028.c.o(.rodata);
        C8000_RODATA_END = .;
        C8000_RODATA_SIZE = ABSOLUTE(C8000_RODATA_END - C8000_RODATA_START);
    }
    C8000_bss_VRAM = ADDR(.C8000_bss);
    .C8000_bss (NOLOAD) : SUBALIGN(4)
    {
        C8000_BSS_START = .;
        build/us/src/weapon/w_028.c.o(.bss);
        C8000_BSS_END = .;
        C8000_BSS_SIZE = ABSOLUTE(C8000_BSS_END - C8000_BSS_START);
    }
    __romPos += SIZEOF(.C8000);
    __romPos = ALIGN(__romPos, 16);
    C8000_ROM_END = __romPos;
    C8000_VRAM_END = .;

    f_029_ROM_START = __romPos;
    f_029_VRAM = ADDR(.f_029);
    .f_029 0x0 : AT(f_029_ROM_START) SUBALIGN(16)
    {
        f_029_DATA_START = .;
        f_029_png = .;
        build/us/assets/weapon/f_029.png.o(.data);
        f_029_DATA_END = .;
        f_029_DATA_SIZE = ABSOLUTE(f_029_DATA_END - f_029_DATA_START);
    }
    __romPos += SIZEOF(.f_029);
    f_029_ROM_END = __romPos;
    f_029_VRAM_END = .;

    CF000_ROM_START = __romPos;
    CF000_VRAM = ADDR(.CF000);
    .CF000 0x8017A000 : AT(CF000_ROM_START) SUBALIGN(4)
    {
        CF000_DATA_START = .;
        w_029_1 = .;
        build/us/assets/weapon/w_029_1.o(.data);
        w_029_2 = .;
        build/us/assets/weapon/w_029_2.o(.data);
        w_029_data__s = .;
        build/us/asm/us/weapon/data/w_029.data.s.o(.data);
        CF000_DATA_END = .;
        CF000_DATA_SIZE = ABSOLUTE(CF000_DATA_END - CF000_DATA_START);
        CF000_RODATA_START = .;
        build/us/src/weapon/w_029.c.o(.rodata);
        CF000_RODATA_END = .;
        CF000_RODATA_SIZE = ABSOLUTE(CF000_RODATA_END - CF000_RODATA_START);
        CF000_TEXT_START = .;
        build/us/src/weapon/w_029.c.o(.text);
        CF000_TEXT_END = .;
        CF000_TEXT_SIZE = ABSOLUTE(CF000_TEXT_END - CF000_TEXT_START);
        build/us/asm/us/weapon/data/w_029.sbss.s.o(.sbss);
    }
    CF000_bss_VRAM = ADDR(.CF000_bss);
    .CF000_bss (NOLOAD) : SUBALIGN(4)
    {
        CF000_BSS_START = .;
        build/us/src/weapon/w_029.c.o(.bss);
        CF000_BSS_END = .;
        CF000_BSS_SIZE = ABSOLUTE(CF000_BSS_END - CF000_BSS_START);
    }
    __romPos += SIZEOF(.CF000);
    __romPos = ALIGN(__romPos, 16);
    CF000_ROM_END = __romPos;
    CF000_VRAM_END = .;

    f_030_ROM_START = __romPos;
    f_030_VRAM = ADDR(.f_030);
    .f_030 0x0 : AT(f_030_ROM_START) SUBALIGN(16)
    {
        f_030_DATA_START = .;
        f_030_png = .;
        build/us/assets/weapon/f_030.png.o(.data);
        f_030_DATA_END = .;
        f_030_DATA_SIZE = ABSOLUTE(f_030_DATA_END - f_030_DATA_START);
    }
    __romPos += SIZEOF(.f_030);
    f_030_ROM_END = __romPos;
    f_030_VRAM_END = .;

    D6000_ROM_START = __romPos;
    D6000_VRAM = ADDR(.D6000);
    .D6000 0x8017A000 : AT(D6000_ROM_START) SUBALIGN(4)
    {
        D6000_DATA_START = .;
        w_030_1 = .;
        build/us/assets/weapon/w_030_1.o(.data);
        w_030_2 = .;
        build/us/assets/weapon/w_030_2.o(.data);
        w_030_data__s = .;
        build/us/asm/us/weapon/data/w_030.data.s.o(.data);
        D6000_DATA_END = .;
        D6000_DATA_SIZE = ABSOLUTE(D6000_DATA_END - D6000_DATA_START);
        D6000_TEXT_START = .;
        build/us/src/weapon/w_030.c.o(.text);
        D6000_TEXT_END = .;
        D6000_TEXT_SIZE = ABSOLUTE(D6000_TEXT_END - D6000_TEXT_START);
        build/us/asm/us/weapon/data/w_030.sbss.s.o(.sbss);
        D6000_RODATA_START = .;
        build/us/src/weapon/w_030.c.o(.rodata);
        D6000_RODATA_END = .;
        D6000_RODATA_SIZE = ABSOLUTE(D6000_RODATA_END - D6000_RODATA_START);
    }
    D6000_bss_VRAM = ADDR(.D6000_bss);
    .D6000_bss (NOLOAD) : SUBALIGN(4)
    {
        D6000_BSS_START = .;
        build/us/src/weapon/w_030.c.o(.bss);
        D6000_BSS_END = .;
        D6000_BSS_SIZE = ABSOLUTE(D6000_BSS_END - D6000_BSS_START);
    }
    __romPos += SIZEOF(.D6000);
    __romPos = ALIGN(__romPos, 16);
    D6000_ROM_END = __romPos;
    D6000_VRAM_END = .;

    f_031_ROM_START = __romPos;
    f_031_VRAM = ADDR(.f_031);
    .f_031 0x0 : AT(f_031_ROM_START) SUBALIGN(16)
    {
        f_031_DATA_START = .;
        f_031_png = .;
        build/us/assets/weapon/f_031.png.o(.data);
        f_031_DATA_END = .;
        f_031_DATA_SIZE = ABSOLUTE(f_031_DATA_END - f_031_DATA_START);
    }
    __romPos += SIZEOF(.f_031);
    f_031_ROM_END = __romPos;
    f_031_VRAM_END = .;

    DD000_ROM_START = __romPos;
    DD000_VRAM = ADDR(.DD000);
    .DD000 0x8017A000 : AT(DD000_ROM_START) SUBALIGN(4)
    {
        DD000_DATA_START = .;
        w_031_1 = .;
        build/us/assets/weapon/w_031_1.o(.data);
        w_031_2 = .;
        build/us/assets/weapon/w_031_2.o(.data);
        w_031_data__s = .;
        build/us/asm/us/weapon/data/w_031.data.s.o(.data);
        DD000_DATA_END = .;
        DD000_DATA_SIZE = ABSOLUTE(DD000_DATA_END - DD000_DATA_START);
        DD000_TEXT_START = .;
        build/us/src/weapon/w_031.c.o(.text);
        DD000_TEXT_END = .;
        DD000_TEXT_SIZE = ABSOLUTE(DD000_TEXT_END - DD000_TEXT_START);
        build/us/asm/us/weapon/data/w_031.sbss.s.o(.sbss);
        DD000_RODATA_START = .;
        build/us/src/weapon/w_031.c.o(.rodata);
        DD000_RODATA_END = .;
        DD000_RODATA_SIZE = ABSOLUTE(DD000_RODATA_END - DD000_RODATA_START);
    }
    DD000_bss_VRAM = ADDR(.DD000_bss);
    .DD000_bss (NOLOAD) : SUBALIGN(4)
    {
        DD000_BSS_START = .;
        build/us/src/weapon/w_031.c.o(.bss);
        DD000_BSS_END = .;
        DD000_BSS_SIZE = ABSOLUTE(DD000_BSS_END - DD000_BSS_START);
    }
    __romPos += SIZEOF(.DD000);
    __romPos = ALIGN(__romPos, 16);
    DD000_ROM_END = __romPos;
    DD000_VRAM_END = .;

    f_032_ROM_START = __romPos;
    f_032_VRAM = ADDR(.f_032);
    .f_032 0x0 : AT(f_032_ROM_START) SUBALIGN(16)
    {
        f_032_DATA_START = .;
        f_032_png = .;
        build/us/assets/weapon/f_032.png.o(.data);
        f_032_DATA_END = .;
        f_032_DATA_SIZE = ABSOLUTE(f_032_DATA_END - f_032_DATA_START);
    }
    __romPos += SIZEOF(.f_032);
    f_032_ROM_END = __romPos;
    f_032_VRAM_END = .;

    E4000_ROM_START = __romPos;
    E4000_VRAM = ADDR(.E4000);
    .E4000 0x8017A000 : AT(E4000_ROM_START) SUBALIGN(4)
    {
        E4000_DATA_START = .;
        w_032_1 = .;
        build/us/assets/weapon/w_032_1.o(.data);
        w_032_2 = .;
        build/us/assets/weapon/w_032_2.o(.data);
        w_032_data__s = .;
        build/us/asm/us/weapon/data/w_032.data.s.o(.data);
        E4000_DATA_END = .;
        E4000_DATA_SIZE = ABSOLUTE(E4000_DATA_END - E4000_DATA_START);
        E4000_TEXT_START = .;
        build/us/src/weapon/w_032.c.o(.text);
        E4000_TEXT_END = .;
        E4000_TEXT_SIZE = ABSOLUTE(E4000_TEXT_END - E4000_TEXT_START);
        build/us/asm/us/weapon/data/w_032.sbss.s.o(.sbss);
        E4000_RODATA_START = .;
        build/us/src/weapon/w_032.c.o(.rodata);
        E4000_RODATA_END = .;
        E4000_RODATA_SIZE = ABSOLUTE(E4000_RODATA_END - E4000_RODATA_START);
    }
    E4000_bss_VRAM = ADDR(.E4000_bss);
    .E4000_bss (NOLOAD) : SUBALIGN(4)
    {
        E4000_BSS_START = .;
        build/us/src/weapon/w_032.c.o(.bss);
        E4000_BSS_END = .;
        E4000_BSS_SIZE = ABSOLUTE(E4000_BSS_END - E4000_BSS_START);
    }
    __romPos += SIZEOF(.E4000);
    __romPos = ALIGN(__romPos, 16);
    E4000_ROM_END = __romPos;
    E4000_VRAM_END = .;

    f_033_ROM_START = __romPos;
    f_033_VRAM = ADDR(.f_033);
    .f_033 0x0 : AT(f_033_ROM_START) SUBALIGN(16)
    {
        f_033_DATA_START = .;
        f_033_png = .;
        build/us/assets/weapon/f_033.png.o(.data);
        f_033_DATA_END = .;
        f_033_DATA_SIZE = ABSOLUTE(f_033_DATA_END - f_033_DATA_START);
    }
    __romPos += SIZEOF(.f_033);
    f_033_ROM_END = __romPos;
    f_033_VRAM_END = .;

    EB000_ROM_START = __romPos;
    EB000_VRAM = ADDR(.EB000);
    .EB000 0x8017A000 : AT(EB000_ROM_START) SUBALIGN(4)
    {
        EB000_DATA_START = .;
        w_033_1 = .;
        build/us/assets/weapon/w_033_1.o(.data);
        w_033_2 = .;
        build/us/assets/weapon/w_033_2.o(.data);
        w_033_data__s = .;
        build/us/asm/us/weapon/data/w_033.data.s.o(.data);
        EB000_DATA_END = .;
        EB000_DATA_SIZE = ABSOLUTE(EB000_DATA_END - EB000_DATA_START);
        EB000_TEXT_START = .;
        build/us/src/weapon/w_033.c.o(.text);
        EB000_TEXT_END = .;
        EB000_TEXT_SIZE = ABSOLUTE(EB000_TEXT_END - EB000_TEXT_START);
        build/us/asm/us/weapon/data/w_033.sbss.s.o(.sbss);
        EB000_RODATA_START = .;
        build/us/src/weapon/w_033.c.o(.rodata);
        EB000_RODATA_END = .;
        EB000_RODATA_SIZE = ABSOLUTE(EB000_RODATA_END - EB000_RODATA_START);
    }
    EB000_bss_VRAM = ADDR(.EB000_bss);
    .EB000_bss (NOLOAD) : SUBALIGN(4)
    {
        EB000_BSS_START = .;
        build/us/src/weapon/w_033.c.o(.bss);
        EB000_BSS_END = .;
        EB000_BSS_SIZE = ABSOLUTE(EB000_BSS_END - EB000_BSS_START);
    }
    __romPos += SIZEOF(.EB000);
    __romPos = ALIGN(__romPos, 16);
    EB000_ROM_END = __romPos;
    EB000_VRAM_END = .;

    f_034_ROM_START = __romPos;
    f_034_VRAM = ADDR(.f_034);
    .f_034 0x0 : AT(f_034_ROM_START) SUBALIGN(16)
    {
        f_034_DATA_START = .;
        f_034_png = .;
        build/us/assets/weapon/f_034.png.o(.data);
        f_034_DATA_END = .;
        f_034_DATA_SIZE = ABSOLUTE(f_034_DATA_END - f_034_DATA_START);
    }
    __romPos += SIZEOF(.f_034);
    f_034_ROM_END = __romPos;
    f_034_VRAM_END = .;

    F2000_ROM_START = __romPos;
    F2000_VRAM = ADDR(.F2000);
    .F2000 0x8017A000 : AT(F2000_ROM_START) SUBALIGN(4)
    {
        F2000_DATA_START = .;
        w_034_1 = .;
        build/us/assets/weapon/w_034_1.o(.data);
        w_034_2 = .;
        build/us/assets/weapon/w_034_2.o(.data);
        w_034_data__s = .;
        build/us/asm/us/weapon/data/w_034.data.s.o(.data);
        F2000_DATA_END = .;
        F2000_DATA_SIZE = ABSOLUTE(F2000_DATA_END - F2000_DATA_START);
        F2000_TEXT_START = .;
        build/us/src/weapon/w_034.c.o(.text);
        F2000_TEXT_END = .;
        F2000_TEXT_SIZE = ABSOLUTE(F2000_TEXT_END - F2000_TEXT_START);
        build/us/asm/us/weapon/data/w_034.sbss.s.o(.sbss);
        F2000_RODATA_START = .;
        build/us/src/weapon/w_034.c.o(.rodata);
        F2000_RODATA_END = .;
        F2000_RODATA_SIZE = ABSOLUTE(F2000_RODATA_END - F2000_RODATA_START);
    }
    F2000_bss_VRAM = ADDR(.F2000_bss);
    .F2000_bss (NOLOAD) : SUBALIGN(4)
    {
        F2000_BSS_START = .;
        build/us/src/weapon/w_034.c.o(.bss);
        F2000_BSS_END = .;
        F2000_BSS_SIZE = ABSOLUTE(F2000_BSS_END - F2000_BSS_START);
    }
    __romPos += SIZEOF(.F2000);
    __romPos = ALIGN(__romPos, 16);
    F2000_ROM_END = __romPos;
    F2000_VRAM_END = .;

    f_035_ROM_START = __romPos;
    f_035_VRAM = ADDR(.f_035);
    .f_035 0x0 : AT(f_035_ROM_START) SUBALIGN(16)
    {
        f_035_DATA_START = .;
        f_035_png = .;
        build/us/assets/weapon/f_035.png.o(.data);
        f_035_DATA_END = .;
        f_035_DATA_SIZE = ABSOLUTE(f_035_DATA_END - f_035_DATA_START);
    }
    __romPos += SIZEOF(.f_035);
    f_035_ROM_END = __romPos;
    f_035_VRAM_END = .;

    F9000_ROM_START = __romPos;
    F9000_VRAM = ADDR(.F9000);
    .F9000 0x8017A000 : AT(F9000_ROM_START) SUBALIGN(4)
    {
        F9000_DATA_START = .;
        w_035_1 = .;
        build/us/assets/weapon/w_035_1.o(.data);
        w_035_2 = .;
        build/us/assets/weapon/w_035_2.o(.data);
        w_035_data__s = .;
        build/us/asm/us/weapon/data/w_035.data.s.o(.data);
        F9000_DATA_END = .;
        F9000_DATA_SIZE = ABSOLUTE(F9000_DATA_END - F9000_DATA_START);
        F9000_TEXT_START = .;
        build/us/src/weapon/w_035.c.o(.text);
        F9000_TEXT_END = .;
        F9000_TEXT_SIZE = ABSOLUTE(F9000_TEXT_END - F9000_TEXT_START);
        build/us/asm/us/weapon/data/w_035.sbss.s.o(.sbss);
        F9000_RODATA_START = .;
        build/us/src/weapon/w_035.c.o(.rodata);
        F9000_RODATA_END = .;
        F9000_RODATA_SIZE = ABSOLUTE(F9000_RODATA_END - F9000_RODATA_START);
    }
    F9000_bss_VRAM = ADDR(.F9000_bss);
    .F9000_bss (NOLOAD) : SUBALIGN(4)
    {
        F9000_BSS_START = .;
        build/us/src/weapon/w_035.c.o(.bss);
        F9000_BSS_END = .;
        F9000_BSS_SIZE = ABSOLUTE(F9000_BSS_END - F9000_BSS_START);
    }
    __romPos += SIZEOF(.F9000);
    __romPos = ALIGN(__romPos, 16);
    F9000_ROM_END = __romPos;
    F9000_VRAM_END = .;

    f_036_ROM_START = __romPos;
    f_036_VRAM = ADDR(.f_036);
    .f_036 0x0 : AT(f_036_ROM_START) SUBALIGN(16)
    {
        f_036_DATA_START = .;
        f_036_png = .;
        build/us/assets/weapon/f_036.png.o(.data);
        f_036_DATA_END = .;
        f_036_DATA_SIZE = ABSOLUTE(f_036_DATA_END - f_036_DATA_START);
    }
    __romPos += SIZEOF(.f_036);
    f_036_ROM_END = __romPos;
    f_036_VRAM_END = .;

    _100000_ROM_START = __romPos;
    _100000_VRAM = ADDR(._100000);
    ._100000 0x8017A000 : AT(_100000_ROM_START) SUBALIGN(4)
    {
        _100000_DATA_START = .;
        w_036_1 = .;
        build/us/assets/weapon/w_036_1.o(.data);
        w_036_2 = .;
        build/us/assets/weapon/w_036_2.o(.data);
        w_036_data__s = .;
        build/us/asm/us/weapon/data/w_036.data.s.o(.data);
        _100000_DATA_END = .;
        _100000_DATA_SIZE = ABSOLUTE(_100000_DATA_END - _100000_DATA_START);
        _100000_TEXT_START = .;
        build/us/src/weapon/w_036.c.o(.text);
        _100000_TEXT_END = .;
        _100000_TEXT_SIZE = ABSOLUTE(_100000_TEXT_END - _100000_TEXT_START);
        build/us/asm/us/weapon/data/w_036.sbss.s.o(.sbss);
        _100000_RODATA_START = .;
        build/us/src/weapon/w_036.c.o(.rodata);
        _100000_RODATA_END = .;
        _100000_RODATA_SIZE = ABSOLUTE(_100000_RODATA_END - _100000_RODATA_START);
    }
    _100000_bss_VRAM = ADDR(._100000_bss);
    ._100000_bss (NOLOAD) : SUBALIGN(4)
    {
        _100000_BSS_START = .;
        build/us/src/weapon/w_036.c.o(.bss);
        _100000_BSS_END = .;
        _100000_BSS_SIZE = ABSOLUTE(_100000_BSS_END - _100000_BSS_START);
    }
    __romPos += SIZEOF(._100000);
    __romPos = ALIGN(__romPos, 16);
    _100000_ROM_END = __romPos;
    _100000_VRAM_END = .;

    f_037_ROM_START = __romPos;
    f_037_VRAM = ADDR(.f_037);
    .f_037 0x0 : AT(f_037_ROM_START) SUBALIGN(16)
    {
        f_037_DATA_START = .;
        f_037_png = .;
        build/us/assets/weapon/f_037.png.o(.data);
        f_037_DATA_END = .;
        f_037_DATA_SIZE = ABSOLUTE(f_037_DATA_END - f_037_DATA_START);
    }
    __romPos += SIZEOF(.f_037);
    f_037_ROM_END = __romPos;
    f_037_VRAM_END = .;

    _107000_ROM_START = __romPos;
    _107000_VRAM = ADDR(._107000);
    ._107000 0x8017A000 : AT(_107000_ROM_START) SUBALIGN(4)
    {
        _107000_DATA_START = .;
        w_037_1 = .;
        build/us/assets/weapon/w_037_1.o(.data);
        w_037_2 = .;
        build/us/assets/weapon/w_037_2.o(.data);
        w_037_data__s = .;
        build/us/asm/us/weapon/data/w_037.data.s.o(.data);
        _107000_DATA_END = .;
        _107000_DATA_SIZE = ABSOLUTE(_107000_DATA_END - _107000_DATA_START);
        _107000_TEXT_START = .;
        build/us/src/weapon/w_037.c.o(.text);
        _107000_TEXT_END = .;
        _107000_TEXT_SIZE = ABSOLUTE(_107000_TEXT_END - _107000_TEXT_START);
        build/us/asm/us/weapon/data/w_037.sbss.s.o(.sbss);
        _107000_RODATA_START = .;
        build/us/src/weapon/w_037.c.o(.rodata);
        _107000_RODATA_END = .;
        _107000_RODATA_SIZE = ABSOLUTE(_107000_RODATA_END - _107000_RODATA_START);
    }
    _107000_bss_VRAM = ADDR(._107000_bss);
    ._107000_bss (NOLOAD) : SUBALIGN(4)
    {
        _107000_BSS_START = .;
        build/us/src/weapon/w_037.c.o(.bss);
        _107000_BSS_END = .;
        _107000_BSS_SIZE = ABSOLUTE(_107000_BSS_END - _107000_BSS_START);
    }
    __romPos += SIZEOF(._107000);
    __romPos = ALIGN(__romPos, 16);
    _107000_ROM_END = __romPos;
    _107000_VRAM_END = .;

    f_038_ROM_START = __romPos;
    f_038_VRAM = ADDR(.f_038);
    .f_038 0x0 : AT(f_038_ROM_START) SUBALIGN(16)
    {
        f_038_DATA_START = .;
        f_038_png = .;
        build/us/assets/weapon/f_038.png.o(.data);
        f_038_DATA_END = .;
        f_038_DATA_SIZE = ABSOLUTE(f_038_DATA_END - f_038_DATA_START);
    }
    __romPos += SIZEOF(.f_038);
    f_038_ROM_END = __romPos;
    f_038_VRAM_END = .;

    _10E000_ROM_START = __romPos;
    _10E000_VRAM = ADDR(._10E000);
    ._10E000 0x8017A000 : AT(_10E000_ROM_START) SUBALIGN(4)
    {
        _10E000_DATA_START = .;
        w_038_1 = .;
        build/us/assets/weapon/w_038_1.o(.data);
        w_038_2 = .;
        build/us/assets/weapon/w_038_2.o(.data);
        w_038_data__s = .;
        build/us/asm/us/weapon/data/w_038.data.s.o(.data);
        _10E000_DATA_END = .;
        _10E000_DATA_SIZE = ABSOLUTE(_10E000_DATA_END - _10E000_DATA_START);
        _10E000_TEXT_START = .;
        build/us/src/weapon/w_038.c.o(.text);
        _10E000_TEXT_END = .;
        _10E000_TEXT_SIZE = ABSOLUTE(_10E000_TEXT_END - _10E000_TEXT_START);
        build/us/asm/us/weapon/data/w_038.sbss.s.o(.sbss);
        _10E000_RODATA_START = .;
        build/us/src/weapon/w_038.c.o(.rodata);
        _10E000_RODATA_END = .;
        _10E000_RODATA_SIZE = ABSOLUTE(_10E000_RODATA_END - _10E000_RODATA_START);
    }
    _10E000_bss_VRAM = ADDR(._10E000_bss);
    ._10E000_bss (NOLOAD) : SUBALIGN(4)
    {
        _10E000_BSS_START = .;
        build/us/src/weapon/w_038.c.o(.bss);
        _10E000_BSS_END = .;
        _10E000_BSS_SIZE = ABSOLUTE(_10E000_BSS_END - _10E000_BSS_START);
    }
    __romPos += SIZEOF(._10E000);
    __romPos = ALIGN(__romPos, 16);
    _10E000_ROM_END = __romPos;
    _10E000_VRAM_END = .;

    f_039_ROM_START = __romPos;
    f_039_VRAM = ADDR(.f_039);
    .f_039 0x0 : AT(f_039_ROM_START) SUBALIGN(16)
    {
        f_039_DATA_START = .;
        f_039_png = .;
        build/us/assets/weapon/f_039.png.o(.data);
        f_039_DATA_END = .;
        f_039_DATA_SIZE = ABSOLUTE(f_039_DATA_END - f_039_DATA_START);
    }
    __romPos += SIZEOF(.f_039);
    f_039_ROM_END = __romPos;
    f_039_VRAM_END = .;

    _115000_ROM_START = __romPos;
    _115000_VRAM = ADDR(._115000);
    ._115000 0x8017A000 : AT(_115000_ROM_START) SUBALIGN(4)
    {
        _115000_DATA_START = .;
        w_039_1 = .;
        build/us/assets/weapon/w_039_1.o(.data);
        w_039_2 = .;
        build/us/assets/weapon/w_039_2.o(.data);
        w_039_data__s = .;
        build/us/asm/us/weapon/data/w_039.data.s.o(.data);
        _115000_DATA_END = .;
        _115000_DATA_SIZE = ABSOLUTE(_115000_DATA_END - _115000_DATA_START);
        _115000_TEXT_START = .;
        build/us/src/weapon/w_039.c.o(.text);
        _115000_TEXT_END = .;
        _115000_TEXT_SIZE = ABSOLUTE(_115000_TEXT_END - _115000_TEXT_START);
        build/us/asm/us/weapon/data/w_039.sbss.s.o(.sbss);
        _115000_RODATA_START = .;
        build/us/src/weapon/w_039.c.o(.rodata);
        _115000_RODATA_END = .;
        _115000_RODATA_SIZE = ABSOLUTE(_115000_RODATA_END - _115000_RODATA_START);
    }
    _115000_bss_VRAM = ADDR(._115000_bss);
    ._115000_bss (NOLOAD) : SUBALIGN(4)
    {
        _115000_BSS_START = .;
        build/us/src/weapon/w_039.c.o(.bss);
        _115000_BSS_END = .;
        _115000_BSS_SIZE = ABSOLUTE(_115000_BSS_END - _115000_BSS_START);
    }
    __romPos += SIZEOF(._115000);
    __romPos = ALIGN(__romPos, 16);
    _115000_ROM_END = __romPos;
    _115000_VRAM_END = .;

    f_040_ROM_START = __romPos;
    f_040_VRAM = ADDR(.f_040);
    .f_040 0x0 : AT(f_040_ROM_START) SUBALIGN(16)
    {
        f_040_DATA_START = .;
        f_040_png = .;
        build/us/assets/weapon/f_040.png.o(.data);
        f_040_DATA_END = .;
        f_040_DATA_SIZE = ABSOLUTE(f_040_DATA_END - f_040_DATA_START);
    }
    __romPos += SIZEOF(.f_040);
    f_040_ROM_END = __romPos;
    f_040_VRAM_END = .;

    _11C000_ROM_START = __romPos;
    _11C000_VRAM = ADDR(._11C000);
    ._11C000 0x8017A000 : AT(_11C000_ROM_START) SUBALIGN(4)
    {
        _11C000_DATA_START = .;
        w_040_1 = .;
        build/us/assets/weapon/w_040_1.o(.data);
        w_040_2 = .;
        build/us/assets/weapon/w_040_2.o(.data);
        w_040_data__s = .;
        build/us/asm/us/weapon/data/w_040.data.s.o(.data);
        _11C000_DATA_END = .;
        _11C000_DATA_SIZE = ABSOLUTE(_11C000_DATA_END - _11C000_DATA_START);
        _11C000_TEXT_START = .;
        build/us/src/weapon/w_040.c.o(.text);
        _11C000_TEXT_END = .;
        _11C000_TEXT_SIZE = ABSOLUTE(_11C000_TEXT_END - _11C000_TEXT_START);
        build/us/asm/us/weapon/data/w_040.sbss.s.o(.sbss);
        _11C000_RODATA_START = .;
        build/us/src/weapon/w_040.c.o(.rodata);
        _11C000_RODATA_END = .;
        _11C000_RODATA_SIZE = ABSOLUTE(_11C000_RODATA_END - _11C000_RODATA_START);
    }
    _11C000_bss_VRAM = ADDR(._11C000_bss);
    ._11C000_bss (NOLOAD) : SUBALIGN(4)
    {
        _11C000_BSS_START = .;
        build/us/src/weapon/w_040.c.o(.bss);
        _11C000_BSS_END = .;
        _11C000_BSS_SIZE = ABSOLUTE(_11C000_BSS_END - _11C000_BSS_START);
    }
    __romPos += SIZEOF(._11C000);
    __romPos = ALIGN(__romPos, 16);
    _11C000_ROM_END = __romPos;
    _11C000_VRAM_END = .;

    f_041_ROM_START = __romPos;
    f_041_VRAM = ADDR(.f_041);
    .f_041 0x0 : AT(f_041_ROM_START) SUBALIGN(16)
    {
        f_041_DATA_START = .;
        f_041_png = .;
        build/us/assets/weapon/f_041.png.o(.data);
        f_041_DATA_END = .;
        f_041_DATA_SIZE = ABSOLUTE(f_041_DATA_END - f_041_DATA_START);
    }
    __romPos += SIZEOF(.f_041);
    f_041_ROM_END = __romPos;
    f_041_VRAM_END = .;

    _123000_ROM_START = __romPos;
    _123000_VRAM = ADDR(._123000);
    ._123000 0x8017A000 : AT(_123000_ROM_START) SUBALIGN(4)
    {
        _123000_DATA_START = .;
        w_041_1 = .;
        build/us/assets/weapon/w_041_1.o(.data);
        w_041_2 = .;
        build/us/assets/weapon/w_041_2.o(.data);
        w_041_data__s = .;
        build/us/asm/us/weapon/data/w_041.data.s.o(.data);
        _123000_DATA_END = .;
        _123000_DATA_SIZE = ABSOLUTE(_123000_DATA_END - _123000_DATA_START);
        _123000_TEXT_START = .;
        build/us/src/weapon/w_041.c.o(.text);
        _123000_TEXT_END = .;
        _123000_TEXT_SIZE = ABSOLUTE(_123000_TEXT_END - _123000_TEXT_START);
        build/us/asm/us/weapon/data/w_041.sbss.s.o(.sbss);
        _123000_RODATA_START = .;
        build/us/src/weapon/w_041.c.o(.rodata);
        _123000_RODATA_END = .;
        _123000_RODATA_SIZE = ABSOLUTE(_123000_RODATA_END - _123000_RODATA_START);
    }
    _123000_bss_VRAM = ADDR(._123000_bss);
    ._123000_bss (NOLOAD) : SUBALIGN(4)
    {
        _123000_BSS_START = .;
        build/us/src/weapon/w_041.c.o(.bss);
        _123000_BSS_END = .;
        _123000_BSS_SIZE = ABSOLUTE(_123000_BSS_END - _123000_BSS_START);
    }
    __romPos += SIZEOF(._123000);
    __romPos = ALIGN(__romPos, 16);
    _123000_ROM_END = __romPos;
    _123000_VRAM_END = .;

    f_042_ROM_START = __romPos;
    f_042_VRAM = ADDR(.f_042);
    .f_042 0x0 : AT(f_042_ROM_START) SUBALIGN(16)
    {
        f_042_DATA_START = .;
        f_042_png = .;
        build/us/assets/weapon/f_042.png.o(.data);
        f_042_DATA_END = .;
        f_042_DATA_SIZE = ABSOLUTE(f_042_DATA_END - f_042_DATA_START);
    }
    __romPos += SIZEOF(.f_042);
    f_042_ROM_END = __romPos;
    f_042_VRAM_END = .;

    _12A000_ROM_START = __romPos;
    _12A000_VRAM = ADDR(._12A000);
    ._12A000 0x8017A000 : AT(_12A000_ROM_START) SUBALIGN(4)
    {
        _12A000_DATA_START = .;
        w_042_1 = .;
        build/us/assets/weapon/w_042_1.o(.data);
        w_042_2 = .;
        build/us/assets/weapon/w_042_2.o(.data);
        w_042_data__s = .;
        build/us/asm/us/weapon/data/w_042.data.s.o(.data);
        _12A000_DATA_END = .;
        _12A000_DATA_SIZE = ABSOLUTE(_12A000_DATA_END - _12A000_DATA_START);
        _12A000_TEXT_START = .;
        build/us/src/weapon/w_042.c.o(.text);
        _12A000_TEXT_END = .;
        _12A000_TEXT_SIZE = ABSOLUTE(_12A000_TEXT_END - _12A000_TEXT_START);
        build/us/asm/us/weapon/data/w_042.sbss.s.o(.sbss);
        _12A000_RODATA_START = .;
        build/us/src/weapon/w_042.c.o(.rodata);
        _12A000_RODATA_END = .;
        _12A000_RODATA_SIZE = ABSOLUTE(_12A000_RODATA_END - _12A000_RODATA_START);
    }
    _12A000_bss_VRAM = ADDR(._12A000_bss);
    ._12A000_bss (NOLOAD) : SUBALIGN(4)
    {
        _12A000_BSS_START = .;
        build/us/src/weapon/w_042.c.o(.bss);
        _12A000_BSS_END = .;
        _12A000_BSS_SIZE = ABSOLUTE(_12A000_BSS_END - _12A000_BSS_START);
    }
    __romPos += SIZEOF(._12A000);
    __romPos = ALIGN(__romPos, 16);
    _12A000_ROM_END = __romPos;
    _12A000_VRAM_END = .;

    f_043_ROM_START = __romPos;
    f_043_VRAM = ADDR(.f_043);
    .f_043 0x0 : AT(f_043_ROM_START) SUBALIGN(16)
    {
        f_043_DATA_START = .;
        f_043_png = .;
        build/us/assets/weapon/f_043.png.o(.data);
        f_043_DATA_END = .;
        f_043_DATA_SIZE = ABSOLUTE(f_043_DATA_END - f_043_DATA_START);
    }
    __romPos += SIZEOF(.f_043);
    f_043_ROM_END = __romPos;
    f_043_VRAM_END = .;

    _131000_ROM_START = __romPos;
    _131000_VRAM = ADDR(._131000);
    ._131000 0x8017A000 : AT(_131000_ROM_START) SUBALIGN(4)
    {
        _131000_DATA_START = .;
        w_043_1 = .;
        build/us/assets/weapon/w_043_1.o(.data);
        w_043_2 = .;
        build/us/assets/weapon/w_043_2.o(.data);
        w_043_data__s = .;
        build/us/asm/us/weapon/data/w_043.data.s.o(.data);
        _131000_DATA_END = .;
        _131000_DATA_SIZE = ABSOLUTE(_131000_DATA_END - _131000_DATA_START);
        _131000_TEXT_START = .;
        build/us/src/weapon/w_043.c.o(.text);
        _131000_TEXT_END = .;
        _131000_TEXT_SIZE = ABSOLUTE(_131000_TEXT_END - _131000_TEXT_START);
        build/us/asm/us/weapon/data/w_043.sbss.s.o(.sbss);
        _131000_RODATA_START = .;
        build/us/src/weapon/w_043.c.o(.rodata);
        _131000_RODATA_END = .;
        _131000_RODATA_SIZE = ABSOLUTE(_131000_RODATA_END - _131000_RODATA_START);
    }
    _131000_bss_VRAM = ADDR(._131000_bss);
    ._131000_bss (NOLOAD) : SUBALIGN(4)
    {
        _131000_BSS_START = .;
        build/us/src/weapon/w_043.c.o(.bss);
        _131000_BSS_END = .;
        _131000_BSS_SIZE = ABSOLUTE(_131000_BSS_END - _131000_BSS_START);
    }
    __romPos += SIZEOF(._131000);
    __romPos = ALIGN(__romPos, 16);
    _131000_ROM_END = __romPos;
    _131000_VRAM_END = .;

    f_044_ROM_START = __romPos;
    f_044_VRAM = ADDR(.f_044);
    .f_044 0x0 : AT(f_044_ROM_START) SUBALIGN(16)
    {
        f_044_DATA_START = .;
        f_044_png = .;
        build/us/assets/weapon/f_044.png.o(.data);
        f_044_DATA_END = .;
        f_044_DATA_SIZE = ABSOLUTE(f_044_DATA_END - f_044_DATA_START);
    }
    __romPos += SIZEOF(.f_044);
    f_044_ROM_END = __romPos;
    f_044_VRAM_END = .;

    _138000_ROM_START = __romPos;
    _138000_VRAM = ADDR(._138000);
    ._138000 0x8017A000 : AT(_138000_ROM_START) SUBALIGN(4)
    {
        _138000_DATA_START = .;
        w_044_1 = .;
        build/us/assets/weapon/w_044_1.o(.data);
        w_044_2 = .;
        build/us/assets/weapon/w_044_2.o(.data);
        w_044_data__s = .;
        build/us/asm/us/weapon/data/w_044.data.s.o(.data);
        _138000_DATA_END = .;
        _138000_DATA_SIZE = ABSOLUTE(_138000_DATA_END - _138000_DATA_START);
        _138000_TEXT_START = .;
        build/us/src/weapon/w_044.c.o(.text);
        _138000_TEXT_END = .;
        _138000_TEXT_SIZE = ABSOLUTE(_138000_TEXT_END - _138000_TEXT_START);
        build/us/asm/us/weapon/data/w_044.sbss.s.o(.sbss);
        _138000_RODATA_START = .;
        build/us/src/weapon/w_044.c.o(.rodata);
        _138000_RODATA_END = .;
        _138000_RODATA_SIZE = ABSOLUTE(_138000_RODATA_END - _138000_RODATA_START);
    }
    _138000_bss_VRAM = ADDR(._138000_bss);
    ._138000_bss (NOLOAD) : SUBALIGN(4)
    {
        _138000_BSS_START = .;
        build/us/src/weapon/w_044.c.o(.bss);
        _138000_BSS_END = .;
        _138000_BSS_SIZE = ABSOLUTE(_138000_BSS_END - _138000_BSS_START);
    }
    __romPos += SIZEOF(._138000);
    __romPos = ALIGN(__romPos, 16);
    _138000_ROM_END = __romPos;
    _138000_VRAM_END = .;

    f_045_ROM_START = __romPos;
    f_045_VRAM = ADDR(.f_045);
    .f_045 0x0 : AT(f_045_ROM_START) SUBALIGN(16)
    {
        f_045_DATA_START = .;
        f_045_png = .;
        build/us/assets/weapon/f_045.png.o(.data);
        f_045_DATA_END = .;
        f_045_DATA_SIZE = ABSOLUTE(f_045_DATA_END - f_045_DATA_START);
    }
    __romPos += SIZEOF(.f_045);
    f_045_ROM_END = __romPos;
    f_045_VRAM_END = .;

    _13F000_ROM_START = __romPos;
    _13F000_VRAM = ADDR(._13F000);
    ._13F000 0x8017A000 : AT(_13F000_ROM_START) SUBALIGN(4)
    {
        _13F000_DATA_START = .;
        w_045_1 = .;
        build/us/assets/weapon/w_045_1.o(.data);
        w_045_2 = .;
        build/us/assets/weapon/w_045_2.o(.data);
        w_045_data__s = .;
        build/us/asm/us/weapon/data/w_045.data.s.o(.data);
        _13F000_DATA_END = .;
        _13F000_DATA_SIZE = ABSOLUTE(_13F000_DATA_END - _13F000_DATA_START);
        _13F000_TEXT_START = .;
        build/us/src/weapon/w_045.c.o(.text);
        _13F000_TEXT_END = .;
        _13F000_TEXT_SIZE = ABSOLUTE(_13F000_TEXT_END - _13F000_TEXT_START);
        build/us/asm/us/weapon/data/w_045.sbss.s.o(.sbss);
        _13F000_RODATA_START = .;
        build/us/src/weapon/w_045.c.o(.rodata);
        _13F000_RODATA_END = .;
        _13F000_RODATA_SIZE = ABSOLUTE(_13F000_RODATA_END - _13F000_RODATA_START);
    }
    _13F000_bss_VRAM = ADDR(._13F000_bss);
    ._13F000_bss (NOLOAD) : SUBALIGN(4)
    {
        _13F000_BSS_START = .;
        build/us/src/weapon/w_045.c.o(.bss);
        _13F000_BSS_END = .;
        _13F000_BSS_SIZE = ABSOLUTE(_13F000_BSS_END - _13F000_BSS_START);
    }
    __romPos += SIZEOF(._13F000);
    __romPos = ALIGN(__romPos, 16);
    _13F000_ROM_END = __romPos;
    _13F000_VRAM_END = .;

    f_046_ROM_START = __romPos;
    f_046_VRAM = ADDR(.f_046);
    .f_046 0x0 : AT(f_046_ROM_START) SUBALIGN(16)
    {
        f_046_DATA_START = .;
        f_046_png = .;
        build/us/assets/weapon/f_046.png.o(.data);
        f_046_DATA_END = .;
        f_046_DATA_SIZE = ABSOLUTE(f_046_DATA_END - f_046_DATA_START);
    }
    __romPos += SIZEOF(.f_046);
    f_046_ROM_END = __romPos;
    f_046_VRAM_END = .;

    _146000_ROM_START = __romPos;
    _146000_VRAM = ADDR(._146000);
    ._146000 0x8017A000 : AT(_146000_ROM_START) SUBALIGN(4)
    {
        _146000_DATA_START = .;
        w_046_1 = .;
        build/us/assets/weapon/w_046_1.o(.data);
        w_046_2 = .;
        build/us/assets/weapon/w_046_2.o(.data);
        w_046_data__s = .;
        build/us/asm/us/weapon/data/w_046.data.s.o(.data);
        _146000_DATA_END = .;
        _146000_DATA_SIZE = ABSOLUTE(_146000_DATA_END - _146000_DATA_START);
        _146000_TEXT_START = .;
        build/us/src/weapon/w_046.c.o(.text);
        _146000_TEXT_END = .;
        _146000_TEXT_SIZE = ABSOLUTE(_146000_TEXT_END - _146000_TEXT_START);
        build/us/asm/us/weapon/data/w_046.sbss.s.o(.sbss);
        _146000_RODATA_START = .;
        build/us/src/weapon/w_046.c.o(.rodata);
        _146000_RODATA_END = .;
        _146000_RODATA_SIZE = ABSOLUTE(_146000_RODATA_END - _146000_RODATA_START);
    }
    _146000_bss_VRAM = ADDR(._146000_bss);
    ._146000_bss (NOLOAD) : SUBALIGN(4)
    {
        _146000_BSS_START = .;
        build/us/src/weapon/w_046.c.o(.bss);
        _146000_BSS_END = .;
        _146000_BSS_SIZE = ABSOLUTE(_146000_BSS_END - _146000_BSS_START);
    }
    __romPos += SIZEOF(._146000);
    __romPos = ALIGN(__romPos, 16);
    _146000_ROM_END = __romPos;
    _146000_VRAM_END = .;

    f_047_ROM_START = __romPos;
    f_047_VRAM = ADDR(.f_047);
    .f_047 0x0 : AT(f_047_ROM_START) SUBALIGN(16)
    {
        f_047_DATA_START = .;
        f_047_png = .;
        build/us/assets/weapon/f_047.png.o(.data);
        f_047_DATA_END = .;
        f_047_DATA_SIZE = ABSOLUTE(f_047_DATA_END - f_047_DATA_START);
    }
    __romPos += SIZEOF(.f_047);
    f_047_ROM_END = __romPos;
    f_047_VRAM_END = .;

    _14D000_ROM_START = __romPos;
    _14D000_VRAM = ADDR(._14D000);
    ._14D000 0x8017A000 : AT(_14D000_ROM_START) SUBALIGN(4)
    {
        _14D000_DATA_START = .;
        w_047_1 = .;
        build/us/assets/weapon/w_047_1.o(.data);
        w_047_2 = .;
        build/us/assets/weapon/w_047_2.o(.data);
        w_047_data__s = .;
        build/us/asm/us/weapon/data/w_047.data.s.o(.data);
        _14D000_DATA_END = .;
        _14D000_DATA_SIZE = ABSOLUTE(_14D000_DATA_END - _14D000_DATA_START);
        _14D000_TEXT_START = .;
        build/us/src/weapon/w_047.c.o(.text);
        _14D000_TEXT_END = .;
        _14D000_TEXT_SIZE = ABSOLUTE(_14D000_TEXT_END - _14D000_TEXT_START);
        build/us/asm/us/weapon/data/w_047.sbss.s.o(.sbss);
        _14D000_RODATA_START = .;
        build/us/src/weapon/w_047.c.o(.rodata);
        _14D000_RODATA_END = .;
        _14D000_RODATA_SIZE = ABSOLUTE(_14D000_RODATA_END - _14D000_RODATA_START);
    }
    _14D000_bss_VRAM = ADDR(._14D000_bss);
    ._14D000_bss (NOLOAD) : SUBALIGN(4)
    {
        _14D000_BSS_START = .;
        build/us/src/weapon/w_047.c.o(.bss);
        _14D000_BSS_END = .;
        _14D000_BSS_SIZE = ABSOLUTE(_14D000_BSS_END - _14D000_BSS_START);
    }
    __romPos += SIZEOF(._14D000);
    __romPos = ALIGN(__romPos, 16);
    _14D000_ROM_END = __romPos;
    _14D000_VRAM_END = .;

    f_048_ROM_START = __romPos;
    f_048_VRAM = ADDR(.f_048);
    .f_048 0x0 : AT(f_048_ROM_START) SUBALIGN(16)
    {
        f_048_DATA_START = .;
        f_048_png = .;
        build/us/assets/weapon/f_048.png.o(.data);
        f_048_DATA_END = .;
        f_048_DATA_SIZE = ABSOLUTE(f_048_DATA_END - f_048_DATA_START);
    }
    __romPos += SIZEOF(.f_048);
    f_048_ROM_END = __romPos;
    f_048_VRAM_END = .;

    _154000_ROM_START = __romPos;
    _154000_VRAM = ADDR(._154000);
    ._154000 0x8017A000 : AT(_154000_ROM_START) SUBALIGN(4)
    {
        _154000_DATA_START = .;
        w_048_1 = .;
        build/us/assets/weapon/w_048_1.o(.data);
        w_048_2 = .;
        build/us/assets/weapon/w_048_2.o(.data);
        w_048_data__s = .;
        build/us/asm/us/weapon/data/w_048.data.s.o(.data);
        _154000_DATA_END = .;
        _154000_DATA_SIZE = ABSOLUTE(_154000_DATA_END - _154000_DATA_START);
        _154000_TEXT_START = .;
        build/us/src/weapon/w_048.c.o(.text);
        _154000_TEXT_END = .;
        _154000_TEXT_SIZE = ABSOLUTE(_154000_TEXT_END - _154000_TEXT_START);
        build/us/asm/us/weapon/data/w_048.sbss.s.o(.sbss);
        _154000_RODATA_START = .;
        build/us/src/weapon/w_048.c.o(.rodata);
        _154000_RODATA_END = .;
        _154000_RODATA_SIZE = ABSOLUTE(_154000_RODATA_END - _154000_RODATA_START);
    }
    _154000_bss_VRAM = ADDR(._154000_bss);
    ._154000_bss (NOLOAD) : SUBALIGN(4)
    {
        _154000_BSS_START = .;
        build/us/src/weapon/w_048.c.o(.bss);
        _154000_BSS_END = .;
        _154000_BSS_SIZE = ABSOLUTE(_154000_BSS_END - _154000_BSS_START);
    }
    __romPos += SIZEOF(._154000);
    __romPos = ALIGN(__romPos, 16);
    _154000_ROM_END = __romPos;
    _154000_VRAM_END = .;

    f_049_ROM_START = __romPos;
    f_049_VRAM = ADDR(.f_049);
    .f_049 0x0 : AT(f_049_ROM_START) SUBALIGN(16)
    {
        f_049_DATA_START = .;
        f_049_png = .;
        build/us/assets/weapon/f_049.png.o(.data);
        f_049_DATA_END = .;
        f_049_DATA_SIZE = ABSOLUTE(f_049_DATA_END - f_049_DATA_START);
    }
    __romPos += SIZEOF(.f_049);
    f_049_ROM_END = __romPos;
    f_049_VRAM_END = .;

    _15B000_ROM_START = __romPos;
    _15B000_VRAM = ADDR(._15B000);
    ._15B000 0x8017A000 : AT(_15B000_ROM_START) SUBALIGN(4)
    {
        _15B000_DATA_START = .;
        w_049_1 = .;
        build/us/assets/weapon/w_049_1.o(.data);
        w_049_2 = .;
        build/us/assets/weapon/w_049_2.o(.data);
        w_049_data__s = .;
        build/us/asm/us/weapon/data/w_049.data.s.o(.data);
        _15B000_DATA_END = .;
        _15B000_DATA_SIZE = ABSOLUTE(_15B000_DATA_END - _15B000_DATA_START);
        _15B000_TEXT_START = .;
        build/us/src/weapon/w_049.c.o(.text);
        _15B000_TEXT_END = .;
        _15B000_TEXT_SIZE = ABSOLUTE(_15B000_TEXT_END - _15B000_TEXT_START);
        build/us/asm/us/weapon/data/w_049.sbss.s.o(.sbss);
        _15B000_RODATA_START = .;
        build/us/src/weapon/w_049.c.o(.rodata);
        _15B000_RODATA_END = .;
        _15B000_RODATA_SIZE = ABSOLUTE(_15B000_RODATA_END - _15B000_RODATA_START);
    }
    _15B000_bss_VRAM = ADDR(._15B000_bss);
    ._15B000_bss (NOLOAD) : SUBALIGN(4)
    {
        _15B000_BSS_START = .;
        build/us/src/weapon/w_049.c.o(.bss);
        _15B000_BSS_END = .;
        _15B000_BSS_SIZE = ABSOLUTE(_15B000_BSS_END - _15B000_BSS_START);
    }
    __romPos += SIZEOF(._15B000);
    __romPos = ALIGN(__romPos, 16);
    _15B000_ROM_END = __romPos;
    _15B000_VRAM_END = .;

    f_050_ROM_START = __romPos;
    f_050_VRAM = ADDR(.f_050);
    .f_050 0x0 : AT(f_050_ROM_START) SUBALIGN(16)
    {
        f_050_DATA_START = .;
        f_050_png = .;
        build/us/assets/weapon/f_050.png.o(.data);
        f_050_DATA_END = .;
        f_050_DATA_SIZE = ABSOLUTE(f_050_DATA_END - f_050_DATA_START);
    }
    __romPos += SIZEOF(.f_050);
    f_050_ROM_END = __romPos;
    f_050_VRAM_END = .;

    _162000_ROM_START = __romPos;
    _162000_VRAM = ADDR(._162000);
    ._162000 0x8017A000 : AT(_162000_ROM_START) SUBALIGN(4)
    {
        _162000_DATA_START = .;
        w_050_1 = .;
        build/us/assets/weapon/w_050_1.o(.data);
        w_050_2 = .;
        build/us/assets/weapon/w_050_2.o(.data);
        w_050_data__s = .;
        build/us/asm/us/weapon/data/w_050.data.s.o(.data);
        _162000_DATA_END = .;
        _162000_DATA_SIZE = ABSOLUTE(_162000_DATA_END - _162000_DATA_START);
        _162000_TEXT_START = .;
        build/us/src/weapon/w_050.c.o(.text);
        _162000_TEXT_END = .;
        _162000_TEXT_SIZE = ABSOLUTE(_162000_TEXT_END - _162000_TEXT_START);
        build/us/asm/us/weapon/data/w_050.sbss.s.o(.sbss);
        _162000_RODATA_START = .;
        build/us/src/weapon/w_050.c.o(.rodata);
        _162000_RODATA_END = .;
        _162000_RODATA_SIZE = ABSOLUTE(_162000_RODATA_END - _162000_RODATA_START);
    }
    _162000_bss_VRAM = ADDR(._162000_bss);
    ._162000_bss (NOLOAD) : SUBALIGN(4)
    {
        _162000_BSS_START = .;
        build/us/src/weapon/w_050.c.o(.bss);
        _162000_BSS_END = .;
        _162000_BSS_SIZE = ABSOLUTE(_162000_BSS_END - _162000_BSS_START);
    }
    __romPos += SIZEOF(._162000);
    __romPos = ALIGN(__romPos, 16);
    _162000_ROM_END = __romPos;
    _162000_VRAM_END = .;

    f_051_ROM_START = __romPos;
    f_051_VRAM = ADDR(.f_051);
    .f_051 0x0 : AT(f_051_ROM_START) SUBALIGN(16)
    {
        f_051_DATA_START = .;
        f_051_png = .;
        build/us/assets/weapon/f_051.png.o(.data);
        f_051_DATA_END = .;
        f_051_DATA_SIZE = ABSOLUTE(f_051_DATA_END - f_051_DATA_START);
    }
    __romPos += SIZEOF(.f_051);
    f_051_ROM_END = __romPos;
    f_051_VRAM_END = .;

    _169000_ROM_START = __romPos;
    _169000_VRAM = ADDR(._169000);
    ._169000 0x8017A000 : AT(_169000_ROM_START) SUBALIGN(4)
    {
        _169000_DATA_START = .;
        w_051_1 = .;
        build/us/assets/weapon/w_051_1.o(.data);
        w_051_2 = .;
        build/us/assets/weapon/w_051_2.o(.data);
        w_051_data__s = .;
        build/us/asm/us/weapon/data/w_051.data.s.o(.data);
        _169000_DATA_END = .;
        _169000_DATA_SIZE = ABSOLUTE(_169000_DATA_END - _169000_DATA_START);
        _169000_TEXT_START = .;
        build/us/src/weapon/w_051.c.o(.text);
        _169000_TEXT_END = .;
        _169000_TEXT_SIZE = ABSOLUTE(_169000_TEXT_END - _169000_TEXT_START);
        build/us/asm/us/weapon/data/w_051.sbss.s.o(.sbss);
        _169000_RODATA_START = .;
        build/us/src/weapon/w_051.c.o(.rodata);
        _169000_RODATA_END = .;
        _169000_RODATA_SIZE = ABSOLUTE(_169000_RODATA_END - _169000_RODATA_START);
    }
    _169000_bss_VRAM = ADDR(._169000_bss);
    ._169000_bss (NOLOAD) : SUBALIGN(4)
    {
        _169000_BSS_START = .;
        build/us/src/weapon/w_051.c.o(.bss);
        _169000_BSS_END = .;
        _169000_BSS_SIZE = ABSOLUTE(_169000_BSS_END - _169000_BSS_START);
    }
    __romPos += SIZEOF(._169000);
    __romPos = ALIGN(__romPos, 16);
    _169000_ROM_END = __romPos;
    _169000_VRAM_END = .;

    f_052_ROM_START = __romPos;
    f_052_VRAM = ADDR(.f_052);
    .f_052 0x0 : AT(f_052_ROM_START) SUBALIGN(16)
    {
        f_052_DATA_START = .;
        f_052_png = .;
        build/us/assets/weapon/f_052.png.o(.data);
        f_052_DATA_END = .;
        f_052_DATA_SIZE = ABSOLUTE(f_052_DATA_END - f_052_DATA_START);
    }
    __romPos += SIZEOF(.f_052);
    f_052_ROM_END = __romPos;
    f_052_VRAM_END = .;

    _170000_ROM_START = __romPos;
    _170000_VRAM = ADDR(._170000);
    ._170000 0x8017A000 : AT(_170000_ROM_START) SUBALIGN(4)
    {
        _170000_DATA_START = .;
        w_052_1 = .;
        build/us/assets/weapon/w_052_1.o(.data);
        w_052_2 = .;
        build/us/assets/weapon/w_052_2.o(.data);
        w_052_data__s = .;
        build/us/asm/us/weapon/data/w_052.data.s.o(.data);
        _170000_DATA_END = .;
        _170000_DATA_SIZE = ABSOLUTE(_170000_DATA_END - _170000_DATA_START);
        _170000_TEXT_START = .;
        build/us/src/weapon/w_052.c.o(.text);
        _170000_TEXT_END = .;
        _170000_TEXT_SIZE = ABSOLUTE(_170000_TEXT_END - _170000_TEXT_START);
        build/us/asm/us/weapon/data/w_052.sbss.s.o(.sbss);
        _170000_RODATA_START = .;
        build/us/src/weapon/w_052.c.o(.rodata);
        _170000_RODATA_END = .;
        _170000_RODATA_SIZE = ABSOLUTE(_170000_RODATA_END - _170000_RODATA_START);
    }
    _170000_bss_VRAM = ADDR(._170000_bss);
    ._170000_bss (NOLOAD) : SUBALIGN(4)
    {
        _170000_BSS_START = .;
        build/us/src/weapon/w_052.c.o(.bss);
        _170000_BSS_END = .;
        _170000_BSS_SIZE = ABSOLUTE(_170000_BSS_END - _170000_BSS_START);
    }
    __romPos += SIZEOF(._170000);
    __romPos = ALIGN(__romPos, 16);
    _170000_ROM_END = __romPos;
    _170000_VRAM_END = .;

    f_053_ROM_START = __romPos;
    f_053_VRAM = ADDR(.f_053);
    .f_053 0x0 : AT(f_053_ROM_START) SUBALIGN(16)
    {
        f_053_DATA_START = .;
        f_053_png = .;
        build/us/assets/weapon/f_053.png.o(.data);
        f_053_DATA_END = .;
        f_053_DATA_SIZE = ABSOLUTE(f_053_DATA_END - f_053_DATA_START);
    }
    __romPos += SIZEOF(.f_053);
    f_053_ROM_END = __romPos;
    f_053_VRAM_END = .;

    _177000_ROM_START = __romPos;
    _177000_VRAM = ADDR(._177000);
    ._177000 0x8017A000 : AT(_177000_ROM_START) SUBALIGN(4)
    {
        _177000_DATA_START = .;
        w_053_1 = .;
        build/us/assets/weapon/w_053_1.o(.data);
        w_053_2 = .;
        build/us/assets/weapon/w_053_2.o(.data);
        w_053_data__s = .;
        build/us/asm/us/weapon/data/w_053.data.s.o(.data);
        _177000_DATA_END = .;
        _177000_DATA_SIZE = ABSOLUTE(_177000_DATA_END - _177000_DATA_START);
        _177000_TEXT_START = .;
        build/us/src/weapon/w_053.c.o(.text);
        _177000_TEXT_END = .;
        _177000_TEXT_SIZE = ABSOLUTE(_177000_TEXT_END - _177000_TEXT_START);
        build/us/asm/us/weapon/data/w_053.sbss.s.o(.sbss);
        _177000_RODATA_START = .;
        build/us/src/weapon/w_053.c.o(.rodata);
        _177000_RODATA_END = .;
        _177000_RODATA_SIZE = ABSOLUTE(_177000_RODATA_END - _177000_RODATA_START);
    }
    _177000_bss_VRAM = ADDR(._177000_bss);
    ._177000_bss (NOLOAD) : SUBALIGN(4)
    {
        _177000_BSS_START = .;
        build/us/src/weapon/w_053.c.o(.bss);
        _177000_BSS_END = .;
        _177000_BSS_SIZE = ABSOLUTE(_177000_BSS_END - _177000_BSS_START);
    }
    __romPos += SIZEOF(._177000);
    __romPos = ALIGN(__romPos, 16);
    _177000_ROM_END = __romPos;
    _177000_VRAM_END = .;

    f_054_ROM_START = __romPos;
    f_054_VRAM = ADDR(.f_054);
    .f_054 0x0 : AT(f_054_ROM_START) SUBALIGN(16)
    {
        f_054_DATA_START = .;
        f_054_png = .;
        build/us/assets/weapon/f_054.png.o(.data);
        f_054_DATA_END = .;
        f_054_DATA_SIZE = ABSOLUTE(f_054_DATA_END - f_054_DATA_START);
    }
    __romPos += SIZEOF(.f_054);
    f_054_ROM_END = __romPos;
    f_054_VRAM_END = .;

    _17E000_ROM_START = __romPos;
    _17E000_VRAM = ADDR(._17E000);
    ._17E000 0x8017A000 : AT(_17E000_ROM_START) SUBALIGN(4)
    {
        _17E000_DATA_START = .;
        w_054_1 = .;
        build/us/assets/weapon/w_054_1.o(.data);
        w_054_2 = .;
        build/us/assets/weapon/w_054_2.o(.data);
        w_054_data__s = .;
        build/us/asm/us/weapon/data/w_054.data.s.o(.data);
        _17E000_DATA_END = .;
        _17E000_DATA_SIZE = ABSOLUTE(_17E000_DATA_END - _17E000_DATA_START);
        _17E000_TEXT_START = .;
        build/us/src/weapon/w_054.c.o(.text);
        _17E000_TEXT_END = .;
        _17E000_TEXT_SIZE = ABSOLUTE(_17E000_TEXT_END - _17E000_TEXT_START);
        build/us/asm/us/weapon/data/w_054.sbss.s.o(.sbss);
        _17E000_RODATA_START = .;
        build/us/src/weapon/w_054.c.o(.rodata);
        _17E000_RODATA_END = .;
        _17E000_RODATA_SIZE = ABSOLUTE(_17E000_RODATA_END - _17E000_RODATA_START);
    }
    _17E000_bss_VRAM = ADDR(._17E000_bss);
    ._17E000_bss (NOLOAD) : SUBALIGN(4)
    {
        _17E000_BSS_START = .;
        build/us/src/weapon/w_054.c.o(.bss);
        _17E000_BSS_END = .;
        _17E000_BSS_SIZE = ABSOLUTE(_17E000_BSS_END - _17E000_BSS_START);
    }
    __romPos += SIZEOF(._17E000);
    __romPos = ALIGN(__romPos, 16);
    _17E000_ROM_END = __romPos;
    _17E000_VRAM_END = .;

    f_055_ROM_START = __romPos;
    f_055_VRAM = ADDR(.f_055);
    .f_055 0x0 : AT(f_055_ROM_START) SUBALIGN(16)
    {
        f_055_DATA_START = .;
        f_055_png = .;
        build/us/assets/weapon/f_055.png.o(.data);
        f_055_DATA_END = .;
        f_055_DATA_SIZE = ABSOLUTE(f_055_DATA_END - f_055_DATA_START);
    }
    __romPos += SIZEOF(.f_055);
    f_055_ROM_END = __romPos;
    f_055_VRAM_END = .;

    _185000_ROM_START = __romPos;
    _185000_VRAM = ADDR(._185000);
    ._185000 0x8017A000 : AT(_185000_ROM_START) SUBALIGN(4)
    {
        _185000_DATA_START = .;
        w_055_1 = .;
        build/us/assets/weapon/w_055_1.o(.data);
        w_055_2 = .;
        build/us/assets/weapon/w_055_2.o(.data);
        w_055_data__s = .;
        build/us/asm/us/weapon/data/w_055.data.s.o(.data);
        _185000_DATA_END = .;
        _185000_DATA_SIZE = ABSOLUTE(_185000_DATA_END - _185000_DATA_START);
        _185000_TEXT_START = .;
        build/us/src/weapon/w_055.c.o(.text);
        _185000_TEXT_END = .;
        _185000_TEXT_SIZE = ABSOLUTE(_185000_TEXT_END - _185000_TEXT_START);
        build/us/asm/us/weapon/data/w_055.sbss.s.o(.sbss);
        _185000_RODATA_START = .;
        build/us/src/weapon/w_055.c.o(.rodata);
        _185000_RODATA_END = .;
        _185000_RODATA_SIZE = ABSOLUTE(_185000_RODATA_END - _185000_RODATA_START);
    }
    _185000_bss_VRAM = ADDR(._185000_bss);
    ._185000_bss (NOLOAD) : SUBALIGN(4)
    {
        _185000_BSS_START = .;
        build/us/src/weapon/w_055.c.o(.bss);
        _185000_BSS_END = .;
        _185000_BSS_SIZE = ABSOLUTE(_185000_BSS_END - _185000_BSS_START);
    }
    __romPos += SIZEOF(._185000);
    __romPos = ALIGN(__romPos, 16);
    _185000_ROM_END = __romPos;
    _185000_VRAM_END = .;

    f_056_ROM_START = __romPos;
    f_056_VRAM = ADDR(.f_056);
    .f_056 0x0 : AT(f_056_ROM_START) SUBALIGN(16)
    {
        f_056_DATA_START = .;
        f_056_png = .;
        build/us/assets/weapon/f_056.png.o(.data);
        f_056_DATA_END = .;
        f_056_DATA_SIZE = ABSOLUTE(f_056_DATA_END - f_056_DATA_START);
    }
    __romPos += SIZEOF(.f_056);
    f_056_ROM_END = __romPos;
    f_056_VRAM_END = .;

    _18C000_ROM_START = __romPos;
    _18C000_VRAM = ADDR(._18C000);
    ._18C000 0x8017A000 : AT(_18C000_ROM_START) SUBALIGN(4)
    {
        _18C000_DATA_START = .;
        w_056_1 = .;
        build/us/assets/weapon/w_056_1.o(.data);
        w_056_2 = .;
        build/us/assets/weapon/w_056_2.o(.data);
        w_056_data__s = .;
        build/us/asm/us/weapon/data/w_056.data.s.o(.data);
        _18C000_DATA_END = .;
        _18C000_DATA_SIZE = ABSOLUTE(_18C000_DATA_END - _18C000_DATA_START);
        _18C000_TEXT_START = .;
        build/us/src/weapon/w_056.c.o(.text);
        _18C000_TEXT_END = .;
        _18C000_TEXT_SIZE = ABSOLUTE(_18C000_TEXT_END - _18C000_TEXT_START);
        build/us/asm/us/weapon/data/w_056.sbss.s.o(.sbss);
        _18C000_RODATA_START = .;
        build/us/src/weapon/w_056.c.o(.rodata);
        _18C000_RODATA_END = .;
        _18C000_RODATA_SIZE = ABSOLUTE(_18C000_RODATA_END - _18C000_RODATA_START);
    }
    _18C000_bss_VRAM = ADDR(._18C000_bss);
    ._18C000_bss (NOLOAD) : SUBALIGN(4)
    {
        _18C000_BSS_START = .;
        build/us/src/weapon/w_056.c.o(.bss);
        _18C000_BSS_END = .;
        _18C000_BSS_SIZE = ABSOLUTE(_18C000_BSS_END - _18C000_BSS_START);
    }
    __romPos += SIZEOF(._18C000);
    __romPos = ALIGN(__romPos, 16);
    _18C000_ROM_END = __romPos;
    _18C000_VRAM_END = .;

    f_057_ROM_START = __romPos;
    f_057_VRAM = ADDR(.f_057);
    .f_057 0x0 : AT(f_057_ROM_START) SUBALIGN(16)
    {
        f_057_DATA_START = .;
        f_057_png = .;
        build/us/assets/weapon/f_057.png.o(.data);
        f_057_DATA_END = .;
        f_057_DATA_SIZE = ABSOLUTE(f_057_DATA_END - f_057_DATA_START);
    }
    __romPos += SIZEOF(.f_057);
    f_057_ROM_END = __romPos;
    f_057_VRAM_END = .;

    _193000_ROM_START = __romPos;
    _193000_VRAM = ADDR(._193000);
    ._193000 0x8017A000 : AT(_193000_ROM_START) SUBALIGN(4)
    {
        _193000_DATA_START = .;
        w_057_1 = .;
        build/us/assets/weapon/w_057_1.o(.data);
        w_057_2 = .;
        build/us/assets/weapon/w_057_2.o(.data);
        w_057_data__s = .;
        build/us/asm/us/weapon/data/w_057.data.s.o(.data);
        _193000_DATA_END = .;
        _193000_DATA_SIZE = ABSOLUTE(_193000_DATA_END - _193000_DATA_START);
        _193000_TEXT_START = .;
        build/us/src/weapon/w_057.c.o(.text);
        _193000_TEXT_END = .;
        _193000_TEXT_SIZE = ABSOLUTE(_193000_TEXT_END - _193000_TEXT_START);
        build/us/asm/us/weapon/data/w_057.sbss.s.o(.sbss);
        _193000_RODATA_START = .;
        build/us/src/weapon/w_057.c.o(.rodata);
        _193000_RODATA_END = .;
        _193000_RODATA_SIZE = ABSOLUTE(_193000_RODATA_END - _193000_RODATA_START);
    }
    _193000_bss_VRAM = ADDR(._193000_bss);
    ._193000_bss (NOLOAD) : SUBALIGN(4)
    {
        _193000_BSS_START = .;
        build/us/src/weapon/w_057.c.o(.bss);
        _193000_BSS_END = .;
        _193000_BSS_SIZE = ABSOLUTE(_193000_BSS_END - _193000_BSS_START);
    }
    __romPos += SIZEOF(._193000);
    __romPos = ALIGN(__romPos, 16);
    _193000_ROM_END = __romPos;
    _193000_VRAM_END = .;

    f_058_ROM_START = __romPos;
    f_058_VRAM = ADDR(.f_058);
    .f_058 0x0 : AT(f_058_ROM_START) SUBALIGN(16)
    {
        f_058_DATA_START = .;
        f_058_png = .;
        build/us/assets/weapon/f_058.png.o(.data);
        f_058_DATA_END = .;
        f_058_DATA_SIZE = ABSOLUTE(f_058_DATA_END - f_058_DATA_START);
    }
    __romPos += SIZEOF(.f_058);
    f_058_ROM_END = __romPos;
    f_058_VRAM_END = .;

    _19A000_ROM_START = __romPos;
    _19A000_VRAM = ADDR(._19A000);
    ._19A000 0x8017A000 : AT(_19A000_ROM_START) SUBALIGN(4)
    {
        _19A000_DATA_START = .;
        w_058_1 = .;
        build/us/assets/weapon/w_058_1.o(.data);
        w_058_2 = .;
        build/us/assets/weapon/w_058_2.o(.data);
        w_058_data__s = .;
        build/us/asm/us/weapon/data/w_058.data.s.o(.data);
        _19A000_DATA_END = .;
        _19A000_DATA_SIZE = ABSOLUTE(_19A000_DATA_END - _19A000_DATA_START);
        _19A000_TEXT_START = .;
        build/us/src/weapon/w_058.c.o(.text);
        _19A000_TEXT_END = .;
        _19A000_TEXT_SIZE = ABSOLUTE(_19A000_TEXT_END - _19A000_TEXT_START);
        build/us/asm/us/weapon/data/w_058.sbss.s.o(.sbss);
        _19A000_RODATA_START = .;
        build/us/src/weapon/w_058.c.o(.rodata);
        _19A000_RODATA_END = .;
        _19A000_RODATA_SIZE = ABSOLUTE(_19A000_RODATA_END - _19A000_RODATA_START);
    }
    _19A000_bss_VRAM = ADDR(._19A000_bss);
    ._19A000_bss (NOLOAD) : SUBALIGN(4)
    {
        _19A000_BSS_START = .;
        build/us/src/weapon/w_058.c.o(.bss);
        _19A000_BSS_END = .;
        _19A000_BSS_SIZE = ABSOLUTE(_19A000_BSS_END - _19A000_BSS_START);
    }
    __romPos += SIZEOF(._19A000);
    __romPos = ALIGN(__romPos, 16);
    _19A000_ROM_END = __romPos;
    _19A000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
