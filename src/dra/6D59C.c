#define INCLUDE_ASM_NEW
#include "dra.h"
#include "sfx.h"
#include "player.h"

// Game Buttons unofficially refers to buttons used in playing the game.
// Direction, action and shoulder buttons. Any button except start or select.
#define GAMEBUTTONS (~(PAD_START | PAD_SELECT))

u8 g_D_800ACF18[] = {10, 8, 8, 6, 6, 4, 4,   4,   4, 4,
                     4,  4, 4, 4, 4, 4, 255, 255, 0, 0};

void func_8010D59C(void) {
    byte stackpad[40];
    Primitive* prim;
    s32 i;

    if (g_Entities[1].ext.ent1.unk0 != 0) {
        return;
    }
    switch (PLAYER.ext.player.unkAC) {
    case 0x5D:
    case 0x5E:
    case 0x60:
    case 0x61:
    case 0x62:
        g_Entities[1].ext.ent1.unk2 = 10;
        return;
    }
    if ((g_Player.padTapped & GAMEBUTTONS) ||
        ((g_Player.padHeld ^ g_Player.padPressed) & g_Player.padHeld &
         GAMEBUTTONS) ||
        (PLAYER.velocityY > FIX(0.5))) {
        g_Entities[1].ext.ent1.unk2 = 0;
        g_Entities[1].ext.ent1.unk3 = 0;
    } else {
        if (g_Entities[1].ext.ent1.unk2 >= 10) {
            return;
        }
        if (g_Entities[1].ext.ent1.unk3 == 0) {
            g_Entities[1].ext.ent1.unk3 =
                g_D_800ACF18[g_Entities[1].ext.ent1.unk2];
        }
        if (!(--g_Entities[1].ext.ent1.unk3 & 0xFF)) {
            g_Entities[1].ext.ent1.unk2++;
            g_Entities[1].ext.ent1.unk3 =
                g_D_800ACF18[g_Entities[1].ext.ent1.unk2];
        }
    }
    if (g_Entities[1].animFrameIdx != 0) {
        g_Entities[1].animFrameIdx--;
        return;
    }
    prim = &g_PrimBuf[g_Entities[1].primIndex];
    for (i = 0; i < 6; i++) {
        if (i == g_Entities[1].entityId) {
            prim->r0 = prim->g0 = prim->b0 = 0x80;
            prim->x0 = PLAYER.posX.i.hi;
            prim->y0 = PLAYER.posY.i.hi;
            prim->x1 = PLAYER.animCurFrame;
            prim->y1 = 0;
            prim->x2 = PLAYER.facingLeft;
            prim->y2 = PLAYER.palette;
        }
        prim = prim->next;
    }
    g_Entities[1].animFrameIdx = 2;
    g_Entities[1].entityId++;
    if (g_Entities[1].entityId >= 6) {
        g_Entities[1].entityId = 0;
    }
}

u8 g_shadowOpacityReductionTable[] = {
    4, 4, 4, 4, 6, 6, 6, 6, 8, 8, 16, 16, 16, 16, 16, 16};
u8 g_D_800ACF3C[] = {8,  12, 16, 20, 24, 28, 32, 32,
                     32, 32, 32, 32, 32, 32, 32, 32};

