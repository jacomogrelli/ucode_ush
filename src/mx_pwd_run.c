#include "ush.h"

static void pwd_default(void) {
    char *res = strdup(getenv("PWD"));

    printf("%s\n", res);
    mx_strdel(&res);
}

static void pwd_flagp(void) {
    char *path = strdup(getenv("PWD"));
    char realbuf[PATH_MAX];
    struct stat buf;

    if (!lstat(path, &buf)) {
        if (MX_ISLNK(buf.st_mode)) {
            char *res = realpath(path, realbuf);
            if (res)
                printf("%s\n", realbuf);
        }
        else {
            printf("%s\n", path);
        }
        mx_strdel(&path);
    }
}

static char err_heandler(t_envp *var, char **com, bool *status) {
    char res = 'L';

    for (int i = 1; com[i] && com[i][0] == '-'; i++)
        for (int j = 0; com[i][j]; j++) {
            if (com[i][j] == '-' && j < 2)
                continue;
            if (com[i][j] != 'P' && com[i][j] != 'L' && strcmp(com[i], "--")) {
                mx_printerr("ush: ");
                if (!isatty(0))
                    mx_printerr("line 1: ");
                mx_printerr("pwd: -");
                write(2, &com[i][j], 1);
                mx_printerr(": invalid option\npwd: usage: pwd [-LP]\n");
                mx_envp_replace(&var, "?=1");
                *status = true;
            }
            res = com[i][j];
        }
    return res;
}

void mx_pwd_run(t_envp *var, char **com) {
    char flag = 'L';

    if (com[1] && com[1][0] == '-') {
        bool status = false;
        flag = err_heandler(var, com, &status);
        if (status)
            return;
    }
    if (flag == 'L')
        pwd_default();
    if (flag == 'P')
        pwd_flagp();
    mx_envp_replace(&var, "?=0");
    return;
}
