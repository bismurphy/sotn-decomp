// SPDX-License-Identifier: AGPL-3.0-or-later
#include "dra.h"
#include "dra_bss.h"
#include "objects.h"
#include "sfx.h"

// BSS
extern s32 g_WingSmashButtonCounter;
extern s32 g_WingSmashButtonTimer;
extern s32 g_WingSmashTimer;
extern s32 g_BatScreechDone;
extern s32 g_MistTimer; // remaining time in mist transformation
extern s32 D_80138008;

void func_80115F54(void) {
    PlayerDraw* plDraw;
    bool var_s2;

    var_s2 = false;
    PLAYER.drawFlags = FLAG_DRAW_ROTZ;
    plDraw = g_PlayerDraw;
    if (g_unkGraphicsStruct.unk20 == 0xFFF && PLAYER.step_s != 0) {
        SetPlayerStep(Player_Unk17);
        PLAYER.velocityY = 0;
        PLAYER.velocityX = 0;
        return;
    }

    switch (PLAYER.step_s) {
    case 0:
        var_s2 = true;
        PLAYER.velocityY = 0;
        PLAYER.velocityX = 0;
        PlaySfx(SFX_VO_ALU_DEATH);
        func_80113EE0();
        PLAYER.velocityY = -0x1A000;
        PLAYER.ext.player.anim = 0xC1;
        PLAYER.drawMode = DRAW_TPAGE2 | DRAW_TPAGE;
        PLAYER.rotZ = 0x200;
        func_80118C28(1);
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 0x59), 0);
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(49, 6), 0);
        plDraw->r3 = plDraw->b3 = plDraw->g3 = 128;
        plDraw->r2 = plDraw->b2 = plDraw->g2 = 128;
        plDraw->r1 = plDraw->b1 = plDraw->g1 = 128;
        plDraw->r0 = plDraw->b0 = plDraw->g0 = 128;
        plDraw->enableColorBlend = true;
        PLAYER.step_s++;
        break;
    case 1:
        if (plDraw->g0 < 0xF8) {
            plDraw->g0++;
        }
        if (plDraw->r0 >= 9) {
            plDraw->r0--;
        }
        plDraw->g3 = plDraw->g2 = plDraw->g1 = plDraw->g0;
        plDraw->b0 = plDraw->b1 = plDraw->r1 = plDraw->b2 = plDraw->r2 =
            plDraw->b3 = plDraw->r3 = plDraw->r0;
        PLAYER.velocityY += 0x1000;
        if (PLAYER.velocityY > 0x4000) {
            PLAYER.velocityY = 0x1000;
        }
        if (PLAYER.animFrameDuration < 0) {
            StoreImage(&D_800AE130, D_80139A7C);
            PLAYER.step = 0x10;
            D_80137FE4 = 0;
            D_80137FE8 = 0x40;
            g_CurrentEntity->step_s++;
        }
        break;
    }

    if (var_s2 && g_Player.unk72) {
        PLAYER.velocityY = 0;
    }
}

