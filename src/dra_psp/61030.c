// SPDX-License-Identifier: AGPL-3.0-or-later
#include "../dra/dra.h"
#include "../dra/dra_bss.h"


INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_800E9880);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913DA28);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913DAA8);

extern char** D_psp_091CE258;
extern char D_psp_09186E28[];

void StoreSaveData(SaveData* save, s32 block, s32 cardIcon) {
    const int RoomCount = 942;
    MemcardHeader h; //sp80 (i have 70)
    SaveData* dst2; //sp7c
    u8 saveTitle[64]; //sp3c (i have 30)
    
    PlayerStatus* dstStatus; //s8
    MenuNavigation* dstNav; //s7
    GameSettings* dstSettings; //s6
    u32* saveRaw; //s5
    s32 saveNameLen; //s4
    SaveData* dst; //s2
    s32 j; //s1
    s32 i; //s0



    saveRaw = (u32*)save;
    for (i = 0; i < 0x800; i++) {
        *saveRaw++ = 0;
    }

    h.Magic[0] = 'S';
    h.Magic[1] = 'C';
    h.Type = 0x13;
    h.BlockEntry = 1;

    // The h.Title content will look like this:
    // US: ＣＡＳＴＬＥＶＡＮＩＡ－１１　ＡＬＵＣＡＲＤ　２００％
    // HD: ドラキュラＸ−１１　ＡＬＵＣＡＲＤ　オルロックの間　２００％
    for (i = 0; i < 0x5C; i++) {
        h.Title[i] = 0;
    }

#if defined(VERSION_US)
    STRCPY(h.Title, "ＣＡＳＴＬＥＶＡＮＩＡ−");
#elif defined(VERSION_HD)
    STRCPY(h.Title, "ドラキュラＸ−");
#elif defined(VERSION_PSP)
    STRCPY(h.Title, "ドラキュラＸ−");
#endif

    // writes slot number
    if (block > 8) {
        STRCPY(saveTitle, "００");
        saveTitle[1] += (block + 1) / 10;
        saveTitle[3] += (block + 1) % 10;
        strcat(h.Title, saveTitle);
    } else {
        STRCPY(saveTitle, "０");
        saveTitle[1] += block + 1;
        strcat(h.Title, saveTitle);
    }

    strcat(h.Title, "　");
    for (saveNameLen = 7; saveNameLen > 0; saveNameLen--) {
        if (g_Status.saveName[saveNameLen] != 0x20) {
            break;
        }
    }

    // writes save name
    for (i = 0; i < saveNameLen + 1; i++) {
        char ch = g_Status.saveName[i];
        for (j = 0; j < 0x20; j++) {
            // Converts ASCII into Shift-JIS
            if (ch == g_AsciiSet[j]) {
                strcat(h.Title, g_ShiftJisSet[j]);
                break;
            }
        }
    }

#if defined(VERSION_HD)
    // writes stage name
    strcat(h.Title, "　");
    strcat(h.Title, g_SaveAreaNames[g_StageId]);
#endif

    // writes room completion percentage
    strcat(h.Title, "　");
    STRCPY(h.Title, D_psp_091CE258[g_StageId]);
    STRCPY(h.Title, D_psp_09186E28);
    i = g_RoomCount * 100 / RoomCount;
    if (i >= 100) {
        STRCPY(saveTitle, "０００");
        saveTitle[1] += i / 100;
        saveTitle[3] += (i / 10) % 10;
        saveTitle[5] += i % 10;
        strcat(h.Title, saveTitle);
    } else if (i > 9) {
        STRCPY(saveTitle, "００");
        saveTitle[1] += i / 10;
        saveTitle[3] += i % 10;
        strcat(h.Title, saveTitle);
    } else {
        STRCPY(saveTitle, "０");
        saveTitle[1] += i;
        strcat(h.Title, saveTitle);
    }
    strcat(h.Title, "％");

    GetSavePalette(h.Clut, cardIcon);
    GetSaveIcon(h.Icon, cardIcon);

    dst = save;
    dst2 = dst;
    dstStatus = &dst->status;
    dstNav = &dst->menuNavigation;
    dstSettings = &dst->settings;
    dst2->header = h;
    for (i = 0; i < 10; i++) {
        dst->info.name[i] = g_Status.saveName[i];
    }

    dst->info.level = g_Status.level;
    dst->info.gold = g_Status.gold;
    dst->info.playHours = g_Status.timerHours;
    dst->info.playMinutes = g_Status.timerMinutes;
    dst->info.playSeconds = g_Status.timerSeconds;
    dst->info.cardIcon = cardIcon;
    dst->info.stage = g_StageId;
    dst->info.endGameFlags = g_IsTimeAttackUnlocked;
    dst->info.character = g_PlayableCharacter;
    dst->info.nRoomsExplored = g_RoomCount;
    dst->info.roomX = g_Tilemap.left;
    dst->info.roomY = g_Tilemap.top;
    dst->info.saveSize = sizeof(SaveData);

    *dstStatus = g_Status;
    *dstNav = g_MenuNavigation;
    *dstSettings = g_Settings;

    for (i = 0; i < LEN(g_CastleFlags); i++) {
        dst->castleFlags[i] = g_CastleFlags[i];
    }

    for (i = 0; i < LEN(g_CastleMap); i++) {
        dst->castleMap[i] = g_CastleMap[i];
    }

    dst->rng = g_randomNext;
}

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", LoadSaveData);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", MakeMemcardPath);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913E4F8);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913E558);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913E658);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", func_psp_0913E6D0);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", DestroyEntity);

INCLUDE_ASM("dra_psp/psp/dra_psp/61030", DestroyEntitiesFromIndex);
