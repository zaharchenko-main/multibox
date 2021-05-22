#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int usleep_main(int argc, char **argv)
{
  if (argc != 2) {
    printf("usage: usleep [microseconds]\n");
    return 1;
  }
  usleep(atof(argv[1]));
  return 0;
}
