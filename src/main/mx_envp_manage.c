#include "ush.h"

void mx_envp_shlvl(t_envp *var) {
    int cur = atoi(getenv("SHLVL")) + 1;
    char *buf = mx_itoa(cur);
    char *buf2 = mx_strjoin("SHLVL=", buf);

    setenv("SHLVL", buf, 1);
    mx_envp_replace(&var, buf2);
    mx_strdel(&buf);
    mx_strdel(&buf2);
}
