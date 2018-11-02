bits 32

global start
extern kmain

section .text

	header_start:
		dd 0xe85250d6
		dd 0
		dd header_end - header_start
		dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))
		dw 0
		dw 0
		dd 8
	header_end:

	start:
		mov [info], ebx
		cli
		lgdt [gdt_ptr]
		jmp CODE_SEG:enter

	enter:
		mov ax, DATA_SEG
		mov ds, ax
		mov ss, ax
		mov es, ax
		mov fs, ax
		mov gs, ax
		mov esp, stack_top

		mov ebx, [info]
		push ebx
		call kmain
		hlt
		

section .rodata
	gdt_start:
		dd 0x0
		dd 0x0
	gdt_code:
		dw 0xffff
		dw 0x0
		db 0x0
		db 10011010b
		db 11001111b
		db 0x0
	gdt_data:
		dw 0xffff
		dw 0x0
		db 0x0
		db 10010010b
		db 11001111b
		db 0x0
	gdt_end:

	gdt_ptr:
		dw gdt_end - gdt_start - 1
		dd gdt_start
	
	CODE_SEG equ gdt_code - gdt_start
	DATA_SEG equ gdt_data - gdt_start

section .data
	info: dd 0

section .bss
	stack_bottom:
		resb 4096
	stack_top:
