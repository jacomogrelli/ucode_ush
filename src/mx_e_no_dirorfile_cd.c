#include "ush.h"

void mx_e_no_dirorfile_cd (char **splited_arg, t_errors_cd *errors) {
    int count = 0;

    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count == 1) {
            if (mx_dirorfile(splited_arg[0]) == -1) {
                mx_printerr("cd: no such file or directory: ");
                mx_printerr(splited_arg[0]);
                mx_printerr("\n");
                errors->returned_value = 1;
            }
            else if (mx_dirorfile(splited_arg[0]) == 1) {
                mx_printerr("cd: not a directory: ");
                mx_printerr(splited_arg[0]);
                mx_printerr("\n");
                errors->returned_value = 1;
            }
        }
    }
}
