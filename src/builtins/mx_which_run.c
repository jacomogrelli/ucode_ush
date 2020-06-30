#include "ush.h"

t_wh *mx_which_get_fp(t_envp *var, char **com, t_wh *res) {
    res = mx_which_res_init();

    for (int i = 1; com[i] && com[i][0] == '-'; i++) {
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

void mx_which_out(t_envp *var, t_wh *res, char **com) {
    t_envp *head = res->find;

    for (; com[res->pos]; res->pos++) {
        if (!res->find && res->flags[1] == '0')
            printf("%s not found\n", com[res->pos]);
        for (;res->find; res->find = res->find->next) {
            if (!strcmp(com[res->pos], res->find->name)) {
                if (res->flags[1] != '1')
                    printf("%s\n", res->find->val);
                if (res->flags[0] == '0' || !res->find->next)
                    break;
            }
            if (!res->find->next) {
                res->key_s = false;
                if (res->flags[1] == '0')
                    printf("%s not found\n", com[res->pos]);
            }
        }
        res->find = head;
    }
    res->find = head;
    if (!res->key_s)
        mx_envp_replace(&var, "?=1");
    else
        mx_envp_replace(&var, "?=0");
}

void mx_which_bin_finder(t_envp *var, t_wh *res, char **com) {
    char *bin[] = {"env", "export", "set", "unset", "pwd", "exit", "cd",
                   "which", "echo", "true", "false", "help", "return",
                   "chdir", "apropos", "arch", NULL};
    int ind = res->pos;

    if (var)
    for (;com[ind]; ind++)
        for (int i = 0; bin[i]; i++)
            if (!strcmp(com[ind], bin[i])) {
                res->key_s = true;
                mx_which_add_back(&(res->find), com[ind], mx_strjoin(com[ind],
                                  ": shell built-in command"));
            }
}

void mx_which_finder(t_envp *var, t_wh *res, char **com) {
    DIR *dirp;
    struct dirent *bf;
    int ind = res->pos;

    for (;com[ind]; ind++) {
        if (!res->key_s)
            res->key_s = false;
        for (int i = 0; res->path[i]; i++)
            if((dirp = opendir(res->path[i]))) {
                while ((bf = readdir(dirp)))
                    if (!(strcmp(bf->d_name, com[ind]))) {
                        res->key_s = true;
                        char *buf = mx_strjoin(res->path[i], "/");
                        mx_which_add_back(&res->find,
                                          com[ind],
                                          mx_strjoin(buf, com[ind]));
                        mx_strdel(&buf);
                    }
                closedir(dirp);
            }
    }
    mx_which_out(var, res, com);
}

void mx_which_run(t_envp *var, char **com) {
    t_wh *res = NULL;

    if (!com[1]) {
        mx_which_err('c', var, 2);
        return;
    }
    res = mx_which_get_fp(var, com, res);
    if (!res->pos || !res->path || !com[res->pos]) {
        if (!com[res->pos])
            mx_which_err('c', var, 2);
        mx_which_cleaner(var, res, 1);
        return;
    }
    mx_which_bin_finder(var, res, com);
    mx_which_finder(var, res, com);
    mx_which_cleaner(var, res, 0);
}
