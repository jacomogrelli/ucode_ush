#include "libmx.h"

void mx_printlist(t_list *list) {
    t_list *head = list;

    if (!list)
        return;
    while (head) {
        mx_printstr(head->data);
        mx_printstr("\n");
        head = head->next;
    }
    // mx_printstr(head->data);
}
