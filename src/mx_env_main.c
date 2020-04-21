#include "ush.h"

void mx_env_modechoose(t_envp *var, char **com,int *pos) {
    if (var)
    if (!com[(*pos)] || (*pos) == 0) {
        mx_env_main_empty();
        return;
    }
}

void mx_env_main_empty(void) {
    extern char **environ;

    if (!environ[0])
        return;
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
}
