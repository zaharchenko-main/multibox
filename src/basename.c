#include <stdio.h>
#include <libgen.h>

int basename_main(int argc, char **argv)
{
  if (!argv[1]) {
    printf("usage: basename [path]...\n");
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    printf("%s\n", basename(argv[i]));
  }
  return 0;
}
