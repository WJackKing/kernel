#ifndef PRINT_H
#define PRINT_H

#include <util/type.h>
#include <driver/vga.h>

void put_char(u8 c);
void put_int(s32 n);
void put_uint(u32 n);
void put_str(u8 *);
void fprint(u8 *str, ...);
void back();
void clear();

#endif