void func_8010D800(void) {
    byte pad[0x28];
    Unkstruct_800ECBF8_1* current_thing;
    Primitive* prim;
    s32 entNum;
    s32 i;
    u8 temp_t0;
    u8 temp_t1;
    u8 temp_t2;

    i = 0;
    prim = &g_PrimBuf[g_Entities[1].primIndex];
    temp_t2 = g_Entities[1].ext.ent1.unk1;
    temp_t1 = g_shadowOpacityReductionTable[g_Entities[1].ext.ent1.unk2];
    temp_t0 = g_D_800ACF3C[g_Entities[1].ext.ent1.unk2];

    current_thing = &D_80097D1C[1];
    for (i = 0; i < 6; prim = prim->next, i++) {
        if (temp_t0 < prim->r0) {
            prim->r0 -= temp_t1;
        }
        if ((prim->r0 < 0x70) && (prim->b0 < 0xF0)) {
            prim->b0 += 6;
        }
        if (prim->r0 < 0x58) {
            prim->y1 = 0x10;
        } else {
            prim->y1 = 0;
        }
        if (temp_t0 >= prim->r0) {
            prim->x1 = 0;
        }
        if (!((i ^ g_blinkTimer) & 1)) {
            continue;
        }

        entNum = ((i / 2) + 1);
        g_Entities[entNum].posX.i.hi = prim->x0;
        g_Entities[entNum].posY.i.hi = prim->y0;
        g_Entities[entNum].animCurFrame = prim->x1;
        g_Entities[entNum].blendMode = prim->y1;
        g_Entities[entNum].facingLeft = prim->x2;
        g_Entities[entNum].palette = prim->y2;
        g_Entities[entNum].zPriority = PLAYER.zPriority - 2;
        if (temp_t2) {
            g_Entities[entNum].animCurFrame = 0;
            prim->x1 = 0;
        }

        current_thing->unk18 = current_thing->unk1C = current_thing->unk20 =
            current_thing->unk24 = current_thing->unk1A = current_thing->unk1E =
                current_thing->unk22 = current_thing->unk26 = prim->r0;
        current_thing->unk19 = current_thing->unk1D = current_thing->unk21 =
            current_thing->unk25 = prim->b0;
        current_thing->unk1B = 1;
        current_thing++;
    }
}

void func_8010DA2C(s32* arg0) {
    g_CurrentEntity->unk4C = arg0;
    g_CurrentEntity->animFrameDuration = 0;
    g_CurrentEntity->animFrameIdx = 0;
}

void func_8010DA48(u32 arg0) {
    g_CurrentEntity->ext.generic.unkAC = arg0;
    g_CurrentEntity->animFrameDuration = 0;
    g_CurrentEntity->animFrameIdx = 0;
}

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8010DA70);

u32 UpdateUnarmedAnim(s8* frameProps, u16** frames) {
    u16* frameIndex;

    frameIndex =
        frames[g_CurrentEntity->ext.generic.unkAC] + PLAYER.animFrameIdx;
    if (*frameIndex == 0xFFFF) {
        return -1;
    }
    if (frameProps != NULL) {
        frameProps = &frameProps[(*frameIndex >> 9) << 2];
        g_CurrentEntity->hitboxOffX = *frameProps++;
        g_CurrentEntity->hitboxOffY = *frameProps++;
        g_CurrentEntity->hitboxWidth = *frameProps++;
        g_CurrentEntity->hitboxHeight = *frameProps++;
    }
    g_CurrentEntity->animCurFrame = *frameIndex & 0x1FF;
    return PLAYER.animFrameDuration >= 0 ? 0 : -1;
}

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8010DBFC);

u32 UpdateAnim(s8* frameProps, s32* frames) {
    AnimationFrame* animFrame;
    s32 ret;

    if (g_CurrentEntity->animFrameDuration == -1) {
        ret = -1;
    } else if (g_CurrentEntity->animFrameDuration == 0) {
        g_CurrentEntity->animFrameDuration =
            g_CurrentEntity->unk4C[g_CurrentEntity->animFrameIdx].duration;
        ret = 0;
    } else if ((--g_CurrentEntity->animFrameDuration) == 0) {
        g_CurrentEntity->animFrameIdx++;
        animFrame = &g_CurrentEntity->unk4C[g_CurrentEntity->animFrameIdx];
        // Effectively a switch statement, but breaks if I actually use one.
        if (animFrame->duration == 0) {
            g_CurrentEntity->animFrameIdx = animFrame->unk2;
            g_CurrentEntity->animFrameDuration =
                g_CurrentEntity->unk4C[g_CurrentEntity->animFrameIdx].duration;
            ret = 0;
        } else if (animFrame->duration == 0xFFFF) {
            g_CurrentEntity->animFrameIdx--;
            g_CurrentEntity->animFrameDuration = -1;
            ret = -1;
        } else if (animFrame->duration == 0xFFFE) {
            g_CurrentEntity->unk4C = frames[animFrame->unk2];
            g_CurrentEntity->animFrameIdx = 0;
            ret = -2;
            g_CurrentEntity->animFrameDuration =
                g_CurrentEntity->unk4C->duration;
        } else {
            g_CurrentEntity->animFrameDuration = animFrame->duration;
        }
    }
    if (frameProps != NULL) {
        // This is ugly - theoretically the type for frameProps should be
        // FrameProperty* but anything besides this where we assign this big
        // expression fails.
        frameProps =
            &frameProps[(g_CurrentEntity->unk4C[g_CurrentEntity->animFrameIdx]
                             .unk2 >>
                         9)
                        << 2];
        g_CurrentEntity->hitboxOffX = *frameProps++;
        g_CurrentEntity->hitboxOffY = *frameProps++;
        g_CurrentEntity->hitboxWidth = *frameProps++;
        g_CurrentEntity->hitboxHeight = *frameProps++;
    }
    g_CurrentEntity->animCurFrame =
        g_CurrentEntity->unk4C[g_CurrentEntity->animFrameIdx].unk2 & 0x1FF;
    return ret;
}

