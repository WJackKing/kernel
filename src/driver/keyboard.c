#include <driver/keyboard.h>

kb_reg_t kb_reg = 0;

const u8 code_char[57] = {0x01, '1', '2', '3', '4', '5', '6', '7', '8', '9',
				  '0', '-', '=', 0x0e, 0x0f, 'q', 'w', 'e', 'r', 't', 'y',
				  'u', 'i', 'o', 'p', '[', ']', 0x1c, 0x1d, 'a', 's',
				  'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 
				  0x2a, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',',
				  '.', '/', 0x36, '*', 0x38, ' '};

void code_char_press(u8 code) {
	switch(code) {
		case 0x01:
		case 0x0e:
		case 0x0f:
			break;
		case 0x1c:
			put_char('\n');
			break;
		case 0x1d:
		case 0x2a:
		case 0x36:
		case 0x38:
			break;
		default:
			put_char(code_char[code - 0x01]);
	}
}

void keyboard_callback(int_reg_t *r) {
	u8 code = inb(0x60);
	if(kb_reg) {
		kb_reg(code);
	}
}

void install_kb(kb_reg_t kb) {
	kb_reg = kb;
}

void init_keyboard() {
	install_int(IRQ1, keyboard_callback);
}
