#include "ush.h"

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

    mx_envp_add (res, data);
}

void mx_envp_add(t_envp **res, char *data) {
    t_envp *buf = NULL;

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
    //заталкиваем в начало
    buf->next = *res;
    *res = buf;
}

t_envp *mx_envp_fill(char **envp) {
    t_envp *res = NULL;

    for (int i = 0; envp[i]; i++) {
        //заполняем принимаемые main переменные среды в свою собственную
        mx_envp_add(&res, envp[i]);
    }
    mx_envp_add(&res, "?=0");
    return res;
}
