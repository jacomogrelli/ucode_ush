#include "ush.h"

void mx_run_cd(char *args) {
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        printf("running cd builtin, %s\n", args);
        exit(EXIT_SUCCESS);
    }
        wpid = waitpid(pid, &status, WUNTRACED);
    // else if (WIFEXITED(status) || WIFSIGNALED(status))
    return;
}
