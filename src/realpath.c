#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int realpath_main(int argc, char **argv)
{
  if (!argv[1]) {
    printf("usage: realpath [files]...\n");
    return 1;
  }
  char buf[PATH_MAX];
  for (int i = 1; i < argc; i++) {
    char *res_path = realpath(argv[i], buf);
    if (res_path) {
      printf("%s\n", res_path);
    }
  }
  return 0;
}
