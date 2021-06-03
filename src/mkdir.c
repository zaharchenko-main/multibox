#include <stdio.h>
#include <sys/stat.h>

int mkdir_main(int argc, char **argv)
{
  if(!argv[1] || (argv[1] && argv[1][0] == '-')) {
    printf("usage: mkdir [dir]...\n");
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    if(mkdir(argv[i], 0777) < 0) {
      printf("mkdir: error\n");
      return 1;
    }
  }
  return 0;
}