void func_80116208(void) {
    DamageParam damage;
    s32 temp_s0;

    switch (g_CurrentEntity->step_s) {
    case 0:
        func_80113EE0();
        if (g_Player.unk62 == 0) {
            PLAYER.ext.player.anim = 0x37;
            g_Player.timers[2] = 8;
            g_Player.unk40 = 0x8166;
            PlaySfx(SFX_VO_ALU_PAIN_E);
        }
        PLAYER.step_s = 1;
        PLAYER.velocityY = 0;
        PLAYER.velocityX = 0;
        g_Player.unk60 = 2;
        return;
    case 1:
        if (g_Player.unk60 == 3) {
            temp_s0 = HandleDamage(&damage, DAMAGEKIND_2, g_Player.unk64, 1);
            CreateHPNumMove(damage.damageTaken, 0);
            if (temp_s0 == 4) {
                SetPlayerStep(Player_Kill);
                func_80115394(&damage, Player_BossGrab, 1);
                return;
            }
            if (g_Player.unk62 == 0) {
                g_Player.timers[2] = 4;
                g_Player.unk40 = 0x8166;
                PlaySfx(SFX_VO_ALU_PAIN_A);
            }
            if (g_Player.unk62 == 2) {
                g_Player.timers[2] = 4;
                g_Player.unk40 = 0x8161;
            }
            g_Player.unk60 = 2;
            return;
        }
        if (g_Player.unk60 == 4) {
            PLAYER.step = Player_Hit;
            PLAYER.step_s = 0xF;
            g_Player.unk60 = 0;
            SetPlayerAnim(0x2E);
            g_Player.damageTaken = g_Player.unk64;
            PlaySfx(SFX_VO_ALU_YELL);
            return;
        }
        if (g_Player.unk60 == 0) {
            PLAYER.step = Player_Hit;
            PLAYER.step_s = 1;
            return;
        }
    }
}
// Called in EntityAlucard when PLAYER.step is Player_SpellHellfire
void PlayerStepHellfire(void) {
    // Whether we should run the last 3 function calls at the end
    bool runFinishingBlock = 0;
    switch (PLAYER.step_s) {
    case 0:
        // Make factory with blueprint #33. Factory makes entities with ID 25.
        // This is EntityHellfireHandler.
        if (CreateEntFactoryFromEntity(g_CurrentEntity, 33, 0) == NULL) {
            func_8010E570(0);
        }
        SetPlayerAnim(1);
        PLAYER.step_s++;
        break;
    case 1:
        if (g_Player.unk5C == 1) {
            PLAYER.step_s++;
        }
        break;
    case 2:
        PLAYER.velocityX = 0;
        if (CheckMoveDirection() != 0) {
            if (g_Player.padPressed & PAD_RIGHT) {
                if ((g_Player.colFloor[2].effects &
                     (EFFECT_UNK_8000 + EFFECT_SOLID)) ||
                    (g_Player.colFloor[1].effects & EFFECT_UNK_8000) ||
                    (PLAYER.posX.i.hi > 248)) {
                    SetSpeedX(FIX(3));
                }
            } else if ((g_Player.colFloor[3].effects &
                        (EFFECT_UNK_8000 + EFFECT_SOLID)) ||
                       (g_Player.colFloor[1].effects & EFFECT_UNK_8000) ||
                       (PLAYER.posX.i.hi < 8)) {
                SetSpeedX(FIX(3));
            }
        }
        if (g_Player.unk5C == 2) {
            PLAYER.velocityX = 0;
            SetPlayerAnim(0x3D);
            PLAYER.step_s++;
        }
        break;
    case 3:
        CheckMoveDirection();
        if (g_Player.unk5C == 3) {
            SetPlayerAnim(0x3C);
            PLAYER.step_s += 1;
            // In Hellfire, if you press down, it cancels the spell
            if (g_Player.padPressed & PAD_DOWN) {
                runFinishingBlock = 1;
            }
        }
        break;
    case 4:
        if (PLAYER.animFrameIdx == 10 && PLAYER.animFrameDuration == 1) {
            g_Player.timers[12] = 4;
            // Make factory with blueprint 37. This creates entity with ID 28,
            // which is EntityExpandingCircle.
            CreateEntFactoryFromEntity(g_CurrentEntity, 37, 0);
        }
        if (PLAYER.animFrameDuration < 0) {
            runFinishingBlock = 1;
        }
        break;
    }
    // Not sure why this cast to u16 is needed but it is
    if (((u16)runFinishingBlock) || (g_Player.unk5C == 0xFFFF)) {
        func_8010E570(0);
        SetPlayerAnim(0x3D);
        func_80111CC0();
    }
}

void func_801166A4(void) {
    switch (PLAYER.step_s) {
    case 0:
        func_80113EE0();
        g_Player.unk40 = 0x8166;
        g_Player.timers[2] = 6;
        PLAYER.velocityX = 0;
        PLAYER.velocityY = 0;
        PLAYER.ext.player.anim = 0x33;
        CreateEntFactoryFromEntity(g_CurrentEntity, 0, 0);
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 0x58), 0);
        PLAYER.step_s++;
        break;

    case 1:
        if (PLAYER.animFrameDuration < 0) {
            PlaySfx(SFX_VO_ALU_WHAT);
            func_8010E570(0);
        }
        break;

    default:
        break;
    }
}

void func_8011678C(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    if ((g_Player.padSim >> 16) != 2) {
        func_8010E570(0);
    }
}

void func_801167D0(void) {
    s32* velocityX = &PLAYER.velocityX;
    PLAYER.velocityY = 0;
    *velocityX = 0;
    if ((g_Player.padSim >> 16) != 2) {
        PLAYER.step = Player_AxearmorStand;
        PLAYER.step_s = 0;
        PLAYER.velocityY = 0;
        *velocityX = 0;
        PLAYER.ext.player.anim = 0xCF;
        PLAYER.animFrameIdx = 0;
        PLAYER.animFrameDuration = 0;
    }
}

bool BatFormFinished(void) {
    if (PLAYER.step_s == 0) {
        return false;
    }
    if (D_80097448[1] || g_Player.padTapped & PAD_R1 ||
        HandleTransformationMP(FORM_BAT, REDUCE) < 0) {
        SetPlayerStep(Player_UnmorphBat);
        SetPlayerAnim(0xCA);
        D_800AFDA4[1] = 6;
        g_Entities->palette = PAL_OVL(0x10D);
        g_Player.unk66 = 0;
        g_Player.unk68 = 0;
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 0x21), 0);
        PLAYER.velocityY >>= 1;
        return true;
    }
    return false;
}

void func_8011690C(s16 arg0) {
    if (PLAYER.rotZ < arg0) {
        PLAYER.rotZ += 16;
        if (arg0 < PLAYER.rotZ) {
            PLAYER.rotZ = arg0;
        }
    }
    if (arg0 < PLAYER.rotZ) {
        PLAYER.rotZ -= 16;
        if (PLAYER.rotZ < arg0) {
            PLAYER.rotZ = arg0;
        }
    }
}

