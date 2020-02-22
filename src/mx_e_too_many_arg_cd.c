#include "ush.h"

void mx_e_too_many_arg_cd (char **splited_arg) {
    int count = 0;

    while (splited_arg[count]) {
        count++;
    }
    if (count > 2) {
        mx_printerr("cd: too many arguments\n");
        exit(1);
    }
}
