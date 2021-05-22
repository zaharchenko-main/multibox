#include <stdio.h>
#include <libgen.h>

int dirname_main(int argc, char **argv)
{
  if (!argv[1]) {
    printf("usage: dirname [path]...\n");
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    printf("%s\n", dirname(argv[i]));
  }
  return 0;
}
