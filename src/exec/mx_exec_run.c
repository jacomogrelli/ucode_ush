#include "ush.h"

static void err_helper(char *buf, t_envp *var, int sw, int err) {
    errno = err;

    switch (sw) {
        case 1:
            mx_printerr(buf);
            mx_printerr(": command not found\n");
            mx_envp_replace(&var, "?=127");
            free(buf);
            break;
        case 2:
            perror(buf);
            mx_envp_replace(&var, "?=127");
            free(buf);
            break;
        case 3:
            errno = 21;
            perror(buf);
            mx_envp_replace(&var, "?=126");
            free(buf);
            break;
    }
}

void mx_exec_err_out(char *com, int err, t_envp *var) {
    char *buf = mx_strjoin("ush: ", com);
    errno = err;
    DIR *dp;

    if (err == 2 && mx_get_char_index(com, '/') < 0) {
        err_helper(buf, var, 1, errno);
        return;
    }
    if (err == 2) {
        err_helper(buf, var, 2, errno);
        return;
    }
    if (err == 13 && (dp = opendir(com))) {
        closedir(dp);
        err_helper(buf, var, 3, errno);
        return;
    }
    perror(buf);
    mx_envp_replace(&var, "?=126");
    free(buf);
}

static void sasha_grey(t_envp *var, int status, char *com) {
    switch WEXITSTATUS(status) {
        case 0:
            mx_envp_replace(&var, "?=0");
            break;
        case 1:
            mx_envp_replace(&var, "?=1");
            break;
        default:
            mx_exec_err_out(com, WEXITSTATUS(status), var);
            break;
    }
}

void mx_run_exec(char **com, t_envp *var) {
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);
        if (!getenv("PATH")) {
            if ((execv(com[0], com)) < 0)
                exit (errno);
            exit (EXIT_SUCCESS);
        }
        if ((execvp(com[0], com)) < 0)
            exit (errno);
        exit (EXIT_SUCCESS);
    }
    wpid = waitpid(pid, &status, WUNTRACED);
    tcsetpgrp(0, getpid());
    sasha_grey(var, status, com[0]);
}
