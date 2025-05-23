// SPDX-License-Identifier: AGPL-3.0-or-later
#include "weapon_private.h"

#include "../destroy_entity.h"

static void LoadWeaponPalette(s32 clutIndex) {
    RECT dstRect;
    u16* src;
    u16* dst;
    s32 i;

#if !defined(W_029)
    dst = src = g_WeaponCluts[clutIndex];
    dst = D_8006EDCC[g_HandId];
#else
    dst = D_8006EDCC[g_HandId];
    src = g_WeaponCluts[clutIndex];
#endif
    if (src == NULL) {
        return;
    }

    for (i = 0; i < LEN(*D_8006EDCC); i++) {
        *dst++ = *src++;
    }

#if !defined(W_029)
    dstRect.w = 0x100;
    dstRect.h = 3;
    dstRect.x = 0;
    dstRect.y = 0xF1;
#else
    dstRect.x = 0;
    dstRect.w = 0x100;
    dstRect.h = 3;
    dstRect.y = 0xF1;
#endif
    LoadImage(&dstRect, &D_8006EDCC);
}

static void SetSpriteBank1(SpriteParts* animset) {
    SpritePart** spriteBankDst = g_api.o.spriteBanks;

    spriteBankDst += 0x10;
    if (g_HandId != 0) {
        spriteBankDst += 2;
    }
    *spriteBankDst = animset;
}

static void SetSpriteBank2(SpriteParts* animset) {
    SpritePart** spriteBankDst = g_api.o.spriteBanks;

    spriteBankDst += 0x11;
    if (g_HandId != 0) {
        spriteBankDst += 2;
    }
    *spriteBankDst = animset;
}

#if !defined(W_029) && !defined(W_030) && !defined(W_044) && !defined(W_051)
static void SetWeaponAnimation(u8 anim) {
    g_CurrentEntity->ext.weapon.anim = anim;
    g_CurrentEntity->poseTimer = 0;
    g_CurrentEntity->pose = 0;
}
#endif

#if !defined(W_044)

#include "../decelerate.h"

#include "../set_speed_x.h"

#endif

#if !defined(W_030) && !defined(W_051)
static void DestroyEntityWeapon(bool arg0) {
    if (arg0 == false) {
        DestroyEntity(&g_Entities[E_WEAPON]);
    }
    if (arg0 == true && g_Player.unk48 != 0) {
        DestroyEntity(&g_Entities[E_WEAPON]);
        g_Player.unk48 = 0;
    }
}
#endif

static void SetWeaponProperties(Entity* self, s32 kind) {
    Equipment equip;

    g_api.GetEquipProperties(g_HandId, &equip, self->ext.weapon.equipId);
    switch (kind) {
    case 0:
    case 1:
        self->attack = equip.attack;
        self->attackElement = equip.element;
        self->hitboxState = equip.hitType;
        self->nFramesInvincibility = equip.enemyInvincibilityFrames;
        self->stunFrames = equip.stunFrames;
        self->hitEffect = equip.hitEffect;
        self->entityRoomIndex = equip.criticalRate;
        g_api.func_80118894(self);
        break;
    case 2:
        self->attack = equip.attack;
        break;
    }
    if (self->hitboxState == 4) {
        self->attack = 0xFF;
    }
}
