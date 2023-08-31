#include "st0.h"
extern u8 D_8003BF7C[];
extern u16 D_80181618[];
extern u8 D_80181938[];
extern u16 D_80181948[];
extern u8 D_8018195C[];

void TestCollisions(void) {
    EnemyDef* temp_a0_6;
    Entity* extraEnt;
    Entity* var_s2;
    Primitive* prim;
    s32 heightM1;
    s32 widthM1;
    s16 primRand;
    s16 temp_v1_4;
    u16 i;
    s16 hitboxX;
    s16 hitboxY;
    s32 hitboxY_1;
    s32* var_a3;
    s32* var_s3;
    u16 temp_a1;
    u16 temp_s1_2;
    u16 temp_s1_3;
    u16 hitbox_state;
    u16 var_a0;
    u16 var_s1_2;
    u16 var_s4;
    u32 temp_a1_2;
    u8 var_s7;
    Entity* iterEnt1;
    Entity* iterEnt2;
    u16 rareDropDiff;
    u16 temp_enemyId;
    s32 bit_to_set;

    u32 comp_v0;
    u32 comp_v1;

    var_a3 = (s32*)0x1F800000;
    var_s3 = (s32*)0x1F8000C0;
    for (iterEnt1 = &g_Entities[0]; iterEnt1 < &g_Entities[48]; var_a3++,
        iterEnt1++) {
        *var_a3 = iterEnt1->hitboxState;
        if ((*var_a3 != 0) && !(*var_a3 & 0x80)) {
            *var_s3 = iterEnt1->posX.i.hi;
            if (iterEnt1->facing != 0) {
                *var_s3 -= (s16)iterEnt1->hitboxOffX;
            } else {
                *var_s3 += (s16)iterEnt1->hitboxOffX;
            }
            hitboxY_1 = iterEnt1->posY.i.hi + iterEnt1->hitboxOffY;
            if ((*var_s3 > 0x120 || *var_s3 < -0x20) ||
                (hitboxY_1 > 0x100 || hitboxY_1 < -0x20) ||
                (iterEnt1->hitboxWidth == 0) || (iterEnt1->hitboxHeight == 0)) {
                *var_a3 = 0;
            } else {
                var_s3++;
                *var_s3++ = iterEnt1->hitboxWidth;
                *var_s3++ = hitboxY_1;
                *var_s3++ = iterEnt1->hitboxHeight;
                continue;
            }
        }
        var_s3 += 4;
    }

    // THIS GIGANTIC FOR LOOP CONTROLS EVERYTHING
    for (iterEnt1 = &g_Entities[64]; iterEnt1 < &g_Entities[192]; iterEnt1++) {
        hitbox_state = iterEnt1->hitboxState;
        if ((hitbox_state == 0) || (iterEnt1->hitboxWidth == 0) ||
            (iterEnt1->hitboxHeight == 0) ||
            (((iterEnt1->flags & 0x100) != 0))) {
            continue;
        }
        for (i = 0; i < 11; i++) {
            if (iterEnt1->unk6D[i] != 0) {
                iterEnt1->unk6D[i]--;
            }
        }
        hitboxX = (u16)iterEnt1->posX.i.hi;
        if (iterEnt1->facing != 0) {
            hitboxX -= (u16)iterEnt1->hitboxOffX;
        } else {
            hitboxX += (u16)iterEnt1->hitboxOffX;
        }
        hitboxY = (u16)iterEnt1->posY.i.hi + (u16)iterEnt1->hitboxOffY;
        if ((u16)(hitboxX + 0x1F) >= 0x13F) {
            continue;
        }
        if ((u16)(hitboxY + 0x1F) >= 0x11F) {
            continue;
        }
        var_s7 = 0;
        heightM1 = iterEnt1->hitboxHeight - 1;
        widthM1 = iterEnt1->hitboxWidth - 1;
        temp_v1_4 = hitbox_state & 0x3E;
        if (temp_v1_4 != 0) {
            var_a3 = (s32*)0x1F800004;
            var_s3 = (s32*)0x1F8000D0;
            for (iterEnt2 = &g_Entities[1]; iterEnt2 < &g_Entities[48];
                 iterEnt2++) {
                if ((temp_v1_4 & *var_a3) &&
                    iterEnt1->unk6D[iterEnt2->enemyId] == 0) {
                    if ((*var_a3 & 0x80)) {
                        var_s7 = 0xFF;
                        iterEnt1->unk44 = (u16)iterEnt2->hitEffect;
                        break;
                    }
                    comp_v0 = *(u16*)var_s3++;
                    comp_v1 = widthM1 + *var_s3++;

                    if (comp_v1 * 2 <= (u16)(comp_v0 - hitboxX + comp_v1)) {
                        comp_v0 = *(u16*)var_s3++;
                        comp_v1 = heightM1 + *var_s3++;
                        if (comp_v1 * 2 <= (u16)(comp_v0 - hitboxY + comp_v1)) {
                            temp_a1 = iterEnt2->hitEffect;
                            if (!(iterEnt2->flags & iterEnt1->flags &
                                  0x100000)) {
                                iterEnt2->hitFlags = 1;
                                iterEnt2->ext.generic.unkB8 = iterEnt1;
                                if (temp_a1 == 0xC) {
                                    if (iterEnt1->flags & 0x8000) {
                                        iterEnt2->hitFlags = 2;
                                    }
                                }
                                if ((temp_a1 == 0xA) &&
                                    (iterEnt1->flags & 0x4000)) {
                                    iterEnt2->hitFlags = 2;
                                }
                            }
                            iterEnt1->unk44 = temp_a1;
                            var_s7 = 0xFF;
                            break;
                        } else {
                            var_a3++;
                        }
                    } else {
                        var_a3++;
                        var_s3 += 2;
                    }

                } else {
                    var_a3++;
                    var_s3 += 4;
                }
            }
        }
        if (hitbox_state & 1) {
            if (var_s7 == 0) {
                iterEnt2 = g_Entities;
                var_a3 = (s32*)0x1F800000;
                var_s3 = (s32*)0x1F8000C0;
                if (iterEnt1->unk6D[PLAYER.enemyId] == 0 && (*var_a3 & 1)) {
                    comp_v0 = *(u16*)var_s3++;
                    comp_v1 = widthM1 + *var_s3++;
                    if (comp_v1 * 2 <= (u16)(comp_v0 - hitboxX + comp_v1)) {
                        comp_v0 = *(u16*)var_s3++;
                        comp_v1 = heightM1 + *var_s3++;
                        if (comp_v1 * 2 <= (u16)(comp_v0 - hitboxY + comp_v1)) {
                            PLAYER.ext.generic.unkB8 = iterEnt1;
                            PLAYER.hitFlags = 1;
                            PLAYER.unk44 = iterEnt1->attackElement;
                            PLAYER.hitPoints = iterEnt1->attack;
                            iterEnt1->unk44 = PLAYER.hitEffect;
                            iterEnt1->hitFlags = 0x80;
                            var_s7 = 0xFF;
                        }
                    }
                }
            }
        }

        if (var_s7 == 0) {
            continue;
        }
    block_61:

        if (iterEnt1->unk5C != NULL) {
            var_s2 = iterEnt1->unk5C;
            var_s2->unk44 = iterEnt1->unk44;
        } else {
            var_s2 = iterEnt1;
        }
        if ((var_s2->flags & 0x100) || !((u8)var_s7 & 0xFF)) {
            continue;
        }
        var_s4 = D_80181618[var_s2->enemyId];
        if (var_s4 != 0) {
            var_s4--;
            bit_to_set = 1 << (var_s4 & 7);
            D_8003BF7C[var_s4 >> 3] |= (bit_to_set);
        }
        if ((g_Status.relics[RELIC_FAERIE_SCROLL] & 2) && (var_s2->flags & 0x01000000) == 0) {
            if (g_BottomCornerTextTimer != 0) {
                g_api_FreePrimitives(g_BottomCornerTextPrims);
                g_BottomCornerTextTimer = 0;
            }
            BottomCornerText(g_api.enemyDefs[var_s2->enemyId].name, 0);
            var_s2->flags |= 0x01000000;
        }
        if (var_s2->hitPoints != 0) {
            if (iterEnt2->attack != 0) {
                if (!(iterEnt2->hitboxState & 0x80)) {
                    var_s3 -= 4;
                    hitboxX = (s16)(hitboxX + *var_s3) / 2;

                    var_s3 += 2;
                    hitboxY = (s16)(hitboxY + *var_s3) / 2;
                }
                for (prim = &g_PrimBuf[D_800973F8]; prim != NULL;
                     prim = prim->next) {
                    if (prim->blendMode == 8) {
                        prim->clut = 0x199;

                        primRand = ((Random() & 7) - 0xD);
                        prim->x0 = prim->x2 = hitboxX + primRand - 3;
                        prim->x1 = prim->x3 = hitboxX + primRand + 0x1D;

                        primRand = ((Random() & 7) - 0xA);
                        prim->y0 = prim->y1 = hitboxY + primRand - 3;
                        prim->y2 = prim->y3 = hitboxY + primRand + 0x1D;
                        prim->p1 = 0;

                        if (iterEnt2->zPriority > iterEnt1->zPriority) {
                            prim->priority = iterEnt2->zPriority + 1;
                        } else {
                            prim->priority = iterEnt1->zPriority + 1;
                        }
                        prim->blendMode = 2;
                        break;
                    }
                }

                if ((iterEnt2->attack != 0) && (var_s2->hitPoints != 0x7FFF)) {
                    var_s4 = g_api_DealDamage(iterEnt1, iterEnt2);
                    if (var_s4 == 0x4000) {
                        var_s4 = 0;
                    }
                    if (g_Status.relics[RELIC_SPIRIT_ORB] & 2) {
                        if (!(var_s2->flags & 0x04000000)) {
                            extraEnt =
                                AllocEntity(&g_Entities[160], &g_Entities[192]);
                            if (extraEnt != NULL) {
                                DestroyEntity(extraEnt);
                                extraEnt->entityId = 4;
                                extraEnt->pfnUpdate = EntityNumericDamage;
                                extraEnt->posX.i.hi = (s16)hitboxX;
                                extraEnt->posY.i.hi = (s16)hitboxY;
                                extraEnt->params = var_s4;
                            }
                        }
                    }
                } else {
                    var_s4 = 0;
                }
            } else {
                var_s4 = 0;
            }

            if (var_s4 != 0xC000) {
                if (var_s4 & 0x8000) {
                    var_s7 = 9;
                } else {
                    temp_s1_2 = iterEnt2->attackElement;
                    if (temp_s1_2 & 0xFFC0) {
                        for (i = 0; i < 10; i++) {
                            if ((temp_s1_2 & D_80181948[i])) {
                                var_s7 = D_8018195C[i];
                                break;
                            }
                        }
                    } else {
                        var_s7 = 0;
                    }
                }
            } else {
                var_s4 = 0;
                var_s2->hitFlags |= 0x20;
            }

            if (var_s4 != 0) {
                if (var_s4 & 0x8000) {
                    var_s2->hitPoints += (var_s4 & 0x3FFF);
                    temp_s1_3 = g_api.enemyDefs[var_s2->enemyId].hitPoints;
                    if (temp_s1_3 < var_s2->hitPoints) {
                        var_s2->hitPoints = temp_s1_3;
                    }
                } else {
                    var_s4 &= 0x3FFF;
                    g_api_PlaySfx(0x705);
                    if (var_s2->hitPoints != 0x7FFE) {
                        if (var_s2->hitPoints < (var_s4 * 2)) {
                            var_s2->hitFlags |= 3;
                        } else if (var_s2->hitPoints < (var_s4 * 4)) {
                            var_s2->hitFlags |= 2;
                        } else {
                            var_s2->hitFlags |= 1;
                        }
                        var_s2->hitPoints -= var_s4;
                    }
                }

                extraEnt = var_s2;
                if (var_s2->hitPoints > 0) {
                    temp_enemyId = iterEnt2->enemyId;
                    do {
                        extraEnt->unk6D[temp_enemyId] =
                            iterEnt2->nFramesInvincibility;
                        if ((iterEnt1->flags & 0x400000) == 0) {
                            extraEnt->stunFrames = iterEnt2->stunFrames;
                        }
                        if ((extraEnt->hitEffect == 0) &&
                            !(extraEnt->flags & 0xF)) {
                            extraEnt->hitEffect = extraEnt->palette;
                        }
                        extraEnt->nFramesInvincibility = var_s7;
                        extraEnt->flags |= 0xF;
                        extraEnt = (Entity*)extraEnt->unk60;
                    } while (extraEnt != NULL && extraEnt != var_s2);
                    continue;
                } else {
                    goto block_127;
                }
            }
        } else {
        block_127:
            PreventEntityFromRespawning(var_s2);
            g_api_func_800FE044((u16)g_api_enemyDefs[var_s2->enemyId].exp,
                                (u16)g_api_enemyDefs[var_s4].level);
            if ((var_s2->flags & 0x1000) && (g_Status.killCount < 999999)) {
                g_Status.killCount += 1;
            }
            if (var_s2->flags & 0xC00) {
                if ((u32)(rand() & 0xFF) < 0x20U) {
                    extraEnt = AllocEntity(&g_Entities[160], &g_Entities[192]);
                    if (extraEnt != NULL) {
                        temp_a1_2 = rand() & 0xFF;
                        temp_a0_6 = &g_api_enemyDefs[var_s4 & 0xFFFF];
                        if (temp_a1_2 >= temp_a0_6->rareItemDropRate) {
                            rareDropDiff =
                                temp_a1_2 - temp_a0_6->rareItemDropRate;
                            var_s1_2 = ((rareDropDiff <
                                         (u16)temp_a0_6->uncommonItemDropRate) ^
                                        1) *
                                       2;
                        } else {
                            var_s1_2 = 1;
                        }
                        if ((var_s1_2 & 0xFFFF) >= 0x80U) {
                            var_s1_2 -= 0x80;
                            var_a0 = 0xA;
                        } else {
                            var_a0 = 3;
                        }
                        CreateEntityFromEntity(var_a0, iterEnt1, extraEnt);
                        extraEnt->params = var_s1_2;
                        extraEnt->velocityY = -0x38000;
                    }
                }
            }

            extraEnt = var_s2;
            do {
                extraEnt->flags |= 0x10C100;
                extraEnt->flags &= 0xDFFFFFFF;
                if (extraEnt->hitEffect == 0) {
                    extraEnt->hitEffect = extraEnt->palette;
                }
                extraEnt->nFramesInvincibility = var_s7;
                extraEnt->flags |= 0xF;
                extraEnt = (Entity*)extraEnt->unk60;

            } while (extraEnt != NULL && extraEnt != var_s2);

            continue;
        }

        extraEnt = var_s2;
        if (!(var_s2->hitFlags & 0xF)) {
            var_s2->hitFlags |= 0x10;
        }

        temp_enemyId = iterEnt2->enemyId;
        do {
            if ((iterEnt1->hitPoints != 0x7FFF) ||
                (extraEnt->hitPoints == iterEnt1->hitPoints)) {
                extraEnt->unk6D[temp_enemyId] = iterEnt2->nFramesInvincibility;
            }
            extraEnt = (Entity*)extraEnt->unk60;
        } while ((extraEnt != NULL) && (extraEnt != var_s2));
    }
    // END OF GIGANTIC FOR LOOP

    for (prim = &g_PrimBuf[D_800973F8]; prim != NULL; prim = prim->next) {
        if (prim->blendMode != 8) {
            var_s7 = prim->p1;
            prim->u0 = prim->u2 = D_80181938[var_s7];
            prim->u1 = prim->u3 = prim->u0 + 0x20;
            prim->v0 = prim->v1 = D_80181938[var_s7 + 2];
            prim->v2 = prim->v3 = prim->v0 + 0x20;
            if (++var_s7 >= 7) {
                prim->blendMode = 8;
            } else {
                prim->p1 = var_s7;
            }
        }
    }
}

