#include <stdio.h>
#include <unistd.h>

int clear_main(int argc, char **argv)
{
  int x = 0;
  if (argv[1]) {
    if (!argv[2] && argv[1][0]=='-' && argv[1][1]=='x' && argv[1][2]=='\0') {
      x = 1;
    }
    else {
      printf("usage: clear [-x]\n");
      return 1;
    }
  }
  if (!x) {
    printf("\033c");
  }
  printf("\x1b[2J\x1b[H");
  return 0;
}
