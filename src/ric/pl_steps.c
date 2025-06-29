// SPDX-License-Identifier: AGPL-3.0-or-later
#include "ric.h"
#include "sfx.h"

static void func_80158B04(u16 arg0) {
    s16 xMod = 3;
    if (PLAYER.facingLeft) {
        xMod = -xMod;
    }

    PLAYER.posY.i.hi -= 16;
    PLAYER.posX.i.hi += xMod;
    RicCreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(BP_EMBERS, 1), 0);
    PLAYER.posY.i.hi += 16;
    PLAYER.posX.i.hi -= xMod;

    if (arg0 & 1) {
        g_api.func_80102CD8(3);
        g_api.PlaySfx(SFX_WALL_DEBRIS_B);
    }
    if (arg0 & 2) {
        PLAYER.velocityX = 0;
        PLAYER.velocityY = 0;
    }
}

void RicStepStand(void) {
    s16 xMod;
    s32 facing;

    if (PLAYER.step < 64) {
        if (D_8015459C != 0) {
            D_8015459C--;
        } else if (D_80097448[0] > 48) {
            xMod = 4;
            if (PLAYER.facingLeft) {
                xMod = -xMod;
            }
            PLAYER.posX.i.hi += xMod;
            PLAYER.posY.i.hi -= 16;
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_EMBERS, 8), 0);
            PLAYER.posY.i.hi += 16;
            PLAYER.posX.i.hi -= xMod;
            D_8015459C = 0x60;
        }
    }

    if (!RicCheckInput(CHECK_FALL | CHECK_FACING | CHECK_JUMP | CHECK_CRASH |
                       CHECK_ATTACK | CHECK_CROUCH | CHECK_SLIDE)) {
        RicDecelerateX(FIX(0.125));
        switch (PLAYER.step_s) {
        case 0:
            if (RicCheckFacing()) {
                RicSetWalk(0);
            } else if (g_Player.padPressed & PAD_UP) {
                RicSetAnimation(ric_anim_press_up);
                PLAYER.step_s = 1;
                break;
            }
            break;
        case 1:
            if (RicCheckFacing()) {
                RicSetWalk(0);
            } else if (g_Player.padPressed & PAD_UP) {
            } else {
                RicSetStand(0);
            }
            break;
        case 64:
            DisableAfterImage(1, 1);
            if (PLAYER.pose < 3) {
                facing = RicCheckFacing();
                if (g_Player.padPressed & PAD_DOWN) {
                    PLAYER.step = PL_S_CROUCH;
                    PLAYER.anim = D_801555A8;
                    break;
                }
            }

            if (PLAYER.poseTimer < 0) {
                if (g_Player.padPressed & PAD_SQUARE) {
                    PLAYER.step_s++;
                    g_Player.unk46 = 2;
                    RicSetAnimation(ric_anim_brandish_whip);
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_ARM_BRANDISH_WHIP, 0);
                    break;
                }
                g_Player.unk46 = 0;
                RicSetStand(0);
            }
            break;
        case 65:
            DisableAfterImage(1, 1);
            if (g_Player.padPressed & PAD_SQUARE) {
                break;
            }
            g_Player.unk46 = 0;
            RicSetStand(0);
            break;
        case 66:
            DisableAfterImage(1, 1);
            if (PLAYER.pose < 3) {
                RicCheckFacing();
            }
            if (PLAYER.poseTimer < 0) {
                g_Player.unk46 = 0;
                RicSetStand(0);
            }
            break;
        }
    }
}

void RicStepWalk(void) {
    if (!RicCheckInput(CHECK_FALL | CHECK_FACING | CHECK_JUMP | CHECK_CRASH |
                       CHECK_ATTACK | CHECK_CROUCH)) {
        RicDecelerateX(FIX(0.125));
        if (RicCheckFacing() == 0) {
            RicSetStand(0);
            return;
        }
        if (PLAYER.step_s != 0) {
            if (PLAYER.step_s) {
            }
        } else {
            RicSetSpeedX(FIX(1.25));
        }
    }
}

void RicStepRun(void) {
#ifdef VERSION_US
    if (g_Player.unk7A != 0) {
        RicSetWalk(0);
        return;
    }
#endif
    g_Player.timers[PL_T_8] = 8;
    g_Player.timers[PL_T_CURSE] = 8;
    if (!RicCheckInput(CHECK_FALL | CHECK_FACING | CHECK_JUMP | CHECK_CRASH |
                       CHECK_ATTACK | CHECK_CROUCH)) {
        RicDecelerateX(FIX(0.125));
        if (RicCheckFacing() == 0) {
            RicSetStand(0);
            if (g_Player.timers[PL_T_RUN] == 0) {
                if (!(g_Player.vram_flag & 0xC)) {
                    RicSetAnimation(ric_anim_stop_run);
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_SKID_SMOKE, 0);
                }
            } else {
                PLAYER.velocityX = 0;
            }
            return;
        }
        if (PLAYER.step_s != 0) {
            if (PLAYER.step_s) {
            }
        } else {
            RicSetSpeedX(FIX(2.25));
        }
    }
}

