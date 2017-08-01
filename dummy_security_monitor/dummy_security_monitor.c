#include <stdint.h>
#include "sbi.h"

asm (".globl _start\n\
  _start: la sp, stack\n\
  j entry\n\
  .pushsection .rodata\n\
  .align 4\n\
  .skip 4096\n\
  stack:\n\
  .popsection");

void entry()
{
  const char* message =
"This is sanctum's dummy_security_monitor.  To boot a real security monitor, reconfigure\n\
sanctum_bootloader with the flag --with-sanctum-payload=PATH, then rebuild sanctum_bootloader.\n";
  while (*message)
    sbi_console_putchar(*message++);
  sbi_shutdown();
}
