#include "ush.h"

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

static void if_str_aud(char *str) {
    if (str)
        printf("%s", str);
    else
        printf("%s", "\n");    
}

static void free_arrs_aud(char *splited_str, t_flags_echo *flags_echo) {
    free(flags_echo);
    free(splited_str);

}
void mx_run_echo_command(t_envp *var, char **splited_input) {
    t_flags_echo *flags_echo = (t_flags_echo *)malloc(sizeof(t_flags_echo));
    char *splited_str = NULL;

    init_flags_echo(splited_input, flags_echo);
    if (!splited_input[1])
        printf("%c",'\n');
    else {
        splited_str = join_for_echo(splited_input, flags_echo);
        if (!flags_echo->act_flag || flags_echo->n_flag)
            if_str_aud(splited_str);
        else {
            if (flags_echo->E_flag)
                printf("%s",splited_str);
            else if (flags_echo->e_flag)
                mx_print_e_for_echo(splited_str);
        }
        if (!flags_echo->n_flag)
            printf("%s", "\n");
    }
    free_arrs_aud(splited_str, flags_echo);
    mx_envp_replace(&var, "?=0");
}
