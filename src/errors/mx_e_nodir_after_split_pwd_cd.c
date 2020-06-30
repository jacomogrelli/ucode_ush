#include "ush.h"

static void print_errors(char *res_str, t_errors_cd *errors) {
    if (mx_dirorfile(res_str) == -1) {
        mx_printerr("cd: no such file or directory: " );
        mx_printerr(res_str);
        mx_printerr("\n");
        errors->returned_value = 1;
    }
    else {
        opendir(res_str);
        if (errno == 13) {
            mx_printerr("cd: permission denied:" );
            mx_printerr(res_str);
            mx_printerr("\n");
            errors->returned_value = 1;
        }
    }
}

void mx_e_nodir_after_split_pwd_cd(char **splited_arg, t_errors_cd *errors,
                                   t_flags_cd *flags_cd) {
    int count = 0;
    char *res_str = NULL;
    int count_arg = 2;
    int which_arg = 0;
    errno = 0;

    if (flags_cd->act_flag == true) {
        count_arg = 3;
        which_arg = 1;
    }
    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count == count_arg) {
            res_str = mx_my_repl_substr_cd(splited_arg[which_arg],
                                           splited_arg[which_arg + 1]);
            print_errors(res_str, errors);
            free(res_str);
        }
    }
}
