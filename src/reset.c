#include <stdio.h>

int reset_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: reset\n");
    return 1;
  }
  printf("\033c\033[?7h");
  return 0;
}
