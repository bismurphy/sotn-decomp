// SPDX-License-Identifier: AGPL-3.0-or-later
// Weapon ID #46. Used by weapons:
// Holbein dagger, Blue knuckles
#include "weapon_private.h"
#include "w_046_1.h"
#include "w_046_2.h"
#define g_Animset w_046_1
#define g_Animset2 w_046_2

static u16 D_146000_8017A2B0[] = {
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xE670,
    0xDDEE, 0xD58C, 0xC54A, 0xB508, 0xA8C6, 0x9884, 0x8C42, 0x0000, 0xAD54,
    0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xCD2B, 0xD58C, 0xDE0E,
    0xE670, 0xEEF1, 0xF753, 0xFFD5, 0xFFFF, 0x0000, 0xAD54, 0xB5D6, 0xBE58,
    0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8C42, 0x9884, 0xA8C6, 0xB508, 0xC54A,
    0xD58C, 0xDDEE, 0xE670, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D,
    0xD7DF, 0xFFFF, 0x8000, 0x8C42, 0x9884, 0xA8C6, 0xB508, 0xC54A, 0xD58C,
    0xDDEE, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF,
    0x8000, 0x8000, 0x8C42, 0x9884, 0xA8C6, 0xB508, 0xC54A, 0xD58C, 0x0000,
    0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8000, 0x8000,
    0x8000, 0x8C42, 0x9884, 0xA8C6, 0xB508, 0xC54A, 0x0000, 0xAD54, 0xB5D6,
    0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8C42, 0x9884, 0xA8C6, 0xB508, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB,
    0xCF5D, 0xD7DF, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8C42,
    0x9884, 0xA8C6, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF,
    0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8C42, 0x9884,
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8C42};

static u16 D_146000_8017A3F0[] = {
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xA1C8, 0xC290, 0xD7DF, 0xFFFF, 0xA1C8,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0xAD54,
    0xB5D6, 0xBE58, 0xA5A8, 0xC270, 0xD7DF, 0xFFFF, 0x90C4, 0xA5A8, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58,
    0xA988, 0xC650, 0xD7DF, 0xFFFF, 0x8000, 0x94C4, 0xA988, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xAD68, 0xCA50,
    0xD7DF, 0xFFFF, 0x8000, 0x8000, 0x94A4, 0xAD68, 0x8000, 0x8000, 0x8000,
    0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xB148, 0xCA30, 0xD7DF, 0xFFFF,
    0x8000, 0x8000, 0x8000, 0x98A4, 0xB148, 0x8000, 0x8000, 0x8000, 0x0000,
    0xAD54, 0xB5D6, 0xBE58, 0xB528, 0xCE10, 0xD7DF, 0xFFFF, 0x8000, 0x8000,
    0x8000, 0x8000, 0x9884, 0xB528, 0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6,
    0xBE58, 0xB908, 0xD210, 0xD7DF, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x9C84, 0xB908, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xBCE8,
    0xD1F0, 0xD7DF, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x9C64, 0xBCE8, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xACA6, 0xC9CE, 0xD7DF,
    0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0xACA6,
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000};

static u16 D_146000_8017A530[] = {
    0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x8087,
    0x84A7, 0x88C7, 0x94E7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x0000, 0x99A6,
    0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x810F, 0x8D6F, 0x91AF,
    0xA9CF, 0xBDEF, 0xBDEF, 0xBDEF, 0xBDEF, 0x0000, 0x99A6, 0xAA0A, 0xBA6E,
    0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x8000, 0x8087, 0x84A7, 0x88C7, 0x94E7,
    0x9CE7, 0x9CE7, 0x9CE7, 0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37,
    0xEF9B, 0xFFFF, 0x8000, 0x8000, 0x810F, 0x8D6F, 0x91AF, 0xA9CF, 0xBDEF,
    0xBDEF, 0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF,
    0x8000, 0x8000, 0x8000, 0x8087, 0x84A7, 0x88C7, 0x94E7, 0x9CE7, 0x0000,
    0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x8000, 0x8000,
    0x8000, 0x8000, 0x810F, 0x8D6F, 0x91AF, 0xA9CF, 0x0000, 0x99A6, 0xAA0A,
    0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8087, 0x84A7, 0x88C7, 0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3,
    0xDF37, 0xEF9B, 0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x810F, 0x8D6F, 0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B,
    0xFFFF, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8087,
    0x0000, 0x99A6, 0xAA0A, 0xBA6E, 0xCED3, 0xDF37, 0xEF9B, 0xFFFF, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000};

