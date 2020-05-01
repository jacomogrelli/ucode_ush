#include "ush.h"

static void get_command(t_envp *var, char **com) {
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
    var = mx_envp_i_fill();
    mx_run_exec(com, var);
}

void mx_env_modechoose(t_envp *var, char **com,int *pos) {
    int com_count = 0;
    char **com_new = NULL;

    if (!com[(*pos)]) {
        mx_env_main_empty();
        return;
    }
    for (;com[(*pos)]; (*pos)++, com_count++);
    (*pos) -= com_count;
    com_new = malloc(sizeof(char *) * com_count);
    for (int i = 0; i < com_count; i++, (*pos)++)
        com_new[i] = strdup(com[(*pos)]);
    com_new[com_count] = NULL;
    get_command(var, com_new);
}

void mx_env_main_empty(void) {
    extern char **environ;

    if (!environ[0])
        return;
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
}
