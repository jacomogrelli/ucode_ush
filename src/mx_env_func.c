#include "ush.h"

static void env_usage_err(char c, int flag) {
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

void mx_env_getp(t_nv *res, char **com) {
    for (int i = 1; com[i] && strcmp(com[i], "--"); i++) {
        if (com[i][0] == '-')
            for (int j = 1; com[i][j]; j++) {
                if (com[i][j] != 'i' && com[i][j] != 'u' && com[i][j] != 'P')
                    env_usage_err(com[i][j], 1);
                if (com[i][j] == 'P') {
                    res->p = 1;
                    if (!com[i + 1])
                        env_usage_err(com[i][j], 2);
                }
            }
    }
}

static t_nv *nv_init(void) {
    t_nv *res = malloc(sizeof(t_nv));

    res->i = 0;
    res->u = 0;
    res->p = 0;
    res->exp = NULL;
    res->path = NULL;
    res->unset = NULL;
    return res;
}

void mx_env_func(t_envp *var, char **com) {
    t_nv *res = nv_init();

    if (var || com || res)
    mx_env_getp(res, com);
    return;
}
