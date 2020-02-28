#include "ush.h"

// Для проверки работы реализуемой команды в buf_com закидываем массив в
// формата {"command", "-flags", "argv[1]", ... "argv[n]", NULL}
// например
// char *buf_com[] = {"ls", "-la", "libmx", NULL}

void mx_ush_init(t_envp *var) {
    size_t bufsize = 1;
    char *input_line = malloc(sizeof (char) * (int)bufsize);
    char **com;

    while (1) {
        mx_printstr(var->val);
        mx_printchar('\n');
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            printf("u$h> ");
        if (getline(&input_line, &bufsize, stdin) < 0)
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            exit (EXIT_SUCCESS);
        com = mx_strsplit(mx_strtrim(input_line), ' ');
        if (com[0]) {
            mx_get_command(var, com);
            mx_del_strarr(&com);
            }
        mx_strdel(&input_line);
        // system("leaks -q ush");
    }
}

        // mx_printstr("iteration - ");
        // mx_printint(count);
        // mx_printchar('\n');