void RicStepJump(void) {
    s32 facing;

    if (!g_IsPrologueStage && (PLAYER.velocityY < FIX(-1)) &&
        !(g_Player.unk44 & 0x40) && !(g_Player.padPressed & PAD_CROSS)) {
        PLAYER.velocityY = FIX(-1);
    }
    if ((g_Player.vram_flag & 2) && (PLAYER.velocityY < FIX(-1))) {
        PLAYER.velocityY = FIX(-0.25);
        g_Player.unk44 |= 0x20;
    }
    if (RicCheckInput(
            CHECK_GROUND | CHECK_FACING | CHECK_ATTACK | CHECK_GRAVITY_JUMP)) {
        return;
    }
    switch (PLAYER.step_s) {
    case 0:
        RicDecelerateX(FIX(0.0625));
        facing = RicCheckFacing();
        if (facing) {
            if (g_Player.unk44 & 0x10) {
                RicSetSpeedX(FIX(2.25));
            } else {
                RicSetSpeedX(FIX(1.25));
            }
            g_Player.unk44 &= ~4;
        } else {
            g_Player.unk44 &= ~0x10;
            if ((PLAYER.pose < 2) && !(g_Player.unk44 & 8) &&
                (g_Player.unk44 & 4) && (g_Player.padTapped & PAD_CROSS)) {
                RicSetAnimation(D_8015555C);
                RicSetSpeedX(FIX(-1.5));
                PLAYER.velocityY = FIX(-2.625);
                if (g_Player.unk72) {
                    PLAYER.velocityY = 0;
                }
                g_Player.unk44 |= 0xA;
                g_Player.unk44 &= ~4;
                PLAYER.step_s = 2;
            }
        }
        break;
    case 2:
        break;
    case 0x40:
        DisableAfterImage(1, 1);
        if (PLAYER.pose < 3) {
            facing = RicCheckFacing();
            if (facing) {
                if (g_Player.unk44 & 0x10) {
                    RicSetSpeedX(FIX(2.25));
                } else {
                    RicSetSpeedX(FIX(1.25));
                }
                g_Player.unk44 &= ~4;
            } else {
                g_Player.unk44 &= ~0x10;
            }
        } else {
            if (((g_Player.padPressed & PAD_RIGHT) && PLAYER.facingLeft == 0) ||
                ((g_Player.padPressed & PAD_LEFT) && PLAYER.facingLeft)) {
                if (g_Player.unk44 & 0x10) {
                    RicSetSpeedX(FIX(2.25));
                } else {
                    RicSetSpeedX(FIX(1.25));
                }
                RicSetSpeedX(FIX(1.25));
                g_Player.unk44 &= ~4;
            } else {
                g_Player.unk44 &= ~0x10;
            }
        }
        if (PLAYER.poseTimer < 0) {
            if (g_Player.padPressed & PAD_SQUARE) {
                PLAYER.step_s += 1;
                g_Player.unk46 = 2;
                RicSetAnimation(D_80155740);
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, BP_ARM_BRANDISH_WHIP, 0);
            } else {
                g_Player.unk46 = 0;
                PLAYER.step_s = 0;
                RicSetAnimation(D_80155528);
            }
        }
        break;
    case 0x41:
        DisableAfterImage(1, 1);
        if (!(g_Player.padPressed & PAD_SQUARE)) {
            g_Player.unk46 = 0;
            PLAYER.step_s = 0;
            RicSetAnimation(D_80155528);
        }
        break;
    case 0x42:
        DisableAfterImage(1, 1);
        if (PLAYER.pose < 3) {
            facing = RicCheckFacing();
            if (facing) {
                if (g_Player.unk44 & 0x10) {
                    RicSetSpeedX(FIX(2.25));
                } else {
                    RicSetSpeedX(FIX(1.25));
                }
                g_Player.unk44 &= ~4;
            } else {
                g_Player.unk44 &= ~0x10;
            }
        } else {
            if (((g_Player.padPressed & PAD_RIGHT) && PLAYER.facingLeft == 0) ||
                ((g_Player.padPressed & PAD_LEFT) && PLAYER.facingLeft)) {
                if (g_Player.unk44 & 0x10) {
                    RicSetSpeedX(FIX(2.25));
                } else {
                    RicSetSpeedX(FIX(1.25));
                }
                RicSetSpeedX(FIX(1.25));
                g_Player.unk44 &= ~4;
            } else {
                g_Player.unk44 &= ~0x10;
            }
        }
        if (PLAYER.poseTimer < 0) {
            g_Player.unk46 = 0;
            PLAYER.step_s = 0;
            RicSetAnimation(D_80155528);
        }
        break;
    }
}

void RicStepFall(void) {
    if (RicCheckInput(
            CHECK_GROUND | CHECK_FACING | CHECK_ATTACK | CHECK_GRAVITY_FALL)) {
        return;
    }
    RicDecelerateX(FIX(1. / 16));
    switch (PLAYER.step_s) {
    case 0:
        if (g_Player.timers[PL_T_5] && g_Player.padTapped & PAD_CROSS) {
            RicSetJump();
        } else if (RicCheckFacing()) {
            RicSetSpeedX(FIX(0.75));
        }
        break;
    }
}

void RicStepCrouch(void) {
    s32 i;
    s16 xShift;
    s32 facing;

    if ((g_Player.padTapped & PAD_CROSS) && !g_Player.unk46 &&
        (g_Player.padPressed & PAD_DOWN)) {
        for (i = 0; i < NUM_HORIZONTAL_SENSORS; i++) {
            if (g_Player.colFloor[i].effects & EFFECT_SOLID_FROM_ABOVE) {
                g_Player.timers[PL_T_7] = 8;
                return;
            }
        }
    }
    if (RicCheckInput(CHECK_FALL | CHECK_FACING | CHECK_ATTACK | CHECK_SLIDE)) {
        return;
    }
    if ((g_Player.padTapped & PAD_CROSS) && !g_Player.unk46 &&
        (!g_Player.unk72)) {
        RicSetJump(1);
        return;
    } else if (!g_Player.unk72 && !g_Player.unk46 &&
               (g_Player.padTapped & PAD_TRIANGLE) && RicDoCrash()) {
        return;
    }
    RicDecelerateX(FIX(0.125));
    switch (PLAYER.step_s) {
    case 0x0:
        if (D_8015459C != 0) {
            D_8015459C--;
        } else if (*D_80097448 > 0x18 && !g_Player.unk48) {
            xShift = 9;
            if (PLAYER.facingLeft) {
                xShift = -xShift;
            }
            PLAYER.posX.i.hi += xShift;
            PLAYER.posY.i.hi += 2;
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_EMBERS, 8), 0);
            PLAYER.posY.i.hi -= 2;
            PLAYER.posX.i.hi -= xShift;
            D_8015459C = 0x60;
        }
        if (!(g_Player.padPressed & PAD_DOWN) &&
            ((!g_Player.unk72) || !(g_Player.vram_flag & 0x40))) {
            RicSetAnimation(D_801554E0);
            PLAYER.step_s = 2;
            return;
        }
        break;
    case 0x1:
        if (!(g_Player.padPressed & PAD_DOWN) &&
            ((!g_Player.unk72) || !(g_Player.vram_flag & 0x40))) {
            if (RicCheckFacing()) {
                RicSetWalk(0);
                return;
            }
            PLAYER.anim = D_801554E0;
            PLAYER.step_s = 2;
            PLAYER.pose = 2 - PLAYER.pose;
            PLAYER.poseTimer = 1;
            break;
        }
    case 0x4:
        if (PLAYER.poseTimer != -1) {
            return;
        }
        RicSetAnimation(ric_anim_crouch);
        PLAYER.step_s = 0;
        break;
    case 0x2:
        if (!g_Player.unk72 || !(g_Player.vram_flag & 0x40)) {
            if (RicCheckFacing()) {
                RicSetWalk(0);
                return;
            }
            if (PLAYER.poseTimer == -1) {
                RicSetStand(0);
                return;
            }
        }
        break;
    case 0x3:
        if (PLAYER.poseTimer < 0) {
            RicSetAnimation(ric_anim_crouch);
            PLAYER.step_s = 0;
            return;
        }
        break;
    case 0x40:
        DisableAfterImage(1, 1);
        if (PLAYER.pose < 3) {
            facing = RicCheckFacing();
            if (!(g_Player.padPressed & PAD_DOWN) && !g_Player.unk72) {
                PLAYER.step = PL_S_STAND;
                PLAYER.anim = D_80155588;
                return;
            }
        }
        if (PLAYER.poseTimer < 0) {
            if (g_Player.padPressed & PAD_SQUARE) {
                PLAYER.step_s++;
                g_Player.unk46 = 2;
                RicSetAnimation(D_80155738);
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, BP_ARM_BRANDISH_WHIP, 0);
                return;
            }
            g_Player.unk46 = 0;
            PLAYER.step_s = 0;
            RicSetAnimation(ric_anim_crouch);
        }
        break;
    case 0x41:
        DisableAfterImage(1, 1);
        if (!(g_Player.padPressed & PAD_SQUARE)) {
            g_Player.unk46 = 0;
            PLAYER.step_s = 0;
            RicSetAnimation(ric_anim_crouch);
        }
        break;
    }
}

