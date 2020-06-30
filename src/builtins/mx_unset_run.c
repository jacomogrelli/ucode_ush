#include "ush.h"

t_envp *mx_unset_envp_del(t_envp *var, char *com) {
    t_envp *head = var;
    t_envp *head2 = var;
    int count = 0;

    for (;head; head = head->next, count++) {
        if (!strcmp(head->name, com)) {
            for (int i = 0; i < count - 1; i++)
                head2 = head2->next;
            t_envp *buf = head->next;
            mx_strdel(&head->name);
            mx_strdel(&head->val);
            free(head);
            head2->next = buf;
            break;
        }
    }
    return var;
}

void mx_set_run(t_envp *var, char **com) {
    t_envp *head = var;

    if (!var || !com[0])
        return;
    // head = mx_envp_sort(head);
    while (head) {
        printf("%s=", head->name);
        printf("%s\n", head->val);
        head = head->next;
    }
    mx_envp_replace(&var, "?=0");
}

void mx_print_var(t_envp *var, char *com) {
    t_envp *head = var;

    if (!var)
        return;
    while (head) {
        if (!strcmp(com, head->name)) {
            printf("%s=", head->name);
            printf("%s\n", head->val);
        }
        head = head->next;
    }
}

void mx_unset_run(t_envp *var, char **com) {
    for (int i = 1; com[i]; i++) {
        unsetenv(com[i]);
        var = mx_unset_envp_del(var, com[i]);
    }
    mx_envp_replace(&var, "?=0");
    return;
}
