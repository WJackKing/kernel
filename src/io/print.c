#include <io/print.h>

void put_char(u8 c) {
	write_char(c);
	flush();
}

void put_int(s32 n) {
	write_int(n, 10);
	flush();
}

void put_uint(u32 n) {
	write_uint(n, 10);
	flush();
}

void put_str(u8 *str) {
	write_str(str);
	flush();
}

void fprint(u8 *str, ...) {
	u8 **p_arg = (u8 **)&str;
	p_arg++;

	while(*str != 0) {
		u8 tmp = *str++;
		if(tmp == '%') {
			switch(*str++) {
				case 'd':
					write_int(*((s32*)p_arg), 10);
					p_arg++;
					break;
				case 'x':
					write_int(*((s32*)p_arg), 16);
					p_arg++;
					break;
				case 'u':
					write_uint(*((s32*)p_arg), 10);
					p_arg++;
					break;
				case 'p':
					write_uint(*((s32*)p_arg), 16);
					p_arg++;
					break;
				case 'c':
					write_char(*((u8*)p_arg));
					p_arg++;
					break;
				case 's':
					write_str(*((u8**)p_arg));
					p_arg++;
					break;
			}
		}else{
			write_char(tmp);
		}
	}
	flush();
}

void back() {
	buf_back();
	flush();
}

void clear() {
	clear_buffer();
	flush();
}
