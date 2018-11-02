#ifndef VGA_H
#define VGA_H

#include <util/type.h>
#include <io/port.h>

#define BUF_WIDTH 80
#define BUF_HEIGHT 25

typedef enum{
	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Brown,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	Pink,
	Yellow,
	White,
}Color;

typedef struct{
	u32 x;
	u32 y;
	u16 buf[BUF_HEIGHT][BUF_WIDTH];
}Buffer;

#define CHAR 8199
#define COLOR 7

void write_char(u8 c);
void write_char_color(u8, u8);
void write_str(u8 *str);
void write_str_color(u8 *, u8);
void write_int(s32 value, u8 base);
void write_int_color(s32 value, u8 base, u8 color);
void write_uint(u32 value, u8 base);
void write_uint_color(u32 value, u8 base, u8 color);
void clear_buffer();
void new_line();
void buf_back();
void flush();
void update_cursor(u32 x, u32 y);
u32 get_pos();
void get_buf_str(u32, u32, u8 *);
void enable_cursor();
void init_vga();

#endif
