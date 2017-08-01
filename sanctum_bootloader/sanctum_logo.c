#include <string.h>
#include "mtrap.h"
#include "csr.h"

static const char logo[] =
" __  __ ___ _____   ___   _   _  _  ___ _____ _   _ __  __ \n"
"|  \\/  |_ _|_   _| / __| /_\\ | \\| |/ __|_   _| | | |  \\/  |\n"
"| |\\/| || |  | |   \\__ \\/ _ \\| .` | (__  | | | |_| | |\\/| |\n"
"|_|  |_|___| |_|   |___/_/ \\_\\_|\\_|\\___| |_|  \\___/|_|  |_|\n"
"\n"
"Secure Software Isolation Containers for RISCV Rocket Chip.\n";

void print_logo() {
  putstring(logo);
}
