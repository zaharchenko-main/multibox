#include <stdio.h>

#define ESC "\033"

int reset_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: reset\n");
    return 1;
  }
  printf(ESC"c"ESC"(B"ESC"[m"ESC"[J"ESC"[?25h");
  return 0;
}
