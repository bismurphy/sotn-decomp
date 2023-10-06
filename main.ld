SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        header_DATA_START = .;
        header_s = .;
        build/us/asm/us/main/header.s.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main 0x80010000 : AT(main_ROM_START) SUBALIGN(4)
    {
        main_RODATA_START = .;
        build/us/asm/us/main/data/800.rodata.s.o(.rodata);
        build/us/asm/us/main/data/874.rodata.s.o(.rodata);
        build/us/asm/us/main/data/C94.rodata.s.o(.rodata);
        build/us/asm/us/main/data/EB4.rodata.s.o(.rodata);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
        main_TEXT_START = .;
        build/us/asm/us/main/15F4.s.o(.text);
        build/us/asm/us/main/psxsdk/libapi1.s.o(.text);
        build/us/src/main/5A38.c.o(.text);
        build/us/src/main/psxsdk/libetc.c.o(.text);
        build/us/src/main/5E78.c.o(.text);
        build/us/asm/us/main/psxsdk/libc.s.o(.text);
        build/us/src/main/psxsdk/sprintf.c.o(.text);
        build/us/src/main/7190.c.o(.text);
        build/us/asm/us/main/psxsdk/libcard.s.o(.text);
        build/us/src/main/72A4.c.o(.text);
        build/us/asm/us/main/psxsdk/libapi2.s.o(.text);
        build/us/src/main/psxsdk/libcd/sys.c.o(.text);
        build/us/src/main/psxsdk/libcd/bios.c.o(.text);
        build/us/src/main/psxsdk/libcd/iso9660.c.o(.text);
        build/us/asm/us/main/C464.s.o(.text);
        build/us/src/main/psxsdk/libcd/cdread.c.o(.text);
        build/us/src/main/psxsdk/libcd/cdread2.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_002.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_003.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_004.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_005.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_007.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_008.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_009.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_010.c.o(.text);
        build/us/src/main/psxsdk/libcd/c_011.c.o(.text);
        build/us/src/main/psxsdk/libsnd/scsmvol.c.o(.text);
        build/us/src/main/psxsdk/libsnd/scssattr.c.o(.text);
        build/us/src/main/psxsdk/libsnd/scssvol.c.o(.text);
        build/us/src/main/psxsdk/libsnd/seqinit.c.o(.text);
        build/us/src/main/psxsdk/libsnd/seqread.c.o(.text);
        build/us/src/main/psxsdk/libsnd/miditime.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ccadsr.c.o(.text);
        build/us/src/main/psxsdk/libsnd/next.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssvkoff.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssvkon.c.o(.text);
        build/us/src/main/psxsdk/libsnd/sscall.c.o(.text);
        build/us/src/main/psxsdk/libsnd/cres.c.o(.text);
        build/us/src/main/psxsdk/libsnd/pause.c.o(.text);
        build/us/src/main/psxsdk/libsnd/play.c.o(.text);
        build/us/src/main/psxsdk/libsnd/replay.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssclose.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssinit.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssinit_h.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssquit.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssstart.c.o(.text);
        build/us/src/main/psxsdk/libsnd/sstick.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssend.c.o(.text);
        build/us/src/main/psxsdk/libsnd/sstable.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssplay.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ssvol.c.o(.text);
        build/us/src/main/psxsdk/libsnd/stop.c.o(.text);
        build/us/src/main/psxsdk/libsnd/tempo.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_mono.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_srv.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vab.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vfb.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vh.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vtb.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vtbp.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vs_vtc.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vm_doff.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vm_don.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_gpa.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vm_vsu.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_gva.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_rev.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_ron.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_roff.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_rfb.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_rdep.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_rdel.c.o(.text);
        build/us/src/main/psxsdk/libsnd/ut_sva.c.o(.text);
        build/us/src/main/psxsdk/libsnd/vmanager.c.o(.text);
        build/us/src/main/psxsdk/libspu/s_i.c.o(.text);
        build/us/src/main/psxsdk/libspu/s_ini.c.o(.text);
        build/us/asm/us/main/psxsdk_stuff.s.o(.text);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        _1BCE0_data__s = .;
        build/us/asm/us/main/data/1BCE0.data.s.o(.data);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 16);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