s32 CheckWingSmashInput(void) {
    u32 directionsPressed;
    s32 backward;
    s32 forward;
    s32 up;
    s32 down;

    directionsPressed =
        g_Player.padPressed & (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT);
    up = PAD_UP;
    down = PAD_DOWN;
    if (PLAYER.facingLeft) {
        forward = PAD_LEFT;
        backward = PAD_RIGHT;
    } else {
        backward = PAD_LEFT;
        forward = PAD_RIGHT;
    }
    // Counter tells us how many correct buttons have been given in the
    // sequence. In each case, if we aren't pressing the right buttons, we
    // decrement the timer If the timer expires, progress gets wiped. Otherwise
    // we register the correct button by incrementing counter and resetting
    // timer to 20 frames.
    switch (g_WingSmashButtonCounter) {
    case 0:
        if (directionsPressed != up) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 1:
        if (directionsPressed != (backward + up)) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 2:
        if (directionsPressed != backward) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 3:
        if (directionsPressed != (down + backward)) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 4:
        if (directionsPressed != down) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 5:
        if (directionsPressed != (down + forward)) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 6:
        if (directionsPressed != forward) {
            if (--g_WingSmashButtonTimer == 0) {
                g_WingSmashButtonCounter = 0;
            }
            break;
        }
        g_WingSmashButtonTimer = 0x14;
        g_WingSmashButtonCounter++;
        break;
    case 7: // All buttons are in, nothing more to test for.
        if (--g_WingSmashButtonTimer == 0) {
            g_WingSmashButtonCounter = 0;
        }
    }
    // If we're not pressing cross (and we haven't put in all the buttons)
    // then all progress is lost.
    if (!(g_Player.padPressed & PAD_CROSS) && (g_WingSmashButtonCounter != 7)) {
        g_WingSmashButtonCounter = 0;
    }
    // And then we return 7 if all 7 buttons in the input were correctly
    // provided.
    return g_WingSmashButtonCounter == 7;
}

