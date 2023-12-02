import unittest
from split_jpt_yaml import check_file, execute

test_string = """
.include "macro.inc"

.section .rodata

/* Generated by spimdisasm 1.10.4 */

glabel jpt_80102918
/* 3CC2C 800DCC2C 20291080 */ .word .L80102920
/* 3CC30 800DCC30 F82A1080 */ .word .L80102AF8
/* 3CC34 800DCC34 30291080 */ .word .L80102930
/* 3CC38 800DCC38 A02A1080 */ .word .L80102AA0
/* 3CC3C 800DCC3C F82A1080 */ .word .L80102AF8
/* 3CC40 800DCC40 F82A1080 */ .word .L80102AF8
/* 3CC44 800DCC44 30291080 */ .word .L80102930
/* 3CC48 800DCC48 30291080 */ .word .L80102930
/* 3CC4C 800DCC4C 202A1080 */ .word .L80102A20
/* 3CC50 800DCC50 00000000 */ .word 0x00000000

glabel jpt_80102D9C
/* 3CC54 800DCC54 DC2D1080 */ .word .L80102DDC
/* 3CC58 800DCC58 C42D1080 */ .word .L80102DC4
/* 3CC5C 800DCC5C A42D1080 */ .word .L80102DA4
/* 3CC60 800DCC60 C42D1080 */ .word .L80102DC4
/* 3CC64 800DCC64 C42D1080 */ .word .L80102DC4
/* 3CC68 800DCC68 DC2D1080 */ .word .L80102DDC
/* 3CC6C 800DCC6C C42D1080 */ .word .L80102DC4

glabel D_800DCC70
/* 3CC70 800DCC70 44617461 */ .word 0x61746144
/* 3CC74 800DCC74 20736176 */ .word 0x76617320
/* 3CC78 800DCC78 65648144 */ .word 0x44816465
/* 3CC7C 800DCC7C 00000000 */ .word 0x00000000
"""

