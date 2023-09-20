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
               u16 hitboxOffX;
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
typedef struct {
               void (*EntityWeaponAttack)(Entity* self);
               void (*func_ptr_80170004)(Entity* self);
               void (*func_ptr_80170008)(Entity* self);
               void (*func_ptr_8017000C)(Entity* self);
               void (*func_ptr_80170010)(Entity* self);
               void (*func_ptr_80170014)(Entity* self);
               int (*GetWeaponId)(void);
               void (*LoadWeaponPalette)(s32 clutIndex);
               void (*EntityWeaponShieldSpell)(Entity* self);
               void (*func_ptr_80170024)(Entity* self);
               void (*func_ptr_80170028)(Entity* self);
               void (*WeaponUnused2C)(void);
               void (*WeaponUnused30)(void);
               void (*WeaponUnused34)(void);
               void (*WeaponUnused38)(void);
               void (*WeaponUnused3C)(void);
} Weapon ;
extern u16 D_8006EDCC[][12 * (((16)) * (((16)) / 8))];
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
typedef enum {
    DEBUG_NORMAL,
    DEBUG_TEXTURE_VIEWER,
    DEBUG_TILESET_VIEWER,
    DEBUG_PALETTE_VIEWER,
    DEBUG_END,
} DebugMode;
typedef enum {
    DEBUG_COLOR_CHANNEL_RED,
    DEBUG_COLOR_CHANNEL_GREEN,
    DEBUG_COLOR_CHANNEL_BLUE,
} DebugColorChannel;
typedef enum {
    SimFileType_System,
    SimFileType_StagePrg,
    SimFileType_Vh,
    SimFileType_Vb,
    SimFileType_Seq,
    SimFileType_StageChr,
    SimFileType_Unused6,
    SimFileType_Weapon0Prg,
    SimFileType_Weapon1Prg,
    SimFileType_Weapon0Chr,
    SimFileType_Weapon1Chr,
    SimFileType_FamiliarPrg,
    SimFileType_FamiliarChr,
    SimFileType_Monster,
} SimFileType;
typedef struct {
    const char* path;
    u8* addr;
    s32 size;
    s32 type;
} SimFile;
typedef enum {
    CdStep_None,
    CdStep_LoadInit,
    CdStep_SetSpeed,
    CdStep_SetPos,
    CdStep_Seek,
    CdStep_5,
    CdStep_6,
    CdStep_Complete = 10,
    CdStep_DmaErr = 0xC0,
    CdStep_SdHeaderErr = 0xC1,
    CdStep_DiskErr = 0xC2,
    CdStep_Retry = 0xD0,
    CdStep_RetryXa = 0xD1,
    CdStep_CdShellOpenErr = 0xF0,
    CdStep_F1 = 0xF1,
    CdStep_F2 = 0xF2,
    CdStep_F3 = 0xF3,
} CdStep;
typedef enum {
    CdFile_None,
    CdFile_Sel,
    CdFile_GameChr,
    CdFile_StageChr,
    CdFile_4,
    CdFile_RichterPrg,
    CdFile_Seq = 12,
    CdFile_StageSfx,
    CdFile_14,
    CdFile_15,
    CdFile_16,
    CdFile_Weapon0,
    CdFile_Weapon1,
    CdFile_AlucardPrg,
    CdFile_24 = 24,
    CdFile_25,
    CdFile_26,
    CdFile_ServantChr,
    CdFile_28,
    CdFile_ServantPrg,
    CdFile_30,
    CdFile_31,
    CdFile_DemoKey,
    CdFile_NoNext = 0xFF,
    CdFile_StagePrg = 0x100,
} CdFileType;
typedef enum {
    CdCallback_0,
    CdCallback_1,
    CdCallback_2,
    CdCallback_3,
    CdCallback_4,
    CdCallback_5,
    CdCallback_6,
    CdCallback_7,
    CdCallback_StagePrg,
    CdCallback_9,
    CdCallback_Ric,
    CdCallback_11,
    CdCallback_12,
    CdCallback_13,
    CdCallback_14,
    CdCallback_Familiar,
    CdCallback_16,
    CdCallback_17,
    CdCallback_Seq,
    CdCallback_Vh,
} CdCallbacks;
typedef enum {
    E_NONE,
    E_UNK_1,
    ENTITY_13 = 0x13,
    E_UNK_22 = 0x22,
} EntityIDs;
typedef enum {
    Player_Stand,
    Player_Walk,
    Player_Crouch,
    Player_Unk3,
    Player_Jump,
    Player_MorphBat,
    Player_Unk_6,
    Player_MorphMist,
    Player_Unk8,
    Player_Unk9,
    Player_Hit,
    Player_StatusStone,
    Player_Unk12,
    Player_KillWater,
    Player_Unk14,
    Player_Unk15,
    Player_Unk16,
    Player_Unk17,
    Player_Unk18,
    Player_Unk25 = 25,
    Player_SpellDarkMetamorphosis = 32,
    Player_SpellSummonSpirit,
    Player_SpellHellfire,
    Player_SpellTetraSpirit,
    Player_Spell36,
    Player_SpellSoulSteal,
    Player_Unk38,
    Player_Unk39,
    Player_Unk40,
} PlayerSteps;
typedef enum {
    STATUS_AILMENT_POISON,
    STATUS_AILMENT_CURSE,
    STATUS_AILMENT_PETRIFIED,
    STATUS_AILMENT_DARK_METAMORPHOSIS,
    STATUS_AILMENT_UNK04,
    STATUS_AILMENT_UNK05,
} StatusAilments;
typedef struct {
    s32 loc;
    CdCallbacks cb;
    s32 size;
    u8 vabId;
    u8 unkD;
    u8 nextCdFileType;
    u8 unkF;
} CdFile;
typedef struct {
    s32 loc;
    s32 size;
    u32 unk8;
} CdFileSeq;
typedef struct {
    CdCallbacks cb;
    CdlLOC loc;
} CdMgr;
typedef struct {
    RECT D_800ACD80;
    RECT D_800ACD88;
    RECT D_800ACD90;
    RECT D_800ACD98;
    RECT D_800ACDA0;
    RECT D_800ACDA8;
    RECT D_800ACDB0;
    RECT D_800ACDB8;
    RECT D_800ACDC0;
    RECT D_800ACDC8;
    RECT D_800ACDD0;
    RECT D_800ACDD8;
    RECT D_800ACDE0;
    RECT D_800ACDE8;
    RECT D_800ACDF0;
} Vram;
typedef struct {
               const char* name;
               const char* combo;
               const char* description;
               u8 mpUsage;
               s8 nFramesInvincibility;
               s16 stunFrames;
               s16 hitboxState;
               s16 hitEffect;
               s16 entityRoomIndex;
               u16 attackElement;
               s16 attack;
               s16 unk1A;
} SpellDef;
typedef struct {
    u32 unk0;
    u32 damageKind;
    s32 damageTaken;
    s32 unkC;
} DamageParam;
typedef struct {
                   MenuContext menus[3];
                   s16 D_80137676;
                   s16 D_80137678[6];
                   s32 unused1;
                   s16 D_80137688;
                   s16 D_8013768A;
                   s16 D_8013768C;
                   s16 unused2;
                   s16 unused3;
                   u8 D_80137692;
} MenuData;
typedef struct {
    u16 liningDark;
    u16 liningLight;
    u16 exteriorDark;
    u16 exteriorLight;
} JosephsCloak;
extern void (*D_800A0004)();
extern s32 D_800A0144[];
extern u32 D_800A0158;
extern s32 D_800A015C;
extern s16 D_800A0160[];
extern u8 D_800A0170[];
extern u8 D_800A01B0[];
extern RECT D_800A01C0[];
extern s32 D_800A0248;
extern SimFile D_800A024C[];
extern SimFile D_800A036C[];
extern SimFile D_800A04AC[];
extern s32 D_800A04EC;
extern s32 D_800A04F8;
extern s32 g_UnkMemcardPort[];
extern u16 g_saveIconPalette[0x10][0x10];
extern u8* g_saveIconTexture[0x10];
extern s32 D_800A2438;
extern u8 D_800A243C[];
extern RoomBossTeleport D_800A297C[];
extern s32 D_800A2D68;
extern s32 D_800A2D6C;
extern u8 D_800A2D7C[];
extern u8 c_chPlaystationButtons[];
extern u8 c_chShoulderButtons[];
extern RECT D_800A2D90;
extern Unkstruct_800A2D98 D_800A2D98[];
extern MenuContextInit MenuContextData[];
extern u8 D_800A2EE8[];
extern u8 D_800A2EED;
extern u8 D_800A2EF8[];
extern u8 D_800A2EFD;
extern u8 D_800A2F08[];
extern u8 D_800A2F18[];
extern u8 D_800A2F28[];
extern u8 D_800A2F2D;
extern u8 D_800A2F38[];
extern u8 D_800A2F3D;
extern u16 D_800A2F48[];
extern u16 D_800A2F64[];
extern s16 D_800A2F7E[];
extern u8 D_800A2F9B[];
extern s32 D_800A2FBC[];
extern s32 D_800A2FC0[];
extern RoomTeleport D_800A245C[];
extern s32 D_800A2464[];
extern u32 D_800A2D24;
extern const char* c_strALUCARD;
extern const char** c_strSTR;
extern const char* c_strCON;
extern const char* c_strINT;
extern const char* c_strLCK;
extern const char* c_strEXP;
extern const char* c_strNEXT;
extern const char* c_strGOLD[];
extern const char* c_strLEVEL;
extern const char* c_strTIME;
extern const char* c_strROOMS;
extern const char* c_strKILLS;
extern const char* c_strHP;
extern const char* c_strMP;
extern const char* c_strHEART;
extern const char* c_strSTATUS;
extern const char* c_strButton;
extern const char* c_strCloak;
extern const char* c_strCloak2;
extern const char* c_strExterior;
extern const char* c_strLining;
extern const char* c_strButtonRightHand[];
extern const char* c_strButtonLeftHand;
extern const char* c_strButtonJump;
extern const char* c_strButtonSpecial;
extern const char* c_strButtonWolf;
extern const char* c_strButtonMist;
extern const char* c_strButtonBat;
extern const char* c_strNormal;
extern const char* c_strReversal;
extern const char* c_strSound;
extern const char* c_strStereo;
extern const char* c_strMono;
extern const char* c_strWindow;
extern const char* c_strTime;
extern const char* c_strALUCART;
extern const char* D_800A83AC[];
extern const char* c_strSSword;
extern s32 D_800A3194[];
extern Unkstruct_801092E8 D_800A37D8;
extern JosephsCloak g_JosephsCloak;
extern Lba g_StagesLba[];
extern Unsktruct_800EAF28* D_800A3B5C[];
extern UnkStructClut* D_800A3BB8[];
extern SubweaponDef g_SubwpnDefs[];
extern SpellDef g_SpellDefs[];
extern const char* g_WingSmashComboStr;
extern EnemyDef g_EnemyDefs[];
extern s32 g_ExpNext[];
extern Equipment g_EquipDefs[];
extern Accessory g_AccessoryDefs[];
extern RelicDesc g_RelicDefs[];
extern u8* c_strTimeAttackHiddenEntry;
extern s32 c_strTimeAttackEntries[];
extern u32 D_800AC90C;
extern u16 D_800AC958[];
extern s32 D_800ACC64[];
extern Vram g_Vram;
extern CdFile* D_800ACC74[];
extern u8 D_800ACFB4[][4];
extern s32 D_800ACE44;
extern s32 D_800ACE48[];
extern s16 D_800ACE88[];
extern s16 D_800ACE90[];
extern s16_pair D_800ACEC0[4];
extern Unkstruct_800ACED0 D_800ACED0;
extern u8 D_800ACF4C[];
extern s32 D_800ACF74;
extern s32 D_800ACF78;
extern unkstruct_800ACF7C D_800ACF7C[];
extern s16 D_800ACF8A[];
extern s16 D_800ACF60[];
extern s16 D_800ACF94[];
extern u8 D_800AD094[];
extern PfnEntityUpdate D_800AD0C4[];
extern AnimSoundEvent* D_800AD53C[];
extern s32 D_800ADC44;
extern RECT D_800AE130;
extern s32 D_800AE270[];
extern AnimationFrame* D_800AE294;
extern s16 D_800AFDA6[];
extern const char* c_strEquip;
extern const char* c_strSpells;
extern const char* c_strRelics;
extern const char* c_strSystem;
extern const char* c_strFamiliars;
extern const char* c_strFamiliar;
extern const char* c_strSpecial2;
extern RECT c_backbufferClear;
extern s16 D_800AFFB8[];
extern s32 D_800B0130[];
extern s32 D_800B01B8[];
extern u8 D_800B0608[];
extern s32 D_800B0798[];
extern s32 D_800B07C8;
extern s32 D_800B0830[];
extern s32 D_800B083C[];
extern unk_800B08CC D_800B08CC[];
extern s32 D_800B0914;
extern s32 D_800B0918;
extern s32 D_800B091C;
extern s32 D_800B0920;
extern const char aPbav[];
extern const char aPbav_0[];
extern const char aPbav_1[];
extern const char aPbav_2[];
extern s16 D_800BD07C[];
extern s16 D_800BD19C[];
extern s32 g_DebugEnabled;
extern s32 D_800BD1C4;
extern s32 g_VabAddrs[6];
extern s32 D_800C1ECC[];
extern PixPattern* D_800C52F8[];
extern const char D_800DB524[];
extern Unkstruct_800F9F40 D_800DC6EC;
extern Unkstruct_800F9F40 D_800DC70C[];
extern const char a0104x04x;
extern const char a2304x04x;
extern const char aBlue;
extern u8 g_GfxEquipIcon[][16 * 16 / 2];
extern s16 g_PalEquipIcon[];
extern const char aDr03x;
extern const char aEff03x;
extern const char aEnv03x;
extern const char aG403x;
extern const char aGreen;
extern const char aGt303x;
extern const char aGt403x;
extern const char aHalfOff;
extern const char aHalfOn;
extern const char aLine03x;
extern const char aRed;
extern const char aRgb02x02x02x;
extern const char aSp03x;
extern const char aSp1603x;
extern const char aTile03x;
extern Unkstruct_800BF554 D_800BF554[];
extern char* aErrorStep;
extern char* aAtariNuki;
extern s32 g_DebugFreeze;
extern s32 g_DebugHitboxViewMode;
extern u32 D_801362B4;
extern s32 D_801362B8;
extern s32 D_801362BC;
extern s32 g_DebugPalIdx;
extern DebugColorChannel g_DebugColorChannel;
extern u32 D_801362C8;
extern u32* g_CurrentOT;
extern s32 D_801362D0[];
extern s32 D_801362D4;
extern s32 g_DebugIsRecordingVideo;
extern GpuUsage g_GpuMaxUsage;
extern s32 g_softResetTimer;
extern s32 g_DebugWaitInfoTimer;
extern s32 g_DebugRecordVideoFid;
extern s16 D_80136308[];
extern s32 D_8013640C;
extern s32 D_80136410;
extern s32 D_80136414[];
extern SimFile* D_8013644C;
extern SimFile D_80136450;
extern s16 D_80136460[];
extern s16 D_80136C60[];
extern u8 g_PadsRepeatTimer[8 * 2];
extern s32 D_80137428[];
extern s32 g_MemcardRetryCount;
extern s32 g_MemcardFd;
extern u16 D_80137478[];
extern u16 D_801374B8[];
extern u16 D_801374F8[];
extern u16 D_80137538[];
extern u8* g_DecSrcPtr;
extern u8* g_DecDstPtr;
extern s32 g_DecReadNibbleFlag;
extern s32 g_DecWriteNibbleFlag;
extern u8* D_80137590;
extern s32 D_80137594;
extern RoomLoadDef* D_801375BC;
extern s32 D_801375C8;
extern Unkstruct_800A2D98 D_801375CC;
extern s32 D_801375D4;
extern s32* D_801375D8;
extern s32 D_801375DC;
extern s32 D_801375FC;
extern s32 D_80137608;
extern s32 g_IsCloakLiningUnlocked;
extern s32 g_IsCloakColorUnlocked;
extern s32 g_IsSelectingEquipment;
extern s32 g_EquipmentCursor;
extern s32 D_80137614;
extern s32 D_80137618;
extern MenuData g_MenuData;
extern u8 D_801376B0;
extern s16 D_801376C4;
extern s16 D_801376C8;
extern MenuContext g_JosephsCloakContext;
extern s32 D_8013783C;
extern s32 D_801377FC[];
extern s32 D_80137840;
extern s32 D_80137844[];
extern s32 D_80137848[];
extern s32 D_8013784C;
extern s16 g_RelicMenuFadeTimer;
extern s32 g_TimeAttackEntryTimes[];
extern s32 c_strTimeAttackEntry[];
extern s32 c_strTimeAttackGoals[];
extern s32 g_NewAttackRightHand;
extern s32 g_NewAttackLeftHand;
extern s32 g_NewDefenseEquip;
extern s32 g_NewPlayerStatsTotal[];
extern s8* D_8013794C;
extern s32 D_80137950;
extern s32 D_80137954;
extern s32 D_80137960;
extern s32 D_80137964;
extern s32 D_80137968;
extern u32 g_DisplayHP[];
extern s32 D_80137970;
extern s32 D_80137974;
extern u32 D_80137978;
extern u32 D_8013797C;
extern s32 D_80137980;
extern s32 D_80137984;
extern u32 D_80137988;
extern u32 D_8013798C;
extern Unkstruct_80137990 D_80137990;
extern s32 D_80137994;
extern s32 g_HealingMailTimer[];
extern u32 D_8013799C;
extern s32 D_801379A0;
extern s32 D_801379A4;
extern s32 D_801379A8;
extern Unkstruct_80102CD8 D_801379AC;
extern s32 D_801379B0;
extern s32 D_80137E40;
extern s32 D_80137E44;
extern s32 D_80137E48;
extern s32 D_80137E4C;
extern s32 D_80137E50;
extern s32 D_80137E58;
extern s32 D_80137E5C;
extern s32 D_80137E60;
extern s32 D_80137E64;
extern s32 D_80137E68;
extern s32 D_80137F6C;
extern void* D_80137F7C;
extern s32 D_80137F9C;
extern s32 D_80137FB4;
extern s32 D_80137FB8;
extern s32 D_80137FBC;
extern s32 D_80137FDC;
extern s32 D_80137FE0;
extern s32 D_80137FE4;
extern s32 D_80137FE8;
extern u32 g_WingSmashButtonCounter;
extern s32 g_WingSmashButtonTimer;
extern s32 g_WingSmashTimer;
extern s32 g_BatScreechDone;
extern s32 g_MistTimer;
extern s32 D_80138008;
extern s32 D_8013800C[];
extern u8 D_8013803C;
extern u8 D_80138040;
extern u8 D_80138044;
extern u8 D_80138048;
extern s32 D_8013808C;
extern s32 D_8013841C;
extern s32 D_8013842C;
extern s32 D_80138430;
extern s32 D_80138438;
extern s32 D_80138440;
extern s32 D_80138444;
extern s32 D_80138454;
extern char g_SeqTable[176 * 0x10 * 1];
extern const char* D_80138784[487];
extern s32 D_80138F20;
extern u8 D_80138F24[];
extern u8 D_80138F2C[];
extern s32 D_80138F28;
extern s32 D_80138F7C;
extern s16 D_80138F80;
extern s32 D_80138F84[];
extern s16 D_80138FAC;
extern DebugMode g_DebugMode;
extern s16 g_VolL;
extern s16 D_80138FBC;
extern Unkstruct_80138FC0 D_80138FC0[0x10];
extern s16 D_80138FC8;
extern s16 D_80138FCA;
extern s16 g_sfxRingBufferPos1;
extern s16 g_VolR;
extern s32 D_80139008;
extern s16 D_80139010;
extern u8 D_80139014;
extern s8 D_80139018[];
extern u32 g_DebugCurPal;
extern s16 D_8013901C;
extern u8 D_80139020;
extern s8 D_80139058[];
extern s16 D_8013909C;
extern u8 D_801390A0;
extern s16 D_801390A4;
extern u8 D_801390A8;
extern s16 D_801390AC[];
extern s32 D_801390B4[];
extern s8 D_801390C4;
extern GpuBuffer* g_BackBuffer;
extern u8 D_801390D8;
extern SfxRingBufferItem g_sfxRingBuffer1[(0x100)];
extern u16 D_801396E0;
extern u16 D_801396E4;
extern Multi D_801396E6;
extern u16 D_801396E8;
extern s16 D_801396EA;
extern u16 D_801396EC;
extern s32 D_801396F0;
extern volatile s16 D_801396F4;
extern s32 D_801396F8[0x20];
extern s32 D_80139778[0x20];
extern s32 D_801397FC;
extern s16 D_80139800;
extern s16 D_80139804;
extern s32 D_8013980C;
extern u8 D_80139810;
extern s16 D_80139814[];
extern s16 D_80139820;
extern s32 D_80139824;
extern s32 D_80139828[];
extern s32 D_8013982C;
extern s32 D_80139830[];
extern s32 D_8013983C;
extern s32 D_80139840;
extern s32 D_80139844;
extern s32 D_80139848;
extern s32 D_8013984C;
extern s32 D_80139850;
extern s32 D_80139854;
extern s16 D_80139868[(0x100)];
extern s16 D_80139A68;
extern s16 D_80139A6C;
extern s16 g_sfxRingBufferPos2;
extern s16 D_80139A74;
extern s16 D_80139A78;
extern u_long* D_80139A7C;
extern u16 D_8013AE7C;
extern volatile unsigned char D_8013AE80;
extern s16 D_8013AE84[];
extern s16 D_8013AE8C;
extern s16 D_8013AEA0[];
extern s16 D_8013AE94;
extern s32 D_8013AE9C;
extern s32 D_8013AECC;
extern s32 D_8013AED0;
extern s16 D_8013AED4[];
extern u32 D_8013AEE4;
extern s16 g_volumeL;
extern s16 g_volumeR;
extern s16 D_8013B678[];
extern s16 D_8013B698;
extern u8 D_8013B6A0[];
extern u8 D_8017D350[];
extern u8 D_8018B4E0[];
extern u8 D_801A9C80[];
extern u16 D_8013AEE0;
extern s8 D_8013AEE8;
extern u8 D_8013AEEC;
extern s16 D_8013AEF0;
extern s32 D_8013B158;
extern s32 D_8013B3D0;
extern s16 g_sfxRingBuffer2[(0x100)];
extern s32 D_8013B5E8;
extern u8 D_8013B5EC[];
extern s8 D_8013B614[];
extern s8 D_8013B618;
extern s32 D_8013B61C;
extern s16 D_8013B620[];
extern s32 D_8013B628[];
extern s16 D_8013B648[];
extern s16 D_8013B650[];
extern s16 g_SeqAccessNum;
extern s32 g_MemcardStep;
extern s16 D_8013B664;
extern s16 D_8013B668;
extern s16 D_8013B66C[];
extern u8 D_8013B680;
extern s8 D_8013B684;
extern s8 D_8013B690;
extern s32 D_8013B694;
extern s32 D_8013B69C;
extern s32 D_8016FCC0[];
extern void (*D_8013C00C)(void);
extern PfnEntityUpdate D_80179C80[];
extern Weapon D_8017A000;
extern PfnEntityUpdate D_8017CC40[];
extern Weapon D_8017D000;
extern void (*D_80170000)(void);
extern ImgSrc* g_imgUnk8013C200;
extern ImgSrc* g_imgUnk8013C270;
extern u8 D_801EC000[];
void InitializePads(void);
void ReadPads(void);
void ClearBackbuffer(void);
void SetRoomForegroundLayer(LayerDef2* layerDef);
void SetRoomBackgroundLayer(s32 index, LayerDef2* layerDef);
void CheckCollision(s32 x, s32 y, Collider* res, s32 unk);
void DemoInit(s32 arg0);
void DemoUpdate(void);
void func_80028D3C(s32, s32);
void func_80029FBC(s32);
void func_8002A09C(void*);
void func_8002ABF4(s32);
void func_800E346C(void);
void func_800E34A4(s8 arg0);
void func_800E34DC(s32 arg0);
void SetGameState(GameState gameState);
void func_800E4970(void);
s32 LoadFileSim(s32 id, SimFileType type);
void ResetPadsRepeat(void);
void func_800E8DF0(void);
s32 _peek_event(void);
s32 _card_event_x(void);
void _clear_event_x(void);
void MemcardInit(void);
void MemcardInfoInit(void);
s32 func_800EA5E4(u32);
void func_800EA538(s32);
void func_800EAD7C(void);
void func_800EAEEC(void);
void LoadEquipIcon(s32 equipIcon, s32 palette, s32 index);
void HideAllBackgroundLayers(void);
void DestroyPrimitive(Primitive* prim);
void DestroyAllPrimitives(void);
void func_800EDAE4(void);
s32 AllocPrimitives(u8 type, s32 count);
s32 func_800EDD9C(u8 primitives, s32 count);
void DemoGameInit(s32 arg0);
void FreePrimitives(s32 index);
void DemoOpenFile(s32);
void DemoInit(s32 arg0);
s32 func_800F087C(u32, u32);
bool SetNextRoomToLoad(u32 chunkX, u32 chunkY);
void func_800F1868(s32, s32, u8*);
void func_800F18C4(s32, s32);
void func_800F1954(s32, s32, s32);
void func_800F1EB0(s32, s32, s32);
void func_800F2120(void);
void func_800F223C(void);
void func_800F4994(void);
s32 CalcAttack(s32, s32);
void func_800F4F48(void);
void CalcDefense(void);
bool IsAlucart(void);
void func_800F53A4(void);
bool ScissorSprite(SPRT* arg0, MenuContext* arg1);
void func_800F5904(MenuContext* ctx, s32 x, s32 y, s32 w, u32 h, s32 u, s32 v,
                   s32 idx, s32 unk2, bool disableTexShade, s32 unk4);
