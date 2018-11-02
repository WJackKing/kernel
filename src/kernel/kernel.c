#include <kernel/kernel.h>

extern void kmain(multiboot_info_t *info) {
	init_mem(info);
	init_cpu();
	init_driver();
	init_shell();

	for(;;){
		asm volatile("hlt");
	}
}

