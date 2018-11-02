#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <cpu/interrupt.h>
#include <util/type.h>
#include <io/print.h>

typedef void (*kb_reg_t)(u8 code);

void keyboard_callback(int_reg_t *r);
void install_kb(kb_reg_t kb);
void code_char_press(u8);
void init_keyboard();

#endif
