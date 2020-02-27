#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_envp *var = mx_envp_fill(envp);

    if (argc && argv && envp)
    mx_ush_init(var);
    return 0;
}
