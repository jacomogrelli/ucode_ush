#include "ush.h"

static void hendler() {
    mx_printstr("\n");
    mx_printstr("u$h> ");
    return;
}

void mx_ush_init(t_envp *var) {
    size_t bufsize = 1;
    char *input_line = malloc(sizeof (char) * (int)bufsize);
    char **com;
    char *ex[] = {"exit", NULL};
    t_history *history = mx_init_story();

    while (1) {
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            printf("u$h> ");
            signal(SIGINT, hendler);
        if (getline(&input_line, &bufsize, stdin) < 0) {
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            if(feof(stdin)) {
                mx_run_exit(var, ex);
            }
            exit (EXIT_SUCCESS);
        }
        if (mx_strcmp(input_line, "\n") != 0)
            mx_save_story(input_line, history);
        com = mx_strsplit(mx_strtrim(input_line), ' ');
        if (com[0]) {
            if (mx_strcmp(input_line, "history\n") == 0)
                mx_print_strory(history);
            else
                mx_get_command(var, com);
            mx_del_strarr(&com);
            }
        mx_strdel(&input_line);
        // system("leaks -q ush");
    }
}
