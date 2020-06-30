#include "ush.h"

void mx_arch_command(t_envp *var, char** com) {
    if (com[1]) {
        mx_printerr("arch: Can't find ");
        mx_printerr(com[1]);
        mx_printerr(" in PATH\n");
        mx_envp_replace(&var, "?=1");
    }
    else {
        printf("%s\n", "i386");
        mx_envp_replace(&var, "?=0");
    }
}
