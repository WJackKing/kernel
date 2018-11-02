#include <cpu/interrupt.h>

idt_t idt[256];
idt_ptr_t idt_ptr;
int_callback int_routines[16];
u8 *int_msg[32] = {
	"Division by zero", "Debug", "Non-maskable interrupt",
	"Breakpoint", "Detected overflow", "Out-of-bounds",
	"Invalid opcode", "No coprocessor", "Double fault",
	"Coprocessor segment overrun", "Bad TSS",
	"Segment no present", "Stack fault",
	"General protection fault", "Page fault", "Unknown interrupt",
	"Coprocessor fault", "Alignment check", "Machine check",
	"Reserved", "Reserved", "Reserved", "Reserved", "Reserved", 
	"Reserved", "Reserved", "Reserved", "Reserved", "Reserved",
	"Reserved", "Reserved", "Reserved"
}; 

void int_handler(int_reg_t *r) {
	if(r->int_no <= 31) {
		put_str(int_msg[r->int_no]);
	}else if(r->int_no <= 47){
		int_callback callback = int_routines[r->int_no - 32];
		if(callback) {
			callback(r);
		}
	}
	
	outb(0x20, 0x20);

	if(r->int_no >= 40) {
		outb(0xa0, 0x20);
	}
}

void install_int(u8 n, int_callback callback) {
	int_routines[n] = callback;
}

void idt_set(u8 num, u32 handler) {
	idt[num].add_low = handler & 0xffff;
	idt[num].sel = 0x08;
	idt[num].res = 0x0;
	idt[num].flags = 0x8e;
	idt[num].add_high = (handler >> 16) & 0xffff;
}

void install_isr() {
	idt_set(0, (u32)int0);
	idt_set(1, (u32)int1);
	idt_set(2, (u32)int2);
	idt_set(3, (u32)int3);
	idt_set(4, (u32)int4);
	idt_set(5, (u32)int5);
	idt_set(6, (u32)int6);
	idt_set(7, (u32)int7);
	idt_set(8, (u32)int8);
	idt_set(9, (u32)int9);
	idt_set(10, (u32)int10);
	idt_set(11, (u32)int11);
	idt_set(12, (u32)int12);
	idt_set(13, (u32)int13);
	idt_set(14, (u32)int14);
	idt_set(15, (u32)int15);
	idt_set(16, (u32)int16);
	idt_set(17, (u32)int17);
	idt_set(18, (u32)int18);
	idt_set(19, (u32)int19);
	idt_set(20, (u32)int20);
	idt_set(21, (u32)int21);
	idt_set(22, (u32)int22);
	idt_set(23, (u32)int23);
	idt_set(24, (u32)int24);
	idt_set(25, (u32)int25);
	idt_set(26, (u32)int26);
	idt_set(27, (u32)int27);
	idt_set(28, (u32)int28);
	idt_set(29, (u32)int29);
	idt_set(30, (u32)int30);
	idt_set(31, (u32)int31);
}

void remap_pic() {
	outb(0x20, 0x11);
	outb(0xa0, 0x11);
	
	outb(0x21, 0x20);
	outb(0xa1, 0x28);

	outb(0x21, 0x04);
	outb(0xa1, 0x02);

	outb(0x21, 0x01);
	outb(0xa1, 0x01);

	outb(0x21, 0xfd);
	outb(0xa1, 0xff);
}

void install_irq() {
	idt_set(32, (u32)int32);
	idt_set(33, (u32)int33);
	idt_set(34, (u32)int34);
	idt_set(35, (u32)int35);
	idt_set(36, (u32)int36);
	idt_set(37, (u32)int37);
	idt_set(38, (u32)int38);
	idt_set(39, (u32)int39);
	idt_set(40, (u32)int40);
	idt_set(41, (u32)int41);
	idt_set(42, (u32)int42);
	idt_set(43, (u32)int43);
	idt_set(44, (u32)int44);
	idt_set(45, (u32)int45);
	idt_set(46, (u32)int46);
	idt_set(47, (u32)int47);
}

void init_idt() {
	asm volatile("cli");

	install_isr();
	remap_pic();
	install_irq();

	idt_ptr.limit = sizeof(idt) - 1;
	idt_ptr.address = (u32)idt;

	asm volatile("lidt %0" :: "m"(idt_ptr));
	asm volatile("sti");
}
