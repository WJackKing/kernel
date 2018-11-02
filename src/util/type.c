#include <util/type.h>

bool mmcmp(u8 *a1, u8 *a2, u32 count) {
	for(; count != 0; count--) {
		if(*a1++ != *a2++) {
			return false;
		}
	}
	return true;
}

void mmset(u8 *addr, u8 value, u32 count) {
	for(; count != 0; count--) {
		*addr++ = value;
	}
}
