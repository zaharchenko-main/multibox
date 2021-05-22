#include <stdio.h>
#include <unistd.h>

int logname_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: logname\n");
    return 1;
  }
  char *login = getlogin();
  if (!login) {
    printf("no login name.\n");
    return 1;
  }
  printf("%s\n", login);
  return 0;
}
