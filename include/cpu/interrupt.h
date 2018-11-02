#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <util/type.h>
#include <io/port.h>
#include <io/print.h>

extern void int0();
extern void int1();
extern void int2();
extern void int3();
extern void int4();
extern void int5();
extern void int6();
extern void int7();
extern void int8();
extern void int9();
extern void int10();
extern void int11();
extern void int12();
extern void int13();
extern void int14();
extern void int15();
extern void int16();
extern void int17();
extern void int18();
extern void int19();
extern void int20();
extern void int21();
extern void int22();
extern void int23();
extern void int24();
extern void int25();
extern void int26();
extern void int27();
extern void int28();
extern void int29();
extern void int30();
extern void int31();

extern void int32();
extern void int33();
extern void int34();
extern void int35();
extern void int36();
extern void int37();
extern void int38();
extern void int39();
extern void int40();
extern void int41();
extern void int42();
extern void int43();
extern void int44();
extern void int45();
extern void int46();
extern void int47();

#define IRQ0 0
#define IRQ1 1
#define IRQ2 2
#define IRQ3 3
#define IRQ4 4
#define IRQ5 5
#define IRQ6 6
#define IRQ7 7
#define IRQ8 8
#define IRQ9 9
#define IRQ10 10
#define IRQ11 11
#define IRQ12 12
#define IRQ13 13
#define IRQ14 14
#define IRQ15 15

typedef struct{
	u32 ds;
	u32 edx, ecx, eax;
	u32 int_no, err_code;
}__attribute__((packed)) int_reg_t;

typedef void (*int_callback)(int_reg_t *r);

extern void int_handler(int_reg_t *r);

typedef struct{
	u16 add_low;
	u16 sel;
	u8 res;
	u8 flags;
	u16 add_high;
}__attribute__((packed)) idt_t;

typedef struct{
	u16 limit;
	u32 address;
}__attribute__((packed)) idt_ptr_t;

void install_int(u8 n, int_callback callback);
void idt_set(u8 num, u32 handler);
void install_isr();
void remap_pic();
void install_irq();
void init_idt();

#endif
