#include "ush.h"

void mx_e_nodir_after_split_pwd_cd(char **splited_arg, t_errors_cd *errors) {
    int count = 0;
    char *res_str = NULL;
    if (errors->returned_value == 0) {
        
        while (splited_arg[count]) {
            count++;
        }
        if (count == 2) {
            res_str = mx_my_repl_substr_cd(splited_arg[0], splited_arg[1]);
            if (mx_dirorfile(res_str) == -1) {
                mx_printerr("cd: no such file or directory: " );
                mx_printerr(res_str);
                mx_printerr("\n");
                errors->returned_value = 1;
            }
            free(res_str);
        }
    }
}
