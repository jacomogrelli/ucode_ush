#include "ush.h"

static void mx_which_err(char c, t_envp *var, int flag) {
    if (flag == 1) {
        mx_printerr("which: illegal option -- ");
        write(2, &c, 1);
        mx_printerr("\nusage: which [-as] program ...\n");
        mx_envp_replace(&var, "?=1");
        return;
    }
    if (flag == 2) {
        mx_printerr("usage: which [-as] program ...\n");
        mx_envp_replace(&var, "?=1");
        return;
    }
}

static t_wh *mx_which_res_init(void) {
    t_wh *res = (t_wh *)malloc(sizeof(t_wh));

    res->flags = strdup("00");
    if (getenv("PATH"))
        res->path = mx_strsplit((getenv("PATH")), ':');
    else
        res->path = NULL;
    res->find = NULL;
    res->pos = 1;
    return res;
}
//аудитор
static t_wh *mx_which_get_fp(t_envp *var, char **com, t_wh *res) {
    res = mx_which_res_init();

    if (com[1][0] == '-')
        for (int i = 1; com[i]; i++) {
            res->pos++;
            if (!strcmp(com[i], "--"))
                break;
            for (int j = 0; com[i][j]; j++) {
                if (j == 0 && com[i][j] == '-')
                    continue;
                if (com[i][j] == 'a') {
                    res->flags[0] = '1';
                    continue;
                }
                if (com[i][j] == 's') {
                    res->flags[1] = '1';
                    continue;
                }
                else {
                    mx_which_err(com[i][j], var, 1);
                    res->pos = 0;
                    return res;
                }
            }
        }
    return res;
}

static void mx_which_cleaner(t_envp *var, t_wh *res, int flag) {
    if (res->flags)
        mx_strdel(&res->flags);
    if (res->path)
        mx_del_strarr(&res->path);
    if (res->find)
        for (;res->find; res->find = res->find->next)
            free(res->find->data);
    if (flag == 1)
        mx_envp_replace(&var, "?=1");
    return;
}

static void mx_which_finder(t_envp *var, t_wh *res, char **com) {
    DIR *dirp;
    struct dirent *bf;
    bool aflag;
    if (var)

    for (;com[res->pos]; res->pos++) {
        for (int i = 0; res->path[i]; i++) {
            if((dirp = opendir(res->path[i]))) {
                while ((bf = readdir(dirp))) {
                    if (!(strcmp(bf->d_name, com[res->pos]))) {
                        if ()
                        printf("%s/%s\n", res->path[i], com[res->pos]);
                    }
                }
            }
        }
    }
    mx_printlist(res->find);
}


void mx_which_run(t_envp *var, char **com) {
    t_wh *res = NULL;

    if (!com[1]) {
        mx_which_err('c', var, 2);
        return;
    }
    res = mx_which_get_fp(var, com, res);
    if (!res->pos || !res->path) {
        mx_which_cleaner(var, res, 1);
        return;
    }
    mx_which_finder(var, res, com);
}


//PATH=/Users/onechaiev/.brew/bin:/usr/local/bin: \
/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/onechaiev/.brew/bin
