.set noat
.set noreorder
.set gp=64
.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    \label:
.endm

# Float register aliases (o32 ABI)

.set $fv0,          $f0
.set $fv0f,         $f1
.set $fv1,          $f2
.set $fv1f,         $f3
.set $ft0,          $f4
.set $ft0f,         $f5
.set $ft1,          $f6
.set $ft1f,         $f7
.set $ft2,          $f8
.set $ft2f,         $f9
.set $ft3,          $f10
.set $ft3f,         $f11
.set $fa0,          $f12
.set $fa0f,         $f13
.set $fa1,          $f14
.set $fa1f,         $f15
.set $ft4,          $f16
.set $ft4f,         $f17
.set $ft5,          $f18
.set $ft5f,         $f19
.set $fs0,          $f20
.set $fs0f,         $f21
.set $fs1,          $f22
.set $fs1f,         $f23
.set $fs2,          $f24
.set $fs2f,         $f25
.set $fs3,          $f26
.set $fs3f,         $f27
.set $fs4,          $f28
.set $fs4f,         $f29
.set $fs5,          $f30
.set $fs5f,         $f31
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel func_800FEEA4
/* 5EEA4 800FEEA4 E8FFBD27 */  addiu      $sp, $sp, -0x18
/* 5EEA8 800FEEA8 1000B0AF */  sw         $s0, 0x10($sp)
/* 5EEAC 800FEEAC 2180A000 */  addu       $s0, $a1, $zero
/* 5EEB0 800FEEB0 18008014 */  bnez       $a0, .L800FEF14
/* 5EEB4 800FEEB4 1400BFAF */   sw        $ra, 0x14($sp)
/* 5EEB8 800FEEB8 EAF8030C */  jal        IsRelicActive
/* 5EEBC 800FEEBC 21200000 */   addu      $a0, $zero, $zero
/* 5EEC0 800FEEC0 63004010 */  beqz       $v0, .L800FF050
/* 5EEC4 800FEEC4 FFFF0224 */   addiu     $v0, $zero, -0x1
/* 5EEC8 800FEEC8 0980063C */  lui        $a2, %hi(g_Status_mp)
/* 5EECC 800FEECC B07BC624 */  addiu      $a2, $a2, %lo(g_Status_mp)
/* 5EED0 800FEED0 0000C28C */  lw         $v0, 0x0($a2)
/* 5EED4 800FEED4 00000000 */  nop
/* 5EED8 800FEED8 FFFF4524 */  addiu      $a1, $v0, -0x1
/* 5EEDC 800FEEDC 4200A018 */  blez       $a1, .L800FEFE8
/* 5EEE0 800FEEE0 00000000 */   nop
/* 5EEE4 800FEEE4 57000012 */  beqz       $s0, .L800FF044
/* 5EEE8 800FEEE8 8888023C */   lui       $v0, (0x88888889 >> 16)
/* 5EEEC 800FEEEC 0480043C */  lui        $a0, %hi(D_8003C8C4)
/* 5EEF0 800FEEF0 C4C8848C */  lw         $a0, %lo(D_8003C8C4)($a0)
/* 5EEF4 800FEEF4 89884234 */  ori        $v0, $v0, (0x88888889 & 0xFFFF)
/* 5EEF8 800FEEF8 19008200 */  multu      $a0, $v0
/* 5EEFC 800FEEFC 10180000 */  mfhi       $v1
/* 5EF00 800FEF00 42190300 */  srl        $v1, $v1, 5
/* 5EF04 800FEF04 00110300 */  sll        $v0, $v1, 4
/* 5EF08 800FEF08 23104300 */  subu       $v0, $v0, $v1
/* 5EF0C 800FEF0C 0EFC0308 */  j          .L800FF038
/* 5EF10 800FEF10 80100200 */   sll       $v0, $v0, 2
.L800FEF14:
/* 5EF14 800FEF14 01000234 */  ori        $v0, $zero, 0x1
/* 5EF18 800FEF18 2D008214 */  bne        $a0, $v0, .L800FEFD0
/* 5EF1C 800FEF1C 02000234 */   ori       $v0, $zero, 0x2
/* 5EF20 800FEF20 EAF8030C */  jal        IsRelicActive
/* 5EF24 800FEF24 07000434 */   ori       $a0, $zero, 0x7
/* 5EF28 800FEF28 49004010 */  beqz       $v0, .L800FF050
/* 5EF2C 800FEF2C FFFF0224 */   addiu     $v0, $zero, -0x1
/* 5EF30 800FEF30 EAF8030C */  jal        IsRelicActive
/* 5EF34 800FEF34 08000434 */   ori       $a0, $zero, 0x8
/* 5EF38 800FEF38 14004010 */  beqz       $v0, .L800FEF8C
/* 5EF3C 800FEF3C 00000000 */   nop
/* 5EF40 800FEF40 0980063C */  lui        $a2, %hi(g_Status_mp)
/* 5EF44 800FEF44 B07BC624 */  addiu      $a2, $a2, %lo(g_Status_mp)
/* 5EF48 800FEF48 0000C28C */  lw         $v0, 0x0($a2)
/* 5EF4C 800FEF4C 00000000 */  nop
/* 5EF50 800FEF50 FEFF4524 */  addiu      $a1, $v0, -0x2
/* 5EF54 800FEF54 2400A018 */  blez       $a1, .L800FEFE8
/* 5EF58 800FEF58 00000000 */   nop
/* 5EF5C 800FEF5C 39000012 */  beqz       $s0, .L800FF044
/* 5EF60 800FEF60 8888023C */   lui       $v0, (0x88888889 >> 16)
/* 5EF64 800FEF64 0480043C */  lui        $a0, %hi(D_8003C8C4)
/* 5EF68 800FEF68 C4C8848C */  lw         $a0, %lo(D_8003C8C4)($a0)
/* 5EF6C 800FEF6C 89884234 */  ori        $v0, $v0, (0x88888889 & 0xFFFF)
/* 5EF70 800FEF70 19008200 */  multu      $a0, $v0
/* 5EF74 800FEF74 10180000 */  mfhi       $v1
/* 5EF78 800FEF78 02190300 */  srl        $v1, $v1, 4
/* 5EF7C 800FEF7C 00110300 */  sll        $v0, $v1, 4
/* 5EF80 800FEF80 23104300 */  subu       $v0, $v0, $v1
/* 5EF84 800FEF84 0EFC0308 */  j          .L800FF038
/* 5EF88 800FEF88 40100200 */   sll       $v0, $v0, 1
.L800FEF8C:
/* 5EF8C 800FEF8C 0980043C */  lui        $a0, %hi(g_Status_mp)
/* 5EF90 800FEF90 B07B8424 */  addiu      $a0, $a0, %lo(g_Status_mp)
/* 5EF94 800FEF94 0000828C */  lw         $v0, 0x0($a0)
/* 5EF98 800FEF98 00000000 */  nop
/* 5EF9C 800FEF9C F6FF4324 */  addiu      $v1, $v0, -0xA
/* 5EFA0 800FEFA0 11006018 */  blez       $v1, .L800FEFE8
/* 5EFA4 800FEFA4 00000000 */   nop
/* 5EFA8 800FEFA8 29000012 */  beqz       $s0, .L800FF050
/* 5EFAC 800FEFAC 21100000 */   addu      $v0, $zero, $zero
/* 5EFB0 800FEFB0 0480023C */  lui        $v0, %hi(D_8003C8C4)
/* 5EFB4 800FEFB4 C4C8428C */  lw         $v0, %lo(D_8003C8C4)($v0)
/* 5EFB8 800FEFB8 00000000 */  nop
/* 5EFBC 800FEFBC 07004230 */  andi       $v0, $v0, 0x7
/* 5EFC0 800FEFC0 23004014 */  bnez       $v0, .L800FF050
/* 5EFC4 800FEFC4 21100000 */   addu      $v0, $zero, $zero
/* 5EFC8 800FEFC8 14FC0308 */  j          .L800FF050
/* 5EFCC 800FEFCC 000083AC */   sw        $v1, 0x0($a0)
.L800FEFD0:
/* 5EFD0 800FEFD0 1F008214 */  bne        $a0, $v0, .L800FF050
/* 5EFD4 800FEFD4 00000000 */   nop
/* 5EFD8 800FEFD8 EAF8030C */  jal        IsRelicActive
/* 5EFDC 800FEFDC 04000434 */   ori       $a0, $zero, 0x4
/* 5EFE0 800FEFE0 03004014 */  bnez       $v0, .L800FEFF0
/* 5EFE4 800FEFE4 00000000 */   nop
.L800FEFE8:
/* 5EFE8 800FEFE8 14FC0308 */  j          .L800FF050
/* 5EFEC 800FEFEC FFFF0224 */   addiu     $v0, $zero, -0x1
.L800FEFF0:
/* 5EFF0 800FEFF0 0980063C */  lui        $a2, %hi(g_Status_mp)
/* 5EFF4 800FEFF4 B07BC624 */  addiu      $a2, $a2, %lo(g_Status_mp)
/* 5EFF8 800FEFF8 0000C28C */  lw         $v0, 0x0($a2)
/* 5EFFC 800FEFFC 00000000 */  nop
/* 5F000 800FF000 FFFF4524 */  addiu      $a1, $v0, -0x1
/* 5F004 800FF004 1100A018 */  blez       $a1, .L800FF04C
/* 5F008 800FF008 00000000 */   nop
/* 5F00C 800FF00C 0D000012 */  beqz       $s0, .L800FF044
/* 5F010 800FF010 8888023C */   lui       $v0, (0x88888889 >> 16)
/* 5F014 800FF014 0480043C */  lui        $a0, %hi(D_8003C8C4)
/* 5F018 800FF018 C4C8848C */  lw         $a0, %lo(D_8003C8C4)($a0)
/* 5F01C 800FF01C 89884234 */  ori        $v0, $v0, (0x88888889 & 0xFFFF)
/* 5F020 800FF020 19008200 */  multu      $a0, $v0
/* 5F024 800FF024 10180000 */  mfhi       $v1
/* 5F028 800FF028 82190300 */  srl        $v1, $v1, 6
/* 5F02C 800FF02C 00110300 */  sll        $v0, $v1, 4
/* 5F030 800FF030 23104300 */  subu       $v0, $v0, $v1
/* 5F034 800FF034 C0100200 */  sll        $v0, $v0, 3
.L800FF038:
/* 5F038 800FF038 05008214 */  bne        $a0, $v0, .L800FF050
/* 5F03C 800FF03C 21100000 */   addu      $v0, $zero, $zero
/* 5F040 800FF040 0000C5AC */  sw         $a1, 0x0($a2)
.L800FF044:
/* 5F044 800FF044 14FC0308 */  j          .L800FF050
/* 5F048 800FF048 21100000 */   addu      $v0, $zero, $zero
.L800FF04C:
/* 5F04C 800FF04C FFFF0224 */  addiu      $v0, $zero, -0x1
.L800FF050:
/* 5F050 800FF050 1400BF8F */  lw         $ra, 0x14($sp)
/* 5F054 800FF054 1000B08F */  lw         $s0, 0x10($sp)
/* 5F058 800FF058 1800BD27 */  addiu      $sp, $sp, 0x18
/* 5F05C 800FF05C 0800E003 */  jr         $ra
/* 5F060 800FF060 00000000 */   nop
.size func_800FEEA4, . - func_800FEEA4
