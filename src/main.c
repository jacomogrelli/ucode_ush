#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_envp *var = mx_envp_fill(envp);

    for (t_envp *head = var; head; head = head->next) {
        printf("%s=", head->name);
        printf("%s\n", head->val);
    }
    exit (0);

    if (argc && argv && envp)
    mx_ush_init(var);
    return 0;
}