test_string2 = """
.include "macro.inc"

.section .rodata

/* Generated by spimdisasm 1.10.4 */

.align 3
glabel jtbl_801B7458
/* 37458 801B7458 94EF1B80 */ .word .L801BEF94
/* 3745C 801B745C 58F01B80 */ .word .L801BF058
/* 37460 801B7460 44F91B80 */ .word .L801BF944
/* 37464 801B7464 78F91B80 */ .word .L801BF978
/* 37468 801B7468 3CFA1B80 */ .word .L801BFA3C
/* 3746C 801B746C D4FA1B80 */ .word .L801BFAD4
/* 37470 801B7470 BCFD1B80 */ .word .L801BFDBC
/* 37474 801B7474 94FE1B80 */ .word .L801BFE94

.align 3
glabel jtbl_801B7478
/* 37478 801B7478 D0F01B80 */ .word .L801BF0D0
/* 3747C 801B747C DCF01B80 */ .word .L801BF0DC
/* 37480 801B7480 88F11B80 */ .word .L801BF188
/* 37484 801B7484 B4F11B80 */ .word .L801BF1B4
/* 37488 801B7488 E4F11B80 */ .word .L801BF1E4
/* 3748C 801B748C 24F21B80 */ .word .L801BF224
/* 37490 801B7490 5CF31B80 */ .word .L801BF35C
/* 37494 801B7494 D4F31B80 */ .word .L801BF3D4
/* 37498 801B7498 68F41B80 */ .word .L801BF468
/* 3749C 801B749C 90F41B80 */ .word .L801BF490
/* 374A0 801B74A0 B8F41B80 */ .word .L801BF4B8
/* 374A4 801B74A4 F0F41B80 */ .word .L801BF4F0
/* 374A8 801B74A8 38F51B80 */ .word .L801BF538
/* 374AC 801B74AC 6CF01B80 */ .word .L801BF06C
/* 374B0 801B74B0 94F51B80 */ .word .L801BF594
/* 374B4 801B74B4 F8F51B80 */ .word .L801BF5F8
/* 374B8 801B74B8 58F61B80 */ .word .L801BF658
/* 374BC 801B74BC A4F61B80 */ .word .L801BF6A4
/* 374C0 801B74C0 D8F61B80 */ .word .L801BF6D8
/* 374C4 801B74C4 E8F61B80 */ .word .L801BF6E8
/* 374C8 801B74C8 A8F71B80 */ .word .L801BF7A8
/* 374CC 801B74CC E4F71B80 */ .word .L801BF7E4
/* 374D0 801B74D0 04F81B80 */ .word .L801BF804
/* 374D4 801B74D4 DCFE1B80 */ .word .L801BFEDC
/* 374D8 801B74D8 40F81B80 */ .word .L801BF840

glabel jtbl_801B74DC
/* 374DC 801B74DC A0FF1B80 */ .word .L801BFFA0
/* 374E0 801B74E0 F4FF1B80 */ .word .L801BFFF4
/* 374E4 801B74E4 58001C80 */ .word .L801C0058
/* 374E8 801B74E8 FC001C80 */ .word .L801C00FC
/* 374EC 801B74EC E4011C80 */ .word .L801C01E4
/* 374F0 801B74F0 88021C80 */ .word .L801C0288

glabel jtbl_801B74F4
/* 374F4 801B74F4 94031C80 */ .word .L801C0394
/* 374F8 801B74F8 AC031C80 */ .word .L801C03AC
/* 374FC 801B74FC 1C051C80 */ .word .L801C051C
/* 37500 801B7500 48051C80 */ .word .L801C0548
/* 37504 801B7504 20061C80 */ .word .L801C0620
/* 37508 801B7508 0C071C80 */ .word .L801C070C
/* 3750C 801B750C B0071C80 */ .word .L801C07B0
/* 37510 801B7510 00000000 */ .word 0x00000000

glabel jtbl_801B7514
/* 37514 801B7514 7C091C80 */ .word .L801C097C
/* 37518 801B7518 000B1C80 */ .word .L801C0B00
/* 3751C 801B751C 580B1C80 */ .word .L801C0B58
/* 37520 801B7520 2C0C1C80 */ .word .L801C0C2C
/* 37524 801B7524 840C1C80 */ .word .L801C0C84
/* 37528 801B7528 C00D1C80 */ .word .L801C0DC0
/* 3752C 801B752C FC0D1C80 */ .word .L801C0DFC
/* 37530 801B7530 340E1C80 */ .word .L801C0E34
/* 37534 801B7534 780E1C80 */ .word .L801C0E78
/* 37538 801B7538 B00E1C80 */ .word .L801C0EB0
/* 3753C 801B753C E40E1C80 */ .word .L801C0EE4
/* 37540 801B7540 1C0F1C80 */ .word .L801C0F1C
/* 37544 801B7544 500F1C80 */ .word .L801C0F50
/* 37548 801B7548 880F1C80 */ .word .L801C0F88
/* 3754C 801B754C B00F1C80 */ .word .L801C0FB0
/* 37550 801B7550 EC0F1C80 */ .word .L801C0FEC
/* 37554 801B7554 2C101C80 */ .word .L801C102C
/* 37558 801B7558 88111C80 */ .word .L801C1188
/* 3755C 801B755C 64101C80 */ .word .L801C1064
/* 37560 801B7560 D0101C80 */ .word .L801C10D0

glabel jtbl_801B7564
/* 37564 801B7564 F8141C80 */ .word .L801C14F8
/* 37568 801B7568 AC151C80 */ .word .L801C15AC
/* 3756C 801B756C C8151C80 */ .word .L801C15C8
/* 37570 801B7570 64161C80 */ .word .L801C1664
/* 37574 801B7574 C0171C80 */ .word .L801C17C0

.align 3
glabel jtbl_801B7578
/* 37578 801B7578 88401C80 */ .word .L801C4088
/* 3757C 801B757C D4431C80 */ .word .L801C43D4
/* 37580 801B7580 60451C80 */ .word .L801C4560
/* 37584 801B7584 10461C80 */ .word .L801C4610
/* 37588 801B7588 5C461C80 */ .word .L801C465C
/* 3758C 801B758C A4461C80 */ .word .L801C46A4

glabel D_801B7590
/* 37590 801B7590 04151010 */ .word 0x10101504
/* 37594 801B7594 10FF0000 */ .word 0x0000FF10

glabel D_801B7598
/* 37598 801B7598 04121010 */ .word 0x10101204
/* 3759C 801B759C 10FF0000 */ .word 0x0000FF10

glabel D_801B75A0
/* 375A0 801B75A0 04111010 */ .word 0x10101104
/* 375A4 801B75A4 10FF0000 */ .word 0x0000FF10

glabel D_801B75A8
/* 375A8 801B75A8 04171010 */ .word 0x10101704
/* 375AC 801B75AC FF000000 */ .word 0x000000FF

glabel D_801B75B0
/* 375B0 801B75B0 04141010 */ .word 0x10101404
/* 375B4 801B75B4 FF000000 */ .word 0x000000FF

glabel D_801B75B8
/* 375B8 801B75B8 04121510 */ .word 0x10151204
/* 375BC 801B75BC FF000000 */ .word 0x000000FF

glabel D_801B75C0
/* 375C0 801B75C0 04111010 */ .word 0x10101104
/* 375C4 801B75C4 FF000000 */ .word 0x000000FF

glabel D_801B75C8
/* 375C8 801B75C8 041510FF */ .word 0xFF101504
/* 375CC 801B75CC 00000000 */ .word 0x00000000

glabel D_801B75D0
/* 375D0 801B75D0 041215FF */ .word 0xFF151204
/* 375D4 801B75D4 00000000 */ .word 0x00000000

glabel D_801B75D8
/* 375D8 801B75D8 0411FF00 */ .word 0x00FF1104
/* 375DC 801B75DC 00000000 */ .word 0x00000000

.align 3
glabel jtbl_801B75E0
/* 375E0 801B75E0 5C671C80 */ .word .L801C675C
/* 375E4 801B75E4 F0671C80 */ .word .L801C67F0
/* 375E8 801B75E8 98681C80 */ .word .L801C6898
/* 375EC 801B75EC CC691C80 */ .word .L801C69CC
/* 375F0 801B75F0 2C6A1C80 */ .word .L801C6A2C
/* 375F4 801B75F4 646A1C80 */ .word .L801C6A64
/* 375F8 801B75F8 0C6B1C80 */ .word .L801C6B0C
/* 375FC 801B75FC 0C6B1C80 */ .word .L801C6B0C

.align 3
glabel jtbl_801B7600
/* 37600 801B7600 18711C80 */ .word .L801C7118
/* 37604 801B7604 70711C80 */ .word .L801C7170
/* 37608 801B7608 98731C80 */ .word .L801C7398
/* 3760C 801B760C 7C741C80 */ .word .L801C747C
/* 37610 801B7610 E8741C80 */ .word .L801C74E8
/* 37614 801B7614 58751C80 */ .word .L801C7558

glabel D_801B7618
/* 37618 801B7618 */ .asciz "Obtained "
                      .balign 4
/* 37624 801B7624 */ .asciz ""
                      .balign 4
"""


