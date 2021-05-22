#include <stdio.h>

int false_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: false\n");
  }
  return 1;
}