static void RicResetPose(void) {
    PLAYER.pose = PLAYER.poseTimer = 0;
    g_Player.unk44 = 0;
    g_Player.unk46 = 0;
    PLAYER.drawFlags &= ~FLAG_DRAW_ROTATE;
}

static void func_80159C04(void) {
    Entity* entity;
    s16 var_s3;
    s16 var_s2;
    s16 var_s1;

    entity = PLAYER.unkB8;
#if defined(VERSION_PSP)
    if (!entity) {
        return;
    }
#endif
    if (entity->facingLeft) {
        var_s3 = -entity->hitboxOffX;
    } else {
        var_s3 = entity->hitboxOffX;
    }
    if (PLAYER.facingLeft) {
        var_s2 = -PLAYER.hitboxOffX;
    } else {
        var_s2 = PLAYER.hitboxOffX;
    }

    var_s1 = PLAYER.posX.i.hi + var_s2 - entity->posX.i.hi - var_s3;
    if (abs(var_s1) < 16 && entity->velocityX != 0) {
        if (entity->velocityX < 0) {
            PLAYER.entityRoomIndex = 0;
            return;
        } else {
            PLAYER.entityRoomIndex = 1;
            return;
        }
    }
    if (var_s1 < 0) {
        PLAYER.entityRoomIndex = 0;
    } else {
        PLAYER.entityRoomIndex = 1;
    }
}

void RicStepDead(
    s32 damageEffects, s32 damageKind, s32 prevStep, s32 prevStepS);
