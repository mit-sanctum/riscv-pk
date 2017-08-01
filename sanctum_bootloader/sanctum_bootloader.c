#include "sanctum_bootloader.h"
#include "mtrap.h"
#include "atomic.h"
#include "vm.h"
#include "bits.h"
#include "config.h"
#include <string.h>

static kernel_elf_info info;
static volatile int elf_loaded;

void boot_loader()
{
  /*
  DRAM Segments:
  a: SM keys
  b: SM certificate
  c: security monitor blob
  d: bootloader stack
  */

  extern char _sanctum_payload_start, _sanctum_payload_end;

  // Print logo
  print_logo();

  // 1. Device keys (in stack)
  // Provision PUF key, if requested.

  // Recover PUF key

  // 2. Load SM --> c
  memcpy(DRAM_BASE+SM_OFFSET, &_sanctum_payload_start, (&_sanctum_payload_end - &_sanctum_payload_start));

  // 3. Compute hash of SM (in stack)
  mb(); // Memory fence
  sha3_Init512(void *priv);
  static void sha3_Update(void *priv, void const *bufIn, size_t len);
  static void const *sha3_Finalize(void *priv);

  // 4. Compute SM keys --> a

  // 5. Compute SM certificate --> b

  // 6. Clean up caches, branch history, etc.

  // 7. Zero memory above the SM amd jump to SM (this destroys the bootloader stack)

  // (Unreachable!)

  // Zero DRAM

  // Load Security Monitor ELF
  load_sm_elf(&_sanctum_payload_start, &_sanctum_payload_end - &_sanctum_payload_start, &info);

  mb(); // Memory fence

  // Jump to boot_loader routine of SM
  void* sm_boot_other_hart = *((void *)(DRAM_BASE+OFFSET_BOOT_ADDR));
  long_jump(sm_boot_other_hart); // load addr into a register, then JALR with rd = x0
}

void boot_other_hart()
{
  while (true)
    ;
  // Other cores are in an infinite loop until an IPC gives them something to do

  void* sm_boot_other_hart = *((void *)(DRAM_BASE+OFFSET_BOOT_ADDR));
  void* boot_addr = (void*)(*sm_boot_other_hart);
  goto *boot_addr;
}
