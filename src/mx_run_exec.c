#include "ush.h"

void mx_run_exec(char **com) {
    pid_t pid;
    pid_t wpid;
    int status;
    // char *ret_val = NULL;

    pid = fork();
    if (pid == 0) {
        if ((execvp(com[0], com)) < 0) {
            mx_exec_err_out(com[0], errno);
            exit (errno);
        }
        // ret_val = strdup(getenv("?"));
        exit (EXIT_SUCCESS);
    }
    wpid = waitpid(pid, &status, WUNTRACED);
    // printf("exit status %d\n", status);
    // printf("exit status %d\n", WIFEXITED(status));
    printf("exit status %d\n", WEXITSTATUS(status));
    // printf("exit status %d\n", WIFSIGNALED(status));
    // printf("exit status %d\n", WTERMSIG(status));
    // printf("exit status %d\n", WIFSTOPPED(status));
    // printf("exit status %d\n", WSTOPSIG(status));
}
