#include "ush.h"

t_ush_init *mx_ush_struct_init() {
    t_ush_init *res = malloc(sizeof(t_ush_init));

    res->bufsize = 1;
    res->iline = malloc(sizeof (char) * (int)res->bufsize);
    res->com = NULL;
    res->i = 0;
    res->argv = NULL;
    return res;
}

void mx_ush_rescleaner(t_ush_init **res) {
    t_ush_init *head = *res;

    mx_del_strarr(&(head->com));
    if (head->iline)
        free(head->iline);
    if (*res) {
        free((*res));
        (*res) = mx_ush_struct_init();
    }
}
