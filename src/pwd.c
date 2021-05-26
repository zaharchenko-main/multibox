#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *getpwd(void)
{
  struct stat a, b;
  char *pwd;
  if ((pwd = getenv("PWD")) != NULL && *pwd == '/') {
    if (stat(pwd, &a) == -1 || stat(".", &b) == -1) {
      return NULL;
    }
    if (a.st_dev == b.st_dev && a.st_ino == b.st_ino) {
      return pwd;
    }
  }
  errno = ENOENT;
  return NULL;
}

int pwd_main(int argc, char **argv)
{
  int opt, p=0, e=0;
  char *cwd;

  while ((opt = getopt(argc, argv, "::LP")) != -1)
  {
    switch (opt)
    {
      case 'L':
        p = 0;
        break;
      case 'P':
        p = 1;
        break;
      case '?':
        e = 1;
    }
  }

  if (e || (argv[1] && (argv[1][0] != '-' || !argv[1][1]))) {
    printf("usage: pwd [-LP]\n");
    return 1;
  }
  if ((!p && (cwd = getpwd()) != NULL) || ((p || errno == ENOENT) && (cwd = getcwd(NULL, 0)) != NULL)) {
    printf("%s\n", cwd);
  }
  else {
    printf("pwd: error\n");
  }
  return 0;
}
