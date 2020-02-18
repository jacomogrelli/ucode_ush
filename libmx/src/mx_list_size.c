#include "libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    if (list) {
        t_list *head = list;
        while (head != NULL) {
            count++;
            head = head->next;
        }
    }
    return count;
}
