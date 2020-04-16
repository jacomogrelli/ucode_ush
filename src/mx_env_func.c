#include "ush.h"

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