class Testing(unittest.TestCase):
    def test(self):
        segments = []
        names = {}
        check_file(test_string, "jpt_", segments, names)
        assert segments[0][0] == 0x3CC2C
        assert segments[1][0] == 0x3CC54
        assert segments[2][0] == 0x3CC70
        assert names[0x3CC2C] == "jpt_80102918"
        assert names[0x3CC54] == "jpt_80102D9C"

    # check that it can switch between jump tables and data
    def test2(self):
        segments = []
        names = {}
        check_file(test_string2, "jtbl_", segments, names)
        assert segments[0][0] == 0x37458  # jtbl_801B7458
        assert segments[1][0] == 0x37478  # jtbl_801B7478
        assert segments[2][0] == 0x374DC  # jtbl_801B74DC
        assert segments[3][0] == 0x374F4  # jtbl_801B74F4
        assert segments[4][0] == 0x37514  # jtbl_801B7514
        assert segments[5][0] == 0x37564  # jtbl_801B7564
        assert segments[6][0] == 0x37578  # jtbl_801B7578
        assert segments[7][0] == 0x37590  # D_801B7590
        assert segments[8][0] == 0x375E0  # jtbl_801B75E0
        assert segments[9][0] == 0x37600  # jtbl_801B7600
        assert segments[10][0] == 0x37618  # D_801B7618

        for segment in segments:
            print(segment)

    # check that it merges with the existing yaml correctly
    def test3(self):
        test_segments = [
            [0, "rodata"],
            [2336, "rodata"],
            [2732, "rodata"],
            [3520, "rodata"],
            [3536, "rodata"],
            [3664, "rodata"],
            [3696, "rodata"],
            [3712, "rodata"],
            [3728, "rodata"],
            [3744, "rodata"],
            [4592, "rodata"],
            [6976, "rodata"],
            [9936, "rodata"],
            [12672, "rodata"],
            [14752, "rodata"],
            [15040, "rodata"],
            [15088, "rodata"],
            [15152, "rodata"],
            [19680, "rodata"],
            [226272, "rodata"],
            [226280, "rodata"],
            [226324, ".rodata", "3C4EC"],
            [226348, ".rodata", "3E134"],
            [226368, "rodata"],
            [226392, "rodata"],
            [226856, "rodata"],
            [227048, "rodata"],
            [227236, ".rodata", 56264],
            [227256, "rodata"],
            [227284, "c"],
            [247020, "c", "3C4EC"],
            [254260, "c", "3E134"],
            [352868, "c"],
            [356528, "data"],
        ]

        names = {}
        execute([test_string2], "jtbl_", test_segments, names)

        assert [0x37458, "rodata"] in test_segments  # jtbl_801B7458
        assert [0x37478, "rodata"] in test_segments  # jtbl_801B7478
        assert [0x374DC, "rodata"] in test_segments  # jtbl_801B74DC
        assert [0x374F4, "rodata"] in test_segments  # jtbl_801B74F4
        assert [0x37514, "rodata"] in test_segments  # jtbl_801B7514
        assert [0x37564, "rodata"] in test_segments  # jtbl_801B7564
        assert [0x37578, "rodata"] in test_segments  # jtbl_801B7578
        assert [0x37590, "rodata"] in test_segments  # D_801B7590
        assert [0x375E0, "rodata"] in test_segments  # jtbl_801B75E0
        assert [0x37600, "rodata"] in test_segments  # jtbl_801B7600
        assert [0x37618, "rodata"] in test_segments  # D_801B7618


if __name__ == "__main__":
    unittest.main()
