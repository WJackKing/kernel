#ifndef MEM_H
#define MEM_H

#include <io/print.h>

typedef struct _multiboot_info_t {
  u32 flags;

  u32 mem_lower;
  u32 mem_upper;

  u32 boot_device;

  u32 cmdline;

  u32 mods_count;
  u32 mods_addr;

  union {
    struct {
      u32 num;
      u32 size;
      u32 addr;
      u32 shndx;
    } __attribute__((packed)) efl_sec;

    struct {
      u32 tabsize;
      u32 strsize;
      u32 addr;
      u32 reserved;
    } __attribute__((packed)) aout_sym;
  };

  u32 mmap_len;
  u32 mmap_addr;

  u32 drives_len;
  u32 driver_addr;

  u32 config_table;

  u32 bootloader_name;

  u32 apm_table;

  struct {
    u32 control_info;
    u32 mode_info;
    u16 mode;
    u16 interface_seg;
    u16 interface_off;
    u16 interface_len;
  } __attribute__((packed)) vbe;

  struct {
    u64 addr;
    u32 pitch;
    u32 width;
    u32 height;
    u8  bpp;
    u8  type;

    union {
      struct {
        u32 addr;
        u16 num_colors;
      } __attribute__((packed)) palette;

      struct {
        u8 red_field_position;
        u8 red_mask_size;
        u8 green_field_position;
        u8 green_mask_size;
        u8 blue_field_position;
        u8 blue_mask_size;
      } __attribute__((packed));
    };
  } __attribute__((packed)) framebuffer;
} __attribute__((packed)) multiboot_info_t;

void init_mem(multiboot_info_t *);

#endif
