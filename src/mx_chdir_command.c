#include "ush.h"

static int count_arg(char **com) {
    int count = 0;

    while (com[count]) {
        count++;
    }
    return count;
}

void mx_chdir_command(t_envp *var, char** com) {
    int count = count_arg(com);

    if (count > 2) {
        mx_printerr("chdir: too many arguments\n");
        mx_envp_replace(&var, "?=1");
    }
    else {
        if (!com[1])
            chdir(getenv("HOME"));
        else {
            if (mx_dirorfile(com[1]) != 0) {
                mx_printerr("chdir: no such file or directory: ");
                mx_printerr(com[1]);
                mx_printerr("\n");
                mx_envp_replace(&var, "?=1");
            }
            else {
                chdir(com[1]);
                setenv("OLDPWD", getenv("PWD"), 1);
                setenv("PWD", com[1], 1);
                mx_envp_replace(&var, "?=0");
            }
        }
    }
}