void func_8010DF70(void) {
    g_CurrentEntity = &PLAYER;

    switch (PLAYER.ext.generic.unkAC) {
    case 0xBA:
    case 0xBB:
    case 0xBE:
    case 0xF0:
    case 0xF1:
        func_8010DBFC(D_800B0130, D_800B01B8);
    }
}

void func_8010DFF0(s32 arg0, s32 arg1) {
    POLY_GT4* poly;
    s32 i;

    if (arg0 != 0) {
        g_Entities[UNK_ENTITY_1].ext.generic.unk7C.U8.unk1 = 1;
        g_Entities[UNK_ENTITY_3].animCurFrame = 0;
        g_Entities[UNK_ENTITY_2].animCurFrame = 0;
        g_Entities[UNK_ENTITY_1].animCurFrame = 0;
        poly = &g_PrimBuf[g_Entities[UNK_ENTITY_1].primIndex];

        for (i = 0; i < 6; i++) {
            poly->x1 = 0;
            poly = (POLY_GT4*)poly->tag;
        }
    }

    g_Entities[UNK_ENTITY_1].ext.generic.unk7C.U8.unk0 = 1;
    g_Entities[UNK_ENTITY_1].ext.generic.unk7E.modeU8.unk0 = 10;

    if (arg1 != 0) {
        if (arg1 < 4) {
            g_Player.D_80072F1E = 4;
        } else {
            g_Player.D_80072F1E = arg1;
        }
    }
}

void func_8010E0A8(void) {
    Entity* entity = &g_Entities[UNK_ENTITY_1];

    entity->ext.generic.unk7E.modeU8.unk0 = 0;
}

void func_8010E0B8(void) {
    Entity* entity = &g_Entities[UNK_ENTITY_1];

    entity->ext.generic.unk7C.U8.unk1 = 0;
    entity->ext.generic.unk7C.U8.unk0 = 0;
}

void func_8010E0D0(s32 arg0) {
    Entity* entity;

    if (arg0 == 1) {
        entity = func_8011AAFC(g_Entities, 0x47002C, 0);

        if (entity != NULL) {
            entity->flags |= FLAG_UNK_10000;
        }

        entity = func_8011AAFC(g_Entities, 0x40002C, 0);

        if (entity != NULL) {
            entity->flags |= FLAG_UNK_10000;
        }
    }
    func_8010DFF0(1, 1);
}
void func_8010E168(s32 arg0, s16 arg1) {
    if (arg0 == 0) {
        func_8011AAFC(g_CurrentEntity, 0x15002C, 0);
        if (arg1 >= g_Player.D_80072F1A) {
            g_Player.D_80072F1A = arg1;
        }
    } else if (g_Player.D_80072F1C <= arg1) {
        g_Player.D_80072F1C = arg1;
    }
}

void func_8010E1EC(s32 speed) {
    if (g_CurrentEntity->velocityX < 0) {
        g_CurrentEntity->velocityX += speed;
        if (g_CurrentEntity->velocityX > 0) {
            g_CurrentEntity->velocityX = 0;
        }
    } else {
        g_CurrentEntity->velocityX -= speed;
        if (g_CurrentEntity->velocityX < 0)
            g_CurrentEntity->velocityX = 0;
    }
}

void func_8010E234(s32 speed) {
    if (g_CurrentEntity->velocityY < 0) {
        g_CurrentEntity->velocityY += speed;
        if (g_CurrentEntity->velocityY > 0) {
            g_CurrentEntity->velocityY = 0;
        }
    } else {
        g_CurrentEntity->velocityY -= speed;
        if (g_CurrentEntity->velocityY < 0) {
            g_CurrentEntity->velocityY = 0;
        }
    }
}