INCLUDE_ASM("asm/us/st/st0/nonmatchings/31CA0", EntityNumericDamage);

#include "../create_entity_from_layout.h"

void CreateEntityWhenInVerticalRange(LayoutEntity* layoutObj) {
    s16 yClose;
    s16 yFar;
    s16 posY;
    Entity* entity;

    posY = g_Camera.posY.i.hi;
    yClose = posY - 0x40;
    yFar = posY + 0x120;
    if (yClose < 0) {
        yClose = 0;
    }

    posY = layoutObj->posY;
    if (posY < yClose) {
        return;
    }

    if (yFar < posY) {
        return;
    }

    switch (layoutObj->entityId & 0xE000) {
    case 0x0:
        entity =
            &g_Entities[STAGE_ENTITY_START + (u8)layoutObj->entityRoomIndex];
        if (entity->entityId == E_NONE) {
            CreateEntityFromLayout(entity, layoutObj);
        }
        break;
    case 0x8000:
        break;
    case 0xA000:
        entity =
            &g_Entities[STAGE_ENTITY_START + (u8)layoutObj->entityRoomIndex];
        CreateEntityFromLayout(entity, layoutObj);
        break;
    }
}

void CreateEntityWhenInHorizontalRange(LayoutEntity* layoutObj) {
    s16 xClose;
    s16 xFar;
    s16 posX;
    Entity* entity;

    posX = g_Camera.posX.i.hi;
    xClose = posX - 0x40;
    xFar = posX + 0x140;
    if (xClose < 0) {
        xClose = 0;
    }

    posX = layoutObj->posX;
    if (posX < xClose) {
        return;
    }

    if (xFar < posX) {
        return;
    }

    switch (layoutObj->entityId & 0xE000) {
    case 0x0:
        entity =
            &g_Entities[STAGE_ENTITY_START + (u8)layoutObj->entityRoomIndex];
        if (entity->entityId == E_NONE) {
            CreateEntityFromLayout(entity, layoutObj);
        }
        break;
    case 0x8000:
        break;
    case 0xA000:
        entity =
            &g_Entities[STAGE_ENTITY_START + (u8)layoutObj->entityRoomIndex];
        CreateEntityFromLayout(entity, layoutObj);
        break;
    }
}

