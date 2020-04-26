#include "ush.h"

void mx_env_modechoose(t_envp *var, char **com,int *pos) {
    int com_count = 0;
    char **com_new = NULL;

    if (!com[(*pos)]) {
        mx_env_main_empty();
        return;
    }
    var = mx_envp_i_fill();
    for (;com[(*pos)]; (*pos)++, com_count++);
    (*pos) -= com_count;
    com_new = malloc(sizeof(char *) * com_count);
    for (int i = 0; i < com_count; i++, (*pos)++)
        com_new[i] = strdup(com[(*pos)]);
    com_new[com_count] = NULL;
    mx_run_exec(com_new, var);
}

void mx_env_main_empty(void) {
    extern char **environ;

    if (!environ[0])
        return;
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
}