static u16 D_146000_8017A670[] = {
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xCD2B,
    0xD58C, 0xDE0E, 0xE670, 0xEEF1, 0xF753, 0xFFD5, 0xFFFF, 0x0000, 0xAD54,
    0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xD6B5, 0xD68E, 0xCA0C,
    0xC18A, 0xB928, 0xB0C7, 0xA886, 0xA085, 0x0000, 0xAD54, 0xB5D6, 0xBE58,
    0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xD28F, 0xC60D, 0xBD8B, 0xB529, 0xACC8,
    0xA487, 0xA086, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D,
    0xD7DF, 0xFFFF, 0xC20E, 0xBDAD, 0xB54B, 0xACEA, 0xA4A9, 0xA088, 0x8000,
    0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF,
    0xB9CE, 0xB56D, 0xAD0B, 0xA4AA, 0xA089, 0x8000, 0x8000, 0x8000, 0x0000,
    0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xB18E, 0xAD2D,
    0xA4CC, 0xA08B, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6,
    0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0xAD4E, 0xA4CD, 0xA08C, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB,
    0xCF5D, 0xD7DF, 0xFFFF, 0xA4EF, 0xA08E, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF,
    0xFFFF, 0xA0B0, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x0000, 0xAD54, 0xB5D6, 0xBE58, 0xC6DB, 0xCF5D, 0xD7DF, 0xFFFF, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0x8821,
    0x9484, 0x84C6, 0x814C, 0x9E36, 0x9EDB, 0x8C8D, 0xA174, 0xAC85, 0xC0CC,
    0xC96E, 0xD610, 0xDA93, 0xDF37, 0xEF59, 0x0000, 0xE040, 0xE080, 0xE0C0,
    0xE100, 0xE140, 0xE180, 0xE1C0, 0xE200, 0xE240, 0xE280, 0xE2C0, 0xE300,
    0xE340, 0xE380, 0xE3C0, 0x0000, 0xE044, 0xE084, 0xE0C4, 0xE104, 0xE144,
    0xE184, 0xE1C4, 0xE204, 0xE244, 0xE284, 0xE2C4, 0xE304, 0xE344, 0xE384,
    0xE3C4, 0x0000, 0xE048, 0xE088, 0xE0C8, 0xE108, 0xE148, 0xE188, 0xE1C8,
    0xE208, 0xE248, 0xE288, 0xE2C8, 0xE308, 0xE348, 0xE388, 0xE3C8, 0x0000,
    0xE04C, 0xE08C, 0xE0CC, 0xE10C, 0xE14C, 0xE18C, 0xE1CC, 0xE20C, 0xE24C,
    0xE28C, 0xE2CC, 0xE30C, 0xE34C, 0xE38C, 0xE3CC, 0x0000, 0xE050, 0xE090,
    0xE0D0, 0xE110, 0xE150, 0xE190, 0xE1D0, 0xE210, 0xE250, 0xE290, 0xE2D0,
    0xE310, 0xE350, 0xE390, 0xE3D0, 0x0000, 0xE054, 0xE094, 0xE0D4, 0xE114,
    0xE154, 0xE194, 0xE1D4, 0xE214, 0xE254, 0xE294, 0xE2D4, 0xE314, 0xE354,
    0xE394, 0xE3D4, 0x0000, 0xE058, 0xE098, 0xE0D8, 0xE118, 0xE158, 0xE198,
    0xE1D8, 0xE218, 0xE258, 0xE298, 0xE2D8, 0xE318, 0xE358, 0xE398, 0xE3D8,
    0x0000, 0xE05C, 0xE09C, 0xE0DC, 0xE11C, 0xE15C, 0xE19C, 0xE1DC, 0xE21C,
    0xE25C, 0xE29C, 0xE2DC, 0xE31C, 0xE35C, 0xE39C, 0xE3DC, 0x0000, 0x8821,
    0xB5AD, 0xD6B5, 0x8148, 0x9E31, 0x801F, 0xA08C, 0xC192, 0xA4A7, 0xB0C7,
    0xBD28, 0xC98A, 0xD1CC, 0xDA4D, 0xE2D0, 0x0000, 0x8C25, 0x9C68, 0xA0CD,
    0xAD30, 0xAD93, 0xADF6, 0xC699, 0xE800, 0x8000, 0xA507, 0xB149, 0xBDAC,
    0xCA0F, 0xD672, 0xE2D5, 0x0000, 0x9444, 0xC255, 0xA94B, 0xA5AD, 0x9189,
    0xA316, 0xA087, 0xB509, 0xBDAC, 0x9CE7, 0xB18C, 0xC631, 0xD6B5, 0xEB5A,
    0xFFFF, 0x0000, 0x0421, 0x0C60, 0x08A7, 0x090B, 0x1DF4, 0x4AF9, 0x5100,
    0x69E6, 0x2316, 0x1884, 0x2D27, 0x3DAC, 0x5251, 0x5EB4, 0x6F38, 0x0000,
    0x8000, 0x8820, 0x9041, 0x9C81, 0xA4A2, 0xB0E2, 0xB903, 0xC544, 0xC986,
    0xCDC9, 0xD60C, 0xDA4F, 0xE292, 0xE6D5, 0xEF38, 0x0000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x0000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x0000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x0000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x0000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x0000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000,
};

