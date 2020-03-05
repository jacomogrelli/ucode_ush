#include "ush.h"

static void unset_envp_del(t_envp **var, char *com) {
    t_envp *head = *var;

    while(head) {
        if (!strcmp(head->name, com)) {
            t_envp *buf = head->next;
            mx_strdel(&head->name);
            mx_strdel(&head->val);
            free(head);
            head = buf;
            break;
        }
        head = head->next;
    }
}

void mx_set_run(t_envp *var, char **com) {
    t_envp *head = var;

    if (!var || !com[0])
        return;
    head = mx_envp_sort(head);
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
    if (!com[1]) {
        mx_envp_replace(&var, "?=0");
        return;
    }
    for (int i = 1; com[i]; i++) {
        if (!(unsetenv(com[1])))
            continue;
        unset_envp_del(&var, com[i]);
    }
    mx_envp_replace(&var, "?=0");
    mx_set_run(var, com);
    return;
}
