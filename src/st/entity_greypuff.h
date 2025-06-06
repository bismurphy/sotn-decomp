// SPDX-License-Identifier: AGPL-3.0-or-later
extern s16 greyPuff_rot[];
extern s32 greyPuff_yVel[];

// looks like a particle of dust fading away
// params: Index of scaleX and velocityY to use
void EntityGreyPuff(Entity* self) {
    if (!self->step) {
        self->flags =
            FLAG_UNK_2000 | FLAG_KEEP_ALIVE_OFFCAMERA | FLAG_POS_CAMERA_LOCKED;
        self->palette = PAL_OVL(0x195);
        self->animSet = ANIMSET_DRA(5);
        self->animCurFrame = 1;
        self->drawMode = DRAW_TPAGE;
        self->drawFlags = FLAG_DRAW_SCALEX | FLAG_DRAW_SCALEY;
        self->scaleX = greyPuff_rot[self->params];
        self->scaleY = self->scaleX;
        self->velocityY = greyPuff_yVel[self->params];
        self->step++;
    } else {
        self->posY.val -= self->velocityY;
        self->poseTimer++;
        if (!(self->poseTimer % 2)) {
            self->animCurFrame++;
        }
        if (self->poseTimer > 36) {
            DestroyEntity(self);
        }
    }
}
