#include "ush.h"
// static char *ret_var(t_envp *var, char *com) {
//     t_envp *head = var;

//     if (!var)
//         return NULL;
//     while (head) {
//         if (!strcmp(com, head->name)) {
//             return head->val;
//         }
//         head = head->next;
//     }
//     return NULL;
// }

void mx_ush_init(t_envp *var) {
    t_ush_init *res = mx_ush_struct_init();
    t_history *history = mx_init_story();
    char *ex[] = {"exit", NULL};
    //char *returned_val = NULL;
    bool do_next = true;
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
            res->com = mx_strsplit(mx_strtrim(res->iline), ';');
            for (;res->com[res->i]; res->i++) {
                do_next = true;
                mx_parser_line(res->com[res->i], &(res->argv), var);
                    // int test = 0;
                    // while (res->argv->com[test]) {
                    //     printf("%s ", res->argv->com[test]);
                    //     test++;
                    // }
                for (t_comm *head = res->argv; head; head = head->next) {
                        //mx_print_strarr(head->com, " ");
                            // if (head->com)
                            //     mx_printstr("!!!!!!!!!!!!!!!!!!\n");
                            // if (!head->com)
                            //     mx_printstr("111111111111111111\n");
                        mx_get_command(var, head->com);
                    //mx_print_strarr(head->com, " ");
                    // mx_printchar(head->logic);
                    // mx_printstr("\n");
                    // if (do_next) {
                    //     mx_print_strarr(head->com, "1");
                    //     mx_get_command(var, head->com);
                    //     returned_val = ret_var(var, "?");
                    // }
                    // if (head->logic == '&')
                    //     do_next = true;
                    // else if (head->logic == '|') {
                    //     if (mx_strcmp(returned_val, "0") == 0) {
                    //         do_next = false;
                    //     }
                    //     else
                    //         do_next = true;
                    // }
                    // else {
                    //     do_next = true;
                    // }

                }
                mx_parser_cleaner(&(res->argv));
            }
            mx_ush_rescleaner(&res);
        }
    }
}
