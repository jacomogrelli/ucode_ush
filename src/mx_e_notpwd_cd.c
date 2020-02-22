#include "ush.h"

void mx_e_notpwd_cd(char **splited_arg) {
    int count = 0;
    char *env_str = getenv("PWD");

    while (splited_arg[count]) {
        count++;
    }
    if (count == 2) {
        if (!strstr(env_str, splited_arg[0])) {
            mx_printerr("cd: string not in pwd: ");
            mx_printerr(splited_arg[0]);
            mx_printerr("\n");
            exit(1);
        }
    }
}
