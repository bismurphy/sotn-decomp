// SPDX-License-Identifier: AGPL-3.0-or-later
#include "nz0.h"

void Update();
void HitDetection();
void UpdateRoomPosition();
void InitRoomEntities();
void UpdateStageEntities();

extern s16** OVL_EXPORT(spriteBanks)[];
extern u_long* OVL_EXPORT(cluts)[];
extern LayoutEntity* OVL_EXPORT(pStObjLayoutHorizontal)[];
extern u_long* OVL_EXPORT(gfxBanks)[];
extern RoomDef OVL_EXPORT(rooms_layers)[];
extern RoomHeader OVL_EXPORT(rooms)[];

AbbreviatedOverlay OVL_EXPORT(Overlay) = {
    .Update = Update,
    .HitDetection = HitDetection,
    .UpdateRoomPosition = UpdateRoomPosition,
    .InitRoomEntities = InitRoomEntities,
    .rooms = OVL_EXPORT(rooms),
    .spriteBanks = OVL_EXPORT(spriteBanks),
    .cluts = OVL_EXPORT(cluts),
    .objLayoutHorizontal = OVL_EXPORT(pStObjLayoutHorizontal),
    .tileLayers = OVL_EXPORT(rooms_layers),
    .gfxBanks = OVL_EXPORT(gfxBanks),
    .UpdateStageEntities = UpdateStageEntities,
};

#include "sprite_banks.h"
#include "palette_def.h"
#include "layers.h"

static u_long* D_8018047C[] = {
    GFX_BANK_NONE,
    GFX_ENTRY(0, 0, 0, 0, NULL),
    GFX_TERMINATE(),
};

extern u8 D_8018A508[];
static u_long* D_80180490[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_TERMINATE(),
};

extern u8 D_801858C0[];
extern u8 D_801867B0[];
extern u8 D_80188BB8[];
extern u8 D_80189810[];
extern u8 D_8018BCB8[];
static u_long* D_801804A4[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x080, 128, 128, D_801858C0),
    GFX_ENTRY(0x100, 0x0A0, 128, 128, D_801867B0),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x100, 128, 128, D_80188BB8),
    GFX_ENTRY(0x100, 0x120, 128, 128, D_80189810),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_801873A0[];
static u_long* D_801804F4[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x080, 128, 128, D_801873A0),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_80184CE4[];
extern u8 D_8018B0B4[];
static u_long* D_80180520[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x080, 128, 128, D_801873A0),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x0E0, 128, 128, D_80184CE4),
    GFX_ENTRY(0x100, 0x100, 128, 128, D_80188BB8),
    GFX_ENTRY(0x100, 0x120, 128, 128, D_80189810),
    GFX_ENTRY(0x180, 0x120, 128, 128, D_8018B0B4),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_8018057C[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x100, 128, 128, D_80188BB8),
    GFX_ENTRY(0x100, 0x120, 128, 128, D_80189810),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_801805B4[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_801805D4[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x080, 128, 128, D_801858C0),
    GFX_ENTRY(0x100, 0x0A0, 128, 128, D_801867B0),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x100, 128, 128, D_80188BB8),
    GFX_ENTRY(0x100, 0x120, 128, 128, D_80189810),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_80188058[];
static u_long* D_80180624[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x0C0, 128, 128, D_80188058),
    GFX_ENTRY(0x180, 0x120, 128, 128, D_8018B0B4),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_8018065C[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_8018AAD0[];
static u_long* D_8018067C[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x0E0, 128, 128, D_8018AAD0),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_801806A8[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x120, 128, 128, D_8018B0B4),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_80184154[];
static u_long* D_801806D4[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x080, 128, 128, D_801858C0),
    GFX_ENTRY(0x100, 0x0A0, 128, 128, D_801867B0),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x0C0, 128, 128, D_80184154),
    GFX_ENTRY(0x100, 0x0E0, 128, 128, D_80184CE4),
    GFX_ENTRY(0x180, 0x120, 128, 128, D_8018B0B4),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_801956A4[];
static u_long* D_80180730[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x040, 128, 128, D_801956A4),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x100, 0x0C0, 128, 128, D_80184154),
    GFX_ENTRY(0x100, 0x0E0, 128, 128, D_80184CE4),
    GFX_ENTRY(0x180, 0x0C0, 128, 128, D_80188058),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_8018CC34[];
static u_long* D_80180780[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x0C0, 128, 128, D_8018CC34),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_8018D788[];
extern u8 D_8018E27C[];
extern u8 D_8018EC64[];
extern u8 D_8018F528[];
extern u8 D_80190298[];
static u_long* D_801807AC[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x080, 128, 128, D_8018D788),
    GFX_ENTRY(0x100, 0x0A0, 128, 128, D_8018E27C),
    GFX_ENTRY(0x180, 0x080, 128, 128, D_8018EC64),
    GFX_ENTRY(0x100, 0x0C0, 128, 128, D_8018F528),
    GFX_ENTRY(0x100, 0x0E0, 128, 128, D_80190298),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_80190A58[];
static u_long* D_801807FC[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x140, 128, 128, D_80190A58),
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

static u_long* D_80180828[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

extern u8 D_80191B18[];
extern u8 D_80192E2C[];
static u_long* D_80180848[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x100, 0x080, 128, 128, D_80191B18),
    GFX_ENTRY(0x100, 0x0A0, 128, 128, D_80192E2C),
    GFX_TERMINATE(),
};

static u_long* D_80180868[] = {
    GFX_BANK_COMPRESSED,
    GFX_ENTRY(0x180, 0x0A0, 128, 128, D_8018A508),
    GFX_ENTRY(0x180, 0x160, 128, 128, D_8018BCB8),
    GFX_TERMINATE(),
};

u_long* OVL_EXPORT(gfxBanks)[] = {
    D_8018047C, D_80180848, D_801807FC, D_801804F4, D_80180490,
    D_801805B4, D_80180490, D_80180780, D_801806A8, D_8018065C,
    D_80180730, D_8018057C, D_80180490, D_80180624, D_80180490,
    D_8018067C, D_801807AC, D_801805D4, D_801806D4, D_80180520,
    D_801804A4, D_80180490, D_80180828, D_80180490, D_80180868,
};
