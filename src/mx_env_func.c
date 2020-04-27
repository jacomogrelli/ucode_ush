#include "ush.h"

int mx_env_get_pos(char **com, t_envp *var) {
    char *buf_com[4];
    int res;

    buf_com[0] = "which";
    buf_com[1] = "-s";
    buf_com[3] = NULL;
    for (int i = 1; com[i]; i++) {

        buf_com[2] = com[i];
        mx_which_run(var, buf_com);
        if (!strcmp(getenv("?"), "0"))
            return i;
        res = i;
    }
    return res;
}

void mx_env_err_handler(char **com) {
    for (int i = 0; com[i] && strcmp(com[i], "--") != 0; i++)
        if (com[i][0] == '-')
            for (int j = 1; com[i][j]; j++)
                if (com[i][j] != 'i' && com[i][j] != 'u' && com[i][j] != 'P')
                    mx_env_err_out(com[i][j], 1);
}

void mx_env_err_out(char c, int flag) {
    if (flag == 1) {
        mx_printerr("env: illegal option -- ");
        write(2, &c, 1);
        mx_printerr("\nusage: env [-i] [-P utilpath] [-u name]\n");
        mx_printerr("           [name=value ...] [utility [argument ...]]\n");
        exit(EXIT_FAILURE);
    }
    if (flag == 2) {
        mx_printerr("env: option requires an argument -- P");
        mx_printerr("\nusage: env [-i] [-P utilpath] [-u name]\n");
        mx_printerr("           [name=value ...] [utility [argument ...]]\n");
        exit(EXIT_FAILURE);
    }
}
