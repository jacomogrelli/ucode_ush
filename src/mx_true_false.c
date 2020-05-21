#include "ush.h"

void mx_call_true(t_envp *var) {
    mx_envp_replace(&var, "?=1");
}

void mx_call_false(t_envp *var) {
    mx_envp_replace(&var,"?=0");
}