#ifdef VERSION_PSP
extern s32 ric_hit_stun_timer;
#else
static s32 ric_hit_stun_timer;
#endif
void RicStepHit(s32 damageEffect, u32 damageKind, s16 prevStep, s32 prevStepS) {
    DamageParam damage;
    s32 damageResult;
    s16 xShift;
    bool step_s_zero;
    s32 i;

    step_s_zero = false;
    if (ric_hit_stun_timer) {
        ric_hit_stun_timer--;
    }
    switch (PLAYER.step_s) {
    case 0:
        step_s_zero = true;
        RicResetPose();
        if (damageKind < DAMAGEKIND_16) {
            func_80159C04();
        } else {
            PLAYER.entityRoomIndex = PLAYER.facingLeft;
        }
        if (damageEffect & ELEMENT_THUNDER) {
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, BP_HIT_BY_THUNDER, 0);
            PLAYER.velocityY = FIX(-4);
            func_8015CAAC(FIX(-1.25));
            PLAYER.step_s = 1;
            PLAYER.anim = D_801556C4;
            g_Player.unk40 = 0x8120;
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, BP_HIT_BY_THUNDER, 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x46), 0);
            g_Player.timers[PL_T_2] = 6;
            g_api.PlaySfx(SFX_VO_RIC_PAIN_C);
            break;
        } else {
            if (damageEffect & ELEMENT_ICE) {
                damageKind = DAMAGEKIND_3;
            }
            // TODO check if this is real, i suspect not. Fix damageKind.
            switch (damageKind) {
            case 2:
                switch (prevStep) {
                case PL_S_STAND:
                case PL_S_WALK:
                    PLAYER.velocityY = 0;
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 6;
                    PLAYER.anim = D_8015569C;
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_B);
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_SKID_SMOKE, 0);
                    break;
                case PL_S_CROUCH:
                    PLAYER.velocityY = 0;
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 7;
                    PLAYER.anim = D_80155704;
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_SKID_SMOKE, 0);
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_C);
                    break;
                case PL_S_JUMP:
                case PL_S_FALL:
                    PLAYER.velocityY = FIX(-3);
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 1;
                    PLAYER.anim = ric_anim_stun;
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_B);
                    break;
                }
                break;
            case 5:
            case 4:
                g_Player.damageTaken = PLAYER.hitPoints;
                PLAYER.posY.val -= 1;
                PLAYER.velocityY = FIX(-0.5);
                func_8015CAAC(FIX(-8));
                PLAYER.step_s = 2;
                PLAYER.anim = ric_anim_stun;
                g_Player.timers[PL_T_2] = 0x200;
                PLAYER.facingLeft = PLAYER.entityRoomIndex;
                break;
            default:
            case 16:
            case 3:
                switch (prevStep) {
                default:
                case PL_S_STAND:
                case PL_S_WALK:
                    PLAYER.velocityY = FIX(-4);
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 1;
                    PLAYER.anim = ric_anim_stun;
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_B);
                    break;
                case PL_S_CROUCH:
                    PLAYER.velocityY = 0;
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 7;
                    PLAYER.anim = D_80155704;
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_SKID_SMOKE, 0);
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_C);
                    break;
                case PL_S_JUMP:
                case PL_S_FALL:
                    PLAYER.velocityY = FIX(-3);
                    func_8015CAAC(FIX(-1.25));
                    PLAYER.step_s = 1;
                    PLAYER.anim = ric_anim_stun;
                    g_api.PlaySfx(SFX_VO_RIC_PAIN_B);
                    break;
                }
                break;
            }
            g_Player.unk40 = 0x8166;
            g_Player.timers[PL_T_2] = 6;
            if (damageEffect & ELEMENT_FIRE) {
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(BP_HIT_BY_FIRE, 1), 0);
                RicCreateEntFactoryFromEntity(g_CurrentEntity, 9, 0);
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x43), 0);
                g_Player.unk40 = 0x8160;
                g_Player.timers[PL_T_2] = 0x10;
                break;
            } else if (damageEffect & ELEMENT_CUT) {
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(BP_HIT_BY_CUT, 5), 0);
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x44), 0);
                g_Player.unk40 = 0x8166;
                g_Player.timers[PL_T_2] = 0x10;
                break;
            } else if (damageEffect & ELEMENT_ICE) {
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, BP_HIT_BY_ICE, 0);
                g_Player.timers[PL_T_2] = 0xC;
                g_Player.unk40 = 0x8169;
                break;
            } else {
                if (damageEffect & ELEMENT_DARK) {
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_HIT_BY_DARK, 0);
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x56), 0);
                    g_Player.timers[PL_T_2] = 0x10;
                    g_Player.unk40 = 0x8164;
                }
                if (damageEffect & ELEMENT_HOLY) {
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, BP_HIT_BY_HOLY, 0);
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x57), 0);
                    g_Player.timers[PL_T_2] = 8;
                    g_Player.unk40 = 0x8168;
                }
                if (!(damageEffect & 0xF840)) {
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x53), 0);
                }
            }
        }
        break;
    case 1:
        if ((g_Player.vram_flag & 2) && (PLAYER.velocityY < FIX(-1))) {
            PLAYER.velocityY = FIX(-1);
        }
        if (RicCheckInput(
                CHECK_80 | CHECK_GRAVITY_HIT | CHECK_GROUND_AFTER_HIT)) {
            return;
        }
        break;
    case 2:
        if ((g_Player.unk04 & 0x8000) && !(g_Player.vram_flag & 0x8000)) {
            goto block_6dc;
        }
        if ((g_Player.vram_flag & 0x8000) && !(g_GameTimer & 1)) {
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_SMOKE_PUFF_2, 10), 0);
        }
        if (!(g_Player.vram_flag & 0xE)) {
            break;
        }
        if (g_Player.vram_flag & 2) {
            func_80158B04(1);
            PLAYER.velocityX /= 2;
            PLAYER.velocityY = 0;
            ric_hit_stun_timer = 0x18;
            PLAYER.step_s = 5;
            damage.effects = EFFECT_NONE;
            damage.damageKind = DAMAGEKIND_1;
            damage.damageTaken = g_Player.damageTaken;
            damageResult = g_api.CalcPlayerDamage(&damage);
            if (damageResult) {
                RicSetStep(PL_S_DEAD);
                RicStepDead(0, 2, PL_S_HIT, 2);
                return;
            }
            break;
        } else {
            if ((g_StageId != STAGE_BO6) && (g_StageId != STAGE_RBO6) &&
                (g_StageId != STAGE_DRE)) {
                for (i = 2; i < NUM_VERTICAL_SENSORS; i++) {
                    if (g_Player.colWall[i].effects & EFFECT_UNK_0002) {
                        break;
                    }
                }
                if (i == NUM_VERTICAL_SENSORS) {
                    for (i = NUM_VERTICAL_SENSORS + 2;
                         i < NUM_VERTICAL_SENSORS * 2; i++) {
                        if (g_Player.colWall[i].effects & EFFECT_UNK_0002) {
                            break;
                        }
                    }
                }
                if (i == NUM_VERTICAL_SENSORS * 2) {
                block_6dc:
                    PLAYER.velocityY = FIX(-4);
                    func_8015CAAC(FIX(-1.25));
                    xShift = -3;
                    if (PLAYER.velocityX != 0) {
                        xShift = -xShift;
                    }
                    PLAYER.posY.i.hi += 20;
                    PLAYER.posX.i.hi += xShift;
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(BP_EMBERS, 9), 0);
                    PLAYER.posY.i.hi -= 20;
                    PLAYER.posX.i.hi -= xShift;
                    g_api.PlaySfx(SFX_WALL_DEBRIS_B);
                    g_api.func_80102CD8(2);
                    PLAYER.step_s = 1;
                    damage.effects = EFFECT_NONE;
                    damage.damageKind = DAMAGEKIND_1;
                    damage.damageTaken = g_Player.damageTaken;
                    damageResult = g_api.CalcPlayerDamage(&damage);
                    if (damageResult) {
                        RicSetStep(PL_S_DEAD);
                        RicStepDead(0, 2, PL_S_HIT, 2);
                        return;
                    }
                    break;
                }
            }
            ric_hit_stun_timer = 8;
            g_api.PlaySfx(SFX_WALL_DEBRIS_B);
            PLAYER.velocityY = FIX(-2.5);
            g_api.func_80102CD8(2);
            PLAYER.step_s = 3;
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_SKID_SMOKE_2, 8), 0);
        }
        damage.effects = EFFECT_NONE;
        damage.damageKind = DAMAGEKIND_1;
        damage.damageTaken = g_Player.damageTaken;
        damageResult = g_api.CalcPlayerDamage(&damage);
        if (damageResult) {
            RicSetStep(PL_S_DEAD);
            RicStepDead(0, 2, PL_S_HIT, 2);
            return;
        }
        break;
    case 3:
        if (!ric_hit_stun_timer) {
            RicSetSpeedX(FIX(0.75));
            if (RicCheckInput(
                    CHECK_80 | CHECK_GRAVITY_HIT | CHECK_GROUND_AFTER_HIT)) {
                return;
            }
        }
        break;
    case 5:
        RicDecelerateX(FIX(0.125));
        if (ric_hit_stun_timer) {
            if ((g_Player.vram_flag & 2) && !(g_GameTimer & 3)) {
                func_80158B04(0);
            }
            break;
        } else if (g_Player.vram_flag & 0xC) {
            if (!(g_Player.vram_flag & (u16)~0xFC)) {
                PLAYER.velocityY += FIX(12.0 / 128);
                if (PLAYER.velocityY > FIX(7)) {
                    PLAYER.velocityY = FIX(7);
                }
                if (!(g_GameTimer & 3)) {
                    RicCreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(BP_SKID_SMOKE_3, 4), 0);
                }
                break;
            }
        }
        PLAYER.step_s = 1;
        PLAYER.poseTimer = PLAYER.pose = 0;
        break;
    case 6:
        RicDecelerateX(FIX(0.125));
        if (!(g_Player.vram_flag & 1)) {
            RicSetFall();
        }
        if (PLAYER.poseTimer < 0) {
            if (g_Player.unk5C) {
                if (g_Status.hp <= 0) {
                    RicSetDeadPrologue();
                    return;
                }
                RicSetStand(PLAYER.velocityX);
            } else {
                RicSetStand(PLAYER.velocityX);
            }
        }
        break;
    case 7:
        RicDecelerateX(FIX(0.125));
        if (!(g_Player.vram_flag & 1)) {
            RicSetFall();
        }
        if (PLAYER.poseTimer < 0) {
            if (g_Player.unk5C) {
                if (g_Status.hp <= 0) {
                    RicSetDeadPrologue();
                    return;
                }
                RicSetCrouch(0, PLAYER.velocityX);
            } else {
                RicSetCrouch(0, PLAYER.velocityX);
            }
        }
        break;
    }
    if (step_s_zero && g_Player.unk72) {
        PLAYER.velocityY = 0;
    }
}