static u16 D_146000_8017AAB0[] = {
    0x011A, 0x011B, 0x011C, 0x011D, 0x011E,
    0x011F, 0x0120, 0x0121, 0x0122, 0x0000,
};

static u16 D_146000_8017AAC4[] = {
    0x0122, 0x0121, 0x0120, 0x011F, 0x011E,
    0x011D, 0x011C, 0x011B, 0x011A, 0x0000,
};

static Unkstruct_8017AAD8 D_146000_8017AAD8[] = {
    {0x0001, 0x0000, 0x0000, 0x0018, 0x08E0, 0x00, 0xC0, 0x00, 0x01},
    {0x0001, 0x0000, 0x0000, 0x001D, 0x0960, 0x00, 0xC0, 0xC0, 0x00},
    {0x0001, 0x0000, 0x0000, 0x0024, 0x0AE0, 0xC0, 0x00, 0xC0, 0x00},
    {0x0001, 0x0000, 0x0000, 0x0025, 0x08E0, 0xC0, 0x00, 0x80, 0x00},
    {0x0001, 0x0001, 0x0001, 0x0020, 0x0480, 0x40, 0xC0, 0x40, 0x00},
    {0x0000, 0x0000, 0x0000, 0x0030, 0x00E0, 0x80, 0x00, 0xC0, 0x00},
    {0x0000, 0x0000, 0x0001, 0x0018, 0x02E0, 0x80, 0x80, 0x40, 0x00},
    {0x0000, 0x0000, 0x0000, 0x0025, 0x08E0, 0xC0, 0x00, 0x80, 0x00},
    {0x0000, 0x0001, 0x0001, 0x0020, 0x0C80, 0x40, 0xC0, 0xC0, 0x00},
    {0x0001, 0x0000, 0x0000, 0x0030, 0x00F0, 0x80, 0x20, 0xC0, 0x00},
    {0x0001, 0x0000, 0x0000, 0x0018, 0x0600, 0x40, 0x80, 0x40, 0x00},
    {0x0000, 0x0001, 0x0000, 0x0028, 0x0000, 0x40, 0x80, 0x00, 0x00},
    {0x0001, 0x0000, 0x0001, 0x0030, 0x0AF0, 0x20, 0x20, 0xC0, 0x00}};

