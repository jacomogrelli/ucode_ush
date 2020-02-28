#include "ush.h"

// Для проверки работы реализуемой команды в buf_com закидываем массив в
// формата {"command", "-flags", "argv[1]", ... "argv[n]", NULL}
// например
// char *buf_com[] = {"ls", "-la", "libmx", NULL}

void mx_ush_init(t_envp *var) {
    size_t bufsize = 1;
    char *input_line = malloc(sizeof (char) * (int)bufsize);
    char **com;
    // t_envp *head = var;

    // for (t_envp *head = var; head; head = head->next) {
    //     printf("%s=", head->name);
    //     printf("%s\n", head->val);
    // }
    // exit(0);

    while (1) {
        // printf("?=%s\n", var->val);
        printf("u$h> ");
        getline(&input_line, &bufsize, stdin);
        com = mx_strsplit(mx_strtrim(input_line), ' ');
        // for (int i = 0; com[i]; i++) {
            mx_get_command(var, com);
        // }
        mx_del_strarr(&com);
        mx_strdel(&input_line);
        // system("leaks -q ush");
    }
}