extern LayoutEntity* D_801C00A0;
void func_801B33D4(s16 arg0) {
    while (true) {
        if (D_801C00A0->posX != 0xFFFE && D_801C00A0->posX >= arg0) {
            break;
        }
        D_801C00A0++;
    }
}

void func_801B3420(s16 arg0) {
    while (true) {
        if (D_801C00A0->posX != 0xFFFF &&
            (arg0 >= D_801C00A0->posX || D_801C00A0->posX == 0xFFFE)) {
            break;
        }
        D_801C00A0--;
    }
}

void func_801B3478(s16 arg0) {
    s32 expected;
    u8 flag;

    if (D_801C00A8 != 0) {
        func_801B33D4(arg0 - D_80097908);
        D_801C00A8 = 0;
    }

    while (true) {
        if ((D_801C00A0->posX == 0xFFFF) || (arg0 < D_801C00A0->posX)) {
            return;
        }

        expected = 0;
        flag = (D_801C00A0->entityRoomIndex >> 8) + 0xFF;
        if ((flag == 0xFF) ||
            (g_entityDestroyed[flag >> 5] & (1 << (flag & 0x1F))) == expected) {
            CreateEntityWhenInVerticalRange(D_801C00A0);
        }
        D_801C00A0++;
    }
}

void func_801B3574(s16 arg0) {
    u8 flag;
    s32 expected;

    if (arg0 < 0) {
        arg0 = 0;
    }

    if (D_801C00A8 == 0) {
        func_801B3420(arg0 - D_80097908);
        D_801C00A8 = 1;
    }

    while (true) {
        if ((D_801C00A0->posX == 0xFFFE) || (arg0 > D_801C00A0->posX)) {
            return;
        }

        expected = 0;
        flag = (D_801C00A0->entityRoomIndex >> 8) + 0xFF;
        if ((flag == 0xFF) ||
            (g_entityDestroyed[flag >> 5] & (1 << (flag & 0x1F))) == expected) {
            CreateEntityWhenInVerticalRange(D_801C00A0);
        }
        D_801C00A0--;
    }
}

