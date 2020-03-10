#include "ush.h"

void mx_handler() {
    mx_printstr("\n");
    char *get_prompt = getenv("PROMPT");

    if (!get_prompt)
        mx_printstr("u$h> ");
    else {
        mx_printstr(get_prompt);
        mx_printstr("> ");
    }
    return;
}

void mx_if_eof(t_envp *var, char **ex) {
    if(feof(stdin))
        mx_run_exit(var, ex);
    exit (EXIT_SUCCESS);
}

bool mx_cal_history(t_envp *var, t_ush_init *res, t_history *history) {
    bool ret = false;
    if (mx_strcmp(res->iline, "\n") != 0) {
        mx_save_story(res->iline, history);
    }
    if (mx_strcmp(res->iline, "history\n") == 0) {
        ret = true;
        mx_print_strory(var, history);
    }
    return ret;
}
