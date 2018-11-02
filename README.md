# kernel
This is a pure 32 bits kernel.
# what it can do
- grub bootloader
- keyboard interrupt
# how to read
- main sources in src folds
- include folds include some header files; there is some defines.
- grub load "boot/boot.asm" file
- "boot/boot.asm" file load gdt by using "lgdt", and change charge to "kernel/kernel.c"
# next to do
- complete memory manager
- complete system call
