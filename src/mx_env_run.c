#include "ush.h"

void mx_env_run(t_envp *var, char **com) {
    pid_t pid;
    pid_t wpid;
    int status;
    int pos = 0;

    pid = fork();
    if (pid == 0) {
        // mx_print_var(var, "LANG");
        // mx_printstr(getenv("LANG"));
        // mx_printstr("break\n");
        mx_env_err_handler(com);
        mx_env_flag_i(var, com, &pos);
        mx_env_flag_u(var, com, &pos);
        mx_env_flag_p(var, com, &pos);
        mx_env_flag_equally(var, com, &pos);
        mx_env_modechoose(var, com, &pos);
        printf("pos = %d\n", pos);
        // mx_print_var(var, "LANG");
        // mx_printstr(getenv("PATH"));
        // mx_printstr("after break\n");

        exit (EXIT_SUCCESS);
    }
    wpid = waitpid(pid, &status, WUNTRACED);
}
