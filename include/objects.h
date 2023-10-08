/*
 * File: objects.h
 * Description: SOTN Object header
 */

void EntityBreakable(Entity*);
void EntityExplosion(Entity*);
void EntityPrizeDrop(Entity*);
void EntityNumericDamage(Entity*);
void EntityRedDoor(Entity*);
void EntityIntenseExplosion(Entity*);
void EntitySoulStealOrb(Entity*);
void EntityRoomForeground(Entity*);
void BottomCornerText(u8*, u8);
void EntityStageNamePopup(Entity*);
void EntityEquipItemDrop(Entity*);
void EntityRelicOrb(Entity*);
#ifndef MAD_H
void EntityHeartDrop(Entity*);
#else
void EntityHeartDrop(Entity* entity, u32 arg1);
#endif
void EntityEnemyBlood(Entity*);
void EntityMessageBox(Entity*);
void EntityDummy(Entity*);
