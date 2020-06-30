#include "ush.h"

void mx_export_new_var(t_envp *var, char *com) {
    char *name = strndup(com, mx_get_char_index(com, '='));
    char *val = strdup(com + mx_get_char_index(com, '=') + 1);

    setenv(name, val, 1);
    mx_envp_replace(&var, com);
    mx_strdel(&name);
    mx_strdel(&val);
}

void mx_export_from_envp(t_envp *var, char *com) {
    t_envp *head = var;

    for (;head; head = head->next) {
        if (!strcmp(com, head->name))
            setenv(com, head->val, 1);
    }
}

void mx_export_argfree(t_envp *var) {
    extern char **environ;
    int count = 0;

    for (;environ[count]; count++);
    mx_bubble_sort(environ, count);
    for (int i = 0; environ[i]; i++) {
        printf("declare -x %s\n", environ[i]);
    }
    mx_envp_replace(&var, "?=0");
}

void mx_export_run(t_envp *var, char **com) {
    if (!com[1]) {
        mx_export_argfree(var);
        return;
    }
    for (int i = 1; com[i]; i++) {
        if (mx_get_char_index(com[i], '=') < 0)
            mx_export_from_envp(var, com[i]);
        if (mx_get_char_index(com[i], '=') > 0)
            mx_export_new_var(var, com[i]);
    }
    mx_envp_replace(&var, "?=0");
}
