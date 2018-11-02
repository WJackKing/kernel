#include <mem/mem.h>

void init_mem(multiboot_info_t *info) {
	fprint("%p\n", *info);
}
