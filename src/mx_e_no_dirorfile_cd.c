#include "ush.h"

static void printf_no_file_or_dir(char **splited_arg, t_errors_cd *errors) {
    mx_printerr("cd: no such file or directory: ");
    mx_printerr(splited_arg[0]);
    mx_printerr("\n");
    errors->returned_value = 1;
}

static void not_a_dir(char **splited_arg, t_errors_cd *errors) {
    mx_printerr("cd: not a directory: ");
    mx_printerr(splited_arg[0]);
    mx_printerr("\n");
    errors->returned_value = 1;
}

static void prem_denied(char **splited_arg, t_errors_cd *errors) {
    opendir(splited_arg[0]);
    if (errno == 13) {
        mx_printerr("cd: permission denied: ");
        mx_printerr(splited_arg[0]);
        mx_printerr("\n");
        errors->returned_value = 1;
    }
}

void mx_e_no_dirorfile_cd (char **splited_arg, t_errors_cd *errors,
                           t_flags_cd *flags_cd) {
    int count = 0;
    errno = 0;

    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count == 1) {
            if (flags_cd->act_flag == false) {
                if (mx_dirorfile(splited_arg[0]) == -1) {
                    printf_no_file_or_dir(splited_arg, errors);
                }
                else if (mx_dirorfile(splited_arg[0]) == 1) {
                    not_a_dir(splited_arg, errors);
                }
                else {
                    prem_denied(splited_arg, errors);
                }
            }
        }
    }
}
