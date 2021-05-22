#include <stdio.h>
#include <unistd.h>
#include <string.h>

int tty_main(int argc, char **argv)
{
  if (argv[1]) {
    if (argv[1][0] == '-' && argv[1][1] == 's' && argv[1][2] == '\0') {
      return 0;
    }
    else {
      printf("usage: tty [-s]\n");
      return 1;
    }
  }
  else {
    char *tty = ttyname(0);
    if (tty) {
      printf("%s\n", tty);
    }
    else {
      printf("not a tty\n");
    }
  }
  return 0;
}
