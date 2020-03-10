#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_envp *var = mx_envp_fill(envp);
    // printf("%p\n", (void *)var);
    // for (t_envp *head = var; head; head = head->next) {
    //     printf("%s=", head->name);
    //     printf("%s\n", head->val);
    // }
    // exit(0);
    signal(SIGINT, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGUSR1, SIG_IGN);
    if (argc && argv)
    mx_ush_init(var);
    return 0;
}