void RicStepBossGrab(void) {
    DamageParam damage;
    s32 damageResult;

    switch (g_CurrentEntity->step_s) {
    case 0:
        RicResetPose();
        if (g_Player.unk62 == 0) {
            PLAYER.anim = ric_anim_stun;
            g_Player.timers[PL_T_2] = 8;
            g_Player.unk40 = 0x8166;
            g_api.PlaySfx(SFX_VO_RIC_PAIN_B);
        }
        PLAYER.velocityX = PLAYER.velocityY = 0;
        PLAYER.step_s = 1;
        g_Player.unk60 = 2;
        break;
    case 1:
        // Effectively a switch on g_Player.unk60
        if (g_Player.unk60 == 3) {
            damage.effects = EFFECT_NONE;
            damage.damageKind = DAMAGEKIND_1;
            damage.damageTaken = g_Player.damageTaken;
            damageResult = g_api.CalcPlayerDamage(&damage);
            if (damageResult) {
                RicSetStep(PL_S_DEAD);
                RicStepDead(0, 2, PL_S_BOSS_GRAB, 1);
                return;
            }
            if (g_Player.unk62 == 0) {
                g_Player.timers[PL_T_2] = 4;
                g_Player.unk40 = 0x8166;
                g_api.PlaySfx(SFX_VO_RIC_PAIN_C);
            }
            if (g_Player.unk62 == 2) {
            }
            g_Player.unk60 = 2;
        } else if (g_Player.unk60 == 4) {
            PLAYER.step = PL_S_HIT;
            PLAYER.step_s = 2;
            g_Player.unk60 = 0;
            g_Player.damageTaken = g_Player.unk64;
            g_api.PlaySfx(SFX_VO_RIC_PAIN_D);
        } else if (g_Player.unk60 == 0) {
            PLAYER.step = PL_S_HIT;
            PLAYER.step_s = 1;
        }
        break;
    }
}

// Compare to DRA PlayerStepKill
enum DeathKind {
    DEATH_GENERIC,
    DEATH_BY_FIRE,
    DEATH_BY_THUNDER,
    DEATH_BY_ICE,
};
#if defined(VERSION_PSP)
extern u8 dead_dissolve_bmp[0x1400];
extern s16 D_80174F68;
extern s16 D_80174F6C;
extern enum DeathKind death_kind;
RECT D_801545A0 = {512, 256, 32, 80};
#else
static u8 dead_dissolve_bmp[0x1400];
static s16 D_80174F68;
STATIC_PAD_BSS(2);
static s16 D_80174F6C;
STATIC_PAD_BSS(2);
static enum DeathKind death_kind;
#endif
void RicStepDead(
    s32 damageEffects, s32 damageKind, s32 prevStep, s32 prevStepS) {
    s32 j;
    s32 i;
    u8* s2;
    u8* imgPtr;
    s32 disableColorChange = 0;
    PlayerDraw* playerDraw = &g_PlayerDraw[0];

    switch (PLAYER.step_s) {
    case 0:
        RicResetPose();
        func_80159C04();
        func_8015CAAC(FIX(-0.75));
        RicSetAnimation(D_80155544);
        PLAYER.velocityY = FIX(-1.625);
        g_api.PlaySfx(SFX_VO_RIC_DEATH);
        if (damageEffects & ELEMENT_FIRE) {
            func_8015FA5C(0);
            // RIC blueprint 33 has child 31, EntityPlayerBlinkWhite
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x48), 0);
            // RIC blueprint 53 has child 9, func_80161C2C
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_DEATH_BY_FIRE, 2), 0);
            death_kind = DEATH_BY_FIRE;
        } else if (damageEffects & ELEMENT_THUNDER) {
            func_8015FA5C(2);
            // RIC blueprint 33 has child 31, EntityPlayerBlinkWhite
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x4C), 0);
            // RIC blueprint 48 has child 41, EntityHitByLightning
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_HIT_BY_THUNDER, 1), 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_HIT_BY_THUNDER, 2), 0);
            death_kind = DEATH_BY_THUNDER;
        } else if (damageEffects & ELEMENT_ICE) {
            func_8015FA5C(3);
            // RIC blueprint 33 has child 31, EntityPlayerBlinkWhite
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x4D), 0);
            // RIC blueprint 47 has child 40, EntityHitByIce
            RicCreateEntFactoryFromEntity(g_CurrentEntity, 47, 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_HIT_BY_ICE, 1), 0);
            death_kind = DEATH_BY_ICE;
            PLAYER.drawMode = DRAW_TPAGE2 | DRAW_TPAGE;
        } else {
            func_8015FA5C(1);
            // RIC blueprint 33 has child 31, EntityPlayerBlinkWhite
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x4A), 0);
            // RIC blueprint 11 has child 5, RicEntityHitByCutBlood
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_MULTIPLE_EMBERS, 5), 0);
            death_kind = DEATH_GENERIC;
        }
        playerDraw->r0 = playerDraw->g0 = playerDraw->b0 = playerDraw->r1 =
            playerDraw->g1 = playerDraw->b1 = playerDraw->r2 = playerDraw->g2 =
                playerDraw->b2 = playerDraw->r3 = playerDraw->g3 =
                    playerDraw->b3 = 0x80;
        playerDraw->enableColorBlend = 1;
        PLAYER.step_s++;
        break;
    case 1:
        if (PLAYER.pose != 4) {
            break;
        }
        PLAYER.step_s++;
        break;
    case 2:
        // Unusual, FIX usually has denominator of 128
        PLAYER.velocityY += FIX(11.0 / 256);
        if (PLAYER.velocityY > FIX(1.0 / 16)) {
            PLAYER.velocityY >>= 2;
            PLAYER.velocityX >>= 3;
            StoreImage(&D_801545A0, (u_long*)dead_dissolve_bmp);
            D_80174F6C = 0;
            D_80174F68 = 0x40;
            PLAYER.step_s++;
        }
        break;
    case 3:
        if (g_Timer & 1) {
            break;
        }
        if (D_80174F68 > 16) {
            // Another really weird velocityY value.
            // It's 0x233.
            PLAYER.velocityY += FIX(0.0086);
        } else {
            PLAYER.velocityX = 0;
            PLAYER.velocityY = 0;
        }
        for (i = 0; i < 4; i++) {
            s2 = imgPtr = dead_dissolve_bmp;
            s2 += ((D_80174F6C >> 1) & 7);
            s2 += ((D_80174F6C & 0xFF) >> 4) << 6;
            for (j = 0; j < 0x28; j++) {
                if (D_80174F6C & 1) {
                    *(s2 + ((j & 7) * 8) + ((j >> 3) * 0x400)) &= 0xF0;
                } else {
                    *(s2 + ((j & 7) * 8) + ((j >> 3) * 0x400)) &= 0x0F;
                }
            }
            D_80174F6C += 0x23;
            D_80174F6C &= 0xFF;
        }
        LoadImage(&D_801545A0, (u_long*)imgPtr);
        if (--D_80174F68 == 0) {
            PLAYER.velocityY = 0;
            playerDraw->enableColorBlend = 0;
            PLAYER.step_s = 0x80;
        }
        break;
    case 0x80:
        break;
    }
    // Always happens, kind of weird
    if (!disableColorChange) {
        if (death_kind == DEATH_GENERIC) {
            if (playerDraw->r0 < 0xF8) {
                playerDraw->r0 += 2;
            }
            if (playerDraw->b0 > 8) {
                playerDraw->b0 -= 2;
            }

            playerDraw->r3 = playerDraw->r2 = playerDraw->r1 = playerDraw->r0;
            playerDraw->g0 = playerDraw->g1 = playerDraw->b1 = playerDraw->g2 =
                playerDraw->b2 = playerDraw->g3 = playerDraw->b3 =
                    playerDraw->b0;
        }
        if (death_kind == DEATH_BY_FIRE || death_kind == DEATH_BY_THUNDER) {
            if (playerDraw->b0 > 8) {
                playerDraw->b0 -= 2;
            }
            playerDraw->r3 = playerDraw->r2 = playerDraw->r1 = playerDraw->r0 =
                playerDraw->g0 = playerDraw->g1 = playerDraw->b1 =
                    playerDraw->g2 = playerDraw->b2 = playerDraw->g3 =
                        playerDraw->b3 = playerDraw->b0;
        }
        if (death_kind == DEATH_BY_ICE) {
            if ((playerDraw->r0 > 8) && (g_Timer & 1)) {
                playerDraw->r0 -= 1;
            }
            playerDraw->r3 = playerDraw->r2 = playerDraw->r1 = playerDraw->g3 =
                playerDraw->g2 = playerDraw->g1 = playerDraw->g0 =
                    playerDraw->r0;
        }
    }
}

