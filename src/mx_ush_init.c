#include "ush.h"

void mx_ush_init(t_envp *var) {
    t_ush_init *res = mx_ush_struct_init();
    t_history *history = mx_init_story();
    char *ex[] = {"exit", NULL};
    while (1) {
        mx_print_var(var, "?");
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            mx_uniq_prompt();
        signal(SIGINT, mx_handler);
        if (getline(&(res->iline), &(res->bufsize), stdin) < 0) {
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            mx_if_eof(var, ex);
        }
        if (!mx_cal_history(var, res, history)) {
            res->com = mx_strsplit(mx_del_extra_spaces(res->iline), ';');
            for (;res->com[res->i]; res->i++) {
                mx_parser_line(res->com[res->i], &(res->argv), var);
                for (t_comm *head = res->argv; head; head = head->next) {
                    // mx_print_strarr(head->argv->com, " ");
                    mx_get_command(var, head->com);
                }
                mx_parser_cleaner(&(res->argv));
            }
            mx_ush_rescleaner(&res);
        }
    }
}
