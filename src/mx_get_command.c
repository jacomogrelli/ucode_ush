#include "ush.h"


void mx_get_command(t_envp *var, char **com) {
    char *bin[] = {"pwd", "exit", "cd", NULL};
    void (*builtin_func[])() = {&mx_pwd_run, &mx_run_exit, &mx_run_cd_commnd};

    for (int i = 0; bin[i]; i++) {
        if (!strcmp(com[0], bin[i])) {
            (*builtin_func[i])(var, com);
            return;
        }
    }
    mx_run_exec(com, var);
    return;
}
