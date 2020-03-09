#include "ush.h"


static t_ush_init *ush_struct_init() {
    t_ush_init *res = malloc(sizeof(t_ush_init));

    res->bufsize = 1;
    res->iline = malloc(sizeof (char) * (int)res->bufsize);
    res->com = NULL;
    res->i = 0;
    res->argv = NULL;
    return res;
}

void mx_ush_init(t_envp *var) {
    t_ush_init *res = ush_struct_init();
    t_history *history = mx_init_story();
    char *ex[] = {"exit", NULL};

    while (1) {
        mx_print_var(var, "?");
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            printf("u$h> ");
        signal(SIGINT, mx_handler);
        if (getline(&(res->iline), &(res->bufsize), stdin) < 0) {
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            mx_if_eof(var, ex);
        }
        if (!mx_cal_history(res, history)) {
            res->com = mx_strsplit(mx_del_extra_spaces(res->iline), ';');
            for (;res->com[res->i]; res->i++) {
                mx_parser(res->com[res->i], &(res->argv));
                for (t_comm *head = res->argv; head; head = head->next) {
                    // mx_print_strarr(head->argv->com, " ");
                    mx_get_command(var, head->com);
                    printf("%s", "TEST");
                }
                mx_parser_cleaner(&(res->argv));
                res->i = 0;
        }
        }
    }
}
