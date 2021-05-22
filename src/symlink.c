#include <stdio.h>
#include <unistd.h>

int symlink_main(int argc, char **argv)
{
  if (argc != 3) {
    printf("usage: symlink [target] [name]\n");
    return 1;
  }
  if (symlink(argv[1], argv[2]) < 0) {
    printf("failed to create symbolic link\n");
    return 1;
  }
  return 0;
}
