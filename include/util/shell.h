#ifndef SHELL_H
#define SHELL_H

#include <util/type.h>
#include <driver/keyboard.h>
#include <io/print.h>

void kb_callback(u8 code);
void input_handler(u8 *);
void update_pos();
void init_shell();

#endif
