#include "ush.h"

static void change_returned(t_envp *var, int trigger) {
    if (trigger > 0)
        mx_envp_replace(&var, "?=0");
    else
        mx_envp_replace(&var, "?=1");
}

static void print_inside_apropos(int j, char **commands) {
    printf("%s ", commands[j]);
    printf("%s\n", "      - analog bash-3.2 command");
}

void mx_apropos_command(t_envp *var, char **com) {
    int count = 0;
    bool find = false;
    char *commands[] = {"env", "export", "set", "unset", "pwd", "exit", "cd",
                   "which", "echo", "true", "false", "help", "return",
                   "chdir", "apropos", "arch", NULL};
    if (com[0] && !com[1]) {
        mx_printerr("usage: apropos keyword ...\n");
        count++;
        mx_envp_replace(&var, "?=1");
    }
    else {
        for (int i = 1; com[i]; i++) {
            find = false;
            for(int j = 0; commands[j]; j++)
                if (mx_strcmp(com[i], commands[j]) == 0) {
                    print_inside_apropos(j, commands);
                    count++;
                    find = true;
                }
            if (!find) {
                printf("%s ", com[i]);
                printf("%s ", ": nothing appropriate\n");
            }
        }
    }
    change_returned(var, count);
}
