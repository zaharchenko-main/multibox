#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int readlink_main(int argc, char **argv) {
  int opt, n=0, f=0, qs=0, e=0;
  while ((opt = getopt(argc, argv, "::nfqs")) != -1)
  {
    switch (opt)
    {
      case 'n':
        n = 1;
        break;
      case 'f':
        f = 1;
        break;
      case 'q':
      case 's':
        qs = 1;
        break;
      case '?':
        e = 1;
    }
  }
  if (e || (argc - optind != 1)) {
    printf("usage: readlink [-nfqs] [file]\n");
    return 1;
  }

  char name[PATH_MAX];
  if (f) {
    if(!realpath(argv[optind], name)) {
      if (!qs) {
        perror("readlink");
      }
      return 1;
    }
  }
  else {
    ssize_t len = readlink(argv[optind], name, PATH_MAX);
    if (len < 0) {
      if (!qs) {
        perror("readlink");
      }
      return 1;
    }
    name[len] = '\0';
  }
  fputs(name, stdout);
  if (!n) {
    fputs("\n", stdout);
  }
  return 0;
}
