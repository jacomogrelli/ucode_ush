#include "ush.h"

int main(int argc, char **argv) {
  char *input_line;
  size_t bufsize = 0;

  while (true) {
    printf("%s", "u$h>");
    getline(&input_line, &bufsize, stdin);
    mx_errors_cd(input_line);
    system("leaks -q ush");
  }
  argc = 0;
  argv = NULL;
  return 0;
}
