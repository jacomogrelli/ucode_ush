#include "ush.h"

void mx_e_notpwd_cd(char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd) {
    int count = 0;
    char *env_str = getenv("PWD");
    int count_args = 0;
    int which_arg = 2;

    if (flags_cd->act_flag == true) {
        count_args = 1;
        which_arg = 3;
    }
    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count == which_arg) {
            if (!strstr(env_str, splited_arg[count_args])) {
                mx_printerr("cd: string not in pwd: ");
                mx_printerr(splited_arg[count_args]);
                mx_printerr("\n");
                errors->returned_value = 1;
            }
        }
    }
}
