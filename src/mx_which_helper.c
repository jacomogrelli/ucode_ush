#include "ush.h"

void mx_which_cleaner(t_envp *var, t_wh *res, int flag) {
    if (res->flags)
        mx_strdel(&res->flags);
    if (res->path)
        mx_del_strarr(&res->path);
    if (res->find)
        for (;res->find; res->find = res->find->next) {
            free(res->find->name);
            free(res->find->val);
        }
    if (flag == 1)
        mx_envp_replace(&var, "?=1");
    return;
}

void mx_which_add_back(t_envp **res, char *name, char *val) {
    t_envp *buf = NULL;
    t_envp *head = *res;

    //создаем ноду
    buf = malloc(sizeof(t_envp));
    buf->name = strdup(name);
    buf->val = strdup(val);
    buf->next = NULL;
    //проверка на пустую структуру
    if (!*res) {
        *res = buf;
        return;
    }
    //заталкиваем в конец
    while (head->next) {
        head = head->next;
    }
    head->next = buf;
}

void mx_which_err(char c, t_envp *var, int flag) {
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

t_wh *mx_which_res_init(void) {
    t_wh *res = (t_wh *)malloc(sizeof(t_wh));

    res->flags = strdup("00");
    if (getenv("PATH"))
        res->path = mx_strsplit((getenv("PATH")), ':');
    else
        res->path = NULL;
    res->find = NULL;
    res->pos = 1;
    res->key_s = false;
    return res;
}
