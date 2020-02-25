#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {
        (*head)->data = NULL;
        free(*head);
        *head = NULL;
        return;
    }
    t_list *temp = (*head)->next;
    (*head)->data = NULL;
    free((*head)->data);
    *head = temp;
    
}
