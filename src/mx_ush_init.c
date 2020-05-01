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

// static char *check_pwd(char *input) {
//     char *buffer = getenv("PWD");
//     char tmp_pwd[] = "\"$(pwd)\"";
//     bool check = true;
//     int count = 0;
//     char *res = NULL;

//     for (int i  = 13; i < 21; i++) {
//         if (input[i] != tmp_pwd[count])
//             check = false;
//         count++;
//     }
//     if (check) {
//         res = mx_replace_substr(input, tmp_pwd, buffer);
//         return res;
//     }
//     else {
//         return input;
//     }
// }

// static char *check_second_pwd(char *input) {
//     char *buffer = getenv("PWD");
//     char tmp_pwd[] = "\"`echo \\`pwd\\``\"";
//     bool check = true;
//     int count = 0;
//     char *res = NULL;

//     for (int i  = 13; i < 27; i++) {
//         if (input[i] != tmp_pwd[count])
//             check = false;
//         count++;
//     }
//     if (check) {
//         res = mx_replace_substr(input, tmp_pwd, buffer);
//         return res;
//     }
//     else {
//         return input;
//     }
// }
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

// static void free_solo_command(char **solo_command) {
//     int count = 0;

//     while (solo_command[count]) {
//         free(solo_command[count]);
//     }
//     if (solo_command)
//         free(solo_command);
// }

// static void free_ignored_com(char **ignored_com) {
//     int count = 0;
//     if (ignored_com[count]) {
//         while(ignored_com[count]) {
//             free(ignored_com[count]);
//             count++;
//         }
//     }
//     if (ignored_com)
//         free(ignored_com);
// }

void mx_ush_init(t_envp *var) {
    t_ush_init *res = mx_ush_struct_init();
    t_history *history = mx_init_story();
    char *ex[] = {"exit", NULL};
    bool do_next = true;
    int count_com = 0;

    while (1) {
        count_com = 0;
        // mx_print_var(var, "?");
        if (isatty(0)) //проверка наличия перенаправления потока вывода
            mx_uniq_prompt();
        signal(SIGINT, mx_handler);
        if (getline(&(res->iline), &(res->bufsize), stdin) < 0) {
            //чекаем будет ли ввод, для "echo "ls -la" | ./ush
            mx_if_eof(var, ex);
        }
        if (!mx_cal_history(var, res, history)) {
            mx_pwd_replace(&res->iline);
            // res->iline = check_pwd(res->iline);
            // res->iline = check_second_pwd(res->iline);
            // printf("%s", res->iline);
            res->com = mx_mystrsplit(mx_strtrim(res->iline), ';');
            //for (;res->com[res->i]; res->i++) {
                do_next = true;

                res->ignored_com = mx_main_parse(res->com);
                //free_ignored_com(res->ignored_com);
                while(res->ignored_com[count_com]) {
                    res->ignored_com[count_com] = mx_parser_tilda(res->ignored_com[count_com]);
                    res->ignored_brack = mx_second_parse(res->ignored_com[count_com]);
                    res->change_var = mx_change_var(res->ignored_brack, var);
                    res->splited_or_and = mx_or_and(res->change_var);
                    res->count_logic = 0;
                    //while (res->splited_or_and[res->count_logic]) {
                        res->solo_com = mx_strsplit(res->change_var, ' ');
                        reverse_space(res->solo_com);
                        mx_get_command(var, res->solo_com);
                        //res->count_logic++;
                    //}
                    // res->solo_com = mx_strsplit(res->ignored_brack, ' ');
                    // mx_get_command(var, res->solo_com);
                    //free(res->ignored_brack);
                    count_com++;
                }
                //free(res->ignored_com);
            //}
            //mx_ush_rescleaner(&res);
        }
    }
}
