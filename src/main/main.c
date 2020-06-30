#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_envp *var = mx_envp_fill(envp);

    signal(SIGINT, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGUSR1, SIG_IGN);
    if (argc && argv)
    mx_ush_init(var);
    return 0;
}
