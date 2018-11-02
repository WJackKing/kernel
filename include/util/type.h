#ifndef TYPE_H
#define TYPE_H

typedef unsigned char u8;
typedef			 char s8;
typedef unsigned short u16;
typedef			 short s16;
typedef unsigned int u32;
typedef			 int s32;
typedef unsigned long u64;
typedef u8 bool;
#define false 0
#define true 1

bool mmcmp(u8 *, u8 *, u32);
void mmset(u8 *, u8, u32);

#endif
