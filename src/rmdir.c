#include <stdio.h>
#include <unistd.h>

int rmdir_main(int argc, char **argv)
{
  if(!argv[1] || (argv[1] && argv[1][0] == '-')) {
    printf("usage: rmdir [dir]...\n");
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    if(rmdir(argv[i]) < 0) {
      perror("rmdir");
      return 1;
    }
  }
  return 0;
}