static s32 D_146000_8017AB90[] = {
    0x00000000, 0x00000004, 0x00000006, 0x00000007, 0x00000008, 0x00000009,
    0x0000000A, 0x0000000A, 0x0000000B, 0x0000000B, 0x0000000C, 0x0000000C,
    0x0000000D, 0x0000000C, 0x0000000B, 0x00000000,
};

static s32 D_146000_8017ABD0[] = {
    0x00000000, 0x00000009, 0x0000000A, 0x0000000C, 0x0000000D, 0x0000000E,
    0x0000000F, 0x0000000F, 0x00000010, 0x00000010, 0x00000011, 0x00000011,
    0x00000012, 0x00000011, 0x00000010, 0x00000000,
};

static s32 D_146000_8017AC10[] = {
    0x00000000, 0x00000030, 0x00000060, 0x00000090, 0x000000C0, 0x000000F0,
    0x00000120, 0x00000150, 0x00000150, 0x00000120, 0x000000F0, 0x000000C0,
    0x00000090, 0x00000060, 0x00000030, 0x00000000,
};

static u16* g_WeaponCluts[] = {
    D_146000_8017A2B0, D_146000_8017A530, D_146000_8017A670, D_146000_8017A3F0};

static s32 g_HandId = HAND_ID;

#include "shared.h"

