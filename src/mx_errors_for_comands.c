#include "ush.h"

char **mx_errors_for_comands(char **splited_input, t_flags_cd *flags_cd,
                             t_errors_cd *errors) {
    errors->returned_value = 0;
    char **splited_arg = NULL;

    if (mx_strcmp(splited_input[0], "cd") == 0)
        splited_arg = mx_errors_cd(splited_input, errors, flags_cd);
    return splited_arg;
}
