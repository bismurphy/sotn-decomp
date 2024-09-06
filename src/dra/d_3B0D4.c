// SPDX-License-Identifier: AGPL-3.0-only
#include "dra.h"

u16 D_800DB0D4[] = {
    0x0000, 0x0842, 0x1084, 0x18c6, 0x2108, 0x294a, 0x318c, 0x39ce,
    0x4631, 0x4e73, 0x56b5, 0x5ef7, 0x6739, 0x6f7b, 0x77bd, 0x7fff,
};

u16 D_800DB0F4[] = {
    0x8000, 0x8485, 0x90c5, 0x9907, 0x996a, 0x9d69, 0xa9ae, 0xd250,
    0xd6d3, 0xf339, 0x9172, 0x91d4, 0x8df8, 0x9e76, 0x8048, 0x80b1,
};

u16 D_800DB114[] = {
    0x0000, 0x8841, 0x8c80, 0xad60, 0xd6a0, 0xdfe0, 0xd607, 0xeed2, 0xfffc,
    0x80ee, 0x81f4, 0x8f5f, 0xbfff, 0x800d, 0x8010, 0x8016, 0x0000, 0x87e1,
    0xb023, 0xd427, 0xf865, 0xfd61, 0xfe2d, 0xff47, 0x8421, 0x9c2d, 0xa0cd,
    0x9d34, 0xa19b, 0xba3e, 0xe39f, 0x843f, 0x0000, 0x8421, 0x8c63, 0x94a5,
    0x9ce7, 0xb5ad, 0xb5ad, 0xc210, 0x83e0, 0x8426, 0x842d, 0x8431, 0x8437,
    0x992d, 0xadd0, 0xac34, 0x0000, 0x90a4, 0x80e0, 0x81a3, 0xb6a6, 0xa4c5,
    0xb96d, 0xd270, 0xfc1f, 0x84c8, 0x8d0c, 0x95b0, 0x8db2, 0xa214, 0xa298,
    0xc2b8, 0x0000, 0x90a4, 0xb4a3, 0xc5a8, 0xe2ce, 0x9907, 0xb1cc, 0xcab2,
    0xfc1f, 0x84c8, 0x8d0c, 0x95b0, 0x8db2, 0xa214, 0xa298, 0xc2b8, 0x0000,
    0x8421, 0x8c68, 0x88ae, 0x950f, 0x9d96, 0xbabb, 0xb2c8, 0x9045, 0xa487,
    0xb8ea, 0xc92d, 0xd9d1, 0xe676, 0xf71a, 0xfffe, 0x0000, 0x8421, 0x8c68,
    0x88ae, 0x950f, 0x9d96, 0xb2c8, 0x801e, 0x9045, 0xa487, 0xb8ed, 0xc92d,
    0xd9d1, 0xe676, 0xf71a, 0xfffe,
};

u16 D_800DB1F4[] = {
    0x0000, 0x8421, 0x84ab, 0x8d2f, 0x91d6, 0x929b, 0x994a, 0xa5ce, 0x8421,
    0x9ce7, 0x0000, 0x98a5, 0xa94a, 0xbe2e, 0xc2f7, 0xf39c, 0x0000, 0x8421,
    0x84ab, 0x8d2f, 0x91d6, 0x929b, 0x994a, 0xa5ce, 0x8421, 0x9ce7, 0x845b,
    0x98a5, 0xa94a, 0xbe2e, 0xc2f7, 0xf39c, 0x0000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0xffe0, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x0000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0xbdef, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x0000, 0x8421, 0xa465, 0xbc88, 0xc8ec, 0xe5cf, 0x9db5, 0xbebd,
    0xff9a, 0x8888, 0x98f0, 0x800d, 0xff35, 0x8019, 0xa17f, 0x801f, 0x0000,
    0x8000, 0x9802, 0x9423, 0xa866, 0xb908, 0x90ec, 0xa990, 0xa9f6, 0x8023,
    0x8049, 0x81e1, 0xd1a9, 0x81c0, 0x8360, 0x801f, 0x0000, 0x8001, 0x8008,
    0x800e, 0x8015, 0x801a, 0x801f, 0x8d3f, 0x95df, 0x9e5f, 0xa6bf, 0xaf1f,
    0xab7f, 0xb7df, 0xd7ff, 0xffff, 0x0000, 0x8cef, 0x8d30, 0x9171, 0x95b3,
    0x99f4, 0x9e35, 0xa277, 0xa6b8, 0xaafa, 0xb71b, 0xc35c, 0xd37c, 0xdf9d,
    0xf3de, 0xffff, 0x0000, 0x8cef, 0x8d10, 0x9151, 0x9592, 0x99b3, 0x9df4,
    0xa235, 0xa677, 0xaa97, 0xaeb8, 0xb2d9, 0xb6f9, 0xbb1a, 0xbf3b, 0xc35c,
    0x0000, 0x88b0, 0x88f1, 0x8d33, 0x9175, 0x95b7, 0x95f8, 0x9a3a, 0x9e7c,
    0xa2be, 0xb2de, 0xc31e, 0xd35e, 0xdf9e, 0xefde, 0xffff, 0x8000, 0x8421,
    0x84ab, 0x8d2f, 0x91d6, 0x929b, 0x994a, 0xa5ce, 0x8421, 0x9ce7, 0x8000,
    0x98a5, 0xa94a, 0xbe2e, 0xc2f7, 0xf39c, 0x8129, 0x814a, 0x816b, 0x818c,
    0x81ad, 0x81ce, 0x81ef, 0x81ce, 0x81ad, 0x818c, 0x816b, 0x814a, 0x8129,
    0x8108, 0x80e7, 0x80c6, 0xa529, 0xa94a, 0xad6b, 0xb18c, 0xb5ad, 0xb9ce,
    0xbdef, 0xb9ce, 0xb5ad, 0xb18c, 0xad6b, 0xa94a, 0xa529, 0xa108, 0x9ce7,
    0x98c6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
