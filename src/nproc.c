#include <stdio.h>
#include <sys/sysinfo.h>

int nproc_main(int argc, char **argv)
{
  if (argv[1]) {
    printf("usage: nproc\n");
    return 1;
  }
  printf("%d\n", get_nprocs());
  return 0;
}
