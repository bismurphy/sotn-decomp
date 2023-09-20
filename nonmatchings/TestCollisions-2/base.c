typedef enum {
    PLAYER_CHARACTER,
    UNK_ENTITY_1,
    UNK_ENTITY_2,
    UNK_ENTITY_3,
    UNK_ENTITY_4,
    UNK_ENTITY_5,
    UNK_ENTITY_6,
    UNK_ENTITY_7,
    UNK_ENTITY_8,
    E_WEAPON = 0x10,
    UNK_ENTITY_13 = 0x13,
    UNK_ENTITY_20 = 0x20,
    UNK_ENTITY_51 = 0x51,
    UNK_ENTITY_100 = 0x100
} EntityTypes;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_long;
typedef unsigned int size_t;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char byte;
typedef enum { false, true } bool;
int sprintf(char* dst, const char* fmt, ...);
struct DIRENTRY {
               char name[20];
               long attr;
               long size;
               struct DIRENTRY* next;
              long head;
               char system[4];
};
void EnterCriticalSection(void);
void ExitCriticalSection(void);
long _card_info(long chan);
long _card_clear(long chan);
long _card_load(long chan);
void InitCARD(long val);
long StartCARD(void);
struct EXEC {
    unsigned long pc0;
    unsigned long gp0;
    unsigned long t_addr;
    unsigned long t_size;
    unsigned long d_addr;
    unsigned long d_size;
    unsigned long b_addr;
    unsigned long b_size;
    unsigned long s_addr;
    unsigned long s_size;
    unsigned long sp, fp, gp, ret, base;
};
extern void InitHeap(unsigned long*, unsigned long);
extern long Load(char*, struct EXEC*);
extern long Exec(struct EXEC*, long, char**);
extern void _bu_init(void);
extern long open(char* devname,
                 int flag
);
extern long lseek(long, long, long);
extern long read(long fd,
                 void* buf,
                 long n
);
extern long write(long, void*, long);
extern int close(int fd
);
extern long format(char* fs
);
extern struct DIRENTRY* firstfile(char*, struct DIRENTRY*);
extern struct DIRENTRY* nextfile(struct DIRENTRY*);
extern long erase(char*);
extern long Krom2RawAdd(unsigned long);
extern void ChangeClearPAD(long);
extern void StopPAD(void);
int PAD_init(s32 , s32* );
extern void FlushCache(void);
extern void DeliverEvent(unsigned long, unsigned long);
extern long TestEvent(unsigned long event
);
extern long OpenEvent(unsigned long, long, long, long (*func)());
extern long EnableEvent(long);
extern void _96_remove(void);
extern long SetRCnt(unsigned long, unsigned short, long);
extern long StartRCnt(unsigned long);
extern void exit();
extern void puts(char*);
extern char* strcat(char*, char*);
extern char* strcpy(char*, char*);
extern int strlen(char*);
extern void* memcpy(unsigned char*, unsigned char*, int);
extern void* memset(unsigned char*, unsigned char, int);
extern int rand(void);
extern void srand(unsigned int);
extern void* malloc(size_t
);
extern void free(void*);
int printf(char*, ...);
typedef struct {
    u_char minute;
    u_char second;
    u_char sector;
    u_char track;
} CdlLOC;
typedef struct {
    u_char val0;
    u_char val1;
    u_char val2;
    u_char val3;
} CdlATV;
typedef struct {
    u_short id;
    u_short type;
    u_short secCount;
    u_short nSectors;
    u_long frameCount;
    u_long frameSize;
    u_short width;
    u_short height;
    u_long dummy1;
    u_long dummy2;
    CdlLOC loc;
} StHEADER;
typedef struct {
    CdlLOC pos;
    u_long size;
    char name[16];
} CdlFILE;
typedef void (*CdlCB)(u_char, u_char*);
void def_cbsync(u_char intr, u_char* result);
void def_cbready(u_char intr, u_char* result);
void def_cbread(u_char intr, u_char* result);
int CdInit(void);
int CdStatus(void);
int CdMode(void);
int CdLastCom(void);
int CdReset(int mode);
void CdFlush(void);
int CdSetDebug(int level);
char* CdComstr(u_char com);
char* CdIntstr(u_char intr);
int CdSync(int mode, u_char* result);
int CdReady(int mode, u_char* result);
CdlCB CdSyncCallback(CdlCB func);
CdlCB CdReadyCallback(CdlCB func);
int CdControl(u_char com, u_char* param, u_char* result);
int CdControlB(u_char com, u_char* param, u_char* result);
int CdControlF(u_char com, u_char* param);
int CdMix(CdlATV* vol
);
int CdGetSector(void* madr, int size);
void(*CdDataCallback(void (*func)()));
CdlLOC* CdIntToPos(int i, CdlLOC* p);
int CdPosToInt(CdlLOC* p);
CdlFILE* CdSearchFile(CdlFILE* fp, char* name);
int CdRead(int sectors, u_long* buf, int mode);
int CdReadSync(int mode, u_char* result);
CdlCB CdReadCallback(CdlCB func);
int CdRead2(long mode);
void StClearRing(void);
void StSetStream(u_long mode, u_long start_frame, u_long end_frame,
                 void (*func1)(), void (*func2)());
