#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sleep_main(int argc, char **argv)
{
  if (argc != 2) {
    printf("usage: sleep [seconds]\n");
    return 1;
  }
  usleep(atof(argv[1])*1000000);
  return 0;
}
