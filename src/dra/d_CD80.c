#include "dra.h"

Vram g_Vram = {
    {0x0000, 0x0000, 0x0100, 0x0100}, {0x0000, 0x0000, 0x0400, 0x0200},
    {0x0000, 0x0000, 0x0200, 0x00f0}, {0x0380, 0x0180, 0x0010, 0x0001},
    {0x0000, 0x0000, 0x0200, 0x0200}, {0x0000, 0x00f0, 0x0100, 0x0010},
    {0x0100, 0x00f0, 0x0100, 0x0010}, {0x0200, 0x00f0, 0x0100, 0x0010},
    {0x0200, 0x0000, 0x0100, 0x00f0}, {0x0080, 0x0100, 0x0180, 0x0100},
    {0x0200, 0x0000, 0x0040, 0x00f0}, {0x0280, 0x0000, 0x0080, 0x00f0},
    {0x0200, 0x0000, 0x0020, 0x0080}, {0x0340, 0x0100, 0x0040, 0x0100},
    {0x0000, 0x0000, 0x0280, 0x0200}};