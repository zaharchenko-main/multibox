#include <stdio.h>
#include <unistd.h>

int unlink_main(int argc, char **argv)
{
  if (!argv[1]) {
    printf("usage: unlink [file]\n");
    return 1;
  }
  if (unlink(argv[1]) < 0) {
    printf("unlink: error\n");
    return 1;
  }
  return 0;
}