void StSetMask(u_long mask, u_long start, u_long end);
u_long StGetNext(u_long** addr, u_long** header);
u_long StFreeRing(u_long* base);
int StGetBackloc(CdlLOC* loc);
void StUnSetRing(void);
struct Callbacks {
    void (*unk0)(void);
    void* (*DMACallback)(int dma, void (*func)());
    void (*unk8)(void);
    int (*ResetCallback)(void);
    int (*StopCallback)(void);
    int (*VSyncCallbacks)(int ch, void (*f)());
    int (*RestartCallback)(void);
};
extern u16 D_8002C2BA;
extern struct Callbacks* D_8002D340;
int ResetCallback(void);
int VSyncCallback(void (*f)());
int VSyncCallbacks(int ch, void (*f)());
int StopCallback(void);
int RestartCallback(void);
u16 CheckCallback(void);
long SetVideoMode(long mode);
void PadInit(int mode);
u_long PadRead(int id);
void PadStop(void);
typedef struct {
              short x;
              short y;
              short w;
              short h;
} RECT;
typedef struct {
              u_long tag;
              u_long code[15];
} DR_ENV;
typedef struct {
    unsigned addr : 24;
    unsigned len : 8;
    u_char r0, g0, b0, code;
} P_TAG;
typedef struct {
    u_char r0, g0, b0, code;
} P_CODE;
typedef struct {
               u_long tag;
               u_char r0, g0, b0, code;
               short x0, y0;
               u_char r1, g1, b1, p1;
               short x1, y1;
} LINE_G2;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char u0;
               u_char v0;
               u_short clut;
               u_char r1;
               u_char g1;
               u_char b1;
               u_char p1;
               short x1;
               short y1;
               u_char u1;
               u_char v1;
               u_short tpage;
               u_char r2;
               u_char g2;
               u_char b2;
               u_char p2;
               short x2;
               short y2;
               u_char u2;
               u_char v2;
               u_short pad2;
} POLY_GT3;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char r1;
               u_char g1;
               u_char b1;
               u_char pad1;
               short x1;
               short y1;
               u_char r2;
               u_char g2;
               u_char b2;
               u_char pad2;
               short x2;
               short y2;
               u_char r3;
               u_char g3;
               u_char b3;
               u_char pad3;
               short x3;
               short y3;
} POLY_G4;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char u0;
               u_char v0;
               u_short clut;
               u_char r1;
               u_char g1;
               u_char b1;
               u_char p1;
               short x1;
               short y1;
               u_char u1;
               u_char v1;
               u_short tpage;
               u_char r2;
               u_char g2;
               u_char b2;
               u_char p2;
               short x2;
               short y2;
               u_char u2;
               u_char v2;
               u_short pad2;
               u_char r3;
               u_char g3;
               u_char b3;
               u_char p3;
               short x3;
               short y3;
               u_char u3;
               u_char v3;
               u_short pad3;
} POLY_GT4;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char u0;
               u_char v0;
               u_short clut;
               short w;
               short h;
} SPRT;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char u0;
               u_char v0;
               u_short clut;
} SPRT_16;
typedef struct {
               u_long tag;
               u_char r0;
               u_char g0;
               u_char b0;
               u_char code;
               short x0;
               short y0;
               u_char u0;
               u_char v0;
               u_short clut;
} SPRT_8;
typedef struct {
               u_long tag;
               u_char r0, g0, b0, code;
               short x0, y0;
               short w, h;
} TILE;
typedef struct {
               RECT clip;
               short ofs[2];
               RECT tw;
               u_short tpage;
               u_char dtd;
               u_char dfe;
               u_char isbg;
               u_char r0, g0, b0;
               DR_ENV dr_env;
} DRAWENV;
typedef struct {
               RECT disp;
               RECT screen;
               u_char isinter;
               u_char isrgb24;
               u_char pad0;
               u_char pad1;
} DISPENV;
typedef struct {
               u_long tag;
               u_long code[2];
} DR_MODE;
typedef struct PixPattern {
    u8 w;
    u8 h;
    u8 x;
    u8 y;
} PixPattern;
extern u_short LoadTPage(u_long* pix,
          int tp,
          int abr,
          int x, int y,
          int w, int h
);
extern u_short LoadClut2(u_long *clut, int x, int y);
u_short GetClut(int x,
                int y
);
extern void AddPrim(void* ot, void* p);
extern void SetShadeTex(void* p, int tge);
extern void SetLineG2(LINE_G2* p);
extern void SetPolyGT3(POLY_GT3* p);
extern void SetPolyG4(POLY_G4* p);
extern void SetPolyGT4(POLY_GT4* p);
extern void SetSemiTrans(void* p, int abe);
extern void SetSprt(SPRT* p);
extern void SetSprt16(SPRT_16* p);
extern void SetSprt8(SPRT_8* p);
extern void SetTile(TILE* p);
extern int ResetGraph(int mode);
int SetGraphDebug(int level);
extern int SetGraphReverse(int mode);
extern int SetGraphQueue(int mode);
extern u_long DrawSyncCallback(void (*func)());
extern void FntLoad(int tx, int ty);
int FntPrint(const char* fmt, ...);
extern void SetDispMask(int mask);
extern void SetDrawMode(DR_MODE* p, int dfe, int dtd, int tpage, RECT* tw);
extern void SetDumpFnt(int id);
extern int ClearImage(RECT* rect, u_char r, u_char g, u_char b);
extern int DrawSync(int mode);
extern int FntOpen(int x, int y, int w, int h, int isbg, int n);
extern u_long* FntFlush(int id);
extern int LoadImage(RECT* rect, u_long* p);
extern int StoreImage(RECT* rect, u_long* p);
extern int MoveImage(RECT* rect, int x, int y);
extern u_long* ClearOTag(u_long* ot, int n);
extern u_long* ClearOTagR(u_long* ot, int n);
extern void DrawOTag(u_long* p);
extern DRAWENV* PutDrawEnv(DRAWENV* env);
extern DISPENV* PutDispEnv(DISPENV* env);
extern DISPENV* SetDefDispEnv(DISPENV* env, int x, int y, int w, int h);
extern DRAWENV* SetDefDrawEnv(DRAWENV* env, int x, int y, int w, int h);
extern void SetDrawEnv(DR_ENV* dr_env, DRAWENV* env);
void GsClearVcount(void);
long GsGetVcount();
void GsInitVcount();
void InitGeom();
typedef struct {
    short m[3][3];
    long t[3];
} MATRIX;
typedef struct {
    long vx, vy, vz;
    long pad;
} VECTOR;
typedef struct {
    short vx, vy, vz;
    short pad;
} SVECTOR;
typedef struct {
    u_char r, g, b;
    u_char cd;
} CVECTOR;
MATRIX* RotMatrix(SVECTOR* r, MATRIX* m);
void SetGeomOffset(long ofx, long ofy);
long RotTransPers(SVECTOR*, long*, long*, long*);
void SetGeomScreen(long h);
void SetRotMatrix(MATRIX* m);
MATRIX* TransMatrix(MATRIX* m, VECTOR* v);
void SetTransMatrix(MATRIX* m);
long RotTransPers4(
    SVECTOR* v0, SVECTOR* v1, SVECTOR* v2,
    SVECTOR* v3,
    long* v10, long* v11, long* v12,
    long* v13,
    long* p,
    long* flag
);
long RotAverageNclip4(
    SVECTOR* v0, SVECTOR* v1, SVECTOR* v2,
    SVECTOR* v3,
    long* sxy0, long* sxy1, long* sxy2,
    long* sxy3,
    long* p,
    long* otz,
    long* flag
);
void NormalColorCol(SVECTOR* v0,
                    CVECTOR* v1,
                    CVECTOR* v2
);
MATRIX* RotMatrixY(long r,
                   MATRIX* m
);
void SetBackColor(long rbk, long gbk, long bbk);
void SetColorMatrix(MATRIX* m);
void SetLightMatrix(MATRIX* m);
void SetTransMatrix(MATRIX* m);
void SetFarColor(long rfc, long gfc, long bfc);
void SetFogNear(long a, long h);
extern void SsSeqClose(short seq_access_num);
extern void SsSetMVol(short voll, short volr);
extern void SsSetSerialAttr(char s_num, char attr, char mode);
extern void SsSetSerialVol(short s_num, short voll, short volr);
extern long SpuClearReverbWorkArea(long rev_mode
);
void SsInitHot(void);
char SsSetReservedVoice(char voices
);
void SsSetTickMode(long tick_mode
);
void SsStart(void);
short SsUtKeyOnV(
    short voice,
    short vabId,
    short prog,
    short tone,
    short note,
    short fine,
    short voll,
    short volr
);
short SsUtSetVVol(short vc,
                  short voll,
                  short volr
);
void SpuGetAllKeysStatus(char* status);
void SsSetTableSize(
    char* table,
    short s_max,
    short t_max
);
void SsSeqStop(short seq_access_num
);
void SsSetMono(void);
void SsSetStereo(void);
s32 SsVabOpenHeadSticky(
    u_char* addr,
    short vabid,
    u_long sbaddr
);
s32 SsVabTransBodyPartly(
    u_char* addr,
    u_long bufsize,
    short vabid
);
s32 SsVabTransCompleted(
    short immediateFlag
);
void SsUtSetReverbType(short type);
void SsUtReverbOn(void);
void SsUtSetReverbDepth(
    short ldepth,
    short rdepth
);
typedef long Event;
typedef enum {
    PRIM_NONE,
    PRIM_TILE,
    PRIM_LINE_G2,
    PRIM_G4,
    PRIM_GT4,
    PRIM_GT3,
    PRIM_SPRT,
    PRIM_ENV,
} PrimitiveType;
typedef struct Vertex {
              u8 r;
              u8 g;
              u8 b;
              u8 p;
              s16 x;
              s16 y;
              u8 u;
              u8 v;
              u16 param;
} Vertex;
typedef struct {
               SVECTOR* v0;
               SVECTOR* v1;
               SVECTOR* v2;
               SVECTOR* v3;
} SVEC4;
typedef struct {
    s16 x;
    s16 y;
    u8 u;
    u8 v;
    u16 param;
    u8 r;
    u8 g;
    u8 b;
    u8 p;
} VertexFake;
typedef struct Prim {
    struct Prim* next;
    struct Vertex v[4];
} Prim;
typedef struct Primitive {
               struct Primitive* next;
               u8 r0;
               u8 g0;
               u8 b0;
               u8 type;
               s16 x0;
               s16 y0;
               u8 u0;
               u8 v0;
               u16 clut;
               u8 r1;
               u8 g1;
               u8 b1;
               u8 p1;
               s16 x1;
               s16 y1;
               u8 u1;
               u8 v1;
               u16 tpage;
               u8 r2;
               u8 g2;
               u8 b2;
               u8 p2;
               s16 x2;
               s16 y2;
               u8 u2;
               u8 v2;
               u16 priority;
               u8 r3;
               u8 g3;
               u8 b3;
               u8 p3;
               s16 x3;
               s16 y3;
               u8 u3;
               u8 v3;
               u16 blendMode;
} Primitive;
typedef union {
    s32 unk;
    void* ptr;
    struct {
        s8 unk0, unk1, unk2, unk3;
    } S8;
    struct {
        u8 unk0, unk1, unk2, unk3;
    } U8;
    struct {
        s16 unk0, unk2;
    } S16;
    struct {
        u16 unk0, unk2;
    } U16;
} Multi;
typedef union {
    s16 s;
    u16 u;
    struct {
        s8 unk0, unk1;
    } S8;
    struct {
        u8 unk0, unk1;
    } U8;
} Multi16;
struct Entity;
typedef struct ET_Generic {
               Multi16 unk7C;
    union {
                   u16 modeU16;
        struct {
                       u8 unk0;
                       u8 unk1;
        } modeU8;
    } unk7E;
    union {
                   s32 modeS32;
                   struct Entity* entityPtr;
        struct {
                       s16 unk0;
                       s16 unk2;
        } modeS16;
        struct {
                       u8 unk0;
                       u8 unk1;
        } modeS8;
    } unk80;
               Multi unk84;
               Multi unk88;
    union {
                   struct Entity* entityPtr;
                   struct Primitive* primPtr;
                   s32 modeS32;
        struct {
                       u16 unk0;
                       u16 unk2;
        } modeU16;
        struct {
                       s16 unk0;
                       s16 unk2;
        } modeS16;
    } unk8C;
               s16 unk90;
               s16 unk92;
               u8 unk94;
               u8 unk95;
               s16 unk96;
               s32 unk98;
               struct Entity* unk9C;
               s16 unkA0;
               s16 unkA2;
               s16 unkA4;
               s16 unkA6;
               s16 unkA8;
               s16 unkAA;
               u8 unkAC;
               s8 unkAD;
               s8 unkAE;
               s8 unkAF;
               s16 unkB0;
               s16 unkB2;
               s16 unkB4;
               s16 unkB6;
    union {
                   void (*unkFuncB8)(struct Entity*);
                   struct Entity* entityPtr;
        struct {
                       u8 unk0;
                       u8 unk1;
                       u8 unk2;
                       u8 unk3;
        } modeU8;
    } unkB8;
} ET_Generic;
typedef struct {
               u16 timer;
               s16 unk7E;
               u8 unk80;
               s8 unk81;
               s16 unk82;
               s16 unk84;
               s16 unk86;
               s16 unk88;
               s16 unk8A;
               s16 unk8C;
               s16 unk8E;
               s16 unk90;
               s16 unk92;
               s16 unk94;
} ET_EquipItemDrop;
typedef struct {
    u16 unk7C;
    u16 unk7E;
    u16 sparkleCycle;
    u16 sparkleAnim;
    u32 unk84;
    u32 unk88;
    s16 iconSlot;
    u16 unk8E;
    u16 floatTimer;
    u16 unk92;
    s32 yFloatSpeed;
} ET_RelicOrb;
typedef struct {
               u8* label;
               u16 width;
               u16 height;
               s16 unk84;
               u16 duration;
} ET_MessageBox;
typedef struct {
               s16 unk7C;
               s16 unk7E;
               s32 unk80;
               s32 unk84;
               s32 unk88;
               struct Entity* parent;
               s32 unk90;
               s32 unk94;
               s32 unk98;
               s32 unk9C;
               s32 unkA0;
               s32 unkA4;
               s32 unkA8;
               u8 unkAC;
               u8 unkAD;
               s16 equipId;
} ET_Weapon;
typedef struct {
               char pad_7C[0x4];
               s16 timer;
               char pad_82[0x2];
               u8 attackMode;
               u8 flag;
               u8 nearDeath;
               s32 speed;
               s16 angle;
               char pad_8E[0xE];
               u8 pickupFlag;
               u8 grabedAscending;
} ET_GaibonSlogra;
typedef struct {
               s16 angle;
               u16 unk7E;
               u16 unk80;
               s16 unk82;
} ET_SoulStealOrb;
typedef struct {
               Primitive* primBg;
               s32 unused80;
               Primitive* primFade;
} ET_WarpRoom;
typedef struct {
               char pad_0[0x8];
               u8 timer;
               char pad_85[0x1];
               s8 timer2;
               char pad_87[0x5];
               u16 palette;
               char pad_8E[0x12];
               u8 isUnderwater;
               u8 ignoreCol;
} ET_Merman;
typedef struct {
               struct Primitive* prim;
               char pad_0[0x6];
               s8 timer;
               char pad_87[0x5];
               s16 rotation;
               char pad_8E[0x12];
               u8 isUnderwater;
               u8 ignoreCol;
} ET_Merman_2;
typedef struct {
               s32 unk7C;
               s16 unk80;
               s16 unk82;
               s16 unk84;
               s16 unk86;
               s16 unk88;
               s16 unk8A;
               s16 unk8C;
               s16 unk8E;
               s32 unk90;
               s32 unk94;
               s32 unk98;
               s32 unk9C;
               s16 unkA0;
               s16 unkA2;
               s16 unkA4;
               s16 unkA6;
               s16 unkA8;
               s16 unkAA;
               s16 cameraX;
               s16 cameraY;
               s32 unkB0;
               struct Entity* ent;
} ET_Familiar;
typedef struct {
               char pad_0[0xC];
               u16 unk88;
               char pad_8A[0x3];
               u8 unk8D;
               char pad_8E[0xE];
               s16 unk9C;
               struct Entity* next;
} ET_801CF254;
typedef struct {
               char pad_0[0x4];
               s16 unk80;
               char pad_82[0xA];
               u8 unk8C;
               char pad_8D[0xF];
               u16 unk9C;
               char pad_9E[0x8];
               s16 unkA6;
} ET_GurkhaSword;
typedef struct ET_Dracula {
               char pad_7C[0x10];
               s16 unk8C;
               char pad_8E[0x2];
               char pad_90[0x4];
               u8 unk94;
               char pad_95[0x3];
               s16 unk98;
               char pad_9A[0x2];
               s16 unk9C;
               char pad_9E[0x2];
               u8 unkA0;
               u8 unkA1;
               u8 unkA2;
               char pad_A3[0x9];
               struct Primitive* prim;
} ET_Dracula;
typedef struct {
               struct Primitive* prim;
               s32 unk80;
               s32 unk84;
               s16 unk88;
               char pad_8A[0x2];
               s16 unk8C;
               s16 unk8E;
} ET_StageTitleCard;
typedef struct ET_Succubus {
               char pad_7C[0x4];
               s16 timer;
               char pad_82[0x2];
               u8 facingLeft;
               u8 unk85;
               u8 nextAttack;
               u8 unk87;
               u16 nextStep;
               char pad_8A[0x4];
               s16 yOffset;
               char pad_90[0xC];
               struct Entity* real;
               s16 clonePosX;
               s16 unkA2;
} ET_Succubus;
typedef struct {
               u16 timer;
               char pad_7E[2];
               s32 unk80;
} ET_RoomTransition2;
typedef struct {
               u8 pad0[0x4];
               s32 unk80;
               s16 unk84;
               u8 pad86[2];
               u8 unk88;
               u8 unk89;
} ET_801B3C38;
typedef struct {
               u16 unk7C;
} ET_801BCC4C;
typedef struct ET_CastleDoor {
               struct Primitive* prim;
               s16 timer;
               char pad_82[0x2];
               s16 rotAngle;
} ET_CastleDoor;
typedef struct {
               struct Primitive* prim;
               s16 unk80;
               s16 unk82;
               s16 timer;
} ET_ShuttingWindow;
typedef struct {
               struct Primitive* prim;
               char pad_80[0x4];
               u16 unk84;
} ET_DeathSkySwirl;
typedef struct {
               struct Primitive* prim;
               char pad_80[0x4];
               s32 elevatorTarget;
} ET_Elevator;
typedef struct {
               struct Primitive* prim;
               char pad_80[0xC];
               u8 unk8C;
               u8 unk8D;
               char pad_8E[0xE];
               u16 unk9C;
} ET_801D1BB8;
typedef struct {
               char pad_0[0xC];
               u16 unk88;
} ET_801D0B78;
typedef struct {
               s32 unk7C;
               s16 unk80;
               s16 unk82;
    union {
                   s32 val;
        struct {
                       s16 unk0;
                       s16 unk2;
        } modeS16;
    } unk84;
               u16 unk88;
} ET_WaterEffects;
typedef struct {
               char pad_0[0x20];
               s16 unk9C;
               s16 unk9E;
               struct Entity* unkA0;
               s16 unkA4;
               s16 unkA6;
               u8 unkA8;
               char pad_A9[0x7];
               s16 unkB0[0x6];
} ET_GurkhaHammer;
typedef struct {
               char pad_0[0x20];
               s16 unk9C;
               char pad_A0[0x6];
               s16 unkA4;
               s16 unkA6;
               char pad_A8[0xC];
               u16 unkB4;
} ET_801CDFD8;
typedef struct {
               char pad_0[0x8];
               u8 unk84;
               char pad_85[0x9];
               u8 unk8E;
               char pad_8F[0x20];
               s16 unkB0;
} ET_801CE4CC;
typedef struct {
               struct Primitive* prim;
               s16 unk80;
} ET_TransparentWater;
typedef struct {
               struct Primitive* prim;
               s32 timer;
} ET_HeartRoomGoldDoor;
typedef struct {
               struct Primitive* prim;
               char pad_80[0x4];
               s8 unk84;
               char pad_85[0x1];
               s8 unk86;
} ET_MermanWaterSplash;
typedef struct {
               s32 playerVelocity;
} ET_CastleDoorTransition;
typedef struct {
               s8 unk7C;
} ET_AlucardController;
typedef struct {
               u16 unk7C;
} ET_ForegroundTree;
typedef struct {
               u16 unk7C;
               u16 unk7E;
               s16 unk80;
} ET_FadeToWhite;
typedef struct {
               u16 unk7C;
} ET_DeathStolenItems;
typedef struct {
               u16 unk7C;
               char pad_7E[0x2];
               s16 posX;
               s16 posY;
               u16 moveTimer;
               u16 moveDirection;
} ET_Death;
typedef struct {
               u8 unk7C;
               char pad_7D[0x3];
               s16 unk80;
               s16 unk82;
               struct Entity* unk84;
} ET_SpittleBone;
typedef struct {
    char pad[0x30];
    u8 unkAC;
} ET_Player;
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} ET_Entity1;
typedef union {
               struct Primitive* prim;
               ET_Generic generic;
               ET_Entity1 ent1;
               ET_EquipItemDrop equipItemDrop;
               ET_RelicOrb relicOrb;
               ET_MessageBox messageBox;
               ET_Weapon weapon;
               ET_SoulStealOrb soulStealOrb;
               ET_GaibonSlogra GS_Props;
               ET_WarpRoom warpRoom;
               ET_Merman merman;
               ET_Merman_2 merman2;
               ET_MermanWaterSplash mermanWaterSplash;
               ET_Familiar fam;
               ET_801CF254 et_801CF254;
               ET_GurkhaSword gurkhaSword;
               ET_Dracula dracula;
               ET_Succubus succubus;
               ET_StageTitleCard stageTitleCard;
               ET_RoomTransition2 roomTransition2;
               ET_801B3C38 et38;
               ET_801BCC4C et_801BCC4C;
               ET_ShuttingWindow shuttingWindow;
               ET_CastleDoor castleDoor;
               ET_DeathSkySwirl deathSkySwirl;
               ET_Elevator elevator;
               ET_801D1BB8 et_801D1BB8;
               ET_801D0B78 et_801D0B78;
               ET_WaterEffects waterEffects;
               ET_GurkhaHammer GH_Props;
               ET_801CE4CC et_801CE4CC;
               ET_801CDFD8 et_801CDFD8;
               ET_TransparentWater transparentWater;
               ET_HeartRoomGoldDoor heartRoomGoldDoor;
               ET_CastleDoorTransition castleDoorTransition;
               ET_AlucardController alucardController;
               ET_ForegroundTree foregroundTree;
               ET_FadeToWhite fadeToWhite;
               ET_DeathStolenItems deathStolenItems;
               ET_Death death;
               ET_SpittleBone spittleBone;
               ET_Player player;
               char stub[0x40];
} Ext;
typedef enum {
    Game_Init,
    Game_Title,
    Game_Play,
    Game_GameOver,
    Game_NowLoading,
    Game_VideoPlayback,
    Game_Unk6,
    Game_PrologueEnd,
    Game_MainMenu,
    Game_Ending,
    Game_99 = 99,
} GameState;
typedef enum {
    STAGE_NO0 = 0x00,
    STAGE_NO1 = 0x01,
    STAGE_LIB = 0x02,
    STAGE_CAT = 0x03,
    STAGE_NO2 = 0x04,
    STAGE_CHI = 0x05,
    STAGE_DAI = 0x06,
    STAGE_NP3 = 0x07,
    STAGE_CEN = 0x08,
    STAGE_NO4 = 0x09,
    STAGE_ARE = 0x0A,
    STAGE_TOP = 0x0B,
    STAGE_NZ0 = 0x0C,
    STAGE_NZ1 = 0x0D,
    STAGE_WRP = 0x0E,
    STAGE_NO1_ALT = 0x0F,
    STAGE_NO0_ALT = 0x10,
    STAGE_DRE = 0x12,
    STAGE_NZ0_DEMO = 0x13,
    STAGE_NZ1_DEMO = 0x14,
    STAGE_LIB_DEMO = 0x15,
    STAGE_BO7 = 0x16,
    STAGE_MAR = 0x17,
    STAGE_BO6 = 0x18,
    STAGE_BO5 = 0x19,
    STAGE_BO4 = 0x1A,
    STAGE_BO3 = 0x1B,
    STAGE_BO2 = 0x1C,
    STAGE_BO1 = 0x1D,
    STAGE_BO0 = 0x1E,
    STAGE_ST0 = 0x1F,
    STAGE_RTOP = STAGE_TOP | 0x20,
    STAGE_RNO0 = STAGE_NO0 | 0x20,
    STAGE_RCEN = STAGE_CEN | 0x20,
    STAGE_RNZ1 = 0x35,
    STAGE_RBO8 = 0x36,
    STAGE_RBO7 = 0x37,
    STAGE_RBO6 = 0x38,
    STAGE_RBO5 = 0x39,
    STAGE_RBO4 = 0x3A,
    STAGE_RBO3 = 0x3B,
    STAGE_RBO2 = 0x3C,
    STAGE_RBO1 = 0x3D,
    STAGE_RBO0 = 0x3E,
    STAGE_MAD = 0x40,
    STAGE_NO3 = 0x41,
    STAGE_IWA_LOAD = 0x42,
    STAGE_IGA_LOAD = 0x43,
    STAGE_HAGI_LOAD = 0x44,
    STAGE_SEL = 0x45,
    STAGE_TE1 = 0x46,
    STAGE_TE2 = 0x47,
    STAGE_TE3 = 0x48,
    STAGE_TE4 = 0x49,
    STAGE_TE5 = 0x4A,
    STAGE_TOP_ALT = 0x4B,
    STAGE_EU_WARNING = 0x70,
    STAGE_ENDING = 0xFE,
    STAGE_MEMORYCARD = 0xFF,
} Stages;
typedef enum {
    Play_Reset = 0,
    Play_Init,
    Play_PrepareDemo,
    Play_Default,
    Play_PrepareNextStage,
    Play_LoadStageChr,
    Play_WaitStageChr,
    Play_LoadStageSfx,
    Play_WaitStageSfx,
    Play_LoadStagePrg,
    Play_WaitStagePrg,
    Gameover_Init = 0,
    Gameover_AllocResources,
    Gameover_2,
    Gameover_3,
    Gameover_4,
    Gameover_5,
    Gameover_6,
    Gameover_7,
    Gameover_8,
    Gameover_9,
    Gameover_10,
    Gameover_11,
    Gameover_Alt = 99,
    Gameover_Init_Alt,
    Gameover_AllocResources_Alt,
    Gameover_2_Alt,
    Gameover_3_Alt,
    Gameover_11_Alt = 111,
    NowLoading_2 = 2,
} GameSteps;
typedef enum {
    Demo_None,
    Demo_PlaybackInit,
    Demo_Recording,
    Demo_End,
    Demo_Playback,
} DemoMode;
typedef enum {
    TIMEATTACK_INVALID = -1,
    TIMEATTACK_GET_RECORD,
    TIMEATTACK_SET_RECORD,
    TIMEATTACK_SET_VISITED,
} TimeAttackActions;
typedef enum {
    TIMEATTACK_EVENT_DRACULA_DEFEAT,
    TIMEATTACK_EVENT_ORLOX_DEFEAT,
    TIMEATTACK_EVENT_DOPPLEGANGER_10_DEFEAT,
    TIMEATTACK_EVENT_GRANFALOON_DEFEAT,
    TIMEATTACK_EVENT_MINOTAUR_WEREWOLF_DEFEAT,
    TIMEATTACK_EVENT_SCYLLA_DEFEAT,
    TIMEATTACK_EVENT_SLOGRA_GAIBON_DEFEAT,
    TIMEATTACK_EVENT_HYPPOGRYPH_DEFEAT,
    TIMEATTACK_EVENT_BEELZEBUB_DEFEAT,
    TIMEATTACK_EVENT_SUCCUBUS_DEFEAT,
    TIMEATTACK_EVENT_KARASUMAN_DEFEAT,
    TIMEATTACK_EVENT_RALPH_GRANT_SYPHA_DEFEAT,
    TIMEATTACK_EVENT_DEATH_DEFEAT,
    TIMEATTACK_EVENT_CERBERUS_DEFEAT,
    TIMEATTACK_EVENT_SAVE_RICHTER,
    TIMEATTACK_EVENT_MEDUSA_DEFEAT,
    TIMEATTACK_EVENT_THE_CREATURE_DEFEAT,
    TIMEATTACK_EVENT_LESSER_DEMON_DEFEAT,
    TIMEATTACK_EVENT_DOPPLEGANGER_40_DEFEAT,
    TIMEATTACK_EVENT_AKMODAN_II_DEFEAT,
    TIMEATTACK_EVENT_DARKWING_BAT_DEFEAT,
    TIMEATTACK_EVENT_GALAMOTH_DEFEAT,
    TIMEATTACK_EVENT_FINAL_SAVEPOINT,
    TIMEATTACK_EVENT_MEET_DEATH,
    TIMEATTACK_EVENT_GET_HOLYGLASSES,
    TIMEATTACK_EVENT_MEET_MASTER_LIBRARIAN,
    TIMEATTACK_EVENT_FIRST_MARIA_MEET,
    TIMEATTACK_EVENT_UNUSED_27,
    TIMEATTACK_EVENT_UNUSED_28,
    TIMEATTACK_EVENT_UNUSED_29,
    TIMEATTACK_EVENT_UNUSED_30,
    TIMEATTACK_EVENT_UNUSED_31,
    TIMEATTACK_EVENT_END,
    TIMEATTACK_EVENT_INVALID = 0xFF,
} TimeAttackEvents;
struct Entity;
typedef void (*PfnEntityUpdate)(struct Entity*);
typedef union {
    s32 val;
    struct {
        s16 lo;
        s16 hi;
    } i;
} f32;
typedef struct {
              char pad0[0xA];
              s16 unkA;
              s16 unkC;
              s16 unkE;
} Unkstruct4;
typedef struct {
              s16 x;
              s16 y;
} Point16;
typedef struct {
              s32 x;
              s32 y;
} Point32;
typedef struct {
              u16 unk0;
              u16 unk2;
} Unsktruct_800EAF28;
typedef struct {
              Unsktruct_800EAF28* unk0;
              u16 unk4;
              s16 unk6;
              s16 unk8;
              s16 unkA;
} unkstruct_80072FA0;
typedef struct {
               u16* fg;
               u16* bg;
               u16 unk8;
               s16 unkA;
               u16 unkC;
               s16 unkE;
               char pad_10[0x30];
               s32 unk40;
               s32 unk44;
               s32 unk48;
} Unkstruct8;
typedef struct {
               u8 unk0;
               u8 unk1;
               u8 pad2[0x1E - 0x02];
} Unkstruct_80137638;
typedef struct {
               u16 unk0;
               char pad2[0x32];
} Unkstruct_80086FFA;
typedef struct {
               u8 vabid;
               u8 prog;
               u8 note;
               s8 volume;
               u8 unk4;
               u8 tone;
               u8 unk6;
} Unkstruct_800BF554;
typedef struct {
               s32 unk0;
               s32 unk4;
               char pad8[0xC];
} Unkstruct_80138094;
typedef struct {
               s32 unk0;
               s32 unk4;
               char pad8[0x2E];
               s16 unk36;
} Unkstruct_80138FB4;
typedef struct {
               s32 unk0;
} Unkstruct_80137990;
typedef struct {
    struct UnkStructClut* struct1;
    struct UnkStructClut* struct2;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u8 unkArray[0x30];
} Unkstruct_8006C3C4;
typedef struct {
    s16 unk0;
    s16 unk2;
} s16_pair;
typedef struct {
               s16_pair pairs[4];
               char pad12[0x8];
               s16 unk1A;
               s16 unk1C;
} Unkstruct_800ACED0;
typedef struct {
               char pad0[0x14];
               s32 unk14;
               s32 unk18;
               s32 unk1C;
               s32 unk20;
} Unkstruct_8010BF64;
typedef struct {
               s16 sndId;
               u16 unk02;
               s16 unk04;
} SfxRingBufferItem;
typedef struct {
               s32 unk0;
               s32 unk4;
               s32 unk8;
} Unkstruct_800FD5BC;
typedef struct {
               u8 unk00[3];
               char unk03[9];
} Unkstruct_80128BBC_Sub;
typedef struct Unkstruct_80128BBC {
               char unk00[4];
               Unkstruct_80128BBC_Sub unk04[4];
} Unkstruct_80128BBC;
typedef struct Unkstruct_aSimCBinDemoKey {
               s32 unk0;
               s8 unk4;
               char pad5[0x3];
               s32 unk8;
               s32 unkC;
               s32 unk10;
               s32 unk14;
} Unkstruct_aSimCBinDemoKey;
typedef struct Unkstruct_800A2D98 {
              s32 equipTypeFilter;
              s32 unk4;
              s32 unk8;
} Unkstruct_800A2D98;
typedef struct {
               s32 unk0;
               s32 unk4;
               s32 unk8;
               s32 unkC;
} Unkstruct_800EA5E4;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Unkstruct_8011A3AC;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unkstruct_800FDB18;
typedef struct Unkstruct_801C3F9C {
               char pad0[0xA];
               s16 unk0A;
               s32 unk0C;
               s32 unk10;
               s16 unk14;
               char pad16[0x8];
               s16 unk1E;
               char pad20[0x4];
               u8 unk24;
               char pad25[0x7];
               s16 unk2C;
} Unkstruct_801C3F9C;
typedef struct {
    u16 D_800A37D8;
    u16 D_800A37DA;
} Unkstruct_801092E8;
typedef struct {
    s32 D_8003C908;
    s32 D_8003C90C;
    s32 D_8003C910;
} Unkstruct_8003C908;
typedef struct Unkstruct_801C6C6C {
    union {
        struct {
            u16 w;
            u16 x;
        } c;
        s32 p;
    } x;
    union {
        struct {
            u16 h;
            u16 y;
        } c;
        s32 p;
    } y;
} Unkstruct_801C6C6C;
typedef struct {
    s16 x, y;
} Unkstruct_80138FC0;
typedef struct {
    s16 unk00, unk02;
    u16 unk04, unk06;
    u16 unk08, unk0A;
    u16 unk0c, unk0E;
    u16 unk10, unk12;
    u16 unk14, unk16;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
} Unkstruct_800ECBF8_1;
typedef struct {
    u16 start;
    s16 current;
    s16* coords;
    s16 unk8;
} Unkstruct_80102CD8;
typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
} unkstruct_800ACF7C;
typedef struct {
              s16 animSet;
              s16 unk2;
              u16 palette;
              s8 blendMode;
              char pad_7;
              s32 unk8;
} Unkstruct_80180FE0;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} UnkStructClut;
typedef struct Unkstruct_800F9F40 {
              s32 unk0;
              s32 unk4;
              s16 unk8;
              s8 unkA;
              s16 unkC;
} Unkstruct_800F9F40;
typedef struct {
               const char* name;
               const char* desc;
               s16 unk08;
               s16 unk0A;
               s32 unk0C;
} RelicDesc;
typedef struct Unkstruct_801C7954 {
               u16 x1;
               u16 x0;
               u16 y2;
               u16 y0;
               u16 y3;
               u16 y1;
               u16 x3;
               u16 x2;
} Unkstruct_801C7954;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} unk_800B08CC;
typedef struct {
    f32 posX;
    f32 posY;
} Camera;
typedef struct {
    unsigned char width;
    unsigned char height;
    unsigned short unk2;
    unsigned char data[0];
} ImgSrc;
typedef struct {
             u32 gfxOff;
             u32 ovlOff;
             u32 ovlLen;
             u32 vhOff;
             u32 vhLen;
             u32 vbLen;
             u32 unk18;
             const char* gfxName;
             const char* ovlName;
             const char* name;
             u8 unk28;
             s8 seqIdx;
             u16 unk2A;
} Lba;
typedef struct {
               s16 cursorX;
               s16 cursorY;
               s16 cursorW;
               s16 cursorH;
               RECT unk1;
               s16 w;
               s16 h;
               s16 unk14;
               s16 unk16;
               s16 unk18;
               s16 unk1A;
               u8 unk1C;
               u8 unk1D;
} MenuContext;
typedef struct {
               s16 cursorX;
               s16 cursorY;
               s16 cursorW;
               s16 cursorH;
               s16 unk08;
               s16 padding;
} MenuContextInit;
typedef struct {
              u8 tileLayoutId;
              u8 tilesetId;
              u8 objGfxId;
              u8 objLayoutId;
} RoomLoadDef;
typedef struct {
              u8 left;
              u8 top;
              u8 right;
              u8 bottom;
              RoomLoadDef load;
} RoomHeader;
typedef struct {
              u16 x;
              u16 y;
              u16 roomId;
              u16 unk6;
              u16 stageId;
} RoomTeleport;
typedef struct {
               s32 x;
               s32 y;
               Stages stageId;
               TimeAttackEvents eventId;
               s32 unk10;
} RoomBossTeleport;
typedef struct {
              u16 pressed;
              s16 previous;
              u16 tapped;
              u16 repeat;
} Pad;
typedef struct {
    u16 duration;
    u16 unk2;
} AnimationFrame;
typedef struct {
    s8 unk0;
    s8 unk2;
    s8 hitboxWidth;
    s8 hitboxHeight;
} FrameProperty;
typedef struct Entity {
               f32 posX;
               f32 posY;
               s32 velocityX;
               s32 velocityY;
               s16 hitboxOffX;
               s16 hitboxOffY;
               u16 facingLeft;
               u16 palette;
               s8 blendMode;
               u8 unk19;
               s16 unk1A;
               s16 unk1C;
               s16 rotAngle;
               s16 rotPivotX;
               s16 rotPivotY;
               u16 zPriority;
               u16 entityId;
               PfnEntityUpdate pfnUpdate;
               u16 step;
               u16 step_s;
               u16 params;
               u16 entityRoomIndex;
               s32 flags;
               s16 unk38;
               u16 enemyId;
               u16 hitboxState;
               s16 hitPoints;
               s16 attack;
               s16 attackElement;
               u16 unk44;
               u8 hitboxWidth;
               u8 hitboxHeight;
               u8 hitFlags;
               u8 nFramesInvincibility;
               s16 unk4A;
               AnimationFrame* unk4C;
               u16 animFrameIdx;
               s16 animFrameDuration;
               s16 animSet;
               s16 animCurFrame;
               s16 stunFrames;
               u16 unk5A;
               s32 unk5C;
               s32 unk60;
               s32 primIndex;
               s16 unk68;
               u16 hitEffect;
               u8 unk6C;
               u8 unk6D[11];
               s32 unk78;
               Ext ext;
} Entity;
typedef struct {
               s16 animSet;
               u16 zPriority;
               Multi16 unk4;
               u16 palette;
               u8 unk8;
               u8 unk9;
               u8 blendMode;
               u8 unkB;
               u32 unkC;
               const u8* unk10;
} ObjInit2;
typedef struct GpuBuffer {
                  struct GpuBuffer* next;
                  DRAWENV draw;
                  DISPENV disp;
                  DR_ENV env[0x10];
                  u_long ot[0x200];
                  DR_MODE drawModes[0x400];
                  POLY_GT4 polyGT4[0x300];
                  POLY_G4 polyG4[0x100];
                  POLY_GT3 polyGT3[0x30];
                  LINE_G2 lineG2[0x100];
                  SPRT_16 sprite16[0x280];
                  TILE tiles[0x100];
                  SPRT sprite[0x200];
} GpuBuffer;
typedef struct {
               u32 drawModes;
               u32 gt4;
               u32 g4;
               u32 gt3;
               u32 line;
               u32 sp16;
               u32 tile;
               u32 sp;
               u32 env;
} GpuUsage;
typedef enum {
    ITEM_S_SWORD,
    ITEM_SWORD,
    ITEM_THROW_1,
    ITEM_FIST,
    ITEM_CLUB,
    ITEM_TWOHAND,
    ITEM_FOOD,
    ITEM_BOMB,
    ITEM_THROW_2,
    ITEM_SHIELD,
    ITEM_MEDICINE,
    ITEM_END,
} ItemCategory;
typedef enum { STAT_STR, STAT_CON, STAT_INT, STAT_LCK } Stats;
typedef struct {
    s32 level;
    s32 exp;
    s32 unk8;
} FamiliarStats;
typedef enum {
    RELIC_SOUL_OF_BAT,
    RELIC_FIRE_OF_BAT,
    RELIC_ECHO_OF_BAT,
    RELIC_FORCE_OF_ECHO,
    RELIC_SOUL_OF_WOLF,
    RELIC_POWER_OF_WOLF,
    RELIC_SKILL_OF_WOLF,
    RELIC_FORM_OF_MIST,
    RELIC_POWER_OF_MIST,
    RELIC_GAS_CLOUD,
    RELIC_CUBE_OF_ZOE,
    RELIC_SPIRIT_ORB,
    RELIC_GRAVITY_BOOTS,
    RELIC_LEAP_STONE,
    RELIC_HOLY_SYMBOL,
    RELIC_FAERIE_SCROLL,
    RELIC_JEWEL_OF_OPEN,
    RELIC_MERMAN_STATUE,
    RELIC_BAT_CARD,
    RELIC_GHOST_CARD,
    RELIC_FAERIE_CARD,
    RELIC_DEMON_CARD,
    RELIC_SWORD_CARD,
    RELIC_JP_0,
    RELIC_JP_1,
    RELIC_HEART_OF_VLAD,
    RELIC_TOOTH_OF_VLAD,
    RELIC_RIB_OF_VLAD,
    RELIC_RING_OF_VLAD,
    RELIC_EYE_OF_VLAD,
    NUM_RELICS,
} RelicIds;
typedef enum {
    SPELL_DARK_METAMORPHOSIS,
    SPELL_SUMMON_SPIRIT,
    SPELL_HELLFIRE,
    SPELL_TETRA_SPIRIT,
    SPELL_WOLF_CHARGE,
    SPELL_SOUL_STEAL,
    SPELL_WING_SMASH,
    SPELL_SWORD_BROTHERS,
    NUM_SPELLS,
} SpellIds;
typedef enum {
    FAMILIAR_BAT,
    FAMILIAR_GHOST,
    FAMILIAR_FAERIE,
    FAMILIAR_DEMON,
    FAMILIAR_SWORD,
    FAMILIAR_YOUSEI,
    FAMILIAR_NOSE_DEMON,
    NUM_FAMILIARS
} FamiliarIds;
typedef struct {
                   u8 relics[30];
                   u8 spells[NUM_SPELLS];
                   u8 equipHandCount[169];
                   u8 equipBodyCount[90];
                   u8 equipHandOrder[169];
                   u8 equipBodyOrder[90];
                   u8 saveName[12];
                   u32 spellsLearnt;
                   s32 hp;
                   s32 hpMax;
                   s32 hearts;
                   s32 heartsMax;
                   s32 mp;
                   s32 mpMax;
                   s32 statsBase[4];
                   s32 statsEquip[4];
                   s32 statsTotal[4];
                   u32 level;
                   u32 exp;
                   u32 gold;
                   u32 killCount;
                   u32 D_80097BF8;
                   u32 subWeapon;
                   u32 equipment[7];
                   u32 attackHands[2];
                   s32 defenseEquip;
                   u16 defenseElement;
                   u16 D_80097C2A;
                   u16 D_80097C2C;
                   u16 D_80097C2E;
                   s32 timerHours;
                   s32 timerMinutes;
                   s32 timerSeconds;
                   s32 timerFrames;
                   u32 D_80097C40;
                   FamiliarStats statsFamiliars[NUM_FAMILIARS];
} PlayerStatus;
typedef struct {
                         s32 cursorMain;
                         s32 cursorRelic;
                         s32 cursorEquip;
                         s32 cursorEquipHand;
                         s32 cursorEquipHead;
                         s32 cursorEquipBody;
                         s32 cursorEquipCloak;
                         s32 cursorEquipOther;
                         s32 scrollEquipHand;
                         s32 scrollEquipAccessories[4];
                         s32 cursorSpells;
                         s32 cursorSettings;
                         s32 cursorCloak;
                         s32 cursorButtons;
                         s32 cursorWindowColors;
                         s32 cursorTimeAttack;
} MenuNavigation;
typedef struct {
                            u32 buttonConfig[8];
                            u16 buttonMask[8];
                            s32 timeAttackRecords[TIMEATTACK_EVENT_END];
                            s32 cloakColors[6];
                            s32 windowColors[3];
                            s32 equipOrderTypes[ITEM_END];
                            s32 isCloakLiningReversed;
                            s32 isSoundMono;
                            s32 D_8003CB00;
                            s32 D_8003CB04;
} GameSettings;
typedef struct {
               u8 Magic[2];
               u8 Type;
               u8 BlockEntry;
               u8 Title[64];
               u8 reserve[28];
               u8 Clut[32];
               u8 Icon[3][128];
} MemcardHeader;
typedef struct {
                MemcardHeader header;
                u8 saveName[12];
                u32 level;
                u32 goldAmount;
                u32 playTimeHours;
                u32 playTimeMinutes;
                u32 playTimeSeconds;
                u32 memcardIcon;
                u32 isTimeAttackUnlocked;
                s16 stageID;
                u16 exploredRoomCount;
                u16 roomX;
                u16 roomY;
                u32 playableCharacter;
                u32 saveSize;
                PlayerStatus status;
                MenuNavigation menuNavigation;
                GameSettings settings;
                u8 castleFlags[0x300];
                u8 castleMap[0x800];
                 s32 rng;
} SaveData;
typedef struct {
               const u8* gfxPage;
               const u8* gfxIndex;
               const u8* clut;
               const u8* collision;
} TileDefinition;
typedef struct {
               u32 left : 6;
               u32 top : 6;
               u32 right : 6;
               u32 bottom : 6;
               u8 flags : 8;
} LayoutRect;
typedef struct {
               const u16* layout;
               const TileDefinition* tileDef;
               const LayoutRect rect;
               const u16 zPriority;
               const u16 unkE;
} LayerDef2;
typedef struct {
               const u16* layout;
               const TileDefinition* tileDef;
               const u32 rect;
               const u16 zPriority;
               const u8 unkE;
               const u8 unkF;
} LayerDef;
typedef struct {
    LayerDef* fg;
    LayerDef* bg;
} RoomDef;
typedef struct {
                   void (*Update)(void);
                   void (*TestCollisions)(void);
                   void (*unk08)(void);
                   void (*InitRoomEntities)(s32 layoutId);
                   RoomHeader* rooms;
                   s16** spriteBanks;
                   UnkStructClut** cluts;
                   void* unk1C;
                   RoomDef* tileLayers;
                   void** entityGfxs;
                   void (*unk28)(void);
                   void (*unk2c)(void);
                   void* unk30;
                   s32* unk34;
                   s32* unk38;
                   void (*unk3C)(void);
} Overlay;
typedef enum {
    EFFECT_SOLID = 1 << 0,
    EFFECT_UNK_0002 = 1 << 1,
    EFFECT_QUICKSAND = 1 << 2,
    EFFECT_WATER = 1 << 3,
    EFFECT_MIST_ONLY = 1 << 4,
    EFFECT_UNK_0020 = 1 << 5,
    EFFECT_SOLID_FROM_ABOVE = 1 << 6,
    EFFECT_SOLID_FROM_BELOW = 1 << 7,
    EFFECT_UNK_0800 = 1 << 11,
    EFFECT_UNK_1000 = 1 << 12,
    EFFECT_UNK_2000 = 1 << 13,
    EFFECT_UNK_4000 = 1 << 14,
    EFFECT_UNK_8000 = 1 << 15,
    EFFECT_NOTHROUGH = EFFECT_SOLID | EFFECT_QUICKSAND,
    EFFECT_NOTHROUGH_PLUS = EFFECT_SOLID | EFFECT_UNK_0002 | EFFECT_QUICKSAND
} ColliderEffectFlags;
typedef struct Collider {
               s32 effects;
               s32 unk4;
               s32 unk8;
               s32 unkC;
               s32 unk10;
               s32 unk14;
               s32 unk18;
               s32 unk1C;
               s32 unk20;
} Collider;
typedef struct {
               const char* name;
               s16 hitPoints;
               u16 attack;
               u16 attackElement;
               s16 defense;
               u16 hitboxState;
               u16 weaknesses;
               u16 strengths;
               u16 immunes;
               u16 absorbs;
               s16 level;
               s16 exp;
               s16 rareItemId;
               s16 uncommonItemId;
               u16 rareItemDropRate;
               u16 uncommonItemDropRate;
               u8 hitboxWidth;
               u8 hitboxHeight;
               s32 flags;
} EnemyDef;
typedef struct {
               s16 attack;
               s16 heartCost;
               u16 attackElement;
               u8 unk6;
               u8 nFramesInvincibility;
               u16 stunFrames;
               u8 unkA;
               u8 unkB;
               u16 hitboxState;
               u16 hitEffect;
               u8 crashId;
               u8 unk11;
               u16 entityRoomIndex;
} SubweaponDef;
typedef struct {
               const char* name;
               const char* description;
               s16 attack;
               s16 defense;
               u16 element;
               u8 itemCategory;
               u8 weaponId;
               u8 palette;
               u8 unk11;
               u8 playerAnim;
               u8 unk13;
               u8 unk14;
               u8 lockDuration;
               u8 chainLimit;
               u8 unk17;
               u8 specialMove;
               u8 isConsumable;
               u8 enemyInvincibilityFrames;
               u8 unk1B;
               u32 comboSub;
               u32 comboMain;
               u16 mpUsage;
               u16 stunFrames;
               u16 hitType;
               u16 hitEffect;
               u16 icon;
               u16 iconPalette;
               u16 criticalRate;
               u16 unk32;
} Equipment;
typedef struct {
             const char* name;
             const char* description;
             s16 attBonus;
             s16 defBonus;
             u8 statsBonus[4];
             u16 unk10;
             u16 unk12;
             u16 unk14;
             u16 unk16;
             u16 icon;
             u16 iconPalette;
             u16 equipType;
             u16 unk1E;
} Accessory;
typedef struct {
               const char* name;
               const char* desc;
               u16 icon;
               u16 iconPalette;
               u16 unk0C;
               u16 unk0E;
} RelicOrb;
typedef struct {
               const char* nextCharDialogue;
               u16 startX;
               u16 nextLineY;
               u16 startY;
               u16 nextCharX;
               u16 nextLineX;
               s16 nextCharY;
               u16 portraitAnimTimer;
               u16 unk12;
               u16 clutIndex;
               u8 nextCharTimer;
               u8 unk17;
               Primitive* prim[6];
               s32 primIndex[3];
               u16 unk3C;
               u16 timer;
               const char* unk40;
} Dialogue;
typedef struct {
                   Overlay o;
                   void (*FreePrimitives)(s32);
                   s16 (*AllocPrimitives)(PrimitiveType type, s32 count);
                   void (*CheckCollision)(s32 x, s32 y, Collider* res, s32 unk);
                   void (*func_80102CD8)(s32 arg0);
                   void (*UpdateAnim)(FrameProperty* frameProps, s32* arg1);
                   void (*SetSpeedX)(s32 value);
                   Entity* (*GetFreeDraEntity)(s16 start, s16 end);
                   void (*GetEquipProperties)(
        s32 handId, Equipment* res, s32 equipId);
                   s32 (*func_800EA5E4)(u32);
                   void (*func_800EAF28)(s32);
                   void (*PlaySfx)(s32 sfxId);
                   s16 (*func_800EDB58)(s32, s32);
                   void (*func_800EA538)(s32 arg0);
                   void (*g_pfn_800EA5AC)(u16 arg0, u8 arg1, u8 arg2, u8 arg3);
                   void* func_801027C4;
                   void* func_800EB758;
                   Entity* (*func_8011AAFC)(Entity* self, u32 flags, s32 arg2);
                   bool (*func_80131F68)(void);
                   DR_ENV* (*func_800EDB08)(POLY_GT4* poly);
                   u16* (*func_80106A28)(u32 arg0, u16 kind);
                   void (*func_80118894)(Entity*);
                   EnemyDef* enemyDefs;
                   void* func_80118970;
                   void* func_80118B18;
                   s32 (*UpdateUnarmedAnim)(s8* frameProps, u16** frames);
                   void (*func_8010DBFC)(s32*, s32*);
                   void* func_80118C28;
                   void (*func_8010E168)(s32 arg0, s16 arg1);
                   void (*func_8010DFF0)(s32 arg0, s32 arg1);
                   u16 (*DealDamage)(
        Entity* enemyEntity, Entity* attackerEntity);
                   void (*LoadEquipIcon)(s32 equipIcon, s32 palette, s32 index);
                   Equipment* equipDefs;
                   Accessory* accessoryDefs;
                   void (*AddHearts)(s32 value);
                   void* func_8010715C;
                   s32 (*TimeAttackController)(
        TimeAttackEvents eventId, TimeAttackActions action);
                   void* (*func_8010E0A8)(void);
                   void (*func_800FE044)(s32, s32);
                   void (*AddToInventory)(u16 itemId, s32 itemCategory);
                   RelicOrb* relicDefs;
                   void (*InitStatsAndGear)(bool debugMode);
                   s32 (*func_80134714)(s32 arg0, s32 arg1, s32 arg2);
                   s32 (*func_80134678)(s16 arg0, u16 arg1);
                   void (*func_800F53A4)(void);
                   u32 (*CheckEquipmentItemCount)(u32 itemId, u32 equipType);
                   void (*func_8010BF64)(Unkstruct_8010BF64* arg0);
                   void (*func_800F1FC4)(s32 arg0);
                   void* func_800F2288;
                   void (*func_8011A3AC)(
        Entity* entity, s32 arg1, s32 arg2, Unkstruct_8011A3AC* arg3);
                   s32 (*func_800FF460)(s32 arg0);
                   s32 (*func_800FF494)(EnemyDef* arg0);
                   bool (*func_80133940)(void);
                   bool (*func_80133950)(void);
                   bool (*func_800F27F4)(s32 arg0);
                   s32 (*func_800FF110)(s32 arg0);
                   s32 (*func_800FD664)(s32 arg0);
                   s32 (*func_800FD5BC)(Unkstruct_800FD5BC* arg0);
                   void (*LearnSpell)(s32 spellId);
                   void (*DebugInputWait)(const char* str);
                   void* unused12C;
                   void* unused130;
                   void* unused134;
                   void* unused138;
                   void* unused13C;
} GameApi;
extern void (*g_api_FreePrimitives)(s32);
extern s16 (*g_api_AllocPrimitives)(PrimitiveType type, s32 count);
extern void (*g_api_CheckCollision)(s32 x, s32 y, Collider* res, s32 unk);
extern void (*g_api_func_80102CD8)(s32 arg0);
extern void (*g_api_UpdateAnim)(FrameProperty* frameProps, s32* arg1);
extern void (*g_api_SetSpeedX)(s32 value);
extern Entity* (*g_api_GetFreeDraEntity)(s16 start, s16 end);
extern void (*g_api_GetEquipProperties)(
    s32 handId, Equipment* res, s32 equipId);
