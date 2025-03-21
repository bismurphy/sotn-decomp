// SPDX-License-Identifier: AGPL-3.0-or-later
#include "ric.h"
#include "sfx.h"

void RicSetAnimation(AnimationFrame* anim) {
    g_CurrentEntity->anim = anim;
    g_CurrentEntity->animFrameDuration = 0;
    g_CurrentEntity->animFrameIdx = 0;
}

void RicDecelerateX(s32 speed) {
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

static void DecelerateY(s32 speed) {
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

s32 RicCheckFacing(void) {
    if (g_Player.unk44 & 2) {
        return 0;
    }

    if (PLAYER.facingLeft == 1) {
        if (g_Player.padPressed & PAD_RIGHT) {
            PLAYER.facingLeft = 0;
            g_Player.unk4C = 1;
            return -1;
        } else if (g_Player.padPressed & PAD_LEFT) {
            return 1;
        }
    } else {
        if (g_Player.padPressed & PAD_RIGHT) {
            return 1;
        }
        if (g_Player.padPressed & PAD_LEFT) {
            PLAYER.facingLeft = 1;
            g_Player.unk4C = 1;
            return -1;
        }
    }
    return 0;
}

void RicSetSpeedX(s32 speed) {
    if (g_CurrentEntity->facingLeft == 1)
        speed = -speed;
    g_CurrentEntity->velocityX = speed;
}

void func_8015CAAC(s32 speed) {
    if (PLAYER.entityRoomIndex == 1)
        speed = -speed;
    PLAYER.velocityX = speed;
}

void RicSetInvincibilityFrames(s32 kind, s16 invincibilityFrames) {
    if (!kind) {
        RicCreateEntFactoryFromEntity(
            g_CurrentEntity, FACTORY(BP_CRASH_DAGGER, 0x15), 0);
        if (g_Player.timers[PL_T_INVINCIBLE_SCENE] <= invincibilityFrames) {
            g_Player.timers[PL_T_INVINCIBLE_SCENE] = invincibilityFrames;
        }
    } else if (g_Player.timers[PL_T_INVINCIBLE] <= invincibilityFrames) {
        g_Player.timers[PL_T_INVINCIBLE] = invincibilityFrames;
    }
}

void DisableAfterImage(s32 resetAnims, s32 arg1) {
    Primitive* prim;

#if defined(VERSION_US)
    FntPrint("op disable\n");
#endif
    if (resetAnims) {
        g_Entities[UNK_ENTITY_1].ext.disableAfterImage.unk7E = 1;
        g_Entities[UNK_ENTITY_3].animCurFrame = 0;
        g_Entities[UNK_ENTITY_2].animCurFrame = 0;
        g_Entities[UNK_ENTITY_1].animCurFrame = 0;

        prim = &g_PrimBuf[g_Entities[UNK_ENTITY_1].primIndex];
        while (prim) {
            prim->x1 = 0;
            prim = prim->next;
        }
    }
    g_Entities[UNK_ENTITY_1].ext.disableAfterImage.unk7C = 1;
    g_Entities[UNK_ENTITY_1].ext.disableAfterImage.unk80 = 0xA;
    if (arg1) {
        g_Player.timers[PL_T_AFTERIMAGE_DISABLE] = 4;
    }
}

void func_8015CC28(void) {
    Entity* entity = &g_Entities[UNK_ENTITY_1];

    entity->ext.entSlot1.unk3 = 0;
    entity->ext.entSlot1.unk2 = 0;
    entity->ext.entSlot1.unk1 = 0;
    entity->ext.entSlot1.unk0 = 0;
}

void RicSetDebug() { RicSetStep(PL_S_DEBUG); }

void func_8015CC70(s16 arg0) {
    PLAYER.step_s = arg0;
    PLAYER.step = PL_S_INIT;
    PLAYER.animFrameDuration = 0;
    PLAYER.animFrameIdx = 0;
    if (arg0 & 1) {
        PLAYER.anim = D_80155950;
    } else {
        PLAYER.anim = D_8015591C;
    }
}

void RicSetCrouch(s32 kind, s32 velocityX) {
    RicSetStep(PL_S_CROUCH);
    RicSetAnimation(ric_anim_crouch);
    PLAYER.velocityX = velocityX;
    PLAYER.velocityY = 0;
    if (kind == 1) {
        PLAYER.anim = ric_anim_crouch_from_stand2;
        PLAYER.step_s = 4;
    }
    if (kind == 2) {
        PLAYER.anim = ric_anim_crouch_from_stand;
        PLAYER.step_s = 1;
    }
    if (kind == 3) {
        PLAYER.anim = ric_anim_land_from_air_run;
        PLAYER.step_s = 4;
    }
}

// Corresponding DRA function is func_8010E570 (much more complex)
void RicSetStand(s32 velocityX) {
    PLAYER.velocityX = velocityX;
    PLAYER.velocityY = 0;
    g_Player.unk44 = 0;
    RicSetStep(PL_S_STAND);
    RicSetAnimation(ric_anim_stand);
}

#ifdef VERSION_HD
void RicSetRun(void) {
    g_Player.unk44 = 0;
    RicSetStep(PL_S_RUN);
    RicSetAnimation(ric_anim_run);
    RicSetSpeedX(FIX(2.25));
    g_Player.timers[PL_T_RUN] = 40;
    PLAYER.velocityY = 0;
    RicCreateEntFactoryFromEntity(
        g_CurrentEntity, FACTORY(BP_SMOKE_PUFF, 5), 0);
}
#endif

void RicSetWalk(s32 arg0) {
    if (g_Player.timers[PL_T_8] && !g_Player.unk7A) {
        RicSetRun();
        return;
    }
    g_Player.timers[PL_T_CURSE] = 8;
    g_Player.timers[PL_T_8] = 12;
    g_Player.timers[PL_T_CURSE] = 12;
    g_Player.unk44 = 0;
    RicSetStep(PL_S_WALK);
    RicSetAnimation(ric_anim_walk);
    RicSetSpeedX(FIX(1.25));
    PLAYER.velocityY = 0;
}

#ifdef VERSION_US
void RicSetRun(void) {
    if (g_Player.unk7A != 0) {
        RicSetWalk(0);
    } else {
        g_Player.unk44 = 0;
        RicSetStep(PL_S_RUN);
        RicSetAnimation(ric_anim_run);
        RicSetSpeedX(FIX(2.25));
        g_Player.timers[PL_T_RUN] = 40;
        PLAYER.velocityY = 0;
        RicCreateEntFactoryFromEntity(
            g_CurrentEntity, FACTORY(BP_SMOKE_PUFF, 5), 0);
    }
}
#endif

void RicSetFall(void) {
    /**
     * TODO: labels are !FAKE
     */
    if (g_Player.prev_step != PL_S_RUN && g_Player.prev_step != PL_S_SLIDE) {
        PLAYER.velocityX = 0;
    }
    if (g_Player.prev_step != PL_S_WALK) {
        if (g_Player.prev_step != PL_S_RUN) {
            RicSetAnimation(D_80155534);
            goto block_6;
        }
        goto block_7;
    }
block_6:
    if (g_Player.prev_step == PL_S_RUN) {
    block_7:
        g_Player.unk44 = 0x10;
    }
    RicSetStep(PL_S_FALL);
    PLAYER.velocityY = 0x20000;
    g_Player.timers[PL_T_5] = 8;
    g_Player.timers[PL_T_6] = 8;
    g_Player.timers[PL_T_CURSE] = 0;
    g_Player.timers[PL_T_8] = 0;
    if (g_Player.prev_step == PL_S_SLIDE) {
        g_Player.timers[PL_T_6] = 0;
        g_Player.timers[PL_T_5] = 0;
        PLAYER.animFrameIdx = 2;
        PLAYER.animFrameDuration = 0x10;
        PLAYER.velocityX /= 2;
    }
}

void RicSetJump(void) {
    if (g_Player.unk72) {
        RicSetFall();
        return;
    }
    if (RicCheckFacing() != 0 || PLAYER.step == Player_Slide) {
        RicSetAnimation(D_8015550C);
        if (PLAYER.step == PL_S_RUN) {
            RicSetSpeedX(FIX(2.25));
            g_Player.unk44 = 0x10;
        } else {
            RicSetSpeedX(FIX(1.25));
            g_Player.unk44 = 0;
        }
    } else {
        RicSetAnimation(D_801554F0);
        PLAYER.velocityX = 0;
        g_Player.unk44 = 4;
    }
    RicSetStep(PL_S_JUMP);
    if (g_IsPrologueStage) {
        PLAYER.velocityY = -FIX(4.6875);
    } else {
        PLAYER.velocityY = -FIX(5.4375);
    }
}

void RicSetHighJump(void) {
    RicSetStep(PL_S_HIGHJUMP);
    PLAYER.velocityX = 0;
    RicSetSpeedX(FIX(1.25));
    PLAYER.velocityY = FIX(-7.5);
    g_Player.high_jump_timer = 0;
    RicSetAnimation(ric_anim_high_jump);
    func_8015CC28();
    RicCreateEntFactoryFromEntity(g_CurrentEntity, BP_HIGH_JUMP, 0);
    g_api.PlaySfx(SFX_VO_RIC_ATTACK_C);
    g_Player.timers[PL_T_12] = 4;
    if (g_Player.unk72) {
        PLAYER.velocityY = 0;
    }
}
