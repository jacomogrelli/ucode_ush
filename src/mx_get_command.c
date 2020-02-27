#include "ush.h"

void mx_get_command(t_envp **var, char **com) {

    if (!com)
        return;
    if (!strcmp("cd", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("export", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("unset", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("fg", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("exit", com[0])) {
        mx_run_exit(var, com);
        return;
    }
    if (!strcmp("env", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("pwd", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("which", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("echo", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    if (!strcmp("./ush", com[0])) {
        printf("command - %s\n", com[0]);
        return;
    }
    else {
        mx_run_exec(com, var);
        return;
    }
}