extern s32 (*g_api_func_800EA5E4)(u32);
extern void (*g_api_func_800EAF28)(s32);
extern void (*g_api_PlaySfx)(s32 sfxId);
extern s16 (*g_api_func_800EDB58)(s32, s32);
extern void (*g_api_func_800EA538)(s32 arg0);
extern void (*g_api_g_pfn_800EA5AC)(u16 arg0, u8 arg1, u8 arg2, u8 arg3);
extern Entity* (*g_api_func_8011AAFC)(Entity* self, u32 flags, s32 arg2);
extern bool (*g_api_func_80131F68)(void);
extern DR_ENV* (*g_api_func_800EDB08)(POLY_GT4* poly);
extern u16* (*g_api_func_80106A28)(u16 arg0, u16 kind);
extern void (*g_api_func_80118894)(Entity*);
extern EnemyDef* g_api_enemyDefs;
extern u32 (*g_api_UpdateUnarmedAnim)(s8* frameProps, u16** frames);
extern void (*g_api_func_8010DBFC)(s32*, s32*);
extern void (*g_api_func_8010E168)(s32 arg0, s16 arg1);
extern void (*g_api_func_8010DFF0)(s32 arg0, s32 arg1);
extern u16 (*g_api_DealDamage)(Entity* enemyEntity, Entity* attackerEntity);
extern void (*g_api_LoadEquipIcon)(s32 equipIcon, s32 palette, s32 index);
extern Equipment* g_api_equipDefs;
extern Accessory* g_api_g_AccessoryDefs;
extern void (*g_api_AddHearts)(s32 value);
extern s32 (*g_api_TimeAttackController)(
    TimeAttackEvents eventId, TimeAttackActions action);
