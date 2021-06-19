#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int usage(void)
{
  printf("usage: env [-iu] [name=value]... [cmd [arg]...]\n");
  return 1;
}

int env_main(int argc, char **argv)
{
  extern char **environ;
  char **aa;
  int opt;

  while ((opt = getopt(argc, argv, "::-iu:")) != -1)
  {
    switch(opt)
    {
      case '-':
      case 'i':
        *environ = NULL;
        break;
      case 'u':
        if (unsetenv(optarg) < 0) {
          printf("unsetenv: error\n");
          return 1;
        }
        break;
      case '?':
      default:
        return usage();
    }
  }
  for (argv += optind; *argv && strchr(*argv, '='); argv++) {
    putenv(*argv);
  }
  if (*argv) {
    execvp(*argv, argv);
    printf("env: error\n");
    return 1;
  }
  for (aa = environ; *aa; aa++) {
    printf("%s\n", *aa);
  }
  return 0;
}
