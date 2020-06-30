#include "ush.h"

static void change_returned(t_envp *var, int trigger) {
    if (trigger > 0)
        mx_envp_replace(&var, "?=0");
    else
        mx_envp_replace(&var, "?=1");
}

static void print_inside_help(char **com, int i, char **commands, int j) {
    printf("%s ", com[i]);
    printf("%s", ": ");
    printf("%s\n", commands[j]);
    printf("%s", "    ");
    printf("\"%s ", commands[j]);
    printf("%s\"\n", "analog bash-3.2 command");
}

void mx_help_command(t_envp *var, char **com) {
    int count = 0;
    bool find = false;
    char *commands[] = {"env", "export", "set", "unset", "pwd", "exit", "cd",
                   "which", "echo", "true", "false", "help", "return",
                   "chdir", "apropos", "arch", NULL};
    if (com[0] && !com[1]) {
        printf("This is bash analog program!\nTo wiew other commands type:\
help [command].\n");
        count++;
        mx_envp_replace(&var, "?=0");
    }
    else {
        for (int i = 1; com[i]; i++) {
            find = false;
            for(int j = 0; commands[j]; j++)
                if (mx_strcmp(com[i], commands[j]) == 0) {
                    print_inside_help(com, i, commands, j);
                    count++;
                    find = true;
                }
            if (!find) {
                printf("%s ", "U$h: help: no help topics match");
                printf("%s\n", com[i]);
            }
        }
    }
    change_returned(var, count);
}