s32 func_8010E27C(void) {
    u16* facing;

    if (g_Player.unk44 & 2) {
        return 0;
    }

    facing = &PLAYER.facingLeft;
    if (*facing == 1) {
        if (g_Player.padPressed & PAD_RIGHT) {
            *facing = 0;
            g_Player.unk4C = 1;
            return -1;
        } else if (g_Player.padPressed & PAD_LEFT) {
            return 1;
        }
    } else {
        if (!(g_Player.padPressed & PAD_RIGHT)) {
            if (g_Player.padPressed & PAD_LEFT) {
                *facing = 1;
                g_Player.unk4C = 1;
                return -1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

s32 func_8010E334(s32 xStart, s32 xEnd) {
    Entity* e = &PLAYER;

    g_Player.unk7A = 1;
    if (e->step == 0 && PLAYER.step_s == 1 && e->posX.i.hi >= xStart &&
        e->posX.i.hi <= xEnd) {
        return 1;
    }
    return 0;
}

// Sets velocity based on an input speed, and the existing facing value
void SetSpeedX(s32 speed) {
    if (g_CurrentEntity->facingLeft == 1) {
        speed = -speed;
    }
    g_CurrentEntity->velocityX = speed;
}

// Updates the Player velocity in the X Axis
void func_8010E3B8(s32 velocityX) {
    if (PLAYER.entityRoomIndex == 1) {
        velocityX = -velocityX;
    }
    PLAYER.velocityX = velocityX;
}

void func_8010E3E0(void) {
    if (g_Player.unk48 != 0) {
        DestroyEntity(&g_Entities[16]);
        g_Player.unk48 = 0;
    }
}

void func_8010E42C(u16 arg0) {
    PLAYER.step_s = arg0;
    PLAYER.step = Player_Unk18;

    if (!(arg0 & 1)) {
        func_8010DA48(0xF4);
    } else {
        func_8010DA48(0xF5);
    }
}

void func_8010E470(s32 arg0, s32 arg1) {
    PLAYER.velocityX = arg1;
    PLAYER.velocityY = 0;
    PLAYER.step = Player_Crouch;
    PLAYER.step_s = D_800ACF4C[arg0 * 2 + 0];
    func_8010DA48(D_800ACF4C[arg0 * 2 + 1]);
}

// This may be the function that turns Alucard into stone
void func_8010E4D0(void) {
    func_80111CC0();

    PLAYER.palette = 0x8100;
    PLAYER.zPriority = g_zEntityCenter.S16.unk0;

    if ((u32)(g_Player.unk72 - 1) < 2U) {
        func_8010DA48(0xC7);
        PLAYER.velocityY = 0;
        PLAYER.velocityX = 0;
        SetPlayerStep(Player_Unk_6);
        func_80111CC0();
        PlaySfx(NA_SE_VO_AL_WHAT);
        return;
    }
    func_80111CC0();
    func_8010E470(0, 0);
}

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8010E570);
void func_8010E570(/*?*/ s32);

void func_8010E6AC(s32 arg0) {
    bool condition = false;

    condition = ((g_Player.pl_vram_flag & 0x20) != condition);
    SetSpeedX(0x18000);
    PLAYER.velocityY = 0;
    SetPlayerStep(Player_Walk);

    if (arg0 != 0) {
        if (PLAYER.ext.generic.unkAC != 0xD) {
            func_8010DA48(0xD);
        }
    } else {
        func_8010DA48(7);
        func_8011AAFC(g_CurrentEntity, 0x50001, 0);
    }

    if (g_Player.unk4C != 0) {
        PLAYER.ext.generic.unkAC = 9;
    }

    if ((PLAYER.ext.generic.unkAC == 7) && (condition)) {
        PLAYER.animFrameIdx = 1;
    }

    if (g_Player.unk50 == 2) {
        PLAYER.animFrameIdx = 4;
    }
}

void func_8010E7AC(void) {
    SetPlayerStep(Player_Unk3);

    if (g_Player.unk50 != 1) {
        func_8010DA48(0x1C);
    }

    PLAYER.velocityY = 0x20000;
    PLAYER.velocityX = 0;
    g_Player.D_80072F0C = 8;

    if (g_Player.unk04 & 1) {
        g_Player.D_80072F0A = 8;
    } else {
        g_Player.D_80072F0A = 0;
    }

    g_Player.unk44 = 0x10;
}

void func_8010E83C(s32 arg0) {
    if (g_Player.unk72 != 0) {
        func_8010E7AC();
        return;
    } else if (func_8010E27C() != 0) {
        func_8010DA48(0x1A);
        SetSpeedX(0x18000);
        g_Player.unk44 = 0;
    } else {
        func_8010DA48(0x16);
        PLAYER.velocityX = 0;
        g_Player.unk44 = 4;
    }

    PLAYER.velocityY = 0xFFFB0000 | 0x2000;
    SetPlayerStep(Player_Jump);

    if (g_Player.unk50 == 1) {
        g_Player.unk44 |= 0x10;
    }

    if (arg0 != 0) {
        g_Player.unk44 &= ~1;
    } else {
        g_Player.unk44 |= 1;
    }
}

void func_8010E940(void) {
    g_Player.unk44 |= 0x21;
    func_8010DA48(0x20);
    PLAYER.step_s = 0;
    PLAYER.velocityY = -0x44000;
    if (g_Player.unk72 != 0) {
        PLAYER.velocityY = 0;
    }
}

void func_8010E9A4(void) {
    if (func_8010E27C() != 0) {
        SetSpeedX(0x30000);
    } else {
        PLAYER.velocityX = 0;
    }

    if (PLAYER.step == 4) {
        g_Player.unk44 |= 1;
    } else {
        g_Player.unk44 = 0;
    }

    func_8011AAFC(g_CurrentEntity, 2, 0);
    SetPlayerStep(Player_Unk8);
    PLAYER.velocityY = -0xC0000;
    func_8010DA48(0x21);
    g_Player.unk4A = 0;
}

void func_8010EA54(s32 arg0) {
    s16 temp_hi;

    if (arg0 != 0) {
        temp_hi = rand() % arg0;
        if (temp_hi < 4) {
            PlaySfx(D_800ACF60[temp_hi]);
        }
    }
}

s32 func_8010EADC(s16 arg0, s16 arg1) {
    Entity* entity = &g_Entities[0x20];
    s32 i;
    s32 var_a2;
    s32 ret;

    for (i = 0, var_a2 = 0, ret = 0; i < 16; i++) {
        if (entity->entityId == E_NONE) {
            ret++;
        }

        if (entity->ext.generic.unkB0 != 0) {
            if (entity->ext.generic.unkB0 == arg0) {
                var_a2++;
            }
        }

        if (var_a2 >= arg1) {
            return -1;
        }
        entity++;
    }

    return (ret == 0) ? -1 : 0;
}

s32 func_8010EB5C(void) {
    SubweaponDef subWpn;
    s16 subWpnId;
    s32 var_s0;
    s32 faker;

    var_s0 = 0;
    if (!(g_Player.padPressed & PAD_UP)) {
        return 1;
    }
    if (g_Player.pl_vram_flag & 0x20) {
        var_s0 = 1;
    }
    subWpnId = func_800FE3C4(&subWpn, 0, false);

    if (subWpnId == 0) {
        return 1;
    }
    if (subWpnId == 6 && D_80097400[0] != 0) {
        return 4;
    }
    if (func_8010EADC(subWpnId, subWpn.unk6) < 0) {
        return 2;
    }
    subWpnId = func_800FE3C4(&subWpn, 0, true);
    if (subWpnId == 0) {
        return 3;
    }
    func_8011AAFC(g_CurrentEntity, (u32)subWpn.unkB, subWpnId << 9);
    g_Player.D_80072F14 = 4;
    if (PLAYER.step_s < 64) {
        faker = subWpn.unkA;
        if (PLAYER.step == 0) {
            func_8010DA48(faker + var_s0);
        }
        func_8010EA54(8);
    }
    return 0;
}

s32 CheckChainLimit(s32 itemId, s32 handId) {
    Entity* entity;
    s32 existing_count;
    s32 i;
    s32 chainLimit;

    chainLimit = D_800A4B04[itemId].chainLimit;
    if (chainLimit & 0x80) {
        return -(s32)((u16)g_Player.unk46 >> 0xF);
    }
    entity = &g_Entities[16];
    for (i = 16, existing_count = 0; i < 64; i++, entity++) {
        // Hack to load unkAE as an s16 (struct has s8)
        // Longer term, figure out what g_Entites[16-64] are
        // and make dedicated ent extension.
        if (LOH(entity->ext.generic.unkAE) != itemId) {
            continue;
        }

        if (handId != 0) {
            if (entity->params & 0x8000) {
                existing_count++;
            }
        } else {
            if (!(entity->params & 0x8000)) {
                existing_count++;
            }
        }

        if (!(existing_count < chainLimit)) {
            return -1;
        }
    }
    return 0;
}

void func_8010ED54(u8 arg0) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_Unk15);
    func_8010DA48(arg0);
    func_8011AAFC(g_CurrentEntity, 0x14003D, 0);
    g_Player.unk48 = 0;
}

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8010EDB8);

