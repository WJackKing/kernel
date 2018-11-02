#include <util/shell.h>

u32 pos = 0;

void kb_callback(u8 code) {
	if(code >= 0x01 && code <= 0x39) {
		switch(code) {
			case 0x0e:
				if(pos < get_pos()) {
					back();
				}
				break;
			case 0x1c:
				{
					u32 n = get_pos() - pos;
					if(n == 0) {
						put_str("\n$");
						break;
					}else{
						u8 c[n + 1];
						get_buf_str(pos, get_pos(), (u8 *)c);
						c[n] = '\0';
						input_handler(c);
					}
				}
				update_pos();
				break;
			default:
				code_char_press(code);
		}
	}
}

void input_handler(u8 *input) {
	if(mmcmp(input, "clear", 5)) {
		clear();
		put_char('$');
	}else{
		put_str("\n$");
	}
}

void update_pos() {
	pos = get_pos();
}

void init_shell() {
	clear();
	install_kb(kb_callback);
	put_char('$');
	update_pos();
}
