#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

static void Print(char *word)
{
  static int header = 1;
  if (!header) {
    fputc(' ', stdout);
  }
  fputs(word, stdout);
  header = 0;
}

static int usage(void)
{
  printf("usage: uname [-asnrvmo]\n");
  return 1;
}

int uname_main(int argc, char **argv)
{
  struct utsname buffer;
  int opt, s=0, n=0, r=0, v=0, m=0, o=0;
  if (uname(&buffer) < 0) {
    printf("uname: error\n");
  }

  while((opt = getopt(argc, argv, "::asnrvmo")) != -1)
  {
    switch(opt)
    {
      case 's':
        s = 1;
        break;
      case 'n':
        n = 1;
        break;
      case 'r':
        r = 1;
        break;
      case 'v':
        v = 1;
        break;
      case 'm':
        m = 1;
        break;
      case 'o':
        o = 1;
        break;
      case 'a':
        s = n = r = v = m = o = 1;
        break;
      case '?':
      default:
        return usage();
    }
  }

  if (argv[1] && (argv[1][0] != '-' || !argv[1][1])) {
    return usage();
  }
  if (s || !(n || r || v || m || o)) {
    Print(buffer.sysname);
  }
  if (n) {
    Print(buffer.nodename);
  }
  if (r) {
    Print(buffer.release);
  }
  if (v) {
    Print(buffer.version);
  }
  if (m) {
    Print(buffer.machine);
  }
  if (o) {
    Print("Android");
  }
  putchar('\n');

  return 0;
}
