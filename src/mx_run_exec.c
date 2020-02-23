#include "ush.h"

void mx_run_exec(char **com) {
    // char *comm[] = {"/bin/lsu", "-laz", "libmx", NULL};
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if ((execvp(com[0], com)) < 0) {
            mx_exec_err_out(com[0], errno);
            exit (errno);
        }
        exit (EXIT_SUCCESS);
    }
    wpid = waitpid(pid, &status, WUNTRACED);
}
