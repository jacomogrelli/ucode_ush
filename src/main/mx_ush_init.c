#include "ush.h"

static void reverse_space(char **solo_com) {
    int count = 0;

    while (solo_com[count]) {
        for (int i = 0; i < mx_strlen(solo_com[count]); i++) {
            if (solo_com[count][i] == '#') {
                solo_com[count][i] = ' ';
            }
        }
        count++;
    }
}

void mx_ush_init(t_envp *var) {
    t_ush_init *res = mx_ush_struct_init();
    t_history *history = mx_init_story();
    char *ex[] = {"exit", NULL};
    bool do_next = true;
    int count_com = 0;

    while (1) {
        count_com = 0;
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            mx_uniq_prompt();
        signal(SIGINT, mx_handler);
        if (getline(&(res->iline), &(res->bufsize), stdin) < 0) {
            mx_if_eof(var, ex);
        }
        if (!mx_cal_history(var, res, history)) {
            mx_pwd_replace(&res->iline);
            res->com = mx_mystrsplit(mx_strtrim(res->iline), ';'); {
            do_next = true;
            res->ignored_com = mx_main_parse(res->com);
            while(res->ignored_com[count_com]) {
                res->ignored_com[count_com] = mx_parser_tilda(res->ignored_com[count_com]);
                res->ignored_brack = mx_second_parse(res->ignored_com[count_com]);
                res->change_var = mx_change_var(res->ignored_brack, var);
                res->solo_com = mx_strsplit(mx_strtrim(res->change_var), ' ');
                    reverse_space(res->solo_com);
                    mx_get_command(var, res->solo_com);
                count_com++;
                }
            }
        }
    }
}