static void EntityWeaponAttack(Entity* self) {
    Primitive* prim;
    s16 angle;
    s16 baseX, baseY;
    s32 maskedParams;
    s32 temp;
    s16 var_s5;
    s16 temp_s5;
    u8 var_s2;
    Unkstruct_8017AAD8* temp_s3;

    maskedParams = self->params >> 8 & 0x7F;
    if (g_HandId) {
        var_s2 = 0x80;
        var_s5 = 0x18;
    } else {
        var_s5 = 0;
        var_s2 = 0;
    }
    temp_s3 = &D_146000_8017AAD8[maskedParams];
    if (self->step == 0) {
        self->posX.val = PLAYER.posX.val;
        self->posY.val = PLAYER.posY.val;
        self->facingLeft = PLAYER.facingLeft;
        self->primIndex = g_api.AllocPrimitives(PRIM_GT4, 1);
        if (self->primIndex == -1) {
            DestroyEntity(self);
            return;
        }
        prim = &g_PrimBuf[self->primIndex];
        if (temp_s3->flipX) {
            prim->u0 = prim->u2 = 0x40;
            prim->u1 = prim->u3 = 0;
        } else {
            prim->u0 = prim->u2 = 0;
            prim->u1 = prim->u3 = 0x40;
        }
        if (temp_s3->flipY) {
            prim->v0 = prim->v1 = var_s2 | 0x40;
            prim->v2 = prim->v3 = var_s2;
        } else {
            prim->v0 = prim->v1 = var_s2;
            prim->v2 = prim->v3 = var_s2 | 0x40;
        }

        prim->r0 = prim->r1 = prim->r2 = prim->r3 = temp_s3->r;
        prim->g0 = prim->g1 = prim->g2 = prim->g3 = temp_s3->g;
        prim->b0 = prim->b1 = prim->b2 = prim->b3 = temp_s3->b;

        prim->tpage = 0x19;
        prim->priority = PLAYER.zPriority + 2;
        prim->drawMode = DRAW_UNK_200 | DRAW_UNK_100 | DRAW_TPAGE2 |
                         DRAW_TPAGE | DRAW_COLORS | DRAW_TRANSP;

        self->flags = FLAG_HAS_PRIMS | FLAG_POS_PLAYER_LOCKED | FLAG_UNK_20000;
        temp = maskedParams & 0xFFFF;
        if (!temp) {
            SetWeaponProperties(self, 0);
            self->hitboxWidth = 15;
            self->hitboxHeight = 20;
            self->hitboxOffY = -5;
        }
        self->ext.weapon.unk82 = 20;
        if (self->facingLeft) {
            self->ext.weapon.unk82 = -20;
        }
        self->ext.weapon.unk80 = -5;
        if (g_Player.status & PLAYER_STATUS_UNK_20) {
            self->ext.weapon.unk80 = 11;
        }
        self->posX.i.hi = self->posX.i.hi + self->ext.weapon.unk82;
        self->posY.i.hi = self->posY.i.hi + self->ext.weapon.unk80;
        DestroyEntityWeapon(true);
        self->ext.factory.unk84 = 0;
        if (!temp) {
            g_api.PlaySfx(SFX_WEAPON_SWISH_A);
        }
        self->rotZ = temp_s3->unk4;
        self->ext.timer.t = temp_s3->unk3;
        self->ext.weapon.unk7E = 0;
        g_Player.timers[9] = 4;
        self->step++;
    }

    if (maskedParams == 0) {
        if (self->ext.weapon.unk7E == 3) {
            g_api.CreateEntFactoryFromEntity(self, WFACTORY(0x32, 1), 0);
        }
        if (self->ext.weapon.unk7E == 6) {
            g_api.CreateEntFactoryFromEntity(self, WFACTORY(0x32, 2), 0);
        }
        if (++self->ext.factory.unk84 == 8) {
            g_api.PlaySfxVolPan(SFX_WEAPON_SWISH_A, 0x50, 0);
        }
    }

    prim = &g_PrimBuf[self->primIndex];
    if (temp_s3->clut) {
        prim->clut = var_s5 + D_146000_8017AAC4[self->ext.weapon.unk7E];
    } else {
        prim->clut = var_s5 + D_146000_8017AAB0[self->ext.weapon.unk7E];
    }

    if (++self->ext.weapon.unk7E >= 9) {
        DestroyEntity(self);
        return;
    }

    temp_s5 = self->ext.timer.t;
    baseX = PLAYER.posX.i.hi + self->ext.weapon.unk82;
    baseY = PLAYER.posY.i.hi + self->ext.weapon.unk80;
    angle = self->rotZ;

    angle += 0x600;
    if (self->facingLeft) {
        prim->x0 = baseX - (((rcos(angle) >> 4) * temp_s5) >> 8);
    } else {
        prim->x0 = baseX + (((rcos(angle) >> 4) * temp_s5) >> 8);
    }
    prim->y0 = baseY - (((rsin(angle) >> 4) * temp_s5) >> 8);

    angle -= 0x400;
    if (self->facingLeft) {
        prim->x1 = baseX - (((rcos(angle) >> 4) * temp_s5) >> 8);
    } else {
        prim->x1 = baseX + (((rcos(angle) >> 4) * temp_s5) >> 8);
    }
    prim->y1 = baseY - (((rsin(angle) >> 4) * temp_s5) >> 8);

    angle -= 0x800;
    if (self->facingLeft) {
        prim->x2 = baseX - (((rcos(angle) >> 4) * temp_s5) >> 8);
    } else {
        prim->x2 = baseX + (((rcos(angle) >> 4) * temp_s5) >> 8);
    }
    prim->y2 = baseY - (((rsin(angle) >> 4) * temp_s5) >> 8);

    angle += 0x400;
    if (self->facingLeft) {
        prim->x3 = baseX - (((rcos(angle) >> 4) * temp_s5) >> 8);
    } else {
        prim->x3 = baseX + (((rcos(angle) >> 4) * temp_s5) >> 8);
    }
    prim->y3 = baseY - (((rsin(angle) >> 4) * temp_s5) >> 8);
}

