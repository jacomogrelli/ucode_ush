#include "ush.h"

// Для проверки работы реализуемой команды в buf_com закидываем массив в
// формата {"command", "-flags", "argv[1]", ... "argv[n]", NULL}
// например
// char *buf_com[] = {"ls", "-la", "libmx", NULL}

void mx_ush_init(t_envp *var) {
    char *input_line;
    size_t bufsize = 0;
    char **com;

    setenv("?", "0", 1);
    while (1) {
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
