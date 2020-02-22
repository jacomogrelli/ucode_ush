#include "libmx.h"

t_list  *mx_create_node(void *data) {
    t_list *buf= malloc(sizeof(t_list));
    buf->data = data;
    buf->next = NULL;
    return buf;
}