void func_801B3688(s16 arg0) {
    while (true) {
        if (D_801C00A4[1] != 0xFFFE && (s32)D_801C00A4[1] >= arg0) {
            break;
        }
        D_801C00A4 += 5;
    }
}

void func_801B36D4(s16 arg0) {
    while (true) {
        if ((D_801C00A4[1] != 0xFFFF) &&
            ((arg0 >= D_801C00A4[1]) || (D_801C00A4[1] == 0xFFFE))) {
            break;
        }
        D_801C00A4 -= 5;
    }
}

void func_801B372C(s16 arg0) {
    s32 expected;
    u8 flag;

    if (D_801C00AC != 0) {
        func_801B3688(arg0 - D_8009790C);
        D_801C00AC = 0;
    }

    while (true) {
        if ((D_801C00A4[1] == 0xFFFF) || (arg0 < D_801C00A4[1])) {
            return;
        }

        expected = 0;
        flag = (D_801C00A4[3] >> 8) + 0xFF;
        if ((flag == 0xFF) ||
            (g_entityDestroyed[flag >> 5] & (1 << (flag & 0x1F))) == expected) {
            CreateEntityWhenInHorizontalRange(D_801C00A4);
        }
        D_801C00A4 += 5;
    }
}

void func_801B3828(s16 arg0) {
    u8 flag;
    s32 expected;

    if (arg0 < 0) {
        arg0 = 0;
    }

    if (D_801C00AC == 0) {
        func_801B36D4(arg0 - D_8009790C);
        D_801C00AC = 1;
    }

    while (true) {
        if ((D_801C00A4[1] == 0xFFFE) || (arg0 > D_801C00A4[1])) {
            return;
        }

        expected = 0;
        flag = (D_801C00A4[3] >> 8) + 0xFF;
        if ((flag == 0xFF) ||
            (g_entityDestroyed[flag >> 5] & (1 << (flag & 0x1F))) == expected) {
            CreateEntityWhenInHorizontalRange(D_801C00A4);
        }
        D_801C00A4 -= 5;
    }
}

