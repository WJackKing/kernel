target := kernel
iso := wos.iso

boot_src := $(wildcard src/boot/*.asm)
kernel_src := $(wildcard src/kernel/*.c)
asm_src := $(wildcard src/asm/*.asm)
mem_src := $(wildcard src/mem/*.c)
cpu_src := $(wildcard src/cpu/*.c)
driver_src := $(wildcard src/driver/*.c)
io_src := $(wildcard src/io/*.c)
util_src := $(wildcard src/util/*.c)

boot_obj := $(boot_src:.asm=.o)
kernel_obj := $(kernel_src:.c=.o)
asm_obj := $(asm_src:.asm=.o)
mem_obj := $(mem_src:.c=.o)
cpu_obj := $(cpu_src:.c=.o)
driver_obj := $(driver_src:.c=.o)
io_obj := $(io_src:.c=.o)
util_obj := $(util_src:.c=.o)

obj := $(boot_obj) $(kernel_obj) $(asm_obj) $(mem_obj) $(cpu_obj) $(driver_obj) $(io_obj) $(util_obj)
linker := src/linker.ld
grub := src/grub.cfg

.PHONY: all iso run clean

all: $(target)

iso: $(iso)

run: $(iso)
	@qemu-system-x86_64 -drive format=raw,file=$(iso)

clean:
	@rm -rf $(obj) $(target) $(iso)

$(target): $(obj)
	@ld -T $(linker) -m elf_i386 -o $@ $^

$(iso): $(target)
	@mkdir -p isofiles/boot/grub
	@cp $(grub) isofiles/boot/grub
	@cp $(target) isofiles/boot
	@grub-mkrescue -o wos.iso isofiles 2> /dev/null
	@rm -fr isofiles

%.o: %.asm
	@nasm -f elf32 -o $@ $<

%.o: %.c
	@cc -m32 -c -Iinclude -masm=intel -fno-stack-protector -o $@ $<
