#include "ush.h"

static int get_question_mark (t_envp *var) {
    t_envp *head = var;

    while (head) {
        if (head->name[0] == '?' && head->name[1] == '\0')
            return atoi(head->val);
        head = head->next;
    }
    return 0;
}

static int get_exit_status(char **com, int count, bool *err, t_envp *var) {
    if (count == 1)
        return get_question_mark(var);
    if (count != 1) {
        for (int i = 0; com[1][i]; i++) {
            if (com[1][0] == '+' || com[1][0] == '-')
                continue;
            if (!isdigit(com[1][i])) {
                *err = true;
                return -1;
            }
        }
        if (count == 2)
            return atoi(com[1]);
    }
        *err = true;
        return 1;
}

static void exit_err(char *com, int flag) {
    switch (flag) {
        case 1:
            if (isatty(0))
                mx_printstr("exit\n");
            mx_printerr("ush: ");
            if (!isatty(0))
                mx_printerr("line 1: ");
            mx_printerr("exit: too many arguments\n");
            break;
        default:
            if (isatty(0))
                mx_printstr("exit\n");
            mx_printerr("ush: ");
            if (!isatty(0))
                mx_printerr("line 1: ");
            mx_printerr("exit: ");
            mx_printerr(com);
            mx_printerr(": numeric argument required\n");
            break;
    }
}

void mx_run_exit(t_envp *var, char **command) {
    bool err = false;
    int count = 0;

     while (command[count])
        count++;
    int i = get_exit_status(command, count, &err, var);
    if (count != 1 && err && i != -1) {
        mx_envp_replace(&var, "?=1");
        exit_err(command[1], 1);
        return;
    }
    if (i == -1 && err) {
        exit_err(command[1], 2);
        exit (-1);
    }
    if (isatty(0))
        mx_printstr("exit\n");
    exit (i);
}