void RicStepStandInAir(void) {
    if (PLAYER.step_s == 0) {
        PLAYER.velocityY += 0x3800;
        if (PLAYER.velocityY > 0) {
            PLAYER.velocityY = 0;
            PLAYER.step_s = 1;
        }
    } else if (g_Player.unk4E) {
        g_Player.unk46 = 0;
        RicSetStep(PL_S_JUMP);
        RicSetAnimation(D_80155528);
        g_Player.unk44 = 0;
    }
    if (g_Player.unk72) {
        PLAYER.velocityY = 0;
    }
}

void RicStepEnableFlameWhip(void) {
    if (PLAYER.animCurFrame == 181 && PLAYER.poseTimer == 1) {
        RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_35, 0);
        g_api.PlaySfx(SFX_WEAPON_APPEAR);
    }

    if (PLAYER.poseTimer < 0) {
        RicSetStand(0);
        g_Player.unk46 = 0;
        RicCreateEntFactoryFromEntity(
            g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x45), 0);
        g_Player.timers[PL_T_POISON] = 0x800;
    }

    if (!(g_Player.vram_flag & 1)) {
        RicSetFall();
        g_Player.unk46 = 0;
        RicCreateEntFactoryFromEntity(
            g_CurrentEntity, FACTORY(BP_RIC_BLINK, 0x45), 0);
        g_Player.timers[PL_T_POISON] = 0x800;
    }
}

void RicStepHydrostorm(void) {
    if (PLAYER.poseTimer < 0) {
        RicSetStand(0);
        g_Player.unk46 = 0;
    }

    if ((g_Player.vram_flag & 1) == 0) {
        RicSetFall();
        g_Player.unk46 = 0;
    }
}

void RicStepGenericSubwpnCrash(void) {
    if (g_Player.unk4E) {
        RicSetStand(0);
        g_Player.unk46 = 0;
    }

    if ((g_Player.vram_flag & 1) == 0) {
        RicSetFall();
        g_Player.unk46 = 0;
    }
}

#if defined(VERSION_PSP)
extern s32 throw_dagger_timer;
#else
static s32 throw_dagger_timer;
#endif
void RicStepThrowDaggers(void) {
    if (PLAYER.step_s == 0) {
        throw_dagger_timer = 0x200;
        PLAYER.step_s++;
    } else {
        RicCheckFacing();
        if (!--throw_dagger_timer) {
            g_Player.unk46 = 0;
            RicSetStand(0);
            g_Player.unk4E = 1;
        }
    }
    if (g_Player.padTapped & PAD_CROSS) {
        RicSetJump();
        g_Player.unk46 = 0;
        g_Player.unk4E = 1;
        throw_dagger_timer = 0;
    }
    if (!(g_Player.vram_flag & 1)) {
        RicSetFall();
        g_Player.unk46 = 0;
        g_Player.unk4E = 1;
        throw_dagger_timer = 0;
    }
}

