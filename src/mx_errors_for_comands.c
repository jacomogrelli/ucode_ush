#include "ush.h"

void mx_errors_for_comands(char **splited_input) {
    t_errors_cd *errors = (t_errors_cd *)malloc(sizeof(t_errors_cd));
    errors->returned_value = 0;
    if (mx_strcmp(splited_input[0], "cd") == 0)
        mx_errors_cd(splited_input, errors);
}
