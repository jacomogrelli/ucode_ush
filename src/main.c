#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_envp *var = mx_envp_fill(envp);
    // mx_envp_replace(&var, "?=1");
    //     while (var) {
    //     printf("%s", var->name);
    //     printf("=%s\n", var->val);
    //     var = var->next;
    // }
    if (argc && argv && envp)


    mx_ush_init(var);

    return 0;
}