// This happens when he dies in prologue and gets saved by Maria.
#if defined(VERSION_PSP)
extern s32 dead_prologue_timer;
#else
static s32 dead_prologue_timer;
#endif
void RicStepDeadPrologue(void) {
    switch (PLAYER.step_s) {
    case 0:
        g_CurrentEntity->flags |= FLAG_UNK_10000;
        g_unkGraphicsStruct.unk20 = 4;
        RicDecelerateX(FIX(0.125));
        if (PLAYER.velocityX == 0) {
            RicSetAnimation(D_80155748);
            g_Player.timers[PL_T_INVINCIBLE_SCENE] = 4;
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_MARIA, 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 9), 0);
            D_801545AC = 0;
            PLAYER.step_s++;
        }
        break;
    case 1:
        D_801545AA += 64;
        PLAYER.drawFlags = FLAG_DRAW_SCALEY;
        PLAYER.scaleY = (rsin(D_801545AA) >> 0xA) + 256;
        if (D_801545AC) {
            if (--D_801545AC == 0) {
                PLAYER.drawFlags = FLAG_DRAW_DEFAULT;
                PLAYER.scaleY = 0x100;
                RicCreateEntFactoryFromEntity(
                    g_CurrentEntity, BP_MARIA_POWERS_APPLIED, 0);
                g_DeadPrologueTimer = 0x90;
                PLAYER.step_s++;
            }
        }
        break;
    case 2:
        // In this step, Richter rises into the air, similar to when he uses the
        // Cross subweapon crash.
        if (--g_DeadPrologueTimer == 0) {
            RicSetAnimation(D_801558B4);
            PLAYER.palette = 0x814E;
            g_CurrentEntity->velocityY = FIX(-1);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, BP_REVIVAL_COLUMN, 0);
            g_DeadPrologueTimer = 0x30;
            g_api.PlaySfx(SFX_RIC_SUC_REVIVE);
            dead_prologue_timer = 0xA0;
            PLAYER.step_s++;
        }
        break;
    case 3:
        if (--g_DeadPrologueTimer == 0) {
            PLAYER.velocityY = 0;
            g_DeadPrologueTimer = 0xC0;
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_36, 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_37, 2), 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_38, 3), 0);
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_39, 4), 0);
            PLAYER.palette = 0x813D;
            g_Player.timers[PL_T_INVINCIBLE_SCENE] = 0;
            PLAYER.step_s++;
        }
        if (g_Status.hp < g_Status.hpMax) {
            g_Status.hp++;
        }
        dead_prologue_timer--;
        if ((dead_prologue_timer >= 0) && (dead_prologue_timer % 20 == 0)) {
            g_api.PlaySfx(SFX_RIC_SUC_REVIVE);
        }
        break;
    case 4:
        if (--g_DeadPrologueTimer == 0) {
            g_DeadPrologueTimer = 0x10;
            PLAYER.step_s++;
        }
        if (g_Status.hp < g_Status.hpMax) {
            g_Status.hp++;
        }
        dead_prologue_timer--;
        if ((dead_prologue_timer >= 0) && (dead_prologue_timer % 20 == 0)) {
            g_api.PlaySfx(SFX_RIC_SUC_REVIVE);
        }
        break;
    case 5:
        if (g_DeadPrologueTimer == 5) {
            PLAYER.pose = 6;
            PLAYER.palette = 0x8120;
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_BLUE_SPHERE, 0);
        }
        if (--g_DeadPrologueTimer == 0) {
            RicSetAnimation(D_801558D4);
            g_api.PlaySfx(SFX_WEAPON_APPEAR);
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_BLUE_CIRCLE, 0);
            PLAYER.step_s++;
            break;
        }
        if (g_Status.hp < g_Status.hpMax) {
            g_Status.hp++;
        }
        break;
    case 6:
        if (PLAYER.poseTimer < 0) {
            RicSetAnimation(D_801558DC);
            PLAYER.step_s++;
        }
        break;
    case 7:
        if (PLAYER.poseTimer < 0) {
            g_CurrentEntity->flags &= ~FLAG_UNK_10000;
            g_unkGraphicsStruct.unk20 = 0;
            RicSetFall();
            RicSetAnimation(D_801558DC);
            g_Player.timers[PL_T_INVINCIBLE_SCENE] = 4;
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_RIC_BLINK, 9), 0);
        }
        break;
    }
}

void RicStepSlide(void) {
    s32 isTouchingGround = 0;

    if (PLAYER.facingLeft == 0 && g_Player.vram_flag & 4) {
        isTouchingGround = 1;
    }
    if (PLAYER.facingLeft && g_Player.vram_flag & 8) {
        isTouchingGround = 1;
    }
    if (PLAYER.posX.i.hi >= STAGE_WIDTH - 4 && PLAYER.facingLeft == 0) {
        isTouchingGround = 1;
    }
    if (PLAYER.posX.i.hi <= 4 && PLAYER.facingLeft) {
        isTouchingGround = 1;
    }
    if ((PLAYER.facingLeft == 0 &&
         g_Player.colFloor[2].effects & EFFECT_UNK_8000) ||
        (PLAYER.facingLeft && g_Player.colFloor[3].effects & EFFECT_UNK_8000)) {
        isTouchingGround = 1;
    }
    if (isTouchingGround && PLAYER.pose < 6) {
        PLAYER.pose = 6;
        if (PLAYER.velocityX > FIX(1)) {
            PLAYER.velocityX = FIX(2);
        }
        if (PLAYER.velocityX < FIX(-1)) {
            PLAYER.velocityX = FIX(-2);
        }
        RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_SKID_SMOKE, 0);
    }
    if (PLAYER.pose < 5) {
        if (RicCheckInput(CHECK_FALL | CHECK_CRASH)) {
            return;
        }
        if ((!g_Player.unk72) && (g_Player.padTapped & PAD_CROSS)) {
            PLAYER.posY.i.hi -= 4;
            RicSetSlideKick();
            return;
        }
    } else if (PLAYER.pose < 7) {
        if (RicCheckInput(CHECK_FALL | CHECK_CRASH | CHECK_SLIDE)) {
            return;
        }
    } else if (
        RicCheckInput(CHECK_FALL | CHECK_FACING | CHECK_CRASH | CHECK_SLIDE)) {
        return;
    }

    RicDecelerateX(FIX(0.125));
#if defined(VERSION_PSP)
    FntPrint("pl_pose = %d\n", PLAYER.pose);
    FntPrint("pl_ptimer = %d\n", PLAYER.poseTimer);
#endif
    switch (PLAYER.step_s) {
    case 0:
        if (!(g_GameTimer & 3) && PLAYER.pose < 6 && PLAYER.pose > 2) {
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_SLIDE, 2), 0);
        }
        if (PLAYER.pose == 6 && PLAYER.poseTimer == 1) {
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_SKID_SMOKE, 0);
        }
        if (PLAYER.poseTimer < 0) {
            RicSetCrouch(0, PLAYER.velocityX);
        }
        break;
    }
}

// same as DRA/func_80115C50
static void func_8015BB80(void) {
    if (g_StageId == STAGE_TOP) {
        if (abs((g_Tilemap.left << 8) + g_PlayerX) - 8000 > 0) {
            PLAYER.posX.i.hi--;
        }

        if (abs((g_Tilemap.left << 8) + g_PlayerX) - 8000 < 0) {
            PLAYER.posX.i.hi++;
        }
    }
    if (g_StageId == (STAGE_TOP | STAGE_INVERTEDCASTLE_FLAG)) {
        if (abs((g_Tilemap.left << 8) + g_PlayerX) - 8384 > 0) {
            PLAYER.posX.i.hi--;
        }

        if (abs((g_Tilemap.left << 8) + g_PlayerX) - 8384 < 0) {
            PLAYER.posX.i.hi++;
        }
    }
}

