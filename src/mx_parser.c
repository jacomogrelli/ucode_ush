#include "ush.h"

void mx_parser_splitter(char *line, t_comm **res, char c) {
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
}

void mx_parser_line(char *line, t_comm **res) {
    int count = 0;

    for (int i = 0; line[i]; i++, count++) {
        if ((line[i] == '&' && line[i + 1] == '&')
            || (line[i] == '|' && line[i + 1] == '|')
            || i == mx_strlen(line)) {
            mx_parser_splitter(strndup(line + i - count, count),
                                      res, line[i]);
            count = 0;
            i += 2;
        }
    }
}

void mx_parser(char *line, t_comm **res) {
    mx_parser_line(line, res);
}
