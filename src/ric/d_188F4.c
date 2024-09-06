// SPDX-License-Identifier: AGPL-3.0-only
#include "ric.h"

u8 D_801548F4[6][8] = {
    0x00, 0x50, 0x10, 0x50, 0x00, 0x60, 0x10, 0x60, 0x10, 0x50, 0x20, 0x50,
    0x10, 0x60, 0x20, 0x60, 0x70, 0x40, 0x80, 0x40, 0x70, 0x50, 0x80, 0x50,
    0x70, 0x30, 0x78, 0x30, 0x70, 0x38, 0x78, 0x38, 0x78, 0x30, 0x80, 0x30,
    0x78, 0x38, 0x80, 0x38, 0x70, 0x38, 0x78, 0x38, 0x77, 0x40, 0x78, 0x40};

AnimationFrame D_80154924[] = {
    {2, FRAME(1, 0)},  {2, FRAME(2, 0)},
    {2, FRAME(3, 0)},  {2, FRAME(4, 0)},
    {2, FRAME(5, 0)},  {2, FRAME(6, 0)},
    {2, FRAME(7, 0)},  {2, FRAME(8, 0)},
    {2, FRAME(9, 0)},  {2, FRAME(10, 0)},
    {2, FRAME(11, 0)}, {2, FRAME(12, 0)},
    {2, FRAME(13, 0)}, A_END};