void InitRoomEntities(s32 objLayoutId) {
    u16* pObjLayoutStart = D_80180314[objLayoutId];
    Unkstruct8* currentRoomTileLayout = &g_CurrentRoomTileLayout;
    s16 temp_s0;
    s16 arg0;
    s16 i;
    u16* temp_v1;

    D_801C00A0 = pObjLayoutStart;
    D_801C00A4 = D_801803E8[objLayoutId];

    if (*pObjLayoutStart != 0xFFFE) {
        D_801C00A0 = pObjLayoutStart + 1;
        arg0 = Random() & 0xFF;
        for (i = 0; true; i++) {
            temp_v1 = D_801C00A0;
            D_801C00A0 = temp_v1 + 1;
            arg0 -= temp_v1[0];
            if (arg0 < 0) {
                break;
            }
            D_801C00A0 = temp_v1 + 3;
        }
        D_801C00A0 = (temp_v1[2] << 0x10) + temp_v1[1];
        D_801C00A4 += i * 2 + 2;
        D_801C00A4 = (D_801C00A4[1] << 0x10) + D_801C00A4[0];
    }
    arg0 = currentRoomTileLayout->unkA;
    temp_s0 = arg0 + 0x140;
    i = arg0 - 0x40;
    if (i < 0) {
        i = 0;
    }

    D_801C00A8 = 0;
    D_801C00AC = 0;
    func_801B33D4(i);
    func_801B3478(temp_s0);
    func_801B3688(currentRoomTileLayout->unkE + 0x120);
}

void func_801B3AB4(void) {
    Unkstruct8* currentRoomTileLayout = &g_CurrentRoomTileLayout;

    if (D_80097908 != 0) {
        s16 tmp = g_Camera.posX.i.hi;
        if (D_80097908 > 0)
            func_801B3478(tmp + 320);
        else
            func_801B3574(tmp - 64);
    }

    if (D_8009790C != 0) {
        s16 tmp = currentRoomTileLayout->unkE;
        if (D_8009790C > 0)
            func_801B372C(currentRoomTileLayout->unkE + 288);
        else
            func_801B3828(tmp - 64);
    }
}

void CreateEntityFromCurrentEntity(u16 entityId, Entity* entity) {
    DestroyEntity(entity);
    entity->entityId = entityId;
    entity->pfnUpdate = PfnEntityUpdates[entityId - 1];
    entity->posX.i.hi = g_CurrentEntity->posX.i.hi;
    entity->posY.i.hi = g_CurrentEntity->posY.i.hi;
}

void CreateEntityFromEntity(u16 entityId, Entity* source, Entity* entity) {
    DestroyEntity(entity);
    entity->entityId = entityId;
    entity->pfnUpdate = PfnEntityUpdates[entityId - 1];
    entity->posX.i.hi = source->posX.i.hi;
    entity->posY.i.hi = source->posY.i.hi;
}

s32 func_801B3C58(Entity* e) {
    s16 diff;

    diff = PLAYER.posX.i.hi - e->posX.i.hi;
    diff = ABS(diff);

    if (diff >= 17) {
        diff = 0;
    } else {
        diff = PLAYER.posY.i.hi - e->posY.i.hi;
        diff = ABS(diff);
        diff = diff < 33;
    }

    return diff;
}

INCLUDE_ASM("asm/us/st/st0/nonmatchings/31CA0", EntityRedDoor);

void DestroyEntity(Entity* item) {
    s32 i;
    s32 length;
    u32* ptr;

    if (item->flags & FLAG_HAS_PRIMS) {
        g_api.FreePrimitives(item->primIndex);
    }

    ptr = (u32*)item;
    length = sizeof(Entity) / sizeof(s32);
    for (i = 0; i < length; i++)
        *ptr++ = 0;
}

void DestroyEntityFromIndex(s16 index) {
    Entity* entity = &g_Entities[index];

    while (entity < &D_8007EF1C) {
        DestroyEntity(entity);
        entity++;
    }
}

void PreventEntityFromRespawning(Entity* entity) {
    if (entity->entityRoomIndex) {
        u32 value = (entity->entityRoomIndex - 1);
        u16 index = value / 32;
        u16 bit = value % 32;
        g_entityDestroyed[index] |= 1 << bit;
    }
}

#include "st/AnimateEntity.h"

u8 func_801B4AF0(u8 frames[], Entity* self, u8 arg2) {
    u16 animFrameStart = self->animFrameIdx * 2;
    u8* var_s1 = &frames[animFrameStart];
    s16 var_a1 = 0;

    if (self->animFrameDuration == 0) {
        if (*var_s1 != 0) {
            if (*var_s1 == 0xFF) {
                return 0;
            }
            self->animFrameDuration = *var_s1++ + (u8)self->ext.stub[0x3F];
            self->animCurFrame = *var_s1++;
            self->animFrameIdx++;
            var_a1 = 128;
        } else {
            var_s1 = frames;
            self->animFrameIdx = 0;
            self->animFrameDuration = 0;
            self->ext.stub[0x3F] = (arg2 * Random()) >> 8;
            self->animFrameDuration = *var_s1++ + (u8)self->ext.stub[0x3F];
            self->animCurFrame = *var_s1;
            self->animFrameIdx++;
            return 0;
        }
    }
    self->animFrameDuration--;
    self->animCurFrame = var_s1[-1];
    var_a1 |= 1;
    return var_a1;
}

