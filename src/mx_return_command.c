#include "ush.h"

int count_args(char **com) {
    int res = 0;

    while (com[res]) {
        res++;
    }
    return res;
}

void mx_return_command(t_envp *var, char **com) {
    int count = count_args(com);
    char *repl_return = NULL;
    if (count > 2)
        mx_printerr("return: too many arguments\n");
    else if (com[1]) {
        if (mx_atoi(com[1]) != 0) {
            repl_return = mx_strjoin("?=", com[1]);
            mx_envp_replace(&var, repl_return);
            free(repl_return);
        }
    }
}
