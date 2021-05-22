#include <stdio.h>

int reset_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: reset\n");
    return 1;
  }
  printf("\033c\033(B\033[m\033[J\033[?25h");
  return 0;
}