void ControlBatForm(void) {
    Entity* newEntity;
    s32 pressingCross;
    // When we initially move left/right, bat makes a screech sound.
    s32 screechDone;
    s16 x_offset;
    u32 directionsPressed;

    screechDone = 0;
    if (BatFormFinished()) {
        return;
    }

    directionsPressed =
        g_Player.padPressed & (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT);
    pressingCross = g_Player.padPressed & PAD_CROSS;
    PLAYER.drawFlags = FLAG_DRAW_ROTZ;
    PLAYER.rotPivotY = 0;

#if defined(VERSION_HD)
    if (PLAYER.step_s != 3) {
#else
    // Just to make the curly brackets match at the end of this block
    if (1) {
#endif
        if (CheckWingSmashInput() && (!pressingCross) && (PLAYER.step_s) &&
            CastSpell(SPELL_WING_SMASH)) {
            LearnSpell(SPELL_WING_SMASH);
            SetPlayerAnim(0xC6);
            SetSpeedX(FIX(6));
            PLAYER.step_s = 3;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 0x5c), 0);
            CreateEntFactoryFromEntity(g_CurrentEntity, 67, 0);
            g_WingSmashTimer = 0x40;
#if !defined(VERSION_HD)
            g_WingSmashButtonCounter = 0;
#endif
        } else if ((g_Player.padTapped & PAD_TRIANGLE) &&
                   (PLAYER.step_s == 1 || PLAYER.step_s == 2) &&
                   (IsRelicActive(RELIC_ECHO_OF_BAT))) {
            CreateEntFactoryFromEntity(g_CurrentEntity, 103, 0);
        } else if ((g_Player.padTapped & (PAD_SQUARE | PAD_CIRCLE)) &&
                   (PLAYER.step_s == 1 || PLAYER.step_s == 2) &&
                   (IsRelicActive(RELIC_FIRE_OF_BAT)) && (CastSpell(9))) {
            SetPlayerAnim(0xC9);
            PLAYER.step_s = 4;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 5), 0);
        }
    }

    switch (PLAYER.step_s) {
    case 0:
        g_WingSmashButtonCounter = 0;
        PLAYER.rotZ = 0;
        g_Player.unk44 = g_Player.unk46 = g_Player.unk48 = 0;
        if (g_Entities[16].entityId == 0x22) {
            PLAYER.unk5A = 0;
            PLAYER.animSet = 13;
            D_800AFDA4[1] = 6;
            PLAYER.ext.player.anim = 0xCA;
            if (!func_8011203C()) {
                return;
            }
        } else {
            if (g_Player.unk66 == 0) {
                newEntity = CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(44, 0x20), 0);
#if !defined(VERSION_HD)
                if (newEntity == NULL) {
                    return;
                }
#endif
                func_8010FAF4();
                g_Player.unk66++;
            }
            DecelerateX(0x480);
            DecelerateY(0x480);
            if (abs(PLAYER.velocityY) > FIX(1.25)) {
                if (PLAYER.velocityY > 0) {
                    PLAYER.velocityY = FIX(1.25);
                } else {
                    PLAYER.velocityY = FIX(-1.25);
                }
            }
            SetPlayerAnim(0xCA);
            D_800AFDA4[1] = PLAYER.animCurFrame;
            PLAYER.palette = 0x810D;
            if (g_Player.unk66 == 1) {
                return;
            }
            if (g_Player.unk66 == 2) {
                PLAYER.unk5A = 0;
                PLAYER.animSet = 0xD;
                D_800AFDA4[1] = 6;
                return;
            }
        }
        SetPlayerAnim(0xC3);
        PLAYER.animFrameDuration = 1;
        PLAYER.animFrameIdx = 2;
        PLAYER.palette = 0x8100;
        CheckMoveDirection();
        PLAYER.step_s++;
        break;
    case 1:
        if (directionsPressed && !pressingCross) {
            if (PLAYER.ext.player.anim == 0xC3) {
                PLAYER.animFrameIdx /= 3;
            }
            PLAYER.step_s++;
        } else {
            func_8011690C(0);
            DecelerateX(0x1200);
            DecelerateY(0x1200);
            break;
        }
    case 2:
        // If you're pressing cross, you can't move and inputs are ignored.
        if (pressingCross) {
            directionsPressed = 0;
        }
        switch (directionsPressed) {
        case 0:
        default:
            SetPlayerAnim(0xC3);
            PLAYER.step_s = 1;
            break;
        case PAD_UP:
            PLAYER.ext.player.anim = 0xC2;
            if (PLAYER.velocityY < FIX(-1.25)) {
                DecelerateY(0x1200);
            } else {
                PLAYER.velocityY = FIX(-1.25);
            }
            func_8011690C(-0x80);
            DecelerateX(0x1200);
            break;
        case PAD_DOWN:
            if (g_Player.pl_vram_flag & 1) {
                PLAYER.ext.player.anim = 0xC4;
            } else {
                PLAYER.ext.player.anim = 0xC5;
            }
            if (PLAYER.velocityY > FIX(1.25)) {
                DecelerateY(0x1200);
            } else {
                PLAYER.velocityY = FIX(1.25);
            }
            func_8011690C(0);
            DecelerateX(0x1200);
            break;
        case PAD_RIGHT:
            PLAYER.ext.player.anim = 0xC2;
            PLAYER.facingLeft = 0;
            func_8011690C(0x180);
            if (PLAYER.velocityX > FIX(1.25)) {
                DecelerateX(0x1200);
            } else {
                PLAYER.velocityX = FIX(1.25);
            }
            DecelerateY(0x1200);
            if (!g_BatScreechDone) {
                PlaySfx(SFX_BAT_SCREECH);
            }
            screechDone = 1;
            break;
        case PAD_LEFT:
            PLAYER.ext.player.anim = 0xC2;
            PLAYER.facingLeft = 1;
            func_8011690C(0x180);
            if (PLAYER.velocityX < FIX(-1.25)) {
                DecelerateX(0x1200);
            } else {
                PLAYER.velocityX = FIX(-1.25);
            }
            DecelerateY(0x1200);
            if (!g_BatScreechDone) {
                PlaySfx(SFX_BAT_SCREECH);
            }
            screechDone = 1;
            break;
        case PAD_RIGHT | PAD_UP:
            PLAYER.ext.player.anim = 0xC2;
            PLAYER.facingLeft = 0;
            func_8011690C(0x80);
            if (PLAYER.velocityX > FIX(0.875)) {
                DecelerateX(0xC00);
            } else {
                PLAYER.velocityX = FIX(0.875);
            }
            if (PLAYER.velocityY < FIX(-0.875)) {
                DecelerateY(0xC00);
            } else {
                PLAYER.velocityY = FIX(-0.875);
            }
            break;
        case PAD_LEFT | PAD_UP:
            PLAYER.ext.player.anim = 0xC2;
            PLAYER.facingLeft = 1;
            func_8011690C(0x80);
            if (PLAYER.velocityX < FIX(-0.875)) {
                DecelerateX(0xC00);
            } else {
                PLAYER.velocityX = FIX(-0.875);
            }
            if (PLAYER.velocityY < FIX(-0.875)) {
                DecelerateY(0xC00);
            } else {
                PLAYER.velocityY = FIX(-0.875);
            }
            break;
        case PAD_RIGHT | PAD_DOWN:
            if (g_Player.pl_vram_flag & 1) {
                PLAYER.ext.player.anim = 0xC4;
            } else {
                PLAYER.ext.player.anim = 0xC5;
            }
            PLAYER.facingLeft = 0;
            func_8011690C(0);
            if (PLAYER.velocityX > FIX(0.875)) {
                DecelerateX(0xC00);
            } else {
                PLAYER.velocityX = FIX(0.875);
            }
            if (PLAYER.velocityY > FIX(1.75)) {
                DecelerateY(0xC00);
            } else {
                PLAYER.velocityY = FIX(1.75);
            }
            break;
        case PAD_LEFT | PAD_DOWN:
            if (g_Player.pl_vram_flag & 1) {
                PLAYER.ext.player.anim = 0xC4;
            } else {
                PLAYER.ext.player.anim = 0xC5;
            }
            PLAYER.facingLeft = 1;
            func_8011690C(0);
            if (PLAYER.velocityX < FIX(-0.875)) {
                DecelerateX(0xC00);
            } else {
                PLAYER.velocityX = FIX(-0.875);
            }
            if (PLAYER.velocityY > FIX(1.75)) {
                DecelerateY(0xC00);
            } else {
                PLAYER.velocityY = FIX(1.75);
            }
            break;
        }
        break;
    case 3:
        if (!PLAYER.facingLeft && (g_Player.pl_vram_flag & 4) ||
            PLAYER.facingLeft && (g_Player.pl_vram_flag & 8)) {
            g_Player.padTapped = PAD_R1;
            BatFormFinished();
            func_80102CD8(2);
            PlaySfx(SFX_WALL_DEBRIS_B);
            PLAYER.velocityX = 0;
            g_Player.D_80072EFC = 0x20;
            g_Player.padSim = 0;
            break;
        }
        // When wing smash ends, force an un-transform
        if (--g_WingSmashTimer == 0) {
            g_Player.padTapped = PAD_R1;
            BatFormFinished();
            g_Player.D_80072EFC = 0x20;
            g_Player.padSim = 0;
        } else {
            if (directionsPressed & PAD_UP) {
                PLAYER.velocityY -= FIX(0.125);
                func_8011690C(0x80);
            }
            if (directionsPressed & PAD_DOWN) {
                PLAYER.velocityY += FIX(0.125);
            }
            if (!(directionsPressed & PAD_UP)) {
                func_8011690C(0x180);
            }
            if (!(directionsPressed & (PAD_DOWN | PAD_UP))) {
                DecelerateY(0x2000);
            }
            if (g_Player.pl_vram_flag & 0x800) {
                if (PLAYER.facingLeft && (g_Player.pl_vram_flag & 0x400) ||
                    !PLAYER.facingLeft && !(g_Player.pl_vram_flag & 0x400)) {
                    PLAYER.velocityY = FIX(6);
                }
            }
            if (g_Player.pl_vram_flag & 0x8000) {
                if (PLAYER.facingLeft && (g_Player.pl_vram_flag & 0x4000) ||
                    !PLAYER.facingLeft && !(g_Player.pl_vram_flag & 0x4000)) {
                    PLAYER.velocityY = FIX(-6);
                }
            }
            if (PLAYER.velocityY < FIX(-6)) {
                PLAYER.velocityY = FIX(-6);
            }
            if (PLAYER.velocityY > FIX(6)) {
                PLAYER.velocityY = FIX(6);
            }
            if (g_GameTimer % 3 == 0) {
                CreateEntFactoryFromEntity(g_CurrentEntity, 65, 0);
                if (g_Player.pl_vram_flag & 1) {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(69, 9), 0);
                }
                if (g_Player.pl_vram_flag & 2) {
                    x_offset = 3;
                    if (PLAYER.facingLeft) {
                        x_offset = -x_offset;
                    }
                    PLAYER.posY.i.hi -= 8;
                    PLAYER.posX.i.hi += x_offset;
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(4, 1), 0);
                    PLAYER.posY.i.hi += 8;
                    PLAYER.posX.i.hi -= x_offset;
                }
            }
        }
        break;
    // Happens when shooting fireball with Fire of Bat
    case 4:
        DecelerateX(FIX(12.0 / 128));
        DecelerateY(FIX(28.0 / 128));
        func_8011690C(0x180);
        if (PLAYER.animFrameDuration < 0) {
            // This actually creates the entity factory to produce the fireball
            CreateEntFactoryFromEntity(g_CurrentEntity, 81, 0);
            SetSpeedX(FIX(-1.5));
            func_8011690C(0);
            SetPlayerAnim(0xC3);
            PLAYER.step_s++;
        }
        break;
    // Finishing up on the fireball
    case 5:
        DecelerateX(FIX(12.0 / 128));
        DecelerateY(FIX(28.0 / 128));
        func_8011690C(0);
        if (PLAYER.ext.player.anim == 0xC4 && PLAYER.animFrameIdx == 8) {
            PLAYER.step_s = 1;
        }
        break;
    }

    if (D_8013AECC != 0) {
        if (PLAYER.velocityX > 0) {
            PLAYER.velocityX = 0;
        }
    }
    if (D_8013AECC != 0) {
        if (D_8013AECC > 0) {
            D_8013AECC--;
            g_CurrentEntity->posY.i.hi++;
        } else {
            D_8013AECC++;
            g_CurrentEntity->posY.i.hi--;
        }
    }
    g_BatScreechDone = screechDone;
}

