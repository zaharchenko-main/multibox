#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ln_main(int argc, char **argv)
{
  if(argc == 4 && strcmp(argv[1], "-s") == 0) {
    if (symlink(argv[2], argv[3]) < 0) {
      printf("failed to create symbolic link\n");
      return 1;
    }
  }
  else if (argc == 3){
    if (link(argv[1], argv[2]) < 0) {
      printf("failed to create link\n");
      return 1;
    }
  }
  else {
    printf("usage: ln [-s] [target] [name]\n");
    return 1;
  }
  return 0;
}
