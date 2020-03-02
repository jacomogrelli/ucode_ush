#include "ush.h"

static int get_flag_pos(t_envp *var, char **com, int *flags) {
    int pos = 1;
    if (*flags)

    if (com[1][0] == '-') {
        pos = 2;
        for (int i = 1; com[i]; i++) {
            for (int j = 0; com[i][j]; j++) {
                if (j == 1 && com[i][j] == '-' && com[i][j + 1]) {
                    mx_printerr("which: illegal option --");
                    write(2, &com[i][j], 1);
                    mx_printerr("\nwhich [-as] program ...\n");
                    mx_envp_replace(&var, "?=1");
                }
            }
        }
    }
    return pos;
}

void mx_which_run(t_envp *var, char **com) {
    char *path = strdup(getenv("PATH"));
    int flags = 0; //0 без флагов, 1 - а, 2 - s, 3 - оба
    int pos;

    if (!path) {
        mx_envp_replace(&var, "?=1");
        return;
    }
    pos = get_flag_pos(var, com, &flags);
}


//PATH=/Users/onechaiev/.brew/bin:/usr/local/bin: \
/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/onechaiev/.brew/bin