void func_8010FAF4(void) {
    DestroyEntity(&g_Entities[E_WEAPON]);
    g_Player.unk46 = 0;
}

void func_8010FB24(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_SpellHellfire);
    func_8010E168(1, 0x10);
    func_8010E3E0();
}

void func_8010FB68(void) { // Related to Dark Metamorphosis
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_SpellDarkMetamorphosis);
    func_8010E3E0();
    func_8010DA48(0xBA);
    PlaySfx(NA_SE_VO_AL_DARK_METAMORPHOSIS);
    PlaySfx(NA_SE_PL_MP_GAUGE);
    g_Player.D_80072F16 =
        GetStatusAilmentTimer(STATUS_AILMENT_DARK_METAMORPHOSIS, 0x400);
    func_801092E8(1);
    func_8011AAFC(g_CurrentEntity, 0x110028, 0);
    func_80118C28(0xB);
}

void func_8010FBF4(void) { // Related to Soul Steal spell
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_SpellSoulSteal);
    func_8010E3E0();
    func_8010DA48(0xDA);
    PlaySfx(NA_SE_VO_AL_SOUL_STEAL);
    func_80118C28(0xC);
    g_Player.D_80072F18 = 4;
}

void func_8010FC50(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_SpellSummonSpirit);
    func_8010E3E0();
    func_8011AAFC(g_CurrentEntity, 0x75, 0);
    func_8010DA48(0xF0);
    PlaySfx(NA_SE_VO_AL_PUNCH);
    g_Player.D_80072F18 = 4;
}

