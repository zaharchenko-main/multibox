#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

int arch_main(int argc, char **argv);
int basename_main(int argc, char **argv);
int clear_main(int argc, char **argv);
int dirname_main(int argc, char **argv);
int echo_main(int argc, char **argv);
int env_main(int argc, char **argv);
int false_main(int argc, char **argv);
int hostname_main(int argc, char **argv);
int link_main(int argc, char **argv);
int ln_main(int argc, char **argv);
int logname_main(int argc, char **argv);
int printenv_main(int argc, char **argv);
int pwd_main(int argc, char **argv);
int readlink_main(int argc, char **argv);
int realpath_main(int argc, char **argv);
int reset_main(int argc, char **argv);
int rmdir_main(int argc, char **argv);
int sleep_main(int argc, char **argv);
int symlink_main(int argc, char **argv);
int sync_main(int argc, char **argv);
int test_main(int argc, char **argv);
int true_main(int argc, char **argv);
int tty_main(int argc, char **argv);
int uname_main(int argc, char **argv);
int unlink_main(int argc, char **argv);
int usleep_main(int argc, char **argv);
int whoami_main(int argc, char **argv);
int yes_main(int argc, char **argv);

int multibox(int argc, char **argv, char *func_name)
{
  if (!func_name) {
    printf("multibox: error\n");
    return 1;
  }

  else if (strcmp(func_name, "arch") == 0) {
    return arch_main(argc, argv);
  }
  else if (strcmp(func_name, "basename") == 0) {
    return basename_main(argc, argv);
  }
  else if (strcmp(func_name, "clear") == 0) {
    return clear_main(argc, argv);
  }
  else if (strcmp(func_name, "dirname") == 0) {
    return dirname_main(argc, argv);
  }
  else if (strcmp(func_name, "echo") == 0) {
    return echo_main(argc, argv);
  }
  else if (strcmp(func_name, "env") == 0) {
    return env_main(argc, argv);
  }
  else if (strcmp(func_name, "false") == 0) {
    return false_main(argc, argv);
  }
  else if (strcmp(func_name, "hostname") == 0) {
    return hostname_main(argc, argv);
  }
  else if (strcmp(func_name, "link") == 0) {
    return link_main(argc, argv);
  }
  else if (strcmp(func_name, "ln") == 0) {
    return ln_main(argc, argv);
  }
  else if (strcmp(func_name, "logname") == 0) {
    return logname_main(argc, argv);
  }
  else if (strcmp(func_name, "printenv") == 0) {
    return printenv_main(argc, argv);
  }
  else if (strcmp(func_name, "pwd") == 0) {
    return pwd_main(argc, argv);
  }
  else if (strcmp(func_name, "readlink") == 0) {
    return readlink_main(argc, argv);
  }
  else if (strcmp(func_name, "realpath") == 0) {
    return realpath_main(argc, argv);
  }
  else if (strcmp(func_name, "reset") == 0) {
    return reset_main(argc, argv);
  }
  else if (strcmp(func_name, "rmdir") == 0) {
    return rmdir_main(argc, argv);
  }
  else if (strcmp(func_name, "sleep") == 0) {
    return sleep_main(argc, argv);
  }
  else if (strcmp(func_name, "symlink") == 0) {
    return symlink_main(argc, argv);
  }
  else if (strcmp(func_name, "sync") == 0) {
    return sync_main(argc, argv);
  }
  else if (strcmp(func_name, "test") == 0) {
    return test_main(argc, argv);
  }
  else if (strcmp(func_name, "true") == 0) {
    return true_main(argc, argv);
  }
  else if (strcmp(func_name, "tty") == 0) {
    return tty_main(argc, argv);
  }
  else if (strcmp(func_name, "uname") == 0) {
    return uname_main(argc, argv);
  }
  else if (strcmp(func_name, "unlink") == 0) {
    return unlink_main(argc, argv);
  }
  else if (strcmp(func_name, "usleep") == 0) {
    return usleep_main(argc, argv);
  }
  else if (strcmp(func_name, "whoami") == 0) {
    return whoami_main(argc, argv);
  }
  else if (strcmp(func_name, "yes") == 0) {
    return yes_main(argc, argv);
  }

  else {
    printf("%s: not a function\n", func_name);
  }
  return 1;
}

int main(int argc, char **argv)
{
  char *func_name = basename(argv[0]);
  if (strncmp(func_name, "multibox", 8) == 0) {
    if (!argv[1]) {
      printf("usage: multibox [function [arguments]...]\n");
    }
    else if (argv[1][0]=='-' && argv[1][1]=='v' && argv[1][2]=='\0') {
      printf("multibox 0.02-zaharchenko\n");
    }
    else {
      func_name = argv[1];
      argv[0] = NULL;
      argv++, argc--;
      return multibox(argc, argv, func_name);
    }
  }
  else {
    return multibox(argc, argv, func_name);
  }
}