extern void* (*g_api_func_8010E0A8)(void);
extern void (*g_api_func_800FE044)(s32, s32);
extern void (*g_api_AddToInventory)(u16 itemId, s32 itemCategory);
extern RelicOrb* g_api_relicDefs;
extern s32 (*g_api_func_80134714)(s32 arg0, s32 arg1, s32 arg2);
extern s32 (*g_api_func_80134678)(s16 arg0, u16 arg1);
extern void (*g_api_func_800F53A4)(void);
extern u32 (*g_api_CheckEquipmentItemCount)(u32 itemId, u32 equipType);
extern void (*g_api_func_8010BF64)(Unkstruct_8010BF64* arg0);
extern void (*g_api_func_800F1FC4)(s32 arg0);
extern void (*g_api_func_8011A3AC)(
    Entity* entity, s32 arg1, s32 arg2, Unkstruct_8011A3AC* arg3);
extern s32 (*g_api_func_800FF460)(s32 arg0);
extern s32 (*g_api_func_800FF494)(EnemyDef* arg0);
extern bool (*g_api_func_80133940)(void);
extern bool (*g_api_func_80133950)(void);
extern bool (*g_api_func_800F27F4)(s32 arg0);
extern s32 (*g_api_func_800FF110)(s32 arg0);
extern s32 (*g_api_func_800FD664)(s32 arg0);
extern s32 (*g_api_func_800FD5BC)(Unkstruct_800FD5BC* arg0);
extern void (*g_api_LearnSpell)(s32 spellId);
extern void (*g_api_func_800E2438)(const char* str);
typedef struct {
               s16 x;
               s16 y;
               s16 width;
               s16 height;
               s16 clut;
               s16 tpage;
               u8 texLeft, dummyLeft;
               u8 texTop, dummyTop;
               u8 texRight, dummyRight;
               u8 texBottom, dummyBottom;
} Sprite;
typedef struct {
             s16 flags;
             s16 offsetx;
             s16 offsety;
             s16 width;
             s16 height;
             s16 clut;
             s16 tileset;
             s16 left;
             s16 top;
             s16 right;
             s16 bottom;
} SpritePart;
typedef struct {
             u16 count;
             SpritePart parts[0];
} SpriteParts;
typedef struct {
               u16** frames;
               s8* frameProps;
               s16 unk8;
               u16 soundId;
               u8 ACshift;
               u8 soundFrame;
} AnimSoundEvent;
typedef struct {
                        u16* layout;
                        u32 tileDef;
                        f32 scrollX;
                        f32 scrollY;
                        u32 D_800730E8;
                        u32 D_800730EC;
                        u32 zPriority;
                        u32 D_800730F4;
                        u32 w;
                        u32 h;
                        u32 D_80073100;
                        u32 flags;
} BgLayer;
typedef struct {
                        s32 unk00;
                        s32 hSize;
                        s32 vSize;
                        s32 unk8;
                        s32 left;
                        s32 top;
                        s32 right;
                        s32 bottom;
                        s32 x;
                        s32 y;
                        s32 width;
                        s32 height;
                        s32 unk30;
                        s32 D_800730D4;
                        BgLayer bg[16];
} RoomDimensions;
typedef struct {
                     u16 flags;
                     u16 unk2;
                     u16 unk4;
                     s16 zPriority;
} FgLayer;
typedef struct {
                   s32 D_80072BD0[8][9];
                   s32 D_80072CF0[14][9];
                   s32 padPressed;
                   s32 padTapped;
                   s32 padHeld;
                   s32 D_80072EF4;
                   s32 D_80072EF8;
                   s32 D_80072EFC;
                   s16 D_80072F00;
                   s16 D_80072F02;
                   s16 D_80072F04;
                   s16 D_80072F06;
                   s16 D_80072F08;
                   s16 D_80072F0A;
                   s16 D_80072F0C;
                   s16 D_80072F0E;
                   s16 D_80072F10;
                   s16 D_80072F12;
                   s16 D_80072F14;
                   s16 D_80072F16;
                   s16 D_80072F18;
                   s16 D_80072F1A;
                   s16 D_80072F1C;
                   s16 D_80072F1E;
                   s32 pl_vram_flag;
                   s32 unk04;
                   s32 unk08;
                   u32 unk0C;
                   s32 unk10;
                   u32 unk14;
                   s32 unk18;
                   s32 unk1C;
                   s32 unk20[8];
                   u16 unk40;
                   u16 pl_high_jump_timer;
                   u16 unk44;
                   u16 unk46;
                   u16 unk48;
                   s16 unk4A;
                   u16 unk4C;
                   u16 unk4E;
                   u16 unk50;
                   u16 unk52;
                   u16 unk54;
                   u16 unk56;
                   u16 unk58;
                   u16 unk5A;
                   u16 unk5C;
                   u16 unk5E;
                   u16 unk60;
                   u16 unk62;
                   u16 unk64;
                   u16 unk66;
                   u16 unk68;
                   u16 unk6A;
                   u16 unk6C;
                   u16 unk6E;
                   u16 unk70;
                   u16 unk72;
                   u32 unk74;
                   u16 unk78;
                   u16 unk7A;
                   u16 unk7C;
                   u16 unk7E;
} PlayerState;
extern const s16 g_AtanTable[0x400];
extern s32 D_8003925C;
extern s32 g_IsTimeAttackUnlocked;
extern u8 g_CastleFlags[0x300];
extern u8 D_8003BE23;
extern u8 D_8003BEEC[];
extern u8 D_8003BF9C[];
extern s32 D_8003C0EC[4];
extern s32 D_8003C0F8;
extern s32 D_8003C100;
extern u16 D_8003C104[];
extern u16 D_8003C3C2[];
extern s32 D_8003C704;
extern FgLayer D_8003C708;
extern s16 D_8003C710;
extern s16 D_8003C712;
extern s32 D_8003C728;
extern s32 D_8003C730;
extern GameState g_GameState;
extern s32 D_8003C738;
extern s32 D_8003C73C;
extern u32 D_8003C744;
extern u32 g_RoomCount;
extern Unsktruct_800EAF28** D_8003C798;
extern GameApi g_api;
extern s32 D_8003C8B8;
extern u32 D_8003C8C4;
extern Unkstruct_8003C908 D_8003C908;
extern s32 D_8003C90C[2];
extern u32 g_blinkTimer;
                 extern s32 D_8003C99C;
                 extern s32 g_PlayableCharacter;
                 extern s32 D_8003C9A4;
                 extern MenuNavigation g_MenuNavigation;
                 extern GameSettings g_Settings;
