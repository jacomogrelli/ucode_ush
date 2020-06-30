#include "ush.h"

void mx_get_command(t_envp *var, char **com) {
    char *bin[] = {"env", "export", "set", "unset", "pwd", "exit", "cd",
                   "which", "echo", "true", "false", "help", "return",
                   "chdir", "apropos", "arch", NULL};
    void (*bin_f[])() = {&mx_env_run, &mx_export_run, &mx_set_run,
                         &mx_unset_run, &mx_pwd_run, &mx_run_exit,
                         &mx_run_cd_commnd, &mx_which_run,
                         &mx_run_echo_command, &mx_call_true, &mx_call_false,
                         &mx_help_command, &mx_return_command,
                         &mx_chdir_command, &mx_apropos_command,
                         &mx_arch_command};

    for (int i = 0; bin[i]; i++)
        if (!strcmp(com[0], bin[i])) {
            (*bin_f[i])(var, com);
            return;
        }
    mx_run_exec(com, var);
}
