#include "ush.h"

int main(int argc, char **argv) {
  char *input_line;
  size_t bufsize = 0;
  t_errors_cd *errors = (t_errors_cd *)malloc(sizeof(t_errors_cd));
  errors->returned_value = 0;

// TEST INPUT
  char **test_input;
  test_input = (char **)malloc(sizeof(char*) * 3);
  for (int i = 0; i < 4; i++){
    test_input[i] = mx_strnew(50);
  }
  test_input[0] = mx_strcpy(test_input[0], "cd");
  test_input[1] = mx_strcpy(test_input[1], "/");
  test_input[2] = mx_strcpy(test_input[2], ".");
  test_input[3] = NULL;
//
  while (true) {
    printf("%s", "u$h>");
    getline(&input_line, &bufsize, stdin);
    mx_errors_for_comands(test_input, errors);
  //free_test_mem
  for (int i = 0; i < 3; i++){
      free(test_input[i]);
    }
    free(test_input);
  //free_test_mem
    system("leaks -q ush");
  }
  argc = 0;
  argv = NULL;
  return errors->returned_value;
}
