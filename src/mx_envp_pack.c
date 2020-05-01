#include "ush.h"

static void envp_data_switch(t_envp *i, t_envp *j) {
    t_envp *buf = malloc(sizeof(t_envp));

    buf->name = strdup(i->name);
    mx_strdel(&i->name);
    buf->val = strdup(i->val);
    mx_strdel(&i->name);
    i->name = strdup(j->name);
    mx_strdel(&j->name);
    i->val = strdup(j->val);
    mx_strdel(&j->name);
    j->name = strdup(buf->name);
    mx_strdel(&buf->name);
    j->val = strdup(buf->val);
    mx_strdel(&buf->name);
    free(buf);
}

t_envp *mx_envp_sort(t_envp *var) {
    if (!var)
        return NULL;
    for (t_envp *i = var; i->next; i = i->next)
        for (t_envp *j = i->next; j; j = j->next)
            if (strcmp(i->name, j->name) > 0)
                envp_data_switch(i, j);
    return var;
}

void mx_envp_replace(t_envp **res, char *data) {
    t_envp *head = *res;
    //копируем имя переменной
    char *buf_name = strndup(data, mx_get_char_index(data, '='));
    //ищем, есть ли в нашей структуре такая
    while (head) {

        if (!strcmp(head->name, buf_name)) {
            //если нашли, удаляем старое значение и заталкиваем новое
            mx_strdel(&head->val);
            head->val = strndup(data + mx_get_char_index(data, '=') + 1,
                                strlen(data) - mx_get_char_index(data, '='));
            //удаляем буфер от ликов
            mx_strdel(&buf_name);
            return;
        }
        head = head->next;
    }
    //если не нашли, удаляем буфер от ликов и заталкиваем в начало.
    mx_strdel(&buf_name);
    mx_envp_add(res, data);
}

void mx_envp_add(t_envp **res, char *data) {
    t_envp *buf = NULL;
    t_envp *head = *res;

    if (!data)
        return;
    //создаем ноду
    buf = malloc(sizeof(t_envp));
    buf->name = strndup(data, mx_get_char_index(data, '='));
    buf->val = strndup(data + mx_get_char_index(data, '=') + 1,
                           strlen(data) - mx_get_char_index(data, '='));
    buf->next = NULL;
    //проверка на пустую структуру
    if (!*res) {
        *res = buf;
        return;
    }
    while (head->next) {
        head = head->next;
    }
    head->next = buf;
}

t_envp *mx_envp_fill(char **envp) {
    t_envp *res = mx_envp_i_fill();

    for (int i = 0; envp[i]; i++) {
        //заполняем принимаемые main переменные среды в свою собственную
        mx_envp_add(&res, envp[i]);
    }
    mx_envp_add(&res, "?=0");
    return res;
}