// Absolute distance from g_CurrentEntity to the player in the X Axis
s16 GetDistanceToPlayerX(void) {
    s16 xDistance = g_CurrentEntity->posX.i.hi - PLAYER.posX.i.hi;

    if (xDistance < 0) {
        xDistance = -xDistance;
    }
    return xDistance;
}

// Absolute distance from g_CurrentEntity to the player in the Y Axis
s32 GetDistanceToPlayerY(void) {
    s32 yDistance = g_CurrentEntity->posY.i.hi - PLAYER.posY.i.hi;

    if (yDistance < 0) {
        yDistance = -yDistance;
    }
    return yDistance;
}

s16 GetSideToPlayer(void) {
    s16 side = g_CurrentEntity->posX.i.hi > PLAYER.posX.i.hi;

    if (g_CurrentEntity->posY.i.hi > PLAYER.posY.i.hi) {
        side |= 2;
    }
    return side;
}

void MoveEntity(void) {
    g_CurrentEntity->posX.val += g_CurrentEntity->velocityX;
    g_CurrentEntity->posY.val += g_CurrentEntity->velocityY;
}

void FallEntity(void) {
    if (g_CurrentEntity->velocityY < FALL_TERMINAL_VELOCITY) {
        g_CurrentEntity->velocityY += FALL_GRAVITY;
    }
}

u8 func_801B4D18(void) {
    u8 unkState;
    Entity* entity;

    MoveEntity();
    FallEntity();

    entity = g_CurrentEntity;

    if (unkState & 1) {
        entity->velocityY = 0;
    }

    return unkState;
}

s32 func_801B4D5C(u16* sensors) {
    Collider col;
    Collider colBack;
    s16 x;
    s16 y;
    s16 i;

    MoveEntity();
    FallEntity();
    if (g_CurrentEntity->velocityY >= 0) {
        x = g_CurrentEntity->posX.i.hi;
        y = g_CurrentEntity->posY.i.hi;
        for (i = 0; i < 4; i++) {
            x += *sensors++;
            y += *sensors++;
            g_api.CheckCollision(x, y, &col, 0);
            if (col.effects & EFFECT_UNK_8000) {
                if (i == 1) {
                    if (col.effects & EFFECT_SOLID) {
                        g_api.CheckCollision(x, y - 8, &colBack, 0);
                        if (!(colBack.effects & EFFECT_SOLID)) {
                            g_CurrentEntity->posY.i.hi =
                                (u16)g_CurrentEntity->posY.i.hi + 4 + col.unk18;
                            g_CurrentEntity->velocityX = 0;
                            g_CurrentEntity->velocityY = 0;
                            g_CurrentEntity->flags &= ~FLAG_UNK_10000000;
                            return 1;
                        }
                    }
                    continue;
                }
            }
            if (col.effects & EFFECT_NOTHROUGH && i != 1) {
                if (col.effects & EFFECT_QUICKSAND) {
                    g_CurrentEntity->flags &= ~FLAG_UNK_10000000;
                    return 4;
                }
                g_api.CheckCollision(x, y - 8, &colBack, 0);
                if (!(colBack.effects & EFFECT_SOLID)) {
                    g_CurrentEntity->posY.i.hi =
                        g_CurrentEntity->posY.i.hi + col.unk18;
                    g_CurrentEntity->velocityX = 0;
                    g_CurrentEntity->velocityY = 0;
                    g_CurrentEntity->flags &= ~FLAG_UNK_10000000;
                    return 1;
                }
            }
        }
    }
    g_CurrentEntity->flags |= FLAG_UNK_10000000;
    return 0;
}

INCLUDE_ASM("asm/us/st/st0/nonmatchings/31CA0", func_801B4FD4);

INCLUDE_ASM("asm/us/st/st0/nonmatchings/31CA0", func_801B51E4);

Entity* AllocEntity(Entity* start, Entity* end) {
    Entity* current = start;
    while (current < end) {
        if (current->entityId == E_NONE) {
            DestroyEntity(current);
            return current;
        }

        current++;
    }
    return NULL;
}

s32 func_801B542C(u8 arg0, s16 arg1) { return D_80181990[arg0] * arg1; }

s16 func_801B5458(u8 arg0) { return D_80181990[arg0]; }

void func_801B5474(s32 arg0, s16 arg1) {
    g_CurrentEntity->velocityX = func_801B542C(arg0, arg1);
    g_CurrentEntity->velocityY = func_801B542C(arg0 - 0x40, arg1);
}

u8 func_801B54E0(s16 arg0, s16 arg1) {
    return ((ratan2(arg1, arg0) >> 4) + 0x40);
}

u8 func_801B5518(Entity* arg0, Entity* arg1) {
    s16 a = arg1->posX.i.hi - arg0->posX.i.hi;
    s16 b = arg1->posY.i.hi - arg0->posY.i.hi;
    return func_801B54E0(a, b);
}

u8 func_801B5560(s32 arg0, s32 arg1) {
    s16 a = (arg0 - (u16)g_CurrentEntity->posX.i.hi);
    s16 b = (arg1 - (u16)g_CurrentEntity->posY.i.hi);
    return func_801B54E0(a, b);
}

u8 func_801B55A8(u8 arg0, u8 arg1, u8 arg2) {
    u8 var_v0;
    s8 temp_a2 = arg2 - arg1;

    if (temp_a2 < 0) {
        var_v0 = -temp_a2;
    } else {
        var_v0 = temp_a2;
    }

    if (var_v0 > arg0) {
        if (temp_a2 < 0) {
            var_v0 = arg1 - arg0;
        } else {
            var_v0 = arg1 + arg0;
        }

        return var_v0;
    }

    return arg2;
}

void UnkEntityFunc0(u16 slope, s16 speed) {
    Entity* entity;
    s32 moveX;
    s32 moveY;

    moveX = rcos(slope) * speed;
    entity = g_CurrentEntity;

    if (moveX < 0) {
        moveX += 15;
    }

    entity->velocityX = moveX >> 4;

    moveY = rsin(slope) * speed;
    entity = g_CurrentEntity;

    if (moveY < 0) {
        moveY += 15;
    }

    entity->velocityY = moveY >> 4;
}

u16 func_801B568C(s16 x, s16 y) { return ratan2(y, x); }

u16 func_801B56BC(Entity* a, Entity* b) {
    s32 diffX = b->posX.i.hi - a->posX.i.hi;
    s32 diffY = b->posY.i.hi - a->posY.i.hi;
    return ratan2(diffY, diffX);
}

u16 func_801B56F4(s32 x, s32 y) {
    s16 diffX = x - (u16)g_CurrentEntity->posX.i.hi;
    s16 diffY = y - (u16)g_CurrentEntity->posY.i.hi;
    return ratan2(diffY, diffX);
}

u16 func_801B573C(u16 arg0, s16 arg1, s16 arg2) {
    u16 temp_a2 = arg2 - arg1;
    u16 ret;

    if (temp_a2 & 0x800) {
        ret = temp_a2 & 0x7FF;
    } else {
        ret = temp_a2;
    }

    if (ret > arg0) {
        if (temp_a2 & 0x800) {
            ret = arg1 - arg0;
        } else {
            ret = arg1 + arg0;
        }

        return ret;
    }

    return arg2;
}

void SetStep(u8 step) {
    g_CurrentEntity->step = step;
    g_CurrentEntity->step_s = 0;
    g_CurrentEntity->animFrameIdx = 0;
    g_CurrentEntity->animFrameDuration = 0;
}

void SetSubStep(u8 step_s) {
    g_CurrentEntity->step_s = step_s;
    g_CurrentEntity->animFrameIdx = 0;
    g_CurrentEntity->animFrameDuration = 0;
}

void func_801B57D0(u16 params) {
    Entity* current;

    if (params == 0xFF) {
        DestroyEntity(g_CurrentEntity);
        return;
    }
    current = g_CurrentEntity;
    g_CurrentEntity->entityId = E_EXPLOSION;
    g_CurrentEntity->pfnUpdate = EntityExplosion;
    g_CurrentEntity->unk19 = 0;
    current->params = params;
    current->animCurFrame = 0;
    g_CurrentEntity->step = 0;
    g_CurrentEntity->step_s = 0;
}

void InitializeEntity(u16 arg0[]) {
    u16 enemyId;
    EnemyDef* enemyDef;

    g_CurrentEntity->animSet = *arg0++;
    g_CurrentEntity->animCurFrame = *arg0++;
    g_CurrentEntity->unk5A = *arg0++;
    g_CurrentEntity->palette = *arg0++;

    enemyId = *arg0++;
    g_CurrentEntity->enemyId = enemyId;
    enemyDef = &g_api.enemyDefs[enemyId];
    g_CurrentEntity->hitPoints = enemyDef->hitPoints;
    g_CurrentEntity->attack = enemyDef->attack;
    g_CurrentEntity->attackElement = enemyDef->attackElement;
    g_CurrentEntity->hitboxState = enemyDef->unkC;
    g_CurrentEntity->hitboxWidth = enemyDef->hitboxWidth;
    g_CurrentEntity->hitboxHeight = enemyDef->hitboxHeight;
    g_CurrentEntity->flags = enemyDef->unk24;
    g_CurrentEntity->hitboxOffX = 0;
    g_CurrentEntity->hitboxOffY = 0;
    g_CurrentEntity->step_s = 0;
    g_CurrentEntity->step++;
    if (g_CurrentEntity->zPriority == 0) {
        g_CurrentEntity->zPriority = g_zEntityCenter.S16.unk0 - 0xC;
    }
}

void EntityDummy(Entity* arg0) {
    if (arg0->step == 0) {
        arg0->step++;
    }
}

s32 func_801B5970(u16* hitSensors, s16 sensorCount) {
    Collider collider;
    s16 i;
    s32 velocityX;
    u16 temp_a1;
    s16 x;
    s16 y;

    velocityX = g_CurrentEntity->velocityX;
    if (velocityX != 0) {
        x = g_CurrentEntity->posX.i.hi;
        y = g_CurrentEntity->posY.i.hi;
        for (i = 0; i < sensorCount; i++) {
            if (velocityX < 0) {
                s16 newX = x + *hitSensors++;
                x = newX;
            } else {
                s16 newX = x - *hitSensors++;
                x = newX;
            }

            y += *hitSensors++;
            g_api.CheckCollision(x, y, &collider, 0);
            if (collider.effects & 2 &&
                ((!(collider.effects & 0x8000)) || (i != 0))) {
                return 2;
            }
        }
        return 0;
    }
}

