// SPDX-License-Identifier: AGPL-3.0-or-later
#include "../dra/dra.h"
#include "../dra/dra_bss.h"

// Given a range of start and end values, finds an unused entity
// slot in g_Entities to fill in. Starts at start, and goes to
// end-1. If none in the range are available, returns NULL.
Entity* GetFreeEntity(s16 start, s16 end) {
    Entity* entity = &g_Entities[start];
    s16 i;

    for (i = start; i < end; i++, entity++) {
        if (entity->entityId == E_NONE) {
            return entity;
        }
    }
    return NULL;
}

// Like GetFreeEntity, but searches for an open spot
// starting from the end and working backward
Entity* GetFreeEntityReverse(s16 start, s16 end) {
    Entity* entity = &g_Entities[end - 1];
    s16 i;

    for (i = end - 1; i >= start; i--, entity--) {
        if (entity->entityId == E_NONE) {
            return entity;
        }
    }
    return NULL;
}

void func_80118894(Entity* self) {
    s32 i;
    s32 search_value;

    if (self == &g_Entities[E_WEAPON]) {
        if (!(self->params & 0x8000)) {
            self->enemyId = 1;
        } else {
            self->enemyId = 2;
        }
        return;
    }
    // It appears we're looping over elements of the 8013800C array.
    // If the pointer to arg0 comes before the 32nd (0x20th) g_Entities,
    // we iterate through the 8013800C array, starting from element 3 and going
    // as high as 7, searching for our enemy ID. Otherwise we do the same, but
    // starting from element 7 and going up to 11. 8013800C therefore must have
    // 11 elements. It may be possible to refactor this code to remove the
    // duplication.
    // D_8013800C looks to be keeping track of how many abilities/attacks are
    // targeting a specific enemy selecting the lowest targeted entity from 3-6
    // or 7-11
    if (self < &g_Entities[UNK_ENTITY_20]) {
        for (search_value = 0; true; search_value++) {
            for (i = 3; i < 7; i++) {
                if (D_8013800C[i] == search_value) {
                    D_8013800C[i]++;
                    self->enemyId = i;
                    return;
                }
            }
        }
    } else {
        for (search_value = 0; true; search_value++) {
            for (i = 7; i < 11; i++) {
                if (D_8013800C[i] == search_value) {
                    D_8013800C[i]++;
                    self->enemyId = i;
                    return;
                }
            }
        }
    }
}

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_80118970);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_80118B18);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_80118C28);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_09124FB8);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityNumberMovesToHpMeter);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_09125DB8);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityGuardText);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntitySmallRisingHeart);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_80119E78);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_80119F70);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011A290);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011A328);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_09127348);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011A4C8);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011A4D0);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_091279A0);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_09127B50);

// Problem: Function clearly treats arg2 as s16 (see here: https://decomp.me/scratch/lK7y4)
// If the function is written here as anything but s16, it fails.
// But that's in conflict with the forward declaration in dra.h.
// So we can try to change that declaration to use s16, but then the callers of this function no longer
// match, because then they're doing `seh` on their variables before passing them to this function.
// So okay, we can delete the forward declaration, so that the other functions don't know about arg2
// being s16 and will assume it's an int. But then any function that does 
// entity = CreateEntFactoryFromEntity(blah, blah, blah) will fail, because without the forward
// declaration, we also assume the return type is int. And we can't implicitly cast int to Entity*.

// We need 3 things to all be true:
// 1. Other functions must know this function returns an Entity*
// 2. Other functions must believe arg2 is an s32
// 3. This function must believe arg2 is an s16.
// I do not know any way to make these all work at the same time.

Entity* CreateEntFactoryFromEntity(
    Entity* source, u32 factoryParams, s32 arg2) {
    Entity* newFactory;


    newFactory = GetFreeEntity(8, 16);
    if (newFactory == NULL) {
        return NULL;
    }

    DestroyEntity(newFactory);
    newFactory->entityId = E_ENTITYFACTORY;
    newFactory->ext.factory.parent = source;
    newFactory->posX.val = source->posX.val;
    newFactory->posY.val = source->posY.val;
    newFactory->facingLeft = source->facingLeft;
    newFactory->zPriority = source->zPriority;
    newFactory->params = factoryParams & 0xFFF;
    if (factoryParams & 0x5000) {
        newFactory->ext.factory.unkA8 = 0xE0;
    }
    if (factoryParams & 0xA000) {
        newFactory->ext.factory.unkA8 = 0xF0;
    }
    newFactory->ext.factory.unkA0 = (factoryParams & 0xFF0000) >> 8;
    newFactory->ext.factory.unk92 = arg2;
    if (source->flags & FLAG_UNK_10000) {
        newFactory->flags |= FLAG_UNK_10000;
    }
    if (factoryParams & 0x1000) {
        newFactory->entityId = 0xEF;
    }
    if (factoryParams & 0x2000) {
        newFactory->entityId = 0xFF;
    }
    if (factoryParams & 0x4000) {
        newFactory->entityId = 0xED;
    }
    if (factoryParams & 0x8000) {
        newFactory->entityId = 0xFD;
    }

    return newFactory;
}

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityEntFactory);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityUnarmedAttack);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityDiveKickAttack);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011B480);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011B530);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011B5A4);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityUnkId24);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_psp_091295F0);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityPlayerBlinkWhite);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityPlayerOutline);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", func_8011E0E4);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityGravityBootBeam);

INCLUDE_ASM("dra_psp/psp/dra_psp/47EA8", EntityWingSmashTrail);
