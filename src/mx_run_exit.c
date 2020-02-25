#include "ush.h"

static int get_exit_status(char *com, bool *err) {
    for (char *buf = com; buf; buf++) {
        if (*buf == '+' || *buf == '-')
            continue;

        if(!isdigit(*buf)) {
            *err = true;
            return -1;
        }
    }
    return atoi(com);
}

int mx_run_exit(t_envp **var, char *command) {
    bool err = false;
    int i = get_exit_status(command, &err);

    exit (i);
}
