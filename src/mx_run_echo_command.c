#include "ush.h"

static void change_til(char **str) {
    char *get_home = getenv("HOME");
    char *get_pwd = getenv("PWD");
    char *get_old_pwd = getenv("OLDPWD");
    int count = 0;

    while (str[count]) {
        if (mx_strcmp(str[count], "~") == 0)
            str[count] = mx_my_repl_substr(str[count], "~", get_home);
        if (mx_strcmp(str[count], "~+") == 0)
            str[count] = mx_my_repl_substr(str[count], "~+", get_pwd);
        if (mx_strcmp(str[count], "~-") == 0)
        str[count] = mx_my_repl_substr(str[count], "~-", get_old_pwd);
        count++;
    }
}

// static void e_flag_echo(char *splited_str) {
//     char *buf = mx_strnew(mx_strlen(splited_str));
//     int count = 0;

//     for (int i = 0; i < mx_strlen(splited_str); i++) {
//        if(splited_str[i] == '\\') {
//             i++;
//         }
//         buf[count] = splited_str[i];
//         count++;
//     }
//     printf("%s", buf);
//     free(buf);
// }

static void init_flags_echo(char **splited_input, t_flags_echo *flags_echo) {
    flags_echo->act_flag = false;
    flags_echo->E_flag = false;
    flags_echo->e_flag = false;
    flags_echo->n_flag = false;
    if (splited_input[1]) {
        if (mx_strcmp(splited_input[1], "-e") == 0) {
            flags_echo->act_flag = true;
            flags_echo->e_flag = true;
        }
        if (mx_strcmp(splited_input[1], "-E") == 0) {
            flags_echo->act_flag = true;
            flags_echo->E_flag = true;
        }
        if (mx_strcmp(splited_input[1], "-n") == 0) {
            flags_echo->act_flag = true;
            flags_echo->n_flag = true;
        }
    }
}

static char *join_for_echo(char **splited_input, t_flags_echo *flags_echo) {
    char *res = NULL;
    int count = 1;
    char *buff = NULL;

    if (flags_echo->act_flag)
        count = 2;
    for (int i = count; splited_input[i] != NULL; i++) {
        res = mx_strjoin(buff, splited_input[i]);
        if (buff)
            free(buff);
        if (!splited_input[i + 1])
            buff = mx_strjoin(res, NULL);
        else
            buff = mx_strjoin(res, " ");
        free(res);
    }
    return buff;
}

void mx_run_echo_command(t_envp *var, char **splited_input) {
    t_flags_echo *flags_echo = (t_flags_echo *)malloc(sizeof(t_flags_echo));
    char *splited_str = NULL;

    init_flags_echo(splited_input, flags_echo);
    if (!splited_input[1])
        printf("%c",'\n');
    else {
        change_til(splited_input);
        splited_str = join_for_echo(splited_input, flags_echo);
        if (!flags_echo->act_flag || flags_echo->n_flag) {
            if (splited_str)
                printf("%s", splited_str);
            else
                printf("%s", "\n");
        }
        else {
            if (flags_echo->E_flag)
                printf("%s",splited_str);
            else if (flags_echo->e_flag)
                mx_print_e_for_echo(splited_str);
                //e_flag_echo(splited_str);
        }
        if (!flags_echo->n_flag)
            printf("%s", "\n");
    }
    free(flags_echo);
    free(splited_str);
    mx_envp_replace(&var, "?=1");
}