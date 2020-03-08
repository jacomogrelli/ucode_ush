#include "ush.h"

void mx_get_command(t_envp *var, char **com) {
    char *bin[] = {"set", "unset", "pwd", "exit", "cd", "which", "echo", NULL};
    void (*builtin_func[])() = {&mx_set_run,
                                &mx_unset_run,
                                &mx_pwd_run,
                                &mx_run_exit,
                                &mx_run_cd_commnd,
                                &mx_which_run,
                                &mx_run_echo_command};
    for (int i = 0; bin[i]; i++) {
        if (!strcmp(com[0], bin[i])) {
            (*builtin_func[i])(var, com);
            return;
        }
    }
    mx_run_exec(com, var);
    return;
}
