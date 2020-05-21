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

static void error_one(t_envp *var) {
        mx_printerr("usage: apropos keyword ...\n");
        mx_envp_replace(&var, "?=1");
}

static int main_llop_apropos(char **com, char **comms, bool find, int count) {
    for (int i = 1; com[i]; i++) {
        find = false;
        for(int j = 0; comms[j]; j++)
            if (mx_strcmp(com[i], comms[j]) == 0) {
                print_inside_apropos(j, comms);
                count++;
                find = true;
            }
        if (!find) {
            printf("%s ", com[i]);
            printf("%s ", ": nothing appropriate\n");
        }
    }
    return count;
}

void mx_apropos_command(t_envp *var, char **com) {
    int count = 0;
    bool find = false;
    char *commands[] = {"env", "export", "set", "unset", "pwd", "exit", "cd",
                   "which", "echo", "true", "false", "help", "return",
                   "chdir", "apropos", "arch", NULL};
    if (com[0] && !com[1]) {
        error_one(var);
        count++;
    }
    else {
        count = main_llop_apropos(com, commands, find, count);
    }
    change_returned(var, count);
}