void func_801177A0(void) {
    byte pad[0x28];
    s32 i;
    s32 else_cycles;

    PLAYER.drawFlags = FLAG_DRAW_ROTZ;
    DecelerateX(0x2000);
    if (g_Player.pl_vram_flag & 3) {
        PLAYER.velocityY = 0;
    }
    DecelerateY(0x2000);
    func_8011690C(0);
    else_cycles = 0;
    switch (PLAYER.step_s) {
    case 0:
        for (i = 0; i < 4; i++) {
            if (g_SensorsFloor[i].y < g_SensorsFloorDefault[i]) {
                g_SensorsFloor[i].y++;
            } else {
                else_cycles++;
            }
            if (g_SensorsCeilingDefault[i] < g_SensorsCeiling[i].y) {
                g_SensorsCeiling[i].y--;
            } else {
                else_cycles++;
            }
            // This means the lower parts only run once!
            if (i != 0) {
                continue;
            }
            if (g_Player.unk68 != 0) {
                if (D_8013AECC >= 12) {
                    continue;
                }
                D_8013AECC++;
            } else {
                if (g_Player.pl_vram_flag & 0x8000) {
                    PLAYER.posY.i.hi--;
                }
            }
        }

        if ((g_Player.pl_vram_flag & 3) == 3) {
            g_Player.unk68 = 1;
            PLAYER.velocityY = 0;
            PLAYER.velocityX = 0;
        }
        if (else_cycles == 8) {
            PLAYER.animSet = 1;
            PLAYER.rotZ = 0;
            PLAYER.drawFlags = FLAG_DRAW_DEFAULT;
            g_Player.unk66 = 1;
            if (g_Player.unk68 != 0) {
                PLAYER.step_s = 2;
                D_800AFDA4[1] = 0xC7;
            } else {
                PLAYER.step_s = 1;
                D_800AFDA4[1] = 0x5F;
            }
        }
        break;
    case 1:
        if (g_Player.unk66 == 3) {
            func_8010E83C(0);
            PLAYER.posY.i.hi -= 3;
            if (!(g_Player.pl_vram_flag & 0x8000)) {
                PLAYER.velocityY = FIX(-1);
            }
            PLAYER.palette = 0x8100;
#if defined(VERSION_US)
            g_Player.unk20 = 0x18;
#elif defined(VERSION_HD)
            D_800ACEDC_hd = 0x18;
#endif
            g_Player.unk44 |= 0x100;
            func_80111CC0();
        }
        break;
    case 2:
        if (g_Player.unk66 == 3) {
            func_8010E4D0();
        }
        break;
    }
    if (func_80111DE8(0) != 0) {
        PLAYER.velocityX = 0;
    }
}

