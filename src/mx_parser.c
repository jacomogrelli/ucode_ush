#include "ush.h"

void mx_parser_cleaner(t_comm **res) {
    t_comm *head = *res;

    while (head) {
        if (head->com)
            mx_del_strarr(&head->com);
        head = head->next;
    }
    free((*res));
}

void mx_parser(char *line, t_comm **res, char c, t_envp *var) {
    t_comm *ptr = *res;

    if (ptr) {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = (t_comm *)malloc(sizeof(t_comm));
        ptr->next->com = mx_strsplit(line, ' '); //ЗАМЕНИТЬ НА ДАЛЬНЕЙШИЙ ПАРСЕР
        ptr->next->logic = c;
        ptr->next->next = NULL;
    }
    else {
        (*res) = (t_comm *)malloc(sizeof(t_comm));
        (*res)->com = mx_strsplit(line, ' '); //ЗАМЕНИТЬ НА ДАЛЬНЕЙШИЙ ПАРСЕР
        (*res)->logic = c;
        (*res)->next = NULL;
    }
    if (var)
    free(line);
}

void mx_parser_line(char *line, t_comm **res, t_envp *var) {
    int count = 0;

    for (int i = 0; line[i]; i++, count++) {
        if ((line[i] == '&' && line[i + 1] == '&')
            || (line[i] == '|' && line[i + 1] == '|')) {
            mx_parser(strndup(line + i - count, count), res, line[i], var);
            count = 0;
            i += 2;
        }
        if (line[i + 1] == '\0') {
            mx_parser(strndup(line + i - count, count + 1), res, line[i], var);
            break;
        }
    }
}
