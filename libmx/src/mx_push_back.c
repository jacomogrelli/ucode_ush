#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list* back = NULL;
    t_list* tmp = NULL;

    if (!list)
         return ;
    back = mx_create_node(data);
    if (!back)
         return ;
    tmp = *list;
    if (*list == NULL) {
       *list = back;
       return ;
    }
    while (tmp->next != NULL) {
           tmp = tmp->next;
    }
    tmp->next = back;
}