void func_80117AC0(void) {
    Collider collider;
    s32 collisionCount;

    CheckCollision(PLAYER.posX.i.hi, PLAYER.posY.i.hi + 0x19, &collider, 0);
    collisionCount = (s32)collider.effects & EFFECT_SOLID;
    CheckCollision(PLAYER.posX.i.hi + 4, PLAYER.posY.i.hi + 0x19, &collider, 0);
    if ((s32)collider.effects & EFFECT_SOLID) {
        collisionCount += 1;
    }
    CheckCollision(PLAYER.posX.i.hi - 4, PLAYER.posY.i.hi + 0x19, &collider, 0);
    if ((s32)collider.effects & EFFECT_SOLID) {
        collisionCount += 1;
    }
    if ((g_Player.pl_vram_flag & 0x41) == 0x41) {
        collisionCount += 1;
    }
    PLAYER.rotZ = 0;
    CheckMoveDirection();
    if (collisionCount == 0) {
        func_8010E7AC();
        return;
    }

    switch (PLAYER.step_s) {
    case 0:
        if (PLAYER.animFrameDuration < 0) {
            SetPlayerAnim(0xF6);
            PLAYER.step_s += 1;
        }
        break;
    case 1:
        if (g_Player.padTapped & (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT)) {
            SetPlayerAnim(0xC8);
            PlaySfx(SFX_VO_ALU_ATTACK_A);
            PLAYER.step_s = 0;
        } else if (g_Player.unk72 == 1) {
            PLAYER.animFrameIdx = 0;
            PLAYER.animFrameDuration = 3;
        } else if (g_Player.unk72 == 2) {
            if (PLAYER.animFrameIdx != 0) {
                PLAYER.animFrameIdx = 1;
                PLAYER.animFrameDuration = 3;
            }
        } else if (g_Player.unk72 == 3) {
            if (PLAYER.animFrameIdx >= 2) {
                PLAYER.animFrameIdx = 2;
                PLAYER.animFrameDuration = 3;
                PLAYER.step = 2;
                PLAYER.step_s = 5;
            }
        } else if (g_Player.unk72 == 4) {
            if (PLAYER.animFrameIdx >= 3) {
                PLAYER.animFrameIdx = 3;
                PLAYER.animFrameDuration = 3;
                PLAYER.step = 2;
                PLAYER.step_s = 5;
            }
        }
        break;
    }
}

bool MistFormFinished(void) {
    if (PLAYER.step_s == 0) {
        return 0;
    }
    if (D_80097448[1] != 0 || g_Player.padTapped & PAD_L1 ||
        HandleTransformationMP(FORM_MIST, REDUCE) < 0 ||
        (!IsRelicActive(RELIC_POWER_OF_MIST) &&
         (g_MistTimer == 0 || --g_MistTimer == 0))) {
        CheckMoveDirection();
        SetPlayerStep(0xE);
        return 1;
    }
    return 0;
}

