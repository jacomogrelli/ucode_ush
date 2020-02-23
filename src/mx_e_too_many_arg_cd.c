#include "ush.h"

void mx_e_too_many_arg_cd (char **splited_arg, t_errors_cd *errors) {
    int count = 0;

    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count > 2) {
            mx_printerr("cd: too many arguments\n");
            errors->returned_value = 1;
        }
    }
}
