#ifndef KERNEL_H
#define KERNEL_H

#include <mem/mem.h>
#include <cpu/cpu.h>
#include <driver/driver.h>
#include <io/print.h>
#include <util/shell.h>

extern void kmain(multiboot_info_t *);

#endif
