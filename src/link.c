#include <stdio.h>
#include <unistd.h>

int link_main(int argc, char **argv)
{
  if (argc != 3) {
    printf("usage: link [target] [name]\n");
    return 1;
  }
  if (link(argv[1], argv[2]) < 0) {
    printf("failed to create link\n");
    return 1;
  }
  return 0;
}