// Corresponding DRA function is PlayerStepTeleport
void RicStepTeleport(void) {
    Entity* e;

    PLAYER.velocityX = PLAYER.velocityY = 0;
    g_Player.padSim = 0;
    g_Player.demo_timer = 4;
    switch (PLAYER.step_s) {
    case 0:
        if (PLAYER.pose == 5 && PLAYER.poseTimer == 1) {
            e = RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_TELEPORT, 0), 0);
            if (!e) {
                PLAYER.poseTimer = 2;
            }
        }
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        break;
    case 1:
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        if (g_Player.warp_flag) {
            RicSetStand(0);
        }
        break;
    case 2:
        func_8015BB80();
        if (PLAYER.pose == 5 && PLAYER.poseTimer == 1) {
            e = RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_TELEPORT, 2), 0);
            if (!e) {
                PLAYER.poseTimer = 2;
            }
        }
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        break;
    case 3:
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        if (g_Player.warp_flag) {
            RicSetStand(0);
        }
        break;
    case 4:
        func_8015BB80();
        if (PLAYER.pose == 5 && PLAYER.poseTimer == 1) {
            e = RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_TELEPORT, 4), 0);
            if (!e) {
                PLAYER.poseTimer = 2;
            }
        }
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        break;
    case 5:
        if (PLAYER.poseTimer < 0) {
            RicSetStand(0);
        }
        if (g_Player.warp_flag) {
            RicSetStand(0);
        }
        break;
    }
}

void RicStepSlideKick(void) {
    // If we are pressing square while in contact with an enemy
    // (as detected in g_Player.unk44), we will bounce back.
    if (g_Player.padPressed & PAD_SQUARE && g_Player.unk44 & 0x80) {
        PLAYER.step = PL_S_JUMP;
        RicSetAnimation(D_8015555C);
        RicSetSpeedX(FIX(-1.5));
        PLAYER.velocityY = 0;
        if (!g_Player.unk72) {
            PLAYER.velocityY = FIX(-4.5);
        }
        g_Player.unk44 |= (8 + 2);
        g_Player.unk44 &= ~4;
        PLAYER.step_s = 2;
        return;
    }
    RicDecelerateX(FIX(0.0625));
    PLAYER.velocityY += 0x1000;

    if (g_Player.vram_flag & 1) {
        g_CurrentEntity->velocityX /= 2;
        RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_SKID_SMOKE, 0);
        PLAYER.facingLeft++;
        PLAYER.facingLeft &= 1;
        RicSetCrouch(3, PLAYER.velocityX);
        g_api.PlaySfx(SFX_STOMP_SOFT_A);
        return;
    }
    if (g_Player.vram_flag & 0xC) {
        PLAYER.velocityX = 0;
    }
    if (PLAYER.velocityX < 0) {
        if (g_Player.padPressed & PAD_RIGHT) {
            RicDecelerateX(FIX(0.125));
        }
        if (PLAYER.velocityX > FIX(-3) || (g_Player.vram_flag & 8)) {
            PLAYER.facingLeft++;
            PLAYER.facingLeft &= 1;
            PLAYER.velocityX /= 2;
            RicSetAnimation(D_80155788);
            g_Player.unk44 = 0xA;
            PLAYER.step_s = 2;
            PLAYER.step = PL_S_JUMP;
        }
    }
    if (PLAYER.velocityX > 0) {
        if (g_Player.padPressed & PAD_LEFT) {
            RicDecelerateX(FIX(0.125));
        }
        if (PLAYER.velocityX < FIX(3) || (g_Player.vram_flag & 4)) {
            PLAYER.facingLeft++;
            PLAYER.facingLeft &= 1;
            PLAYER.velocityX /= 2;
            RicSetAnimation(D_80155788);
            g_Player.unk44 = 0xA;
            PLAYER.step_s = 2;
            PLAYER.step = PL_S_JUMP;
        }
    }
}

void RicStepBladeDash(void) {
    RicDecelerateX(0x1C00);

    if (PLAYER.poseTimer < 0) {
        g_Player.unk46 = 0;
        RicSetStand(0);
    } else if (PLAYER.pose >= 0x12 && !(g_Player.vram_flag & 1)) {
        g_Player.unk46 = 0;
        RicSetFall();
    } else {
        if (!(g_GameTimer & 3) && PLAYER.pose < 0x12 &&
            g_Player.vram_flag & 1) {
            RicCreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(BP_SLIDE, 2), 0);
        }

        if (PLAYER.pose == 18 && PLAYER.poseTimer == 1 &&
            (g_Player.vram_flag & 1)) {
            RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_SKID_SMOKE, 0);
        }
    }
}

void RicStepHighJump(void) {
    bool loadAnim;

#if defined(VERSION_US)
    FntPrint("pl_vram_flag:%04x\n", g_Player.vram_flag);
    FntPrint("pl_high_jump_timer:%04x\n", g_Player.high_jump_timer);
    FntPrint("pl_step_s:%02x\n", PLAYER.step_s);
#endif
    loadAnim = false;
    g_Player.high_jump_timer++;
    switch (PLAYER.step_s) {
    case 0:
        if (g_Player.padPressed & (PAD_LEFT | PAD_RIGHT)) {
            if (PLAYER.facingLeft) {
                if (!(g_Player.padPressed & PAD_LEFT)) {
                    RicDecelerateX(FIX(0.0625));
                }
            } else {
                if (!(g_Player.padPressed & PAD_RIGHT)) {
                    RicDecelerateX(FIX(0.0625));
                }
            }
        } else {
            RicDecelerateX(FIX(0.0625));
        }

        if (g_Player.vram_flag & 2) {
            func_80158B04(3);
            g_Player.high_jump_timer = 0;
            PLAYER.step_s = 2;
        } else if (g_Player.high_jump_timer > 0x1C) {
            PLAYER.step_s = 1;
            PLAYER.velocityY = -0x60000;
        }
        break;
    case 1:
        if (g_Player.vram_flag & 2) {
            PLAYER.step_s = 2;
            func_80158B04(3);
            g_Player.high_jump_timer = 0;
        } else {
            PLAYER.velocityY += 0x6000;
            if (PLAYER.velocityY > 0x8000) {
                loadAnim = true;
            }
        }
        break;
    case 2:
        if (g_Player.high_jump_timer > 4) {
            loadAnim = true;
        }
        break;
    }

    if (loadAnim) {
        RicSetAnimation(D_80155534);
        RicSetStep(PL_S_JUMP);
    }
}
