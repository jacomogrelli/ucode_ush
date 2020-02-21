#include "ush.h"

static char *get_first_com(char *command) {
    char **buf = mx_strsplit(command, ' ');
    for (int i = 1; buf[i]; i++) {
        mx_strdel(&buf[i]);
    }
    return buf[0];
}

void mx_get_command(char *command) {
    char *com = get_first_com(command);
    if (!command)
        return;
    if (!strcmp("cd", com)) {
        mx_run_cd(command + strlen(com));
        return;
    }
    if (!strcmp("export", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("unset", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("fg", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("exit", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("env", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("pwd", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("which", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("echo", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (!strcmp("./ush", com)) {
        printf("command - %s\n", com);
        return;
    }
    else {
        printf("command is unbuiltin\n");
        return;
    }
}