void ControlMistForm(void) {
    s32 xSpeedDiag;
    s32 ySpeedDiag;
    s32 ySpeedOrtho;
    s32 xSpeedOrtho;
    u32 directionsPressed;

    if (!IsRelicActive(RELIC_POWER_OF_MIST)) {
        // Ortho and Diag describe the speeds when moving orthogonally (in a
        // single direction) versus moving diagonally (in two directions at
        // once). Overall speed diagonally is 5/16 * sqrt(2) which is 0.442, so
        // a fair bit slower than orthogonal speed.
        xSpeedOrtho = FIX(0.5);
        ySpeedOrtho = FIX(0.5);
        xSpeedDiag = FIX(5.0 / 16);
        ySpeedDiag = FIX(5.0 / 16);
    } else {
        // With Power of Mist, we move at double speed.
        xSpeedOrtho = FIX(1);
        ySpeedOrtho = FIX(1);
        xSpeedDiag = FIX(10.0 / 16);
        ySpeedDiag = FIX(10.0 / 16);
    }
    if (MistFormFinished()) {
        return;
    }
    directionsPressed =
        g_Player.padPressed & (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT);
    switch (PLAYER.step_s) {
    case 0:
        func_800EA5E4(0x1BU);
        CheckMoveDirection();
        g_Player.unk48 = 0;
        g_Player.unk46 = 0;
        g_Player.unk44 = 0;
        func_8010FAF4();
        CreateEntFactoryFromEntity(g_CurrentEntity, 73, 0);
        if (PLAYER.velocityX > 0) {
            PLAYER.velocityX = xSpeedOrtho;
        }
        if (PLAYER.velocityX < 0) {
            PLAYER.velocityX = -xSpeedOrtho;
        }
        if (PLAYER.velocityY > 0) {
            PLAYER.velocityY = ySpeedOrtho;
        }
        if (PLAYER.velocityY < 0) {
            PLAYER.velocityY = -ySpeedOrtho;
        }
        SetPlayerAnim(0xCA);
        D_800AFDA4[1] = PLAYER.animCurFrame;
        func_800EA538(8);
        if (!IsRelicActive(RELIC_GAS_CLOUD)) {
            func_800EA5E4(0x11CU);
        } else {
            func_800EA5E4(0x11FU);
            CreateEntFactoryFromEntity(g_CurrentEntity, 83, 0);
        }
        // Note that this means Power of Mist doesn't make mist infinite!
        // It just lasts 100,000 :)
        if (!IsRelicActive(RELIC_POWER_OF_MIST)) {
            g_MistTimer = 16;
        } else {
            g_MistTimer = 100000;
        }
        PLAYER.step_s += 1;
        break;
    case 1:
        switch (directionsPressed) {
        case 0:
        default:
            DecelerateX(FIX(3.0 / 256));
            DecelerateY(FIX(3.0 / 256));
            break;
        case PAD_UP:
            if (PLAYER.velocityY < -ySpeedOrtho) {
                DecelerateY(FIX(3.0 / 256));
            } else {
                PLAYER.velocityY = -ySpeedOrtho;
            }
            DecelerateX(FIX(3.0 / 256));
            break;
        case PAD_DOWN:
            if (ySpeedOrtho < PLAYER.velocityY) {
                DecelerateY(FIX(3.0 / 256));
            } else {
                PLAYER.velocityY = ySpeedOrtho;
            }
            DecelerateX(FIX(3.0 / 256));
            break;
        case PAD_RIGHT:
            PLAYER.facingLeft = 0;
            if (xSpeedOrtho < PLAYER.velocityX) {
                DecelerateX(FIX(3.0 / 256));
            } else {
                PLAYER.velocityX = xSpeedOrtho;
            }
            DecelerateY(FIX(3.0 / 256));
            break;
        case PAD_LEFT:
            PLAYER.facingLeft = 1;
            if (PLAYER.velocityX < -xSpeedOrtho) {
                DecelerateX(FIX(3.0 / 256));
            } else {
                PLAYER.velocityX = -xSpeedOrtho;
            }
            DecelerateY(FIX(3.0 / 256));
            break;
        case PAD_UP + PAD_RIGHT:
            PLAYER.facingLeft = 0;
            if (xSpeedDiag < PLAYER.velocityX) {
                DecelerateX(FIX(2.0 / 256));

            } else {
                PLAYER.velocityX = xSpeedDiag;
            }
            if (PLAYER.velocityY < -ySpeedDiag) {
                DecelerateY(FIX(2.0 / 256));
            } else {
                PLAYER.velocityY = -ySpeedDiag;
            }
            break;
        case PAD_UP + PAD_LEFT:
            PLAYER.facingLeft = 1;
            if (PLAYER.velocityX < -xSpeedDiag) {
                DecelerateX(FIX(2.0 / 256));
            } else {
                PLAYER.velocityX = -xSpeedDiag;
            }
            if (PLAYER.velocityY < -ySpeedDiag) {
                DecelerateY(FIX(2.0 / 256));
            } else {
                PLAYER.velocityY = -ySpeedDiag;
            }
            break;
        case PAD_DOWN + PAD_RIGHT:
            PLAYER.facingLeft = 0;
            if (xSpeedDiag < PLAYER.velocityX) {
                DecelerateX(FIX(2.0 / 256));
            } else {
                PLAYER.velocityX = xSpeedDiag;
            }
            if (ySpeedDiag < PLAYER.velocityY) {
                DecelerateY(FIX(2.0 / 256));
            } else {
                PLAYER.velocityY = ySpeedDiag;
            }
            break;
        case PAD_DOWN + PAD_LEFT:
            PLAYER.facingLeft = 1;
            if (PLAYER.velocityX < -xSpeedDiag) {
                DecelerateX(FIX(2.0 / 256));
            } else {
                PLAYER.velocityX = -xSpeedDiag;
            }
            if (ySpeedDiag < PLAYER.velocityY) {
                DecelerateY(FIX(2.0 / 256));
            } else {
                PLAYER.velocityY = ySpeedDiag;
            }
            break;
        }
        break;
    default:
        FntPrint("error step\n");
        break;
    }
    if (D_8013AECC != 0) {
        if (D_8013AECC > 0) {
            D_8013AECC -= 1;
            PLAYER.posY.i.hi++;
        } else {
            D_8013AECC += 1;
            PLAYER.posY.i.hi--;
        }
    }
}