extern GpuBuffer g_GpuBuffers[2];
extern s16 g_GpuBuffers_1_buf_draw_clip_y;
extern const char g_MemcardSavePath[];
extern const char aBaslus00067dra[19];
extern const char g_strMemcardRootPath[];
extern s32 g_LoadFile;
extern s32 D_8006BB00;
extern u8 g_CastleMap[0x800];
extern s32 D_8006C374;
extern s32 D_8006C378;
extern GpuBuffer* g_CurrentBuffer;
extern s32 D_8006C384;
extern s32 D_8006C388;
extern s32 D_8006C38C;
extern s32 D_8006C390;
extern s32 D_8006C384;
extern s32 D_8006C388;
extern s32 D_8006C38C;
extern s32 D_8006C390;
extern u32 g_CdStep;
extern s32 D_8006C3AC;
extern s32 g_backbufferX;
extern s32 g_backbufferY;
extern s32 g_IsUsingCd;
extern Entity* g_CurrentEntity;
extern Unkstruct_8006C3C4 D_8006C3C4[32];
extern s32 D_8006CBC4;
extern u16 g_Clut[];
extern u32 D_8006EBCC;
extern u16 D_8006EBE0;
extern u16 D_8006F3CC[];
extern u16 D_8006F42C[];
extern s16 D_800705CC[];
extern u32 D_80070BCC;
extern Unkstruct4 D_80072B34;
extern PlayerState g_Player;
extern u16 g_Player_D_80072EF6;
extern u32 g_Player_unk0C;
extern unkstruct_80072FA0 D_80072FA0[];
extern u32 g_GameStep;
extern s32 D_80073064;
extern Event g_EvSwCardEnd;
extern Event g_EvSwCardErr;
extern Event g_EvSwCardTmo;
extern Event g_EvSwCardNew;
extern s32 D_80073080;
extern TileDefinition* D_80073088;
extern Camera g_Camera;
extern s32 D_8007309C;
extern RoomDimensions g_CurrentRoom;
extern s32 g_CurrentRoom_vSize;
extern Entity g_Entities[256];
extern Entity D_80074C08[];
extern Unkstruct8 g_CurrentRoomTileLayout;
extern Entity D_8007A958[];
extern Entity D_8007C0D8[];
extern Entity D_8007D858[];
extern Entity D_8007DE38[];
extern Multi g_zEntityCenter;
extern s32 g_entityDestroyed[];
extern Entity D_8007EF1C;
extern Event g_EvHwCardEnd;
extern Event g_EvHwCardErr;
extern Event g_EvHwCardTmo;
extern u8 D_80086FF0[];
extern Event g_EvHwCardNew;
extern u8 g_Pix[4][128 * 128 / 2];
extern u16 D_8008701E[];
extern Primitive g_PrimBuf[0x500];
extern s32 playerX;
extern s32 playerY;
extern u32 g_randomNext;
extern s32 D_80096ED8[];
extern u32 D_80097364;
extern s32 D_800973B4;
extern POLY_GT4 D_800973B8[];
extern s8 D_80097B98;
extern s8 D_80097B99;
extern s32 D_800973EC;
extern s32 D_800973F8;
extern s32 D_800973FC;
extern s32 D_80097400[];
extern s32 D_8009740C[];
extern s32 g_BottomCornerTextTimer;
extern s32 g_BottomCornerTextPrims;
extern s32 D_80097418;
extern s32 D_8009741C;
extern s32 D_80097420[];
extern s32 D_80097424;
extern s32 D_80097448[];
extern s32 D_80097450;
extern u16 D_8009748A[];
extern u16 D_8009748E[];
extern Pad g_pads[2];
extern Stages g_StageId;
extern s32 D_800974A4;
extern DR_ENV D_800974AC;
extern s32 g_UseDisk;
extern s32 D_800978B4;
extern s32 D_800978C4;
extern u32 D_800978F8;
extern char D_80097902[];
extern s32 D_80097904;
extern s32 D_80097908;
extern s32 D_8009790C;
extern s32 D_80097910;
extern DemoMode g_DemoMode;
extern s32 g_mapTilesetId;
extern s32 D_80097924;
extern s32 D_80097928;
extern GpuUsage g_GpuUsage;
extern PlayerStatus g_Status;
extern u8 D_80097B9C[];
extern s32 subWeapon;
extern u8 g_SaveName[12] ;
extern Unkstruct_8011A3AC D_80097C38[];
extern u32 D_80097C40[];
extern s32 D_80097C98;
extern Unkstruct_800ECBF8_1 D_80097D1C[0x10];
extern s8 D_80097D37;
extern u8 D_80097F3C;
extern u8 D_80097F3D;
extern u8 D_80097F3E;
extern s8 D_80097F3F;
extern u8 D_80097F40;
extern u8 D_80097F41;
extern u8 D_80097F42;
extern u8 D_80097F44;
extern u8 D_80097F45;
extern u8 D_80097F46;
extern u8 D_80097F48;
extern u8 D_80097F49;
extern u8 D_80097F4A;
extern s32 D_800987B4;
extern s32 D_800987C8;
extern s32 g_DebugPlayer;
extern s32 D_80098894;
void PadInit(s32 arg0);
int VSync(s32);
s32 rcos(s32);
s32 rsin(s32);
s32 SquareRoot0(s32);
s32 SquareRoot12(s32, s32);
long ratan2(long x, long y);
void* DMACallback(int dma, void (*func)());
void func_800192DC(s32 arg0, s32 arg1);
s32 func_8001D290(s32, s32);
s32 func_8001D374(s8, s16, s16);
void func_8001D2E0(s32, s32, s32);
void func_8002A024(s32, s32);
typedef enum ItemSlots {
            LEFT_HAND_SLOT,
            RIGHT_HAND_SLOT,
            HEAD_SLOT,
            ARMOR_SLOT,
            CAPE_SLOT,
            ACCESSORY_1_SLOT,
            ACCESSORY_2_SLOT,
} ItemSlots;
typedef enum ItemTypes {
            HAND_TYPE,
            HEAD_TYPE,
            ARMOR_TYPE,
            CAPE_TYPE,
            ACCESSORY_TYPE,
} ItemTypes;
typedef enum HandItems {
                ITEM_EMPTY_HAND,
                ITEM_MONSTER_VIAL_1,
                ITEM_MONSTER_VIAL_2,
                ITEM_MONSTER_VIAL_3,
                ITEM_SHIELD_ROD,
                ITEM_LEATHER_SHIELD,
                ITEM_KNIGHT_SHIELD,
                ITEM_IRON_SHIELD,
                ITEM_AXELORD_SHIELD,
                ITEM_HERALD_SHIELD,
                ITEM_DARK_SHIELD,
                ITEM_GODDESS_SHIELD,
                ITEM_SHAMAN_SHIELD,
                ITEM_MEDUSA_SHIELD,
                ITEM_SKULL_SHIELD,
                ITEM_FIRE_SHIELD,
                ITEM_ALUCARD_SHIELD,
                ITEM_SWORD_OF_DAWN,
                ITEM_BASILARD,
                ITEM_SHORT_SWORD,
                ITEM_COMBAT_KNIFE,
                ITEM_NUNCHAKU,
                ITEM_WERE_BANE,
                ITEM_RAPIER,
                ITEM_KARMA_COIN,
                ITEM_MAGIC_MISSILE,
                ITEM_RED_RUST,
                ITEM_TAKEMITSU,
                ITEM_SHOTEL,
                ITEM_ORANGE,
                ITEM_APPLE,
                ITEM_BANANA,
                ITEM_GRAPES,
                ITEM_STRAWBERRY,
                ITEM_PINEAPPLE,
                ITEM_PEANUTS,
                ITEM_TOADSTOOL,
                ITEM_SHIITAKE,
                ITEM_CHEESECAKE,
                ITEM_SHORTCAKE,
                ITEM_TART,
                ITEM_PARFAIT,
                ITEM_PUDDING,
                ITEM_ICE_CREAM,
                ITEM_FRANKFURTER,
                ITEM_HAMBURGER,
                ITEM_PIZZA,
                ITEM_CHEESE,
                ITEM_HAM_AND_EGGS,
                ITEM_OMELETTE,
                ITEM_MORNING_SET,
                ITEM_LUNCH_A,
                ITEM_LUNCH_B,
                ITEM_CURRY_RICE,
                ITEM_GYROS_PLATE,
                ITEM_SPAGHETTI,
                ITEM_GRAPE_JUICE,
                ITEM_BARLEY_TEA,
                ITEM_GREEN_TEA,
                ITEM_NATOU,
                ITEM_RAMEN,
                ITEM_MISO_SOUP,
                ITEM_SUSHI,
                ITEM_PORK_BUN,
                ITEM_RED_BEAN_BUN,
                ITEM_CHINESE_BUN,
                ITEM_DIM_SUM_SET,
                ITEM_POT_ROAST,
                ITEM_SIRLION,
                ITEM_TURKEY,
                ITEM_MEAL_TICKET,
                ITEM_NEUTRON_BOMB,
                ITEM_POWER_OF_SIRE,
                ITEM_PENTAGRAM,
                ITEM_BAT_PENTAGRAM,
                ITEM_SHURIKEN,
                ITEM_CROSS_SHURIKEN,
                ITEM_BUFFALO_STAR,
                ITEM_FLAME_STAR,
                ITEM_TNT,
                ITEM_BWAKA_KNIFE,
                ITEM_BOOMERANG,
                ITEM_JAVELIN,
                ITEM_TYRFING,
                ITEM_NAMAKURA,
                ITEM_KNUCKLE_DUSTER,
                ITEM_GLADIUS,
                ITEM_SCIMITAR,
                ITEM_CUTLASS,
                ITEM_SABER,
                ITEM_FALCHION,
                ITEM_BROADSWORD,
                ITEM_BEKATOWA,
                ITEM_DAMASCUS_SWORD,
                ITEM_HUNTER_SWORD,
                ITEM_ESTOC,
                ITEM_BASTARD_SWORD,
                ITEM_JEWEL_KNUCKLES,
                ITEM_CLAYMORE,
                ITEM_TALWAR,
                ITEM_KATANA,
                ITEM_FLAMBERGE,
                ITEM_IRON_FIST,
                ITEM_ZWEIHANDER,
                ITEM_SWORD_OF_HADOR,
                ITEM_LUMINUS,
                ITEM_HARPER,
                ITEM_OBSIDIAN_SWORD,
                ITEM_GRAM,
                ITEM_JEWEL_SWORD,
                ITEM_MORMEGIL,
                ITEM_FIREBRAND,
                ITEM_THUNDERBRAND,
                ITEM_ICEBRAND,
                ITEM_STONE_SWORD,
                ITEM_HOLY_SWORD,
                ITEM_TERMINUS_EST,
                ITEM_MARSIL,
                ITEM_DARK_BLADE,
                ITEM_HEAVEN_SWORD,
                ITEM_FIST_OF_TULKAS,
                ITEM_GURTHANG,
                ITEM_MOURNEBLADE,
                ITEM_ALUCARD_SWORD,
                ITEM_MABLUNG_SWORD,
                ITEM_BADELAIRE,
                ITEM_SWORD_FAMILIAR,
                ITEM_GREAT_SWORD,
                ITEM_MACE,
                ITEM_MORNINGSTAR,
                ITEM_HOLY_ROD,
                ITEM_STAR_FLAIL,
                ITEM_MOON_ROD,
                ITEM_CHAKRAM,
                ITEM_FIRE_BOOMERANG,
                ITEM_IRON_BALL,
                ITEM_HOLBEIN_DAGGER,
                ITEM_BLUE_KNUCKLES,
                ITEM_DYNAMITE,
                ITEM_OSAFUNE_KATANA,
                ITEM_MASAMUNE,
                ITEM_MURAMASA,
                ITEM_HEART_REFRESH,
                ITEM_RUNESWORD,
                ITEM_ANTIVENOM,
                ITEM_UNCURSE,
                ITEM_LIFE_APPLE,
                ITEM_HAMMER,
                ITEM_STR_POTION,
                ITEM_LUCK_POTION,
                ITEM_SMART_POTION,
                ITEM_ATTACK_POTION,
                ITEM_SHIELD_POTION,
                ITEM_RESIST_FIRE,
                ITEM_RESIST_THUNDER,
                ITEM_RESIST_ICE,
                ITEM_RESIST_STONE,
                ITEM_RESIST_HOLY,
                ITEM_RESIST_DARK,
                ITEM_POTION,
                ITEM_HIGH_POTION,
                ITEM_ELIXIR,
                ITEM_MANNA_PRISM,
                ITEM_VORPAL_BLADE,
                ITEM_CRISSAEGRIM,
                ITEM_YASUTSUNA,
                ITEM_LIBRARY_CARD,
                ITEM_ALUCART_SHIELD,
                ITEM_ALUCART_SWORD,
                NUM_HAND_ITEMS,
} HandItems;
typedef enum BodyItems {
               ITEM_NO_ARMOR,
               ITEM_CLOTH_TUNIC,
               ITEM_HIDE_CUIRASS,
               ITEM_BRONZE_CUIRASS,
               ITEM_IRON_CUIRASS,
               ITEM_STEEL_CUIRASS,
               ITEM_SILVER_PLATE,
               ITEM_GOLD_PLATE,
               ITEM_PLATINUM_MAIL,
               ITEM_DIAMOND_PLATE,
               ITEM_FIRE_MAIL,
               ITEM_LIGHTNING_MAIL,
               ITEM_ICE_MAIL,
               ITEM_MIRROR_CUIRASS,
               ITEM_SPIKE_BREAKER,
               ITEM_ALUCARD_MAIL,
               ITEM_DARK_ARMOR,
               ITEM_HEALING_MAIL,
               ITEM_HOLY_MAIL,
               ITEM_WALK_ARMOR,
               ITEM_BRILLIANT_MAIL,
               ITEM_MOJO_MAIL,
               ITEM_FURY_PLATE,
               ITEM_DRACULA_TUNIC,
               ITEM_GODS_GARB,
               ITEM_AXE_LORD_ARMOR,
               ITEM_EMPTY_HEAD,
               ITEM_SUNGLASSES,
               ITEM_BALLROOM_MASK,
               ITEM_BANDANNA,
               ITEM_FELT_HAT,
               ITEM_VELVET_HAT,
               ITEM_GOGGLES,
               ITEM_LEATHER_HAT,
               ITEM_HOLY_GLASSES,
               ITEM_STEEL_HELM,
               ITEM_STONE_MASK,
               ITEM_CIRCLET,
               ITEM_GOLD_CIRCLET,
               ITEM_RUBY_CIRCLET,
               ITEM_OPAL_CIRCLET,
               ITEM_TOPAZ_CIRCLET,
               ITEM_BERYL_CIRCLET,
               ITEM_CAT_EYE_CIRCLET,
               ITEM_CORAL_CIRCLET,
               ITEM_DRAGON_HELM,
               ITEM_SILVER_CROWN,
               ITEM_WIZARD_HAT,
               ITEM_NO_CAPE,
               ITEM_CLOTH_CAPE,
               ITEM_REVERSE_CLOAK,
               ITEM_ELVEN_CLOAK,
               ITEM_CRYSTAL_CLOAK,
               ITEM_ROYAL_CLOAK,
               ITEM_BLOOD_CLOAK,
               ITEM_JOSEPHS_CLOAK,
               ITEM_TWILIGHT_CLOAK,
               ITEM_NO_ACCESSORY,
               ITEM_MOONSTONE,
               ITEM_SUNSTONE,
               ITEM_BLOODSTONE,
               ITEM_STAUROLITE,
               ITEM_RING_OF_PALES,
               ITEM_ZIRCON,
               ITEM_AQUAMARINE,
               ITEM_TURQUOISE,
               ITEM_ONYX,
               ITEM_GARNET,
               ITEM_OPAL,
               ITEM_DIAMOND,
               ITEM_LAPIS_LAZULI,
               ITEM_RING_OF_ARES,
               ITEM_GOLD_RING,
               ITEM_SILVER_RING,
               ITEM_RING_OF_VARDA,
               ITEM_RING_OF_ARCANA,
               ITEM_MYSTIC_PENDANT,
               ITEM_HEART_BROACH,
               ITEM_NECKLACE_OF_J,
               ITEM_GAUNTLET,
               ITEM_ANKH_OF_LIFE,
               ITEM_RING_OF_FEANOR,
               ITEM_MEDAL,
               ITEM_TALISMAN,
               ITEM_DUPLICATOR,
               ITEM_KINGS_STONE,
               ITEM_COVENANT_STONE,
               ITEM_NAUGLAMIR,
               ITEM_SECRET_BOOTS,
               ITEM_ALUCART_MAIL,
               NUM_BODY_ITEMS,
} BodyItems;
void EntityBreakable(Entity*);
void EntityExplosion(Entity*);
void EntityPrizeDrop(Entity*);
void EntityNumericDamage(Entity*);
void EntityRedDoor(Entity*);
void EntityIntenseExplosion(Entity*);
void EntitySoulStealOrb(Entity*);
void EntityRoomForeground(Entity*);
void EntityStageNamePopup(Entity*);
void EntityEquipItemDrop(Entity*);
void EntityRelicOrb(Entity*);
void EntityHeartDrop(Entity*);
void EntityEnemyBlood(Entity*);
void EntityMessageBox(Entity*);
void EntityDummy(Entity*);
typedef enum { MONO_SOUND, STEREO_SOUND } soundMode;
typedef struct {
              u16 posX;
              u16 posY;
              u16 entityId;
              u16 entityRoomIndex;
              u16 params;
} LayoutEntity;
extern PfnEntityUpdate PfnEntityUpdates[];
extern u16 g_ItemIconSlots[0x20];
extern u16 UNK_Invincibility0[];
s32 Random();
void Update(void);
void CreateEntityFromEntity(u16 entityId, Entity* source, Entity* entity);
void CreateEntityFromLayout(Entity* entity, LayoutEntity* initDesc);
void DestroyEntity(Entity*);
void DestroyEntityFromIndex(s16 index);
s32 AnimateEntity(const u8 frames[], Entity* entity);
void MoveEntity();
void FallEntity(void);
Entity* AllocEntity(Entity* start, Entity* end);
void InitializeEntity(u16 arg0[]);
typedef enum {
    E_NONE,
    E_BREAKABLE,
    E_EXPLOSION,
    E_PRIZE_DROP,
    E_NUMERIC_DAMAGE,
    E_RED_DOOR,
    E_INTENSE_EXPLOSION,
    E_SOUL_STEAL_ORB,
    E_ROOM_FOREGROUND,
    E_DUMMY_09,
    E_EQUIP_ITEM_DROP,
    E_DUMMY_0B,
    E_DUMMY_0C,
    E_DUMMY_0D,
    E_DUMMY_0E,
    E_DUMMY_0F,
    E_DUMMY_10,
    E_ID_26 = 0x26,
    E_SECRET_BUTTON = 0x28,
    E_SECRET_STAIRS = 0x29,
} EntityIDs;
void CreateEntityFromEntity(u16 entityId, Entity* source, Entity* entity);
s16 GetSideToPlayer();
void MoveEntity();
void SetStep(u8);
void EntityExplosion(Entity*);
extern const char* D_801A7984;
extern const char* D_801A7990;
extern const char* D_801A799C;
extern s8 c_HeartPrizes[10];
extern PfnEntityUpdate PfnEntityUpdates[];
extern bool g_isSecretStairsButtonPressed;
extern bool g_isDraculaFirstFormDefeated;
LayoutEntity* D_80180314[];
LayoutEntity* D_801803E8[];
extern u16 D_80180574[];
extern u16 g_InitializeEntityData0[];
extern u16 D_80180598[];
extern u16 D_801805A4[];
extern u16 D_801805BC[];
extern u16 D_801805D4[];
extern u16 D_801805E0[];
extern u16 D_801805EC[];
extern u16 D_80180610[];
extern u16 D_8018061C[];
extern u16 D_80180628[];
extern ObjInit2 D_80180638[];
extern s32 D_801806D0[];
extern u8 D_801806F8[];
extern u8 D_80180704[];
extern u16 D_80180710[];
extern s16 D_80180724[];
extern s16 D_80180738[];
extern s8 D_8018074C[];
extern s16 D_80180758[];
extern u8 D_80180770[];
extern const char* D_80180828[];
extern u8 D_80180830[];
extern u8 D_8018083C[];
extern u8 D_8018084C[];
extern u8 D_8018085C[];
extern u8 D_80180864[];
extern u8 D_8018086C[];
extern u8 D_8018087C[];
extern u8 D_80180884[];
extern u8 D_8018088C[];
extern u8 D_80180894[];
extern Point16 D_801808A0[];
extern u16 D_801808B0[];
extern s16 D_801808F8[];
extern s32 D_80180908;
extern u8 D_80180914[];
extern u8 D_80180924[];
extern u8 D_80180934[];
extern u8 D_80180944[];
extern u8 D_80180954[];
extern u8 D_80180964[];
extern u8 D_8018097C[];
extern u8 D_801809A4[];
extern u8 D_80180A0C[];
extern u8 D_80180A20[];
extern u8 D_80180A2C[];
extern u8 D_80180BA0[];
extern u8 D_80180BB8[];
extern u8 D_80180BCC[];
extern u8 D_80180BDC[];
extern u16 D_80180A48[];
extern Point16 D_80180A58[];
extern LayoutEntity* D_801C00A0;
extern u8 D_801C00A8;
extern u8 D_801C00AC;
extern s32 D_801C2578;
extern u32 D_801C257C;
extern u16 D_80181CAC[];
extern u16 D_80181CDC[];
extern u32 D_80181CF0[];
extern s16 D_80181990[];
extern u32 D_80181D7C[];
extern u16 D_80181DA4[];
extern u8* D_80181E28[];
extern s16 D_80181E3C[];
extern s16 D_80181E3E[];
extern s16 D_80181EB0[];
extern u32 D_80181EC0[];
extern s32 D_80181ED8[];
extern u8 D_80181EF0[];
extern u16 D_80181EF4[];
extern u16 D_80181F04[];
extern u8 D_801824CC[];
extern u16* D_801C00A4;
extern s32 D_801C24C8;
extern s32 D_801C2580;
extern u16 D_80181F54[];
extern u16 D_80181F64[];
extern u8 D_80181FC4;
extern Dialogue g_Dialogue;
;
;
extern PfnEntityUpdate PfnEntityUpdates[];
void CreateEntityFromLayout(Entity* entity, LayoutEntity* initDesc) {
    DestroyEntity(entity);
    entity->entityId = initDesc->entityId & 0x3FF;
    entity->pfnUpdate = PfnEntityUpdates[entity->entityId - 1];
    entity->posX.i.hi = initDesc->posX - g_Camera.posX.i.hi;
    entity->posY.i.hi = initDesc->posY - g_Camera.posY.i.hi;
    entity->params = initDesc->params;
    entity->entityRoomIndex = initDesc->entityRoomIndex >> 8;
    entity->unk68 = (initDesc->entityId >> 0xA) & 7;
}
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
            &g_Entities[64 + (u8)layoutObj->entityRoomIndex];
        if (entity->entityId == E_NONE) {
            CreateEntityFromLayout(entity, layoutObj);
        }
        break;
    case 0x8000:
        break;
    case 0xA000:
        entity =
            &g_Entities[64 + (u8)layoutObj->entityRoomIndex];
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
            &g_Entities[64 + (u8)layoutObj->entityRoomIndex];
        if (entity->entityId == E_NONE) {
            CreateEntityFromLayout(entity, layoutObj);
        }
        break;
    case 0x8000:
        break;
    case 0xA000:
        entity =
            &g_Entities[64 + (u8)layoutObj->entityRoomIndex];
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
    diff = g_Entities[PLAYER_CHARACTER].posX.i.hi - e->posX.i.hi;
    diff = ((diff) < 0 ? -(diff) : (diff));
    if (diff >= 17) {
        diff = 0;
    } else {
        diff = g_Entities[PLAYER_CHARACTER].posY.i.hi - e->posY.i.hi;
        diff = ((diff) < 0 ? -(diff) : (diff));
        diff = diff < 33;
    }
    return diff;
}
;
void DestroyEntity(Entity* item) {
    s32 i;
    s32 length;
    u32* ptr;
    if (item->flags & 0x00800000) {
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
s32 AnimateEntity(const u8 frames[], Entity* entity) {
    s32 flag = 0;
    u16 currentFrameIndex = entity->animFrameIdx * 2;
    u8* currentFrame = frames + currentFrameIndex;
    if (entity->animFrameDuration == 0) {
        if (currentFrame[0] > 0) {
            flag = 0x80;
            if (currentFrame[0] == 0xFF) {
                return 0;
            }
            entity->animFrameDuration = *currentFrame++;
            entity->animCurFrame = *currentFrame++;
            entity->animFrameIdx++;
        } else {
            currentFrame = frames;
            entity->animFrameIdx = 0;
            entity->animFrameDuration = 0;
            entity->animFrameDuration = *currentFrame++;
            entity->animCurFrame = *currentFrame++;
            entity->animFrameIdx++;
            return 0;
        }
    }
    entity->animFrameDuration = entity->animFrameDuration - 1;
    entity->animCurFrame = currentFrame[-1];
    flag |= true;
    return (u8)flag;
}
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
s16 GetDistanceToPlayerX(void) {
    s16 xDistance = g_CurrentEntity->posX.i.hi - g_Entities[PLAYER_CHARACTER].posX.i.hi;
    if (xDistance < 0) {
        xDistance = -xDistance;
    }
    return xDistance;
}
s32 GetDistanceToPlayerY(void) {
    s32 yDistance = g_CurrentEntity->posY.i.hi - g_Entities[PLAYER_CHARACTER].posY.i.hi;
    if (yDistance < 0) {
        yDistance = -yDistance;
    }
    return yDistance;
}
s16 GetSideToPlayer(void) {
    s16 side = g_CurrentEntity->posX.i.hi > g_Entities[PLAYER_CHARACTER].posX.i.hi;
    if (g_CurrentEntity->posY.i.hi > g_Entities[PLAYER_CHARACTER].posY.i.hi) {
        side |= 2;
    }
    return side;
}
void MoveEntity(void) {
    g_CurrentEntity->posX.val += g_CurrentEntity->velocityX;
    g_CurrentEntity->posY.val += g_CurrentEntity->velocityY;
}
void FallEntity(void) {
    if (g_CurrentEntity->velocityY < 0x60000) {
        g_CurrentEntity->velocityY += 0x4000;
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
                            g_CurrentEntity->flags &= ~0x10000000;
                            return 1;
                        }
                    }
                    continue;
                }
            }
            if (col.effects & EFFECT_NOTHROUGH && i != 1) {
                if (col.effects & EFFECT_QUICKSAND) {
                    g_CurrentEntity->flags &= ~0x10000000;
                    return 4;
                }
                g_api.CheckCollision(x, y - 8, &colBack, 0);
                if (!(colBack.effects & EFFECT_SOLID)) {
                    g_CurrentEntity->posY.i.hi =
                        g_CurrentEntity->posY.i.hi + col.unk18;
                    g_CurrentEntity->velocityX = 0;
                    g_CurrentEntity->velocityY = 0;
                    g_CurrentEntity->flags &= ~0x10000000;
                    return 1;
                }
            }
        }
    }
    g_CurrentEntity->flags |= 0x10000000;
    return 0;
}
;
;
Entity* AllocEntity(Entity* start, Entity* end) {
    Entity* current = start;
    while (current < end) {
        if (current->entityId == E_NONE) {
            DestroyEntity(current);
            return current;
        }
        current++;
    }
    return (0);
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
    g_CurrentEntity->hitboxState = enemyDef->hitboxState;
    g_CurrentEntity->hitboxWidth = enemyDef->hitboxWidth;
    g_CurrentEntity->hitboxHeight = enemyDef->hitboxHeight;
    g_CurrentEntity->flags = enemyDef->flags;
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
;
void ReplaceBreakableWithItemDrop(Entity* self) {
    u16 params;
    PreventEntityFromRespawning(self);
    params = self->params &= 0xFFF;
    if (params < 0x80) {
        self->entityId = E_PRIZE_DROP;
        self->pfnUpdate = (PfnEntityUpdate)EntityPrizeDrop;
        self->animFrameDuration = 0;
        self->animFrameIdx = 0;
    } else {
        params -= 0x80;
        self->entityId = E_EQUIP_ITEM_DROP;
        self->pfnUpdate = (PfnEntityUpdate)EntityEquipItemDrop;
    }
    self->params = params;
    self->unk6D[0] = 0x10;
    self->step = 0;
}
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
    if (entity->velocityY < ((s32)((0.25)*65536.0))) {
        entity->velocityY += ((s32)((0.125)*65536.0));
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
            g_CurrentEntity->posY.val += ((s32)((0.125)*65536.0));
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
    g_api.PlaySfx(0x67A);
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
    Entity* player = &g_Entities[PLAYER_CHARACTER];
    u16 subWeapon;
    g_api.PlaySfx(0x67C);
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
        g_CurrentEntity->velocityY = ((s32)((-2.5)*65536.0));
        g_CurrentEntity->animCurFrame = 0;
        g_CurrentEntity->ext.generic.unk88.S16.unk2 = 5;
        if (player->facingLeft != 1) {
            g_CurrentEntity->velocityX = ((s32)((-2)*65536.0));
            return;
        }
        g_CurrentEntity->velocityX = ((s32)((2)*65536.0));
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
