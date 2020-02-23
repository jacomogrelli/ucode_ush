#include "ush.h"

void mx_e_notpwd_cd(char **splited_arg, t_errors_cd *errors) {
    int count = 0;
    char *env_str = getenv("PWD");

    if (errors->returned_value == 0) {
        while (splited_arg[count]) {
            count++;
        }
        if (count == 2) {
            if (!strstr(env_str, splited_arg[0])) {
                mx_printerr("cd: string not in pwd: ");
                mx_printerr(splited_arg[0]);
                mx_printerr("\n");
                errors->returned_value = 1;
            }
        }
    }
}
