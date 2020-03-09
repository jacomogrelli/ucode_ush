#include "ush.h"

static void hendler() {
    mx_printstr("\n");
    mx_printstr("u$h> ");
    return;
}

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
        signal(SIGINT, hendler);
        if (getline(&(res->iline), &(res->bufsize), stdin) < 0) {
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            if(feof(stdin))
                mx_run_exit(var, ex);
            exit (EXIT_SUCCESS);
        }
        if (mx_strcmp(res->iline, "\n") != 0)
            mx_save_story(res->iline, history);
        if (mx_strcmp(res->iline, "history\n") == 0)
                mx_print_strory(history);
        else {
            res->com = mx_strsplit(mx_del_extra_spaces(res->iline), ';');
            for (;res->com[res->i]; res->i++) {
                mx_parser(res->com[res->i], &(res->argv));
                for (t_comm *head = res->argv; head; head = head->next) {
                    // mx_print_strarr(head->argv->com, " ");
                    mx_get_command(var, head->com);
                }
                mx_parser_cleaner(&(res->argv));
                res->i = 0;
            }
        }
    }
}
