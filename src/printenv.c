#include <stdio.h>
#include <stdlib.h>

int printenv_main(int argc, char **argv)
{
  extern char **environ;
  char *var;
  if (argv[1] && argv[1][0] == '-') {
    printf("usage: printenv [var]...\n");
    return 1;
  }
  if (!argv[1]) {
    for (; *environ; environ++) {
      printf("%s\n", *environ);
    }
  } else {
    for (int i = 1; i < argc; i++) {
      var = getenv(argv[i]);
      if (var) {
        printf("%s\n", var);
      }
    }
  }
  return 0;
}