void func_801182F8(void) {
    byte pad[0x28];
    s32 i;
    s32 else_cycles;

    if ((g_Player.pl_vram_flag & 1) && (PLAYER.velocityY > 0)) {
        PLAYER.velocityY = 0;
    }
    if ((g_Player.pl_vram_flag & 2) && (PLAYER.velocityY < 0)) {
        PLAYER.velocityY = 0;
    }
    DecelerateX(0x200);
    DecelerateY(0x200);
    else_cycles = 0;
    for (i = 0; i < 4; i++) {
        if (g_SensorsFloor[i].y < g_SensorsFloorDefault[i]) {
            g_SensorsFloor[i].y++;
        } else {
            else_cycles++;
        }
        if (g_SensorsCeilingDefault[i] < g_SensorsCeiling[i].y) {
            g_SensorsCeiling[i].y--;
        } else {
            else_cycles++;
        }
        // This means the lower parts only run once!
        if (i != 0) {
            continue;
        }
        if (PLAYER.step_s != 0) {
            if (D_8013AECC >= 12) {
                continue;
            }
            D_8013AECC++;
        } else {
            if (g_Player.pl_vram_flag & 0x8000) {
                PLAYER.posY.i.hi--;
            }
        }
    }
    if ((g_Player.pl_vram_flag & 3) == 3) {
        PLAYER.step_s = 1;
        PLAYER.velocityY = 0;
        PLAYER.velocityX = 0;
    }
    if (else_cycles == 8) {
        if (func_80111D24()) {
            return;
        }
        PLAYER.animSet = 1;
        PLAYER.unk5A = 0;
        SetPlayerAnim(0xCB);
        if (PLAYER.step_s != 0) {
            SetPlayerAnim(0xCC);
        }
        if (g_Entities[16].step < 3) {
            g_Entities[16].step = 3;
            return;
        }
        if (g_Entities[16].step == 5) {
            PLAYER.palette = 0x8100;
            func_8010FAF4();
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(44, 0x5b), 0);
            if (PLAYER.step_s != 0) {
                func_8010E4D0();
                return;
            }
            func_8010E83C(0);
            PLAYER.posY.i.hi -= 3;
            if (!(g_Player.pl_vram_flag & 0x8000)) {
                PLAYER.velocityY = -0x10000;
            }
#if defined(VERSION_US)
            g_Player.unk20 = 0x18;
#elif defined(VERSION_HD)
            D_800ACEDC_hd = 0x18;
#endif
            g_Player.unk44 |= 0x100;
            func_80111CC0();
        }
    }
    if (func_80111DE8(1) != 0) {
        PLAYER.velocityX = 0;
    }
}

void func_80118614(void) {
    if (PLAYER.animFrameDuration < 0) {
        func_8010E570(0);
    }
}

void func_80118640(void) {
    if (PLAYER.animFrameDuration < 0) {
        func_8010E470(0, 0);
    }
}

void func_80118670(void) {
    if (PLAYER.animFrameIdx == 7 && PLAYER.animFrameDuration == 1) {
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(40, 0x16), 0);
        PlaySfx(SFX_UI_MP_FULL);
        CreateEntFactoryFromEntity(g_CurrentEntity, 112, 0);
    }
    if (PLAYER.animFrameDuration < 0) {
        func_8010E570(0);
    }
}

void func_801186EC(void) {
    if (PLAYER.step_s == 0) {
        if (g_Entities[E_WEAPON].entityId == E_NONE) {
            D_80138008 = 0x10;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(61, 0x15), 0);
            PLAYER.step_s++;
        }
    } else if (--D_80138008 == 0) {
        PLAYER.palette = 0x8100;
        func_8010E570(0);
    }
}
