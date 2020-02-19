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
    printf("%d\n", strcmp("cd", com));
    if (!strcmp("cd", com)) {
        printf("command - %s\n", com);
        return;
    }
    if (strcmp("export", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("unset", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("fg", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("exit", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("env", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("pwd", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("which", com) == 0)
        printf("command - %s\n", com);
    if (strcmp("echo", com) == 0)
        printf("command - %s\n", com);
    else
        printf("command is unbuiltin\n");
}