static s32 func_ptr_80170004(Entity* self) {
    const int PrimCount = 0x20;
    Primitive* prim;
    s16 maskedParams;
    s32 posX, posY;
    s32 sp20;
    s32 sp28;
    s32 sp30;
    s32 a0;
    s32 a1;
    s32 half_i;
    s32 s0;
    s32 angle;
    s32 s7;
    s32 temp_v1_2;
    s32 v1;
    s32 temp_v1_6;
    s32 var_a0;
    s32 s4;
    s32 i;
    s32 s6;
    s32 var_v1_2;

    maskedParams = self->params & 0x7F00;
    self->posX.i.hi = PLAYER.posX.i.hi;
    self->posY.i.hi = PLAYER.posY.i.hi;
    switch (self->step) {
    case 0:
        self->primIndex = g_api.AllocPrimitives(PRIM_G4, PrimCount);
        if (self->primIndex == -1) {
            DestroyEntity(self);
            return;
        }

        self->flags = FLAG_HAS_PRIMS | FLAG_POS_PLAYER_LOCKED | FLAG_UNK_20000;
        prim = &g_PrimBuf[self->primIndex];
        for (i = 0; i < PrimCount; i++) {
            prim->drawMode = DRAW_UNK_200 | DRAW_UNK_100 | DRAW_TPAGE2 |
                             DRAW_TPAGE | DRAW_COLORS | DRAW_TRANSP;
            prim->priority = PLAYER.zPriority + 4;
            prim = prim->next;
        }
        SetWeaponProperties(self, 0);
        DestroyEntityWeapon(true);
        if (g_Player.status & PLAYER_STATUS_UNK_20) {
            self->ext.weapon_046.unk7C = -0x200;
            self->ext.weapon_046.unk94 = -0x200;
            self->ext.weapon_046.unk90 = 0x280;
            self->ext.weapon_046.unk80 = 0x2E;
            self->ext.weapon_046.unk84 = 0x80;
            self->rotPivotX = -0x20;
            self->rotPivotY = 4;
            self->hitboxOffX = 0xB;
            self->hitboxOffY = 2;
            if (maskedParams != 0) {
                self->hitboxWidth = 0xC;
                self->hitboxHeight = 0x1C;
            } else {
                self->hitboxWidth = 8;
                self->hitboxHeight = 0x18;
            }
        } else {
            self->ext.weapon_046.unk7C = -0x500;
            self->ext.weapon_046.unk94 = -0x500;
            self->ext.weapon_046.unk90 = 0x700;
            self->ext.weapon_046.unk80 = 0x13;
            self->ext.weapon_046.unk84 = 0x200;
            self->rotPivotY = -0x10;
            self->hitboxOffX = 8;
            self->rotPivotX = 0;
            self->hitboxOffY = -0x13;
            if (maskedParams != 0) {
                self->hitboxWidth = 0x13;
                self->hitboxHeight = 0x1A;
            } else {
                self->hitboxWidth = 0x10;
                self->hitboxHeight = 0x16;
            }
        }
        g_api.PlaySfx(SFX_WEAPON_SWISH_C);
        self->ext.weapon_046.unk98 = 0x100;
        g_Player.timers[9] = 4;
        self->step++;
        break;
    case 1:
        self->ext.weapon_046.unk7C += self->ext.weapon_046.unk84;
        if (self->ext.weapon_046.unk7C >= self->ext.weapon_046.unk90) {
            self->step++;
        }
        break;
    case 2:
        self->ext.weapon_046.unk98 -= 0x10;
        self->ext.weapon_046.unk94 += self->ext.generic.unk84.unk / 4;

        if (self->ext.weapon_046.unk94 >= self->ext.weapon_046.unk90) {
            self->ext.weapon_046.unk94 = self->ext.weapon_046.unk90;
        }
        if (self->ext.weapon_046.unk98 < 0x80) {
            self->hitboxState = 0;
        }
        if (self->ext.weapon_046.unk98 <= 0) {
            DestroyEntity(self);
            return;
        }
        break;
    }

    posX = self->posX.i.hi + self->rotPivotX;
    posY = self->posY.i.hi + self->rotPivotY;
    sp28 = self->ext.weapon_046.unk94;
    sp20 = (self->ext.weapon_046.unk7C - self->ext.weapon_046.unk94) / 16;
    s7 = self->ext.weapon_046.unk80;
    sp30 = self->ext.weapon_046.unk98;
    prim = &g_PrimBuf[self->primIndex];

    for (i = 0; i < PrimCount; i++) {
        half_i = i >> 1;
        temp_v1_2 = half_i + 1;

        v1 = D_146000_8017AC10[temp_v1_2 % 16] * sp30 / 256;
        a1 = D_146000_8017AC10[half_i] * sp30 / 256;

        if (maskedParams == 0) {
            prim->r0 = v1 * 0x60 / 256;
            prim->g0 = v1 * 0x60 / 256;
            prim->b0 = v1 * 0xC0 / 256;

            prim->r2 = a1 * 0x60 / 256;
            prim->g2 = a1 * 0x60 / 256;
            prim->b2 = a1 * 0xC0 / 256;

            prim->r1 = prim->g1 = prim->b1 = 0;
            prim->r3 = prim->g3 = prim->b3 = 0;

            a1 = i >> 1;
            temp_v1_6 = a1 + 1;
            var_a0 = D_146000_8017AB90[temp_v1_6 % 16];
            var_v1_2 = D_146000_8017AB90[a1];
        } else {
            prim->r0 = v1 * 0xC0 / 256;
            prim->g0 = v1 * 0x60 / 256;
            prim->b0 = v1 * 0x60 / 256;

            prim->r2 = a1 * 0xC0 / 256;
            prim->g2 = a1 * 0x60 / 256;
            prim->b2 = a1 * 0x60 / 256;

            prim->r1 = prim->g1 = prim->b1 = 0;
            prim->r3 = prim->g3 = prim->b3 = 0;

            a1 = i >> 1;
            a0 = a1 + 1;
            var_a0 = D_146000_8017ABD0[a0 % 16];
            var_v1_2 = D_146000_8017ABD0[a1];
        }

        if (i & 1) {
            s4 = s7 + var_a0;
            s6 = s7 + var_v1_2;
        } else {
            s4 = s7 - var_a0;
            s6 = s7 - var_v1_2;
        }
        s0 = i >> 1; // weirdly can't re-use `half_i` here...
        angle = ((s0 + 1) * sp20) + sp28;
        prim->x0 = posX + (((rcos(angle) >> 4) * s7) >> 8);
        prim->y0 = posY - (((rsin(angle) >> 4) * s7) >> 8);
        prim->x1 = posX + (((rcos(angle) >> 4) * s4) >> 8);
        prim->y1 = posY - (((rsin(angle) >> 4) * s4) >> 8);

        angle = (s0 * sp20) + sp28;
        prim->x2 = posX + (((rcos(angle) >> 4) * s7) >> 8);
        prim->y2 = posY - (((rsin(angle) >> 4) * s7) >> 8);
        prim->x3 = posX + (((rcos(angle) >> 4) * s6) >> 8);
        prim->y3 = posY - (((rsin(angle) >> 4) * s6) >> 8);

        prim = prim->next;
    }

    if (self->facingLeft) {
        prim = &g_PrimBuf[self->primIndex];
        a0 = self->posX.i.hi * 2;
        for (i = 0; i < PrimCount; i++) {
            prim->x0 = a0 - prim->x0;
            prim->x1 = a0 - prim->x1;
            prim->x2 = a0 - prim->x2;
            prim->x3 = a0 - prim->x3;
            prim = prim->next;
        }
    }
}

static void func_ptr_80170008(Entity* self) {}

static void func_ptr_8017000C(Entity* self) {}

static s32 func_ptr_80170010(Entity* self) {}

static s32 func_ptr_80170014(Entity* self) {}

static int GetWeaponId(void) { return 46; }

static void EntityWeaponShieldSpell(Entity* self) {}

static void func_ptr_80170024(Entity* self) {}

static void func_ptr_80170028(Entity* self) {}

static void WeaponUnused2C(void) {}

static void WeaponUnused30(void) {}

static void WeaponUnused34(void) {}

static void WeaponUnused38(void) {}

static void WeaponUnused3C(void) {}
