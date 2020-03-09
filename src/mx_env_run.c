#include "ush.h"

void mx_env_run(t_envp *var, char **com) {
    // pid_t pid;
    // pid_t wpid;
    // int status;

    // pid = fork();
    // if (pid == 0) {
    //     mx_env_func(var, com);
    // }
    // wpid = waitpid(pid, &status, WUNTRACED);
    mx_run_exec(com, var);
}