void func_801B5A98(u16* hitSensors, s16 sensorCount) {
    Collider collider;
    s16 i;
    s32 velocityX;
    s16 x;
    s16 y;

    velocityX = g_CurrentEntity->velocityX;
    if (velocityX == 0)
        return;
    x = g_CurrentEntity->posX.i.hi;
    y = g_CurrentEntity->posY.i.hi;
    for (i = 0; i < sensorCount; i++) {
        if (velocityX < 0) {
            x = x + *hitSensors++;
        } else {
            x = x - *hitSensors++;
        }

        y += *hitSensors++;
        g_api.CheckCollision(x, y, &collider, 0);
        if (collider.effects & 2 && (!(collider.effects & 0x8000) || i != 0)) {
            if (velocityX < 0) {
                g_CurrentEntity->posX.i.hi += collider.unk1C;
            } else {
                g_CurrentEntity->posX.i.hi += collider.unk14;
            }
            return;
        }
    }
}

INCLUDE_ASM("asm/us/st/st0/nonmatchings/31CA0", func_801B5BF0);

#include "../replace_breakable_with_item_drop.h"

void func_801B5EC8(void) {
    s32 temp_v1;
    Entity* entity;

    entity = g_CurrentEntity;
    if (entity->velocityY >= 0) {
        temp_v1 =
            entity->ext.generic.unk88.S16.unk0 + entity->ext.generic.unk84.unk;
        entity->ext.generic.unk84.unk = temp_v1;
        entity->velocityX = temp_v1;
        if (temp_v1 == 0x10000 || temp_v1 == -0x10000) {
            entity->ext.generic.unk88.S16.unk0 =
                -entity->ext.generic.unk88.S16.unk0;
        }
        entity = g_CurrentEntity;
    }

    if (entity->velocityY < FIX(0.25)) {
        entity->velocityY += FIX(0.125);
    }
}

void func_801B5F4C(u16 arg0) {
    Collider res;

    if (g_CurrentEntity->velocityX < 0) {
        g_api.CheckCollision(g_CurrentEntity->posX.i.hi,
                             g_CurrentEntity->posY.i.hi - 7, &res, 0);
        if (res.effects & 5) {
            g_CurrentEntity->velocityY = 0;
        }
    }

    g_api.CheckCollision(
        g_CurrentEntity->posX.i.hi, g_CurrentEntity->posY.i.hi + 7, &res, 0);

    if (arg0) {
        if (!(res.effects & 5)) {
            MoveEntity();
            FallEntity();
            return;
        }

        g_CurrentEntity->velocityX = 0;
        g_CurrentEntity->velocityY = 0;

        if (res.effects & 4) {
            g_CurrentEntity->posY.val += FIX(0.125);
            return;
        }

        g_CurrentEntity->posY.i.hi += res.unk18;
        return;
    }

    if (!(res.effects & 5)) {
        MoveEntity();
        func_801B5EC8();
    }
}

void CollectHeart(u16 index) {
    s8 hearts[10];

    __builtin_memcpy(&hearts[0], &c_HeartPrizes[0], 2);
    __builtin_memcpy(&hearts[8], &c_HeartPrizes[4], 2);
    g_api.PlaySfx(NA_SE_PL_COLLECT_HEART);
    g_Status.hearts = hearts[index] + g_Status.hearts;
    if (g_Status.heartsMax < g_Status.hearts) {
        g_Status.hearts = g_Status.heartsMax;
    }
    DestroyEntity(g_CurrentEntity);
}

void CollectGold(u16 index) {
    g_api.PlaySfx(0x6A9);
    index -= 2;
    g_Status.gold += D_80181CF0[index];

    if ((s32)g_Status.gold > 0xF423F) {
        g_Status.gold = 0xF423F;
    }
}

void func_801B61D4(void) {}

void func_801B61DC(void) { DestroyEntity(g_CurrentEntity); }

void CollectSubweapon(u16 subWeaponIdx) {
    Entity* player = &PLAYER;
    u16 subWeapon;

    g_api.PlaySfx(NA_SE_PL_IT_PICKUP);
    subWeapon = g_Status.subWeapon;
    g_Status.subWeapon = D_80181CAC[subWeaponIdx];

    if (subWeapon == g_Status.subWeapon) {
        subWeapon = 1;
        g_CurrentEntity->unk6D[0] = 0x10;
    } else {
        subWeapon = D_80181CDC[subWeapon];
        g_CurrentEntity->unk6D[0] = 0x60;
    }

    if (subWeapon != 0) {
        g_CurrentEntity->params = subWeapon;
        g_CurrentEntity->posY.i.hi = player->posY.i.hi + 12;
        g_CurrentEntity->step = 7;
        g_CurrentEntity->step_s = 0;
        g_CurrentEntity->velocityY = FIX(-2.5);
        g_CurrentEntity->animCurFrame = 0;
        g_CurrentEntity->ext.generic.unk88.S16.unk2 = 5;
        if (player->facing != 1) {
            g_CurrentEntity->velocityX = FIX(-2);
            return;
        }
        g_CurrentEntity->velocityX = FIX(2);
        return;
    }
    DestroyEntity(g_CurrentEntity);
}

void CollectDummy(void) { DestroyEntity(g_CurrentEntity); }

Entity* func_801B633C(void) {
    g_CurrentEntity->step = 3;
    g_CurrentEntity->params = 4;
    return g_CurrentEntity;
}