void DrawMenuSprite(
    MenuContext* context, s32 x, s32 y, s32 width, s32 height, s32 u, s32 v,
    s32 clut, s32 tpage, s32 arg9, s32 colorIntensity, s32 argB);
void DrawMenuRect(MenuContext* context, s32 posX, s32 posY, s32 width,
                  s32 height, s32 r, s32 g, s32 b);
s32 func_800F62E8(s32 arg0);
void InitStatsAndGear(bool isDeathTakingItems);
void func_800F98AC(s32 arg0, s32 arg1);
void func_800F99B8(s32 arg0, s32 arg1, s32 arg2);
void DrawMenuChar(u8 ch, int x, int y, MenuContext* context);
void DrawMenuStr(const u8* str, s32 x, s32 y, MenuContext* context);
void DrawMenuInt(s32 value, s32 x, s32 y, MenuContext*);
void DrawSettingsReverseCloak(MenuContext* context);
void DrawSettingsSound(MenuContext* context);
void DrawPauseMenu(s32 arg0);
void func_800F82F4(void);
void func_800F8858(MenuContext* context);
void CheckWeaponCombo(void);
void func_800FABEC(s32 arg0);
void func_800FAC30(void);
void func_800FAF44(s32);
s32 TimeAttackController(TimeAttackEvents eventId, TimeAttackActions action);
s32 func_800FD664(s32 arg0);
s32 func_800FD6C4(s32 equipTypeFilter);
u8* GetEquipOrder(s32 equipTypeFilter);
u8* GetEquipCount(s32 equipTypeFilter);
const char* GetEquipmentName(s32 equipTypeFilter, s32 equipId);
u32 CheckEquipmentItemCount(u32 itemId, u32 equipType);
void AddToInventory(u16 itemId, s32 itemCategory);
void func_800FD9D4(SpellDef* spell, s32 id);
s16 GetStatusAilmentTimer(StatusAilments statusAilment, s16 timer);
void LearnSpell(s32 spellId);
void func_800FDE00(void);
s32 func_800FE3C4(SubweaponDef* subwpn, s32 subweaponId, bool useHearts);
void GetEquipProperties(s32 handId, Equipment* res, s32 equipId);
s32 HandleDamage(DamageParam*, s32, s32 amount, s32);
s32 func_800FEEA4(s32, s32);
void func_800FF0A0(s32 arg0);
void func_80102CD8(s32);
void func_80102DEC(s32 arg0);
void func_80103EAC(void);
void DestroyEntity(Entity*);
void DestroyEntities(s16 startIndex);
void func_801071CC(POLY_GT4* poly, u32 colorIntensity, s32 vertexIndex);
void func_80107250(POLY_GT4* poly, s32 colorIntensity);
void SetTexturedPrimRect(
    Primitive* poly, s32 x, s32 y, s32 width, s32 height, s32 u, s32 v);
