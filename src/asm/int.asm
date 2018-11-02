bits 32

extern int_handler

%macro int_code 1
	global int%1
	int%1:
		cli
		push %1
		jmp int_service
%endmacro

%macro int_nocode 1
	global int%1
	int%1:
		cli
		push 0
		push %1
		jmp int_service
%endmacro

int_service:
	push eax
	push ecx
	push edx
	push ds
	push esp
	call int_handler
	pop eax
	pop ds
	pop edx
	pop ecx
	pop eax
	add esp, 8
	iret

int_nocode 0
int_nocode 1
int_nocode 2
int_nocode 3
int_nocode 4
int_nocode 5
int_nocode 6
int_nocode 7
int_code 8
int_nocode 9
int_code 10
int_code 11
int_code 12
int_code 13
int_code 14
int_nocode 15
int_nocode 16
int_nocode 17
int_nocode 18
int_nocode 19
int_nocode 20
int_nocode 21
int_nocode 22
int_nocode 23
int_nocode 24
int_nocode 25
int_nocode 26
int_nocode 27
int_nocode 28
int_nocode 29
int_nocode 30
int_nocode 31
int_nocode 32
int_nocode 33
int_nocode 34
int_nocode 35
int_nocode 36
int_nocode 37
int_nocode 38
int_nocode 39
int_nocode 40
int_nocode 41
int_nocode 42
int_nocode 43
int_nocode 44
int_nocode 45
int_nocode 46
int_nocode 47
