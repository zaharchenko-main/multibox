#include <stdio.h>
#include <string.h>
#include <unistd.h>

int hostname_main(int argc, char **argv)
{
  char host[BUFSIZ];
  if (!argv[1]) {
    if (gethostname(host, sizeof(host)) < 0) {
      printf("gethostname: error\n");
      return 1;
    }
    printf("%s\n", host);
  }
  else if (argc == 2 && argv[1][0] != '-') {
    if (sethostname(argv[1], strlen(argv[1])) < 0) {
      printf("sethostname: error\n");
      return 1;
    }
  }
  else {
    printf("usage: hostname [name]\n");
    return 1;
  }
  return 0;
}