void func_801073C0(void);
void func_801092E8(s32);
void SetPrimRect(Primitive* poly, s32 x, s32 y, s32 width, s32 height);
void SetPlayerStep(PlayerSteps step);
u32 UpdateAnim(s8* frameProps, s32*);
void func_8010DFF0(s32, s32);
void func_8010E0A8(void);
void func_8010E0B8(void);
void func_8010E470(s32, s32);
void func_8010E570(s32);
void func_8010E83C(s32 arg0);
s32 func_801104D0();
s32 func_801106A4();
s32 func_8011081C();
s32 func_80110968();
s32 func_80110BC8();
void func_8010DBFC(s32*, s32*);
s32 func_80110DF8();
s32 func_80111018();
s32 func_801112AC();
s32 func_8011151C();
void func_80111928(void);
void func_80111CC0(void);
bool func_80111D24(void);
void func_80115394(s32*, s16, s16);
void func_80115C50(void);
void func_80118894(Entity*);
void func_80118C28(s32 arg0);
void func_80118D0C(Entity* entity);
void func_80119588(Entity* entity);
void func_80119D3C(Entity* entity);
void func_80119F70(Entity* entity);
void func_8011A3AC(
    Entity* entity, s32 arg1, s32 arg2, Unkstruct_8011A3AC* arg3);
void func_8011A4C8(Entity* entity);
Entity* func_8011AAFC(Entity* entity, u32, s32);
void func_8011AC3C(Entity* entity);
void EntityUnarmedAttack(Entity* entity);
void func_8011B334(Entity* entity);
void func_8011B480(Entity* entity);
void func_8011B530(Entity* entity);
void func_8011B5A4(Entity* entity);
void func_8011BBE0(Entity* entity);
void func_8011BDA4(Entity* entity);
void func_8011D9F8(Entity* entity);
void func_8011E0E4(Entity* entity);
void func_8011E0EC(Entity* entity);
void func_8011E390(Entity* entity);
void func_8011E4BC(Entity* entity);
void func_8011EDA0(Entity* entity);
void func_8011EDA8(Entity* entity);
void func_8011F074(Entity* entity);
void func_8011F24C(Entity* entity);
void func_8011F934(Entity* entity);
void func_801200AC(Entity* entity);
void func_80120AF8(Entity* entity);
void func_80120DD0(Entity* entity);
void func_80121980(Entity* entity);
void func_8012231C(Entity* entity);
void func_80123788(Entity* entity);
void func_801238CC(Entity* entity);
void func_80123A60(Entity* entity);
void func_80123B40(Entity* entity);
void func_80123F78(Entity* entity);
void func_801243B0(Entity* entity);
void func_80124A8C(Entity* entity);
void func_80124B88(Entity* entity);
void func_80125330(Entity* entity);
void func_80125C2C(Entity* entity);
void func_80125E68(Entity* entity);
void func_801262AC(Entity* entity);
void func_801267B0(Entity* entity);
void func_80126C48(Entity* entity);
void func_80126ECC(Entity* entity);
void func_801274DC(Entity* entity);
void func_8012768C(Entity* entity);
void func_80127840(Entity* entity);
void func_801279FC(Entity* entity);
void func_80127CC8(Entity* entity);
void func_80127F40(Entity* entity);
void func_80128714(Entity* entity);
void func_80128C2C(Entity* entity);
void func_801291C4(Entity* entity);
void func_80129864(Entity* entity);
void func_8012A0A4(Entity* entity);
void func_8012A528(Entity* entity);
void func_8012A89C(Entity* entity);
void func_8012B78C(Entity* entity);
void func_8012B990(Entity* entity);
void func_8012BEF8(Entity* entity);
void func_8012CB4C(void);
void func_8012CCE4(void);
void func_8012CFA8(void);
void func_8012F894(Entity* entity);
void func_80130264(Entity* entity);
void func_80130618(Entity* entity);
void func_801309B4(Entity* entity);
void func_80130E94(Entity* entity);
void func_8013136C(Entity* entity);
void func_801315F8(Entity* entity);
void func_80131ED8(s32 value);
void func_80131EE8(void);
void func_80131F04(void);
s32 func_80131F28(void);
u16 func_80131F38(void);
bool func_80131F68(void);
s16 func_80131F94(void);
void func_80132134(void);
void func_8013216C(void);
void func_801321FC(void);
void func_80132264(void);
s32 func_801326D8(void);
void func_80132C2C(s16);
u8 func_80132028(u_char com, u_char* param, u_char* result);
void func_8013271C(void);
void func_80132760(void);
void func_80132A04(s16 voice, s16 vabId, s16 prog, s16 tone, s16 note,
                   s16 volume, s16 distance);