void func_8010FCB8(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_SpellTetraSpirit);
    func_8010E3E0();
    func_8011AAFC(g_CurrentEntity, 0x10075, 0);
    func_8010DA48(0xF1);
    PlaySfx(NA_SE_VO_AL_PUNCH);
    g_Player.D_80072F18 = 4;
}

void func_8010FD24(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    SetPlayerStep(Player_Unk39);
    func_8010E3E0();
    func_8010DA48(0xF1);
    func_8011AAFC(g_CurrentEntity, 0x170028, 0);
    g_Player.D_80072F18 = 4;
}

void func_8010FD88(void) {
    PLAYER.step = Player_Stand;
    PLAYER.step_s = 3;
    SetSpeedX(0xFFFC8000);
    g_CurrentEntity->velocityY = 0;
    func_8010DA48(0xDB);
    func_8011AAFC(g_CurrentEntity, 0, 0);
    g_Player.unk46 = 0;
    PlaySfx(NA_SE_AL_BACKSLIDE);
}

bool func_8010FDF8(s32 branchFlags) {
    u8 stackpad[0x28];
    s32 tempYAccel;
    s32 tempTriangle;
    s32 YAccel;

    if (branchFlags & 8 && g_Player.unk46 == 0) {
        func_8010E27C();
    }
    YAccel = -((branchFlags & 0x8000) != 0) & 0x2C00;
    if (branchFlags & 0x10000) {
        if (-0x2000 < PLAYER.velocityY && PLAYER.velocityY < 0x6000 &&
            !(g_Player.unk44 & 0x20) && g_Player.padPressed & PAD_CROSS) {
            YAccel = 0x08CC;
        } else {
            YAccel = 0x2C00;
        }
    }

    if (branchFlags & 0x200) {
        if (-0x2000 < PLAYER.velocityY && PLAYER.velocityY < 0x6000) {
            YAccel = 0x1600;
        } else {
            YAccel = 0x2C00;
        }
    }

    if (D_80097448[0] >= 0x29) {
        if (YAccel < 0) {
            tempYAccel = YAccel + 3;
        } else {
            tempYAccel = YAccel;
        }
        YAccel = (tempYAccel) >> 2;
    }

    PLAYER.velocityY += YAccel;

    if (PLAYER.velocityY > 0x70000) {
        PLAYER.velocityY = 0x70000;
    }
    if ((branchFlags & 0x80) && (g_Player.pl_vram_flag & 2) &&
        (PLAYER.velocityY < -0x10000)) {
        PLAYER.velocityY = -0x10000;
    }

    if (PLAYER.velocityY >= 0) {
        if (branchFlags & 1 && g_Player.pl_vram_flag & 1) {
            if (g_Player.unk46 != 0) {
                if ((g_Player.unk46 & 0x7FFF) == 0xFF) {
                    func_8010E570(0);
                    func_8010FAF4();
                label:
                    PlaySfx(0x64C, 0x30, 0);
                    return 1;
                }

                if (PLAYER.velocityY > 0x6E000) {
                    func_8010E470(1, 0);
                    func_80134714(0x647);
                    func_8011AAFC(g_CurrentEntity, 0, 0);
                } else {
                    if (g_Player.unk44 & 0x10) {
                        func_8010E6AC(1);
                    } else {
                        func_8010E570(0);
                    }
                    PlaySfx(0x64C, 0x30, 0);
                }

                func_8010FAF4();
                return 1;
            }

            if (PLAYER.velocityY > 0x6E000) {
                if ((PLAYER.step_s == 112) || (PLAYER.step == 4)) {
                    func_8010E470(3, PLAYER.velocityX / 2);
                } else {
                    func_8010E470(1, 0);
                }
                PlaySfx(0x647);
                func_8011AAFC(g_CurrentEntity, 0, 0);
                return 1;
            }

            if (g_Player.unk44 & 0x10) {
                func_8010E6AC(1);
                goto label;
            }

            if (ABS(PLAYER.velocityX) > 0x20000) {
                PlaySfx(0x647);
                func_8011AAFC(g_CurrentEntity, 0, 0);
                func_8010E570(PLAYER.velocityX);
            } else {
                PlaySfx(0x64C, 0x30, 0);
                func_8010E570(0);
            }
            return 1;
        }
        if (branchFlags & 0x20000 && g_Player.pl_vram_flag & 1) {
            func_8010E470(3, PLAYER.velocityX);
            PlaySfx(0x647);
            func_8011AAFC(g_CurrentEntity, 0, 0);
            return 1;
        }
    }
    if (branchFlags & 4 && !(g_Player.pl_vram_flag & 1)) {
        func_8010E7AC();
        return 1;
    }

    if (branchFlags & 0x1000 &&
        g_Player.padPressed & (PAD_SQUARE | PAD_CIRCLE) &&
        func_8010EDB8() != 0) {
        return 1;
    }

    if (g_Player.unk46 & 0x8000) {
        return 0;
    }

    if (branchFlags & 0x10 && g_Player.padTapped & PAD_CROSS) {
        func_8010E83C(1);
        return 1;
    }

    if (branchFlags & 0x20 && IsRelicActive(RELIC_LEAP_STONE) &&
        g_Player.padTapped & PAD_CROSS && !(g_Player.unk44 & 1)) {
        func_8010E940();
        return 1;
    }

    if (branchFlags & 0x2000 && g_Player.padPressed & PAD_DOWN) {
        func_8010E470(2, 0);
        return 1;
    }

    if (branchFlags & 0x40000 && PLAYER.ext.generic.unkAC != 0xDB) {
        if (g_Player.unk46 & 0x7FFF) {
            tempTriangle = g_Player.padPressed & PAD_TRIANGLE;
        } else {
            tempTriangle = g_Player.padTapped & PAD_TRIANGLE;
        }
        if (tempTriangle != 0) {
            func_8010FD88();
            return 1;
        }
    }
    return 0;
}

// DECOMP_ME_WIP func_80110394 https://decomp.me/scratch/Akstc 94.80%
INCLUDE_ASM("dra/nonmatchings/6D59C", func_80110394);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_801104D0);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_801106A4);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8011081C);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_80110968);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_80110BC8);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_80110DF8);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_80111018);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_801112AC);

INCLUDE_ASM("dra/nonmatchings/6D59C", func_8011151C);