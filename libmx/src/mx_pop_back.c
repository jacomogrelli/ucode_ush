#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {
        (*head)->data = NULL;
        free(*head);
        *head = NULL;
        return;
    }
    t_list *temp_head = *head;
    while (temp_head->next->next != NULL) temp_head = temp_head->next;
    temp_head->next->data = NULL;
    free(temp_head->next);
    temp_head->next = NULL;
}