void func_801337B4(void);
bool func_80133940(void);
bool func_80133950(void);
void func_80133FCC(void);
void func_8013415C(void);
void func_801361F8(void);
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
s32 func_800FD6C4(s32 equipTypeFilter) {
    s32 itemCount;
    s32 equipType;
    s32 i;
    switch (equipTypeFilter) {
    case HAND_TYPE:
        return NUM_HAND_ITEMS;
    case HEAD_TYPE:
        equipType = HEAD_TYPE - 1;
        break;
    case ARMOR_TYPE:
        equipType = ARMOR_TYPE - 1;
        break;
    case CAPE_TYPE:
        equipType = CAPE_TYPE - 1;
        break;
    case ACCESSORY_TYPE:
        equipType = ACCESSORY_TYPE - 1;
        break;
    }
    for (itemCount = 0, i = 0; i < 90; i++) {
        if (g_AccessoryDefs[i].equipType == equipType) {
            itemCount++;
        }
    }
    return itemCount;
}
const u32 rodataPadding_jpt_800FD6E0 = 0;
u8* GetEquipOrder(s32 equipTypeFilter) {
    if (equipTypeFilter == 0) {
        return g_Status.equipHandOrder;
    }
    return g_Status.equipBodyOrder;
}
u8* GetEquipCount(s32 equipTypeFilter) {
    if (equipTypeFilter == 0) {
        return g_Status.equipHandCount;
    }
    return g_Status.equipBodyCount;
}
const char* GetEquipmentName(s32 equipTypeFilter, s32 equipId) {
    if (!equipTypeFilter) {
        return g_EquipDefs[equipId].name;
    } else {
        return g_AccessoryDefs[equipId].name;
    }
}
u32 CheckEquipmentItemCount(u32 itemId, u32 equipType) {
    if (equipType < 5) {
        switch (equipType) {
        case 0:
            return (g_Status.equipment[LEFT_HAND_SLOT] == itemId) +
                   (g_Status.equipment[RIGHT_HAND_SLOT] == itemId);
        case 1:
            return g_Status.equipment[HEAD_SLOT] == itemId;
        case 2:
            return g_Status.equipment[ARMOR_SLOT] == itemId;
        case 3:
            return g_Status.equipment[CAPE_SLOT] == itemId;
        case 4:
            return (g_Status.equipment[ACCESSORY_1_SLOT] == itemId) +
                   (g_Status.equipment[ACCESSORY_2_SLOT] == itemId);
        }
    }
}
const u32 rodataPadding_800DCBD8 = 0;
;
void func_800FD9D4(SpellDef* spell, s32 id) {
    *spell = g_SpellDefs[id];
    spell->attack += (g_Status.statsTotal[2] * 2 + (rand() % 12)) / 10;
    if (CheckEquipmentItemCount(ITEM_MOJO_MAIL, ARMOR_TYPE) != 0) {
        spell->attack += spell->attack / 2;
    }
}
s16 GetStatusAilmentTimer(StatusAilments statusAilment, s16 timer) {
    s16 ret;
    s32 var_v1;
    switch (statusAilment) {
    case STATUS_AILMENT_POISON:
        ret = timer - (g_Status.statsTotal[STAT_CON] * 16);
        if (ret < 256) {
            ret = 256;
        }
        break;
    case STATUS_AILMENT_CURSE:
        ret = timer - (g_Status.statsTotal[STAT_CON] * 4);
        if (ret < 64) {
            ret = 64;
        }
        break;
    case STATUS_AILMENT_PETRIFIED:
        ret = timer;
        var_v1 = (((rand() % 12) + g_Status.statsTotal[STAT_CON]) - 9) / 10;
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        if (var_v1 > 4) {
            var_v1 = 4;
        }
        ret -= var_v1;
        break;
    case STATUS_AILMENT_DARK_METAMORPHOSIS:
        ret = timer + (g_Status.statsTotal[STAT_INT] * 4);
        break;
    case STATUS_AILMENT_UNK04:
    case STATUS_AILMENT_UNK05:
        ret = timer;
        if (CheckEquipmentItemCount(ITEM_BWAKA_KNIFE, ACCESSORY_TYPE) != 0) {
            ret += ret / 2;
        }
        break;
    }
    return ret;
}
bool CastSpell(SpellIds spellId) {
    u8 mpUsage = g_SpellDefs[spellId].mpUsage;
    if (g_Status.mp < mpUsage) {
        return false;
    } else {
        g_Status.mp -= mpUsage;
        return true;
    }
}
void LearnSpell(s32 spellId) {
    s32 i;
    if ((g_Status.spellsLearnt & (1 << spellId)) == 0) {
        g_Status.spellsLearnt |= 1 << spellId;
        for (i = 0; i < ((s32)(sizeof(g_Status.spells) / sizeof(*(g_Status.spells)))); i++) {
            if (g_Status.spells[i] == 0) {
                g_Status.spells[i] = spellId | (~0x7F);
                return;
            }
        }
    }
}
bool func_800FDD44(s32 itemType) {
    s32 equippedItem = g_Status.equipment[itemType];
    bool isConsumable = g_EquipDefs[equippedItem].isConsumable;
    if (CheckEquipmentItemCount(ITEM_DUPLICATOR, ACCESSORY_TYPE) == 0) {
        if (isConsumable) {
            if (g_Status.equipHandCount[equippedItem] == 0) {
                g_Status.equipment[itemType] = ITEM_EMPTY_HAND;
                func_800F53A4();
                return true;
            }
            g_Status.equipHandCount[equippedItem]--;
        }
    }
    return false;
}
void func_800FDE00(void) {
    D_80137960 = 0;
    D_80137964 = 0;
    D_80137968 = 0;
}
s32 g_LevelHPIncrease[] = {1, 3, 6, 10, 20, 30, 40, 50, 100, 200};
u32 CheckAndDoLevelUp(void) {
    s32 i;
    s32 statsGained;
    s32 statgain;
    if (D_80137960 != 0) {
        D_80137960 -= 1;
        return 3;
    }
    if (D_80137964 != 0) {
        D_80137964 -= 1;
        return 2;
    }
    if (D_80137968 != 0) {
        D_80137968 -= 1;
        return 4;
    }
    if (g_Status.level == 99) {
        return 0;
    }
    if (g_ExpNext[g_Status.level] <= g_Status.exp) {
        g_Status.level++;
        statsGained = 0;
        g_Status.mpMax += 4 + (rand() & 1);
        g_Status.hp += g_LevelHPIncrease[(s32)g_Status.level / 10];
        g_Status.hpMax += g_LevelHPIncrease[(s32)g_Status.level / 10];
        g_Status.heartsMax += 2;
        CheckAndDoLevelUp();
        for (i = 0; i < ((s32)(sizeof(g_Status.statsBase) / sizeof(*(g_Status.statsBase)))); i++) {
            statgain = rand() & 1;
            g_Status.statsBase[i] += statgain;
            if (g_Status.statsBase[i] > 99) {
                g_Status.statsBase[i] = 99;
                statgain = 0;
            }
            statsGained += statgain;
        }
        if (statsGained < 2) {
            i = rand() & 3;
            g_Status.statsBase[i]++;
            if (g_Status.statsBase[i] > 99) {
                g_Status.statsBase[i] = 99;
            }
        }
        return 1;
    }
    return 0;
}
s32 func_800FE044(s32 amount, s32 type) {
    s32 oldHeartMax;
    s32 activeFamiliar;
    s32 levelDiff;
    s32 i;
    s32 familiarXPBoost;
    u32 playerXPBoost;
    if (type == 0x8000) {
        if (g_Status.hpMax == 9999) {
            return 1;
        }
        g_Status.hpMax += amount;
        if (g_Status.hpMax > 9999) {
            g_Status.hpMax = 9999;
        }
        if (g_PlayableCharacter != 0) {
            g_Status.hpMax += amount;
            if (g_Status.hpMax > 9999) {
                g_Status.hpMax = 9999;
            }
        }
        g_Status.hp = g_Status.hpMax;
        D_80137960++;
        return 0;
    }
    if (type == 0x4000) {
        if (g_PlayableCharacter != 0) {
            return 1;
        }
        oldHeartMax = g_Status.heartsMax;
        if (oldHeartMax == 9999) {
            return 1;
        }
        g_Status.heartsMax += amount;
        if (g_Status.heartsMax > 9999) {
            g_Status.heartsMax = 9999;
        }
        g_Status.hearts += (g_Status.heartsMax - oldHeartMax);
        D_80137964++;
        return 0;
    }
    if (type == 0x2000) {
        g_Status.relics[amount] = 3;
        amount++;
        amount--;
        if (g_RelicDefs[amount].unk0C) {
            g_Status.relics[amount] = 1;
        }
        D_80137968++;
        return 0;
    }
    if (amount != 0 && g_Status.level != 99) {
        s32 enemyLevel = type;
        playerXPBoost = amount;
        if (enemyLevel < (s32)g_Status.level) {
            levelDiff = g_Status.level - enemyLevel;
            for (i = 0; i < levelDiff; i++) {
                playerXPBoost = playerXPBoost * 2 / 3;
            }
            if (playerXPBoost == 0) {
                playerXPBoost = 1;
            }
        }
        if ((s32)g_Status.level < enemyLevel) {
            levelDiff = enemyLevel - g_Status.level;
            if (levelDiff > 5) {
                levelDiff = 5;
            }
            for (i = 0; i < levelDiff; i++) {
                playerXPBoost += playerXPBoost / 4;
            }
        }
        g_Status.exp += playerXPBoost;
        if (g_Status.exp >= D_800AC90C) {
            g_Status.exp = D_800AC90C;
        }
        activeFamiliar = D_8006CBC4 - 1;
        if (D_8006CBC4 == 0) {
            return;
        }
        playerXPBoost =
            (amount / g_Status.statsFamiliars[activeFamiliar].level);
        for (familiarXPBoost = 0; playerXPBoost != 0; familiarXPBoost++) {
            playerXPBoost >>= 1;
        }
        if (familiarXPBoost <= 0) {
            familiarXPBoost = 1;
        }
        g_Status.statsFamiliars[activeFamiliar].exp += familiarXPBoost;
        if (g_Status.statsFamiliars[activeFamiliar].exp >= 9900) {
            g_Status.statsFamiliars[activeFamiliar].exp = 9899;
        }
        g_Status.statsFamiliars[activeFamiliar].level =
            (g_Status.statsFamiliars[activeFamiliar].exp / 100) + 1;
    }
}
bool IsRelicActive(RelicIds relicId) {
    u8 bitTest = 2;
    return (g_Status.relics[relicId] & bitTest) != 0;
}
s32 func_800FE3C4(SubweaponDef* subwpn, s32 subweaponId, bool useHearts) {
    u32 accessoryCount;
    if (subweaponId == 0) {
        *subwpn = g_SubwpnDefs[g_Status.subWeapon];
        accessoryCount =
            CheckEquipmentItemCount(ITEM_HEART_BROACH, ACCESSORY_TYPE);
        if (accessoryCount == 1) {
            subwpn->heartCost = subwpn->heartCost / 2;
        }
        if (accessoryCount == 2) {
            subwpn->heartCost = subwpn->heartCost / 3;
        }
        if (subwpn->heartCost <= 0) {
            subwpn->heartCost = 1;
        }
        if (g_Status.hearts >= subwpn->heartCost) {
            if (useHearts) {
                g_Status.hearts -= subwpn->heartCost;
            }
            return g_Status.subWeapon;
        } else {
            return 0;
        }
    } else {
        *subwpn = g_SubwpnDefs[subweaponId];
        if (CheckEquipmentItemCount(ITEM_BRILLIANT_MAIL, ARMOR_TYPE) != 0) {
            subwpn->attack += 10;
        }
        if (subweaponId == 4 || subweaponId == 12) {
            accessoryCount =
                CheckEquipmentItemCount(ITEM_STAUROLITE, ACCESSORY_TYPE);
            if (accessoryCount == 1) {
                subwpn->attack *= 2;
            }
            if (accessoryCount == 2) {
                subwpn->attack *= 3;
            }
        }
        subwpn->attack += ((g_Status.statsTotal[2] * 2) + (rand() % 12)) / 10;
        return subweaponId;
    }
}
void GetEquipProperties(s32 handId, Equipment* res, s32 equipId) {
    s32 criticalModRate;
    Equipment* var_a2;
    s32 criticalRate;
    u8 itemCategory;
    var_a2 = &g_EquipDefs[(s16)equipId];
    criticalModRate = 5;
    __builtin_memcpy(res, &g_EquipDefs[equipId], sizeof(Equipment));
    criticalRate = res->criticalRate;
    criticalRate = criticalRate - criticalModRate +
                   SquareRoot0((g_Status.statsTotal[3] * 2) + (rand() & 0xF));
    if (criticalRate > 255) {
        criticalRate = 255;
    }
    if (criticalRate < 0) {
        criticalRate = 0;
    }
    if (g_StageId == STAGE_ST0) {
        criticalRate = 0;
    }
    res->criticalRate = criticalRate;
    func_800F4994();
    itemCategory = g_EquipDefs[equipId].itemCategory;
    if (itemCategory != ITEM_FOOD && itemCategory != ITEM_MEDICINE) {
        res->attack = CalcAttack(equipId, g_Status.equipment[1 - handId]);
        if (g_Player.unk0C & 0x00004000) {
            res->attack >>= 1;
        }
    }
}
bool HasEnoughMp(s32 mpCount, bool subtractMp) {
    if (g_Status.mp >= mpCount) {
        if (subtractMp != 0) {
            g_Status.mp -= mpCount;
        }
        return false;
    }
    return true;
}
void func_800FE8F0(void) {
    if (D_8013B5E8 == 0) {
        D_8013B5E8 = 0x40;
    }
}
void AddHearts(s32 value) {
    if (g_Status.hearts < g_Status.heartsMax) {
        g_Status.hearts += value;
        if (g_Status.heartsMax < g_Status.hearts) {
            g_Status.hearts = g_Status.heartsMax;
        }
        func_8011AAFC(g_Entities, 99, 0);
        PlaySfx(0x67A);
    }
}
s32 HandleDamage(DamageParam* damage, s32 arg1, s32 amount, s32 arg3) {
    s32 ret;
    s32 itemCount;
    func_800F53A4();
    damage->unk0 = arg1 & ~0x1F;
    damage->damageKind = arg1 & 0x1F;
    if (g_Status.defenseElement & damage->unk0) {
        amount *= 2;
    }
    if (g_Status.D_80097C2A & damage->unk0) {
        amount /= 2;
    }
    if (g_Status.D_80097C2C & damage->unk0) {
        if (!(g_Status.D_80097C2C & damage->unk0 & 0x200)) {
            return 0;
        }
        damage->unk0 &= ~0x200;
    }
    if (g_Status.D_80097C2E & damage->unk0) {
        if (amount < 1) {
            amount = 1;
        }
        damage->unkC = amount;
        if (g_Status.hp != g_Status.hpMax) {
            func_800FE8F0();
            g_Status.hp += damage->unkC;
            if (g_Status.hpMax < g_Status.hp) {
                g_Status.hp = g_Status.hpMax;
            }
        }
        return 5;
    }
    if (CheckEquipmentItemCount(ITEM_CAT_EYE_CIRCLET, HEAD_TYPE) != 0 &&
        damage->damageKind == 7) {
        amount *= 2;
        if (amount < 1) {
            amount = 1;
        }
        damage->unkC = amount;
        if (g_Status.hp != g_Status.hpMax) {
            func_800FE8F0();
            g_Status.hp += damage->unkC;
            if (g_Status.hpMax < g_Status.hp) {
                g_Status.hp = g_Status.hpMax;
            }
        }
        return 5;
    }
    itemCount = CheckEquipmentItemCount(ITEM_BALLROOM_MASK, HEAD_TYPE);
    if (itemCount != 0 && (damage->unk0 & 0xF980)) {
        if (itemCount == 1) {
            amount -= amount / 5;
        }
        if (itemCount == 2) {
            amount -= amount / 3;
        }
    }
    if (g_Player_unk0C & 0x80) {
        damage->damageTaken = g_Status.hpMax / 8;
        ret = 8;
    } else if (damage->unk0 & 0x200) {
        damage->damageTaken = amount - (g_Status.defenseEquip * 2);
        if (damage->damageTaken <= 0) {
            damage->damageTaken = 0;
        }
        ret = 7;
    } else if (damage->damageKind == 6) {
        if (D_8003C8C4 == ((D_8003C8C4 / 10) * 0xA)) {
            damage->damageTaken = 1;
        } else {
            damage->damageTaken = 0;
        }
        ret = 9;
    } else {
        if (damage->damageKind < 16) {
            damage->damageTaken = amount - g_Status.defenseEquip;
        } else {
            damage->damageTaken = g_Status.hpMax / 8;
        }
        if (g_Player_unk0C & 0x4000) {
            damage->damageTaken *= 2;
        }
        itemCount = CheckEquipmentItemCount(ITEM_TALISMAN, ACCESSORY_TYPE);
        if (itemCount != 0) {
            if (itemCount * g_Status.statsTotal[STAT_LCK] >= (rand() & 511)) {
                return 2;
            }
        }
        if (damage->damageTaken > 0) {
            if (damage->damageKind < 2) {
                if ((damage->damageTaken * 2) >= g_Status.hpMax) {
                    damage->damageKind = 4;
                } else if (amount * 50 >= g_Status.hpMax) {
                    damage->damageKind = 3;
                } else {
                    damage->damageKind = 2;
                }
            }
            ret = 3;
        } else {
            if (g_Status.defenseEquip > 99 && !(damage->unk0 & 0x180) &&
                !(g_Player_unk0C & 0x80)) {
                damage->damageKind = 0;
                ret = 1;
            } else {
                damage->damageKind = 2;
                ret = 3;
            }
            damage->damageTaken = 1;
        }
    }
    if (g_Status.hp <= damage->damageTaken) {
        g_Status.hp = 0;
        if (ret == 7) {
            return 7;
        }
        if (ret == 9) {
            ret = 6;
        } else {
            ret = 4;
        }
    } else {
        if (ret != 9) {
            func_800FE8F0();
        }
        g_Status.hp -= damage->damageTaken;
        if ((CheckEquipmentItemCount(ITEM_BLOOD_CLOAK, CAPE_TYPE) != 0) &&
            (ret != 9)) {
            AddHearts(damage->damageTaken);
        }
        if (CheckEquipmentItemCount(ITEM_FURY_PLATE, ARMOR_TYPE) != 0) {
            if (*D_80139828 < 0x200) {
                *D_80139828 = 0x200;
            }
        }
    }
    return ret;
}
void func_800FEE6C(void) {
    s32* var_v1 = D_80139828;
    do {
        if (*var_v1 != 0) {
            (*var_v1)--;
        }
        var_v1++;
    } while ((s32)var_v1 < (s32)&D_80139828[0x10]);
}
;
s32 func_800FF064(s32 arg0) {
    s32 playerMP;
    playerMP = g_Status.mp - 4;
    if (playerMP > 0) {
        if (arg0 != 0) {
            g_Status.mp = playerMP;
        }
        return 0;
    }
    return -1;
}
void func_800FF0A0(s32 context) { D_80139828[context] = 0; }
void func_800FF0B8(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        func_800FF0A0(i);
    }
}
void func_800FF0F4(s32 arg0) { D_80139828[arg0] = 0x1000; }
s32 func_800FF110(s32 arg0) { return D_80139828[arg0]; }
u16 DealDamage(Entity* enemyEntity, Entity* attackerEntity) {
    s32 stats[4];
    EnemyDef sp20;
    EnemyDef* enemy;
    u16 temp_v1;
    u16 elementMask;
    s32 highestStatIdx;
    s32 i;
    u16 element;
    u16 damage;
    u16 result;
    u16 stuff;
    enemy = &sp20;
    sp20 = g_EnemyDefs[enemyEntity->enemyId];
    if (CheckEquipmentItemCount(ITEM_DRAGON_HELM, HEAD_TYPE) != 0) {
        enemy->defense /= 2;
    }
    element = attackerEntity->attackElement;
    damage = attackerEntity->attack;
    if (element == 0) {
        element = 0x20;
    }
    if (element & 0xFF80) {
        elementMask = 0xFF80;
    } else {
        elementMask = 0x7F;
    }
    result = 0;
    temp_v1 = element & elementMask;
    if (temp_v1 == (temp_v1 & (elementMask & enemy->immunes))) {
        result = 0xC000;
    } else if (temp_v1 == (temp_v1 & (elementMask & enemy->absorbs))) {
        result = damage + 0x8000;
    } else {
        if (temp_v1 == (temp_v1 & (elementMask & enemy->strengths))) {
            damage /= 2;
        }
        if (element & enemy->weaknesses) {
            damage *= 2;
        }
        if (attackerEntity->entityRoomIndex > (rand() & 0xFF)) {
            for (i = 0; i < 4; i++) {
                stats[i] = (rand() & 0x3F) + g_Status.statsBase[i];
            }
            highestStatIdx = 0;
            for (i = 1; i < 4; i++) {
                if (stats[i] > stats[highestStatIdx]) {
                    highestStatIdx = i;
                }
            }
            switch (highestStatIdx) {
            case STAT_STR:
                damage *= 2;
                break;
            case STAT_CON:
                if (enemy->defense > damage) {
                    damage += enemy->defense / 2;
                } else {
                    damage += damage / 2;
                }
                break;
            case STAT_INT:
                damage += SquareRoot0(g_RoomCount);
                break;
            case STAT_LCK:
                damage += (rand() % g_Status.statsTotal[STAT_LCK]) + 1;
                break;
            }
            result = 0x4000;
        } else {
            result = 0x0000;
        }
        if (damage > enemy->defense) {
            damage = damage - enemy->defense;
        } else {
            damage = 1;
        }
        if (damage < 0 || damage >= 10000) {
            damage = 9999;
        }
        result += damage;
    }
    return result;
}
s32 func_800FF460(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + ((u32)(arg0 * g_Status.statsTotal[3]) >> 7);
}
s32 func_800FF494(EnemyDef* arg0) {
    s32 ringOfArcanaCount =
        CheckEquipmentItemCount(ITEM_RING_OF_ARCANA, ACCESSORY_TYPE);
    s32 rnd = rand() & 0xFF;
    rnd -= ((rand() & 0x1F) + g_Status.statsTotal[3]) / 20;
    if (ringOfArcanaCount != 0) {
        rnd -= arg0->rareItemDropRate * ringOfArcanaCount;
    }
    if (rnd < arg0->rareItemDropRate) {
        return 0x40;
    } else {
        rnd -= arg0->rareItemDropRate;
        if (ringOfArcanaCount != 0) {
            rnd -= arg0->uncommonItemDropRate * ringOfArcanaCount;
        }
        rnd -= ((rand() & 0x1F) + g_Status.statsTotal[3]) / 20;
        if (rnd >= arg0->uncommonItemDropRate) {
            rnd = rand() % 28;
            if (arg0->rareItemDropRate == 0) {
                rnd++;
            }
            if (arg0->uncommonItemDropRate == 0) {
                rnd++;
            }
            return rnd + ringOfArcanaCount;
        } else {
            return 0x20;
        }
    }
}
void func_800FF60C(void) {
    s32 var_a0_2;
    s32 i;
    func_800EA538(6);
    i = 0;
    while (1) {
        if (g_Status.equipment[CAPE_SLOT] == D_800A2FBC[i]) {
            break;
        }
        if (D_800A2FBC[i] == -1) {
            break;
        }
        i += 2;
    }
    var_a0_2 = D_800A2FC0[i];
    if (g_Status.equipment[CAPE_SLOT] == ITEM_REVERSE_CLOAK &&
        g_Settings.isCloakLiningReversed) {
        var_a0_2++;
    }
    func_800EA5E4(var_a0_2);
    if (g_Status.equipment[CAPE_SLOT] == ITEM_TWILIGHT_CLOAK) {
        func_800EA5E4(0x415);
    }
}
void func_800FF60C();
void func_800FF6C4(void) {
    if (g_StageId != STAGE_ST0 && g_PlayableCharacter == 0) {
        func_800FF60C();
    }
}
void func_800FF708(s32 equipType, s32 arg1) {
    s32 rnd;
    do {
    loop_1:
        rnd = rand() % 90;
        while (rnd == 0x19) {
            goto loop_1;
        }
    } while (g_AccessoryDefs[rnd].equipType != equipType);
    g_Status.equipment[arg1 + 2] = rnd;
}
extern const char* g_CheatCodes[2];
void InitStatsAndGear(bool isDeathTakingItems) {
    s32 prologueBonusState;
    s32 dracDefeatTime;
    u8* fileName;
    s32 equipId;
    s32 i;
    if (D_8003C730 != 0) {
        func_800F53A4();
        func_800FF60C();
        return;
    }
    if (isDeathTakingItems == true) {
        if (g_Status.equipment[LEFT_HAND_SLOT] == ITEM_ALUCARD_SWORD) {
            g_Status.equipment[LEFT_HAND_SLOT] = ITEM_EMPTY_HAND;
        } else if (g_Status.equipment[RIGHT_HAND_SLOT] == ITEM_ALUCARD_SWORD) {
            g_Status.equipment[RIGHT_HAND_SLOT] = ITEM_EMPTY_HAND;
        } else if (g_Status.equipHandCount[ITEM_ALUCARD_SWORD] != 0) {
            g_Status.equipHandCount[ITEM_ALUCARD_SWORD]--;
        }
        if (g_Status.equipment[LEFT_HAND_SLOT] == ITEM_ALUCARD_SHIELD) {
            g_Status.equipment[LEFT_HAND_SLOT] = ITEM_EMPTY_HAND;
        } else if (g_Status.equipment[RIGHT_HAND_SLOT] == ITEM_ALUCARD_SHIELD) {
            g_Status.equipment[RIGHT_HAND_SLOT] = ITEM_EMPTY_HAND;
        } else if (g_Status.equipHandCount[ITEM_ALUCARD_SHIELD] != 0) {
            g_Status.equipHandCount[ITEM_ALUCARD_SHIELD]--;
        }
        if (g_Status.equipment[HEAD_SLOT] == ITEM_DRAGON_HELM) {
            g_Status.equipment[HEAD_SLOT] = ITEM_EMPTY_HEAD;
        } else if (g_Status.equipBodyCount[ITEM_DRAGON_HELM] != 0) {
            g_Status.equipBodyCount[ITEM_DRAGON_HELM]--;
        }
        if (g_Status.equipment[ARMOR_SLOT] == ITEM_ALUCARD_MAIL) {
            g_Status.equipment[ARMOR_SLOT] = ITEM_NO_ARMOR;
        } else if (g_Status.equipBodyCount[ITEM_ALUCARD_MAIL] != 0) {
            g_Status.equipBodyCount[ITEM_ALUCARD_MAIL]--;
        }
        if (g_Status.equipment[CAPE_SLOT] == ITEM_TWILIGHT_CLOAK) {
            g_Status.equipment[CAPE_SLOT] = ITEM_NO_CAPE;
            func_800FF60C();
        } else if (g_Status.equipBodyCount[ITEM_TWILIGHT_CLOAK] != 0) {
            g_Status.equipBodyCount[ITEM_TWILIGHT_CLOAK]--;
        }
        if (g_Status.equipment[ACCESSORY_1_SLOT] == ITEM_NECKLACE_OF_J) {
            g_Status.equipment[ACCESSORY_1_SLOT] = ITEM_NO_ACCESSORY;
        } else if (g_Status.equipment[ACCESSORY_2_SLOT] == ITEM_NECKLACE_OF_J) {
            g_Status.equipment[ACCESSORY_2_SLOT] = ITEM_NO_ACCESSORY;
        } else if (g_Status.equipBodyCount[ITEM_NECKLACE_OF_J] != 0) {
            g_Status.equipBodyCount[ITEM_NECKLACE_OF_J]--;
        }
    } else {
        for (i = 0; i < 2048; i++) {
            g_CastleMap[i] = 0;
        }
        g_RoomCount = 0;
        g_Status.D_80097BF8 = 0;
        for (i = 0; i < 4; i++) {
            g_Status.statsEquip[i] = 0;
        }
        g_Status.exp = 0;
        g_Status.level = 1;
        g_Status.killCount = 0;
        for (i = 0; i < NUM_FAMILIARS; i++) {
            g_Status.statsFamiliars[i].level = 1;
            g_Status.statsFamiliars[i].exp = 0;
            g_Status.statsFamiliars[i].unk8 = 0;
        }
        for (i = 0; i < 169; i++) {
            g_Status.equipHandCount[i] = 0;
            g_Status.equipHandOrder[i] = i;
        }
        for (i = 0; i < 90; i++) {
            g_Status.equipBodyCount[i] = 0;
            g_Status.equipBodyOrder[i] = i;
        }
        g_Status.equipHandCount[ITEM_EMPTY_HAND] = 1;
        g_Status.equipBodyCount[ITEM_EMPTY_HEAD] = 1;
        g_Status.equipBodyCount[ITEM_NO_ARMOR] = 1;
        g_Status.equipBodyCount[ITEM_NO_CAPE] = 1;
        g_Status.equipBodyCount[ITEM_NO_ACCESSORY] = 1;
        for (i = 0; i < ((s32)(sizeof(g_Status.spells) / sizeof(*(g_Status.spells)))); i++) {
            g_Status.spells[i] = 0;
        }
        g_Status.spellsLearnt = 0;
        if ((g_StageId == STAGE_ST0) ||
            (g_PlayableCharacter != 0)) {
            for (i = 0; i < ((s32)(sizeof(g_Status.relics) / sizeof(*(g_Status.relics)))); i++) {
                g_Status.relics[i] = 1;
            }
            g_Status.relics[RELIC_CUBE_OF_ZOE] |= 2;
            g_Status.relics[RELIC_SPIRIT_ORB] |= 2;
            g_Status.relics[RELIC_FAERIE_SCROLL] |= 2;
            g_Status.relics[RELIC_JEWEL_OF_OPEN] |= 2;
            for (i = 0; i < 32; i++) {
                g_Settings.timeAttackRecords[i] = 0;
            }
            g_Settings.D_8003CB00 = 0;
            g_Settings.D_8003CB04 = 0;
            g_Status.subWeapon = 0;
            if ((g_StageId != STAGE_ST0) && (g_StageId != STAGE_NO3)) {
                g_Status.subWeapon = (rand() % 9) + 1;
            }
            g_Status.hp = 50;
            g_Status.hpMax = 50;
            g_Status.hearts = 30;
            g_Status.heartsMax = 99;
            g_Status.mpMax = 20;
            g_Status.mp = 20;
            g_Status.statsBase[STAT_STR] = 10;
            g_Status.statsBase[STAT_CON] = 10;
            g_Status.statsBase[STAT_INT] = 10;
            g_Status.statsBase[STAT_LCK] = 10;
            g_Status.equipment[HEAD_SLOT] = ITEM_EMPTY_HEAD;
            g_Status.equipment[CAPE_SLOT] = ITEM_NO_CAPE;
            g_Status.equipment[ACCESSORY_1_SLOT] = ITEM_NO_ACCESSORY;
            g_Status.equipment[ACCESSORY_2_SLOT] = ITEM_NO_ACCESSORY;
            g_Status.gold = 0;
            g_Status.equipment[LEFT_HAND_SLOT] = ITEM_EMPTY_HAND;
            g_Status.equipment[RIGHT_HAND_SLOT] = ITEM_EMPTY_HAND;
            g_Status.equipment[ARMOR_SLOT] = ITEM_NO_ARMOR;
            if (g_StageId == STAGE_NO3) {
                TimeAttackController(
                    TIMEATTACK_EVENT_FIRST_MARIA_MEET, TIMEATTACK_SET_RECORD);
                TimeAttackController(
                    TIMEATTACK_EVENT_SUCCUBUS_DEFEAT, TIMEATTACK_SET_RECORD);
                TimeAttackController(TIMEATTACK_EVENT_MINOTAUR_WEREWOLF_DEFEAT,
                                     TIMEATTACK_SET_RECORD);
                TimeAttackController(
                    TIMEATTACK_EVENT_SAVE_RICHTER, TIMEATTACK_SET_RECORD);
                TimeAttackController(
                    TIMEATTACK_EVENT_DEATH_DEFEAT, TIMEATTACK_SET_RECORD);
            }
            g_Status.timerHours = 0;
            g_Status.timerMinutes = 0;
            g_Status.timerSeconds = 0;
            g_Status.timerFrames = 0;
        } else {
            if (g_StageId == STAGE_NO3) {
                g_Status.statsBase[STAT_STR] = 6;
                g_Status.statsBase[STAT_CON] = 6;
                g_Status.statsBase[STAT_INT] = 6;
                g_Status.statsBase[STAT_LCK] = 6;
                g_Status.gold = 0;
                for (i = 0; i < ((s32)(sizeof(g_Status.relics) / sizeof(*(g_Status.relics)))); i++) {
                    g_Status.relics[i] = 0;
                }
                if (D_801397FC != 0) {
                    AddToInventory(ITEM_POTION, HAND_TYPE);
                    prologueBonusState = 3;
                } else if (g_Status.hp == g_Status.hpMax) {
                    g_Status.statsBase[STAT_STR]++;
                    g_Status.statsBase[STAT_CON]++;
                    g_Status.statsBase[STAT_INT]++;
                    g_Status.statsBase[STAT_LCK]++;
                    prologueBonusState = 0;
                } else if (g_Status.hp >= g_Status.hpMax / 2) {
                    g_Status.statsBase[STAT_STR]++;
                    prologueBonusState = 1;
                } else {
                    g_Status.statsBase[STAT_CON]++;
                    prologueBonusState = 2;
                }
                if ((g_Status.hearts == 0) && (prologueBonusState < 3)) {
                    AddToInventory(ITEM_HEART_REFRESH, HAND_TYPE);
                }
                g_Status.hpMax = 70;
                if (prologueBonusState == 0) {
                    g_Status.hpMax = 75;
                }
                g_Status.hearts = 10;
                g_Status.heartsMax = 50;
                g_Status.mpMax = 20;
                if (D_80139008 >= 41) {
                    AddToInventory(ITEM_NEUTRON_BOMB, HAND_TYPE);
                    g_Status.statsBase[STAT_INT]++;
                } else {
                    g_Status.statsBase[STAT_STR]++;
                }
                if (g_Status.subWeapon == 4) {
                    if (prologueBonusState < 3) {
                        g_Status.heartsMax += 5;
                        g_Status.mpMax += 5;
                    }
                } else if (g_Status.subWeapon == 3) {
                    if (prologueBonusState < 2) {
                        g_Status.heartsMax += 5;
                        g_Status.statsBase[STAT_INT]++;
                    }
                } else {
                    switch (prologueBonusState) {
                    case 0:
                        g_Status.statsBase[STAT_LCK] += 5;
                        g_Status.statsBase[STAT_INT]++;
                        g_Status.statsBase[STAT_CON]++;
                    case 1:
                        g_Status.hpMax += 5;
                    case 2:
                        g_Status.statsBase[STAT_STR]++;
                        break;
                    }
                }
                dracDefeatTime = TimeAttackController(
                    TIMEATTACK_EVENT_DRACULA_DEFEAT, TIMEATTACK_GET_RECORD);
                if (dracDefeatTime <= 100) {
                    g_Status.hpMax += 5;
                    g_Status.mpMax += 5;
                    g_Status.heartsMax += 5;
                    g_Status.statsBase[STAT_STR] += 5;
                    g_Status.statsBase[STAT_CON] += 5;
                    g_Status.statsBase[STAT_INT] += 5;
                    g_Status.statsBase[STAT_LCK] += 5;
                } else if (dracDefeatTime <= 200) {
                    g_Status.statsBase[STAT_LCK] += 2;
                } else if (dracDefeatTime <= 300) {
                    g_Status.statsBase[STAT_LCK]++;
                } else if (dracDefeatTime >= 1000) {
                    g_Status.statsBase[STAT_CON]++;
                }
                g_Status.equipment[LEFT_HAND_SLOT] = ITEM_ALUCARD_SWORD;
                g_Status.equipment[RIGHT_HAND_SLOT] = ITEM_ALUCARD_SHIELD;
                g_Status.equipment[HEAD_SLOT] = ITEM_DRAGON_HELM;
                g_Status.equipment[ARMOR_SLOT] = ITEM_ALUCARD_MAIL;
                g_Status.equipment[CAPE_SLOT] = ITEM_TWILIGHT_CLOAK;
                g_Status.equipment[ACCESSORY_1_SLOT] = ITEM_NECKLACE_OF_J;
                g_Status.subWeapon = 0;
                g_Status.equipment[ACCESSORY_2_SLOT] = ITEM_NO_ACCESSORY;
                g_Status.hp = g_Status.hpMax;
                g_Status.mp = g_Status.mpMax;
                fileName = g_CheatCodes[0];
                for (i = 0; i < 8; i++) {
                    if (g_SaveName[i] != *fileName++) {
                        break;
                    }
                }
                if (i == 8) {
                    g_Status.statsBase[STAT_STR] = 1;
                    g_Status.statsBase[STAT_CON] = 0;
                    g_Status.statsBase[STAT_INT] = 0;
                    g_Status.statsBase[STAT_LCK] = 99;
                    g_Status.hpMax = 25;
                    g_Status.hearts = 5;
                    g_Status.heartsMax = 5;
                    g_Status.mpMax = 1;
                    g_Status.hp = g_Status.hpMax;
                    g_Status.mp = g_Status.mpMax;
                    g_Status.equipment[ACCESSORY_2_SLOT] = ITEM_LAPIS_LAZULI;
                }
                if (g_IsTimeAttackUnlocked) {
                    fileName = g_CheatCodes[1];
                    for (i = 0; i < 8; i++) {
                        if (g_SaveName[i] != *fileName++) {
                            break;
                        }
                    }
                    if (i == 8) {
                        AddToInventory(ITEM_AXE_LORD_ARMOR, ARMOR_TYPE);
                    }
                }
            } else {
                for (i = 0; i < ((s32)(sizeof(g_Settings.timeAttackRecords) / sizeof(*(g_Settings.timeAttackRecords)))); i++) {
                    g_Settings.timeAttackRecords[i] = 0;
                }
                g_Status.statsBase[STAT_STR] = 6;
                g_Status.statsBase[STAT_CON] = 6;
                g_Status.statsBase[STAT_INT] = 6;
                g_Status.statsBase[STAT_LCK] = 6;
                g_Status.hpMax = 70;
                g_Status.hp = 70;
                g_Status.hearts = 10;
                g_Status.gold = 500000;
                g_Status.heartsMax = 50;
                g_Status.mpMax = 20;
                g_Status.mp = 20;
                g_Status.hearts = 1234;
                g_Status.heartsMax = 2000;
                g_Status.exp = 11000;
                g_Status.level = 20;
                if (g_StageId & 0x20) {
                    g_Status.exp = 110000;
                }
                for (i = 0; i < ((s32)(sizeof(g_Status.relics) / sizeof(*(g_Status.relics)))); i++) {
                    g_Status.relics[i] = 1 | 2;
                    if (g_RelicDefs[i].unk0C != 0) {
                        g_Status.relics[i] = 1;
                    }
                }
                for (i = 0; i < 169; i++) {
                    g_Status.equipHandCount[i] = 50;
                }
                for (i = 0; i < 90; i++) {
                    g_Status.equipBodyCount[i] = 1;
                }
                g_Status.equipment[LEFT_HAND_SLOT] = ITEM_SHORT_SWORD;
                g_Status.equipment[RIGHT_HAND_SLOT] = ITEM_LEATHER_SHIELD;
                g_Status.equipment[HEAD_SLOT] = ITEM_EMPTY_HEAD;
                g_Status.equipment[ARMOR_SLOT] = ITEM_HIDE_CUIRASS;
                g_Status.equipment[CAPE_SLOT] = ITEM_NO_CAPE;
                g_Status.equipment[ACCESSORY_1_SLOT] = ITEM_NO_ACCESSORY;
                g_Status.equipment[ACCESSORY_2_SLOT] = ITEM_NO_ACCESSORY;
                g_Status.timerHours = 0;
                g_Status.timerMinutes = 0;
                g_Status.timerSeconds = 0;
                g_Status.timerFrames = 0;
                g_Status.subWeapon = 0;
                g_Status.relics[RELIC_CUBE_OF_ZOE] = 3;
                g_Status.relics[RELIC_SPIRIT_ORB] = 3;
                g_Status.relics[RELIC_FAERIE_SCROLL] = 3;
                g_Status.relics[RELIC_SOUL_OF_BAT] = 3;
                g_Status.relics[RELIC_FIRE_OF_BAT] = 3;
                g_Status.relics[RELIC_SOUL_OF_WOLF] = 3;
                g_Status.relics[RELIC_POWER_OF_WOLF] = 3;
                g_Status.relics[RELIC_SKILL_OF_WOLF] = 3;
                g_Status.relics[RELIC_FORM_OF_MIST] = 3;
                g_Status.relics[RELIC_GRAVITY_BOOTS] = 3;
                g_Status.relics[RELIC_LEAP_STONE] = 3;
                AddToInventory(ITEM_FIREBRAND, HAND_TYPE);
                AddToInventory(ITEM_THUNDERBRAND, HAND_TYPE);
                AddToInventory(ITEM_ICEBRAND, HAND_TYPE);
                AddToInventory(ITEM_CLAYMORE, HAND_TYPE);
                AddToInventory(ITEM_MACE, HAND_TYPE);
                AddToInventory(ITEM_KATANA, HAND_TYPE);
                AddToInventory(ITEM_KNIGHT_SHIELD, HAND_TYPE);
                AddToInventory(ITEM_IRON_SHIELD, HAND_TYPE);
                AddToInventory(ITEM_BASILARD, HAND_TYPE);
                AddToInventory(ITEM_RAPIER, HAND_TYPE);
                AddToInventory(ITEM_KNUCKLE_DUSTER, HAND_TYPE);
                AddToInventory(ITEM_CUTLASS, HAND_TYPE);
                AddToInventory(ITEM_CLOTH_TUNIC, ARMOR_TYPE);
                AddToInventory(ITEM_BRONZE_CUIRASS, ARMOR_TYPE);
                AddToInventory(ITEM_IRON_CUIRASS, ARMOR_TYPE);
                AddToInventory(ITEM_STEEL_CUIRASS, ARMOR_TYPE);
                AddToInventory(ITEM_SILVER_PLATE, ARMOR_TYPE);
                AddToInventory(ITEM_GOLD_PLATE, ARMOR_TYPE);
                AddToInventory(ITEM_FIRE_MAIL, ARMOR_TYPE);
                AddToInventory(ITEM_MIRROR_CUIRASS, ARMOR_TYPE);
                AddToInventory(ITEM_VELVET_HAT, HEAD_TYPE);
                AddToInventory(ITEM_LEATHER_HAT, HEAD_TYPE);
                AddToInventory(ITEM_STEEL_HELM, HEAD_TYPE);
                AddToInventory(ITEM_CLOTH_CAPE, CAPE_TYPE);
                AddToInventory(ITEM_ELVEN_CLOAK, CAPE_TYPE);
                AddToInventory(ITEM_ROYAL_CLOAK, CAPE_TYPE);
                AddToInventory(ITEM_REVERSE_CLOAK, CAPE_TYPE);
                AddToInventory(ITEM_MEDAL, ACCESSORY_TYPE);
                AddToInventory(ITEM_GAUNTLET, ACCESSORY_TYPE);
                for (i = 0; i < 80; i++) {
                    AddToInventory(ITEM_POTION, HAND_TYPE);
                }
                for (i = 0; i < 10; i++) {
                    AddToInventory(ITEM_MAGIC_MISSILE, HAND_TYPE);
                    AddToInventory(ITEM_TURKEY, HAND_TYPE);
                    AddToInventory(ITEM_POT_ROAST, HAND_TYPE);
                    AddToInventory(ITEM_ANTIVENOM, HAND_TYPE);
                    AddToInventory(ITEM_BOOMERANG, HAND_TYPE);
                    AddToInventory(ITEM_JAVELIN, HAND_TYPE);
                    AddToInventory(ITEM_PENTAGRAM, HAND_TYPE);
                }
            }
        }
    }
    func_800F53A4();
}
void DrawHudRichter(void) {
    Primitive* prim;
    D_80137978 = 400;
    D_8013797C = 400;
    D_801397FC = 0;
    D_80139008 = 0;
    D_80137994 = 0;
    D_8003C744 = 0;
    D_80137980 = 48;
    D_80137984 = 0;
    D_80137990.unk0 = 0;
    D_8013798C = 40000 / D_80137978;
    D_80137988 = 40000 / D_8013797C;
    D_80137970 = func_800EDD9C(4, 9);
    prim = &g_PrimBuf[D_80137970];
    SetTexturedPrimRect(prim, 2, 22, 32, 96, 0, 0);
    prim->tpage = 0x1B;
    prim->clut = 0x101;
    prim->priority = 0x1EF;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, D_80137980 + 216, 22, 32, 96, 32, 0);
    prim->tpage = 0x1B;
    prim->clut = 0x100;
    prim->priority = 0x1EF;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, 4, 112, 9, 3, 64, 89);
    prim->tpage = 0x1B;
    prim->clut = 0x105;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, D_80137980 + 228, 112, 9, 3, 64, 89);
    prim->tpage = 0x1B;
    prim->clut = 0x103;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim->p1 = 0;
    prim->p2 = 6;
    prim = prim->next;
    SetTexturedPrimRect(prim, D_80137980 + 236, 112, 9, 3, 64, 89);
    prim->tpage = 0x1B;
    prim->clut = 0x103;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, 14, 27, 8, 8, 0, 96);
    prim->tpage = 0x1B;
    prim->clut = 0x103;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, 22, 27, 8, 8, 0, 96);
    prim->tpage = 0x1B;
    prim->clut = 0x103;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, 18, 38, 8, 8, 0, 0);
    prim->tpage = 0x1B;
    prim->clut = 0x102;
    prim->priority = 0x1F0;
    prim->blendMode = 0x2000;
    prim = prim->next;
    SetTexturedPrimRect(prim, 33, 20, 64, 24, 64, 40);
    prim->tpage = 0x1B;
    prim->clut = 0x103;
    prim->priority = 0x1EF;
    prim->blendMode = 0x2000;
    D_80137974 = func_800EDD9C(4, 16);
    prim = &g_PrimBuf[D_80137974];
    if (prim != 0) {
        s32 u = 32;
        s32 x = 216;
        do {
            SetTexturedPrimRect(prim, x, 22, 2, 96, u, 0);
            func_801072DC(prim);
            prim->tpage = 0x1B;
            prim->clut = 0x100;
            prim->priority = 0x1EE;
            prim->blendMode = 8;
            prim->p1 = (rand() & 0x3F) + 1;
            prim->p2 = 0;
            prim = prim->next;
            u += 2;
            x += 2;
        } while (prim != 0);
    }
}
;
extern Unkstruct_80137990 D_80137990;
bool func_8010183C(s32 arg0) {
    if (arg0 == 0) {
        if (D_80137990.unk0 == 0) {
            D_80137990.unk0 = 1;
            return true;
        }
        return false;
    } else if (arg0 == 1) {
        if (D_80137990.unk0 == 0x15) {
            D_80137990.unk0 = 0x33;
            return true;
        }
        return false;
    }
    return true;
}
void DrawHudRichter(void);
void func_8010189C(void) {
    Primitive* poly;
    s32 i;
    u16* new_var;
    D_8013B5E8 = 0;
    g_HealingMailTimer[0] = 0;
    g_DisplayHP[0] = g_Status.hp;
    if ((g_StageId == STAGE_ST0) || (g_PlayableCharacter != 0)) {
        DrawHudRichter();
        return;
    }
    D_80137970 = func_800EDD9C(4, 14);
    poly = &g_PrimBuf[D_80137970];
    if (poly != (0)) {
        for (i = 0; poly != (0); i++) {
            SetTexturedPrimRect(
                poly, D_800A2EE8[i], D_800A2EF8[i], D_800A2F28[i],
                D_800A2F38[i], D_800A2F08[i], D_800A2F18[i]);
            poly->tpage = 0x1F;
            new_var = &D_800A2F48[i];
            poly->clut = *new_var;
            poly->priority = 0x1F0;
            poly->blendMode = D_800A2F64[i];
            if (i == 5) {
                SetPrimRect(
                    poly, D_800A2EED, D_800A2EFD, D_800A2F3D, D_800A2F2D);
                poly->y0 = poly->y2;
                poly->x1 = poly->x0;
                poly->x2 = poly->x3;
                poly->y3 = poly->y1;
            }
            if (i == 1) {
                poly->p1 = 0;
                poly->p2 = rand() + 8;
                poly->p3 = (7 & rand()) + 1;
            }
            poly = poly->next;
        }
    }
}
void DrawHudAlucard() {
    SubweaponDef subwpn;
    RECT rect;
    Primitive* prim;
    s32 statXPos;
    s32 hpdiff;
    s32 mpFillSteps;
    s32 leading_zeros;
    s32 digitSpacing;
    u16 clut;
    if (g_StageId == STAGE_ST0 || g_PlayableCharacter != 0) {
        func_80100B50();
        return;
    }
    func_800EB4F8(D_800C52F8[g_Status.subWeapon], 0, 0x3C0, 0x120);
    prim = &g_PrimBuf[D_80137970];
    if (g_Status.subWeapon != 0) {
        prim->blendMode = 0x2000 | 0x0020 | 0x0010 | 0x0001;
        prim = prim->next;
        prim->p2--;
        if (prim->p2 == 0) {
            prim->p1 += 1;
            if (prim->p1 == 0xF) {
                prim->p1 = 0;
                prim->p2 = rand() + 8;
                prim->p3--;
                if (prim->p3 != 0) {
                    prim->p1 = 1;
                    prim->p2 = 1;
                } else {
                    prim->p3 = (rand() & 7) + 1;
                }
            } else {
                prim->p2 = 1;
                prim->clut = D_800A2F7E[prim->p1];
                prim->u0 = D_800A2F9B[prim->p1];
                prim->v0 = D_800A2F9B[prim->p1 + 16];
                prim->u1 = D_800A2F9B[prim->p1] + 16;
                prim->v1 = D_800A2F9B[prim->p1 + 16];
                prim->u2 = D_800A2F9B[prim->p1];
                prim->v2 = D_800A2F9B[prim->p1 + 16] + 16;
                prim->u3 = D_800A2F9B[prim->p1] + 16;
                prim->v3 = D_800A2F9B[prim->p1 + 16] + 16;
            }
        }
        if (prim->p1 != 0) {
            prim->blendMode = 0x2000;
        } else {
            prim->blendMode = 8;
        }
        prim = prim->next;
        prim->blendMode = 0x2000;
    } else {
        prim->blendMode = 8;
        prim = prim->next;
        prim->blendMode = 8;
        prim = prim->next;
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim = prim->next;
    prim = prim->next;
    rect.x = 988;
    rect.y = 256;
    rect.w = 2;
    rect.h = 56;
    ClearImage(&rect, 0, 0, 0);
    if (!(g_Status.D_80097BF8 & 1)) {
        if (!(D_8003C8C4 & 0x3F)) {
            g_Status.mp++;
        }
        if ((CheckEquipmentItemCount(ITEM_MYSTIC_PENDANT, ACCESSORY_TYPE) !=
             0) &&
            ((D_8003C8C4 & 0x3F) == 0x1F)) {
            g_Status.mp++;
        }
        if (g_Status.mp > g_Status.mpMax) {
            g_Status.mp = g_Status.mpMax;
        }
    }
    if ((CheckEquipmentItemCount(ITEM_HEALING_MAIL, ARMOR_TYPE)) &&
        ((g_Player.unk0C & 0x04000007) == 0x04000000)) {
        g_HealingMailTimer[0]++;
        if (g_HealingMailTimer[0] >= 128) {
            g_Player.unk56 = 2;
            g_Player.unk58 = 1;
            g_HealingMailTimer[0] = 0;
        }
    } else {
        g_HealingMailTimer[0] = 0;
    }
    func_800FEE6C();
    mpFillSteps = (g_Status.mp * 50) / g_Status.mpMax;
    LoadTPage(D_800C52F8[10] + 1, 0, 0, 0x3DC, 0x100, 8, mpFillSteps);
    prim->clut = mpFillSteps == 50 ? 0x162 : 0x174;
    if (D_8013B5E8 == 0) {
        hpdiff = g_Status.hp - g_DisplayHP[0];
        if (hpdiff > 0) {
            if (hpdiff >= 11) {
                g_DisplayHP[0] += (hpdiff) / 10;
            } else {
                g_DisplayHP[0]++;
            }
        }
        if (hpdiff < 0) {
            if (hpdiff < -10) {
                g_DisplayHP[0] += (hpdiff) / 10;
            } else {
                g_DisplayHP[0]--;
            }
        }
    } else {
        D_8013B5E8--;
    }
    if (g_DisplayHP[0] == g_Status.hpMax) {
        func_800EA5E4(2);
    } else if (g_DisplayHP[0] <= g_Status.hpMax >> 2) {
        func_800EA5E4(3);
    } else {
        func_800EA5E4(1);
    }
    if (g_DisplayHP[0] >= 1000) {
        leading_zeros = 0;
        digitSpacing = 6;
        statXPos = 3;
    } else if (g_DisplayHP[0] >= 100) {
        leading_zeros = 1;
        digitSpacing = 6;
        statXPos = 0;
    } else {
        digitSpacing = 7;
        statXPos = -6;
        if (g_DisplayHP[0] >= 10) {
            leading_zeros = 2;
        } else {
            leading_zeros = 3;
        }
    }
    prim = prim->next;
    prim->u2 = prim->u0 = ((g_DisplayHP[0] / 1000) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos;
    prim->x1 = prim->x3 = statXPos + 8;
    prim->blendMode = 0x2000;
    if (leading_zeros != 0) {
        leading_zeros--;
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = (((g_DisplayHP[0] / 100) % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + digitSpacing;
    prim->x1 = prim->x3 = statXPos + digitSpacing + 8;
    prim->blendMode = 0x2000;
    if (leading_zeros != 0) {
        leading_zeros--;
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = (((g_DisplayHP[0] / 10) % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + (digitSpacing * 2);
    prim->x1 = prim->x3 = statXPos + (digitSpacing * 2) + 8;
    prim->blendMode = 0x2000;
    if (leading_zeros != 0) {
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = ((g_DisplayHP[0] % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + (digitSpacing * 3);
    prim->x1 = prim->x3 = statXPos + (digitSpacing * 3) + 8;
    if (g_Status.hearts >= 1000) {
        leading_zeros = 0;
        statXPos = 0x3B;
    } else if (g_Status.hearts >= 100) {
        leading_zeros = 1;
        statXPos = 0x37;
    } else {
        statXPos = 0x33;
        if (g_Status.hearts >= 10) {
            leading_zeros = 2;
        } else {
            leading_zeros = 3;
        }
    }
    if (func_800FE3C4(&subwpn, 0, false) == 0) {
        clut = 0x196;
    } else if (g_blinkTimer & 2) {
        clut = 0x196;
    } else {
        clut = 0x193;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = ((g_Status.hearts / 1000) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos;
    prim->x1 = prim->x3 = statXPos + 8;
    prim->blendMode = 0x2000;
    prim->clut = clut;
    if (leading_zeros != 0) {
        leading_zeros--;
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = (((g_Status.hearts / 100) % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + 4;
    prim->x1 = prim->x3 = statXPos + 0xC;
    prim->blendMode = 0x2000;
    prim->clut = clut;
    if (leading_zeros != 0) {
        leading_zeros--;
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = (((g_Status.hearts / 10) % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + 8;
    prim->x1 = prim->x3 = statXPos + 0x10;
    prim->blendMode = 0x2000;
    prim->clut = clut;
    if (leading_zeros != 0) {
        prim->blendMode = 8;
    }
    prim = prim->next;
    prim->u2 = prim->u0 = ((g_Status.hearts % 10) * 8) + 0x20;
    prim->u3 = prim->u1 = prim->u0 + 8;
    prim->x0 = prim->x2 = statXPos + 0xC;
    prim->x1 = prim->x3 = statXPos + 0x14;
    prim->clut = clut;
}
void func_801024DC(void) {
    Primitive* prim;
    Primitive* prim2;
    s32 x;
    D_8013799C = AllocPrimitives(PRIM_TILE, 4);
    prim = &g_PrimBuf[D_8013799C];
    for (x = 0; prim != 0; x++) {
        prim->x0 = (x & 1) << 7;
        prim->u0 = 0x80;
        prim->v0 = 0xF0;
        prim->priority = 0x1FD;
        prim->blendMode = 8;
        prim = prim->next;
    }
    D_801379A8 = 0;
    D_801379A4 = 0;
    D_801379A0 = AllocPrimitives(PRIM_GT4, 1);
    prim2 = &g_PrimBuf[D_801379A0];
    prim2->u1 = 0xFF;
    prim2->v2 = 0xFF;
    prim2->u3 = 0xFF;
    prim2->v3 = 0xFF;
    prim2->tpage = 0x1D;
    prim2->clut = 0x1C0;
    prim2->priority = 0x1FE;
    prim2->u0 = 0;
    prim2->v0 = 0;
    prim = prim2;
    prim->v1 = 0;
    prim->u2 = 0;
    prim->blendMode = 8;
}
extern Unkstruct_80086FFA D_80086FFA[];
u16 func_801025F4(void) { return D_80086FFA[D_8013799C].unk0; }
void func_80102628(s32 arg0) {
    Primitive* poly;
    s32 temp;
    s32 i = 0;
    poly = &g_PrimBuf[D_8013799C];
    if (poly != (0)) {
        temp = arg0 / 2;
        while (poly != (0)) {
            poly->y0 = 0;
            poly->u0 = (u8)temp;
            poly->v0 = 0xF0;
            poly->b0 = 0;
            poly->g0 = 0;
            poly->r0 = 0;
            poly->priority = 0x1FD;
            poly->blendMode = 8;
            poly->x0 = temp * (i & 1);
            poly = poly->next;
            i++;
        }
    }
}
void func_801026BC(s32 arg0) {
    Primitive* poly = &g_PrimBuf[D_801379A0];
    if (arg0 == 0) {
        poly->blendMode = 8;
        return;
    } else if (!(g_StageId & 0x20)) {
        SetPrimRect(poly, 0, 1, 255, 255);
    } else {
        poly->x2 = 255;
        poly->x0 = 255;
        poly->y1 = 240;
        poly->y0 = 240;
        poly->x3 = 0;
        poly->x1 = 0;
        poly->y3 = -15;
        poly->y2 = -15;
    }
    func_80107250(poly, arg0 * 2);
    if (arg0 == 0x40) {
        poly->blendMode = 0;
    } else {
        poly->blendMode = 0x35;
    }
}
void func_801027A4(void) { func_801026BC(0); }
