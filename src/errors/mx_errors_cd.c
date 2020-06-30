#include "ush.h"

static void change_home_dir(char **splited_arg) {
    int count = 0;
    char *buff_str = NULL;
    char *get_home_dir = getenv("HOME");
    char *buff = NULL;

    while (splited_arg[count]) {
        buff_str = mx_strnew(mx_strlen(splited_arg[count]));
        buff_str = mx_strcpy(buff_str, splited_arg[count]);
        free(splited_arg[count]);
        buff = mx_my_repl_substr(buff_str, "~", get_home_dir);
        splited_arg[count] = mx_strnew(mx_strlen(buff));
        splited_arg[count] = mx_strcpy(splited_arg[count], buff);
        if (mx_strcmp(buff, get_home_dir) == 0)
            free(buff);
        free(buff_str);
        count++;
    }
}

static void reverse_spaces(char *arguments) {
    for (int i = 0; i < mx_strlen(arguments) - 1; i++) {
        if (arguments[i + 1] == '\n')
            arguments[i + 1] = '\0';
        if (arguments[i] == '\\'  && arguments[i + 1] == ' ')
            arguments[i + 1] = 1;
    }
}

static void change_spaces(char **splited_arg) {
    int count = 0;

    while (splited_arg[count]) {
        for (int i = 0; i < mx_strlen(splited_arg[count]); i++) {
            if (splited_arg[count][i] == 1)
                splited_arg[count][i] = ' ';
        }
        count++;
    }
}

static void e_free_mem_err_cd (char *buff_arg, char *arguments) {;
    free(buff_arg);
    free(arguments);
}

static void call_err_func(char **splited_arg, t_errors_cd *errors, 
                            t_flags_cd *flags_cd) {
    mx_e_too_many_arg_cd (splited_arg, errors, flags_cd);
    mx_e_no_dirorfile_cd(splited_arg, errors, flags_cd);
    mx_e_notpwd_cd(splited_arg, errors,flags_cd);
    mx_e_nodir_after_split_pwd_cd(splited_arg, errors, flags_cd);
}

char **mx_errors_cd (char **inp_line, t_errors_cd *errors,
                    t_flags_cd *flags_cd) {
    char **splited_arg = NULL;
    char *buff_arg = NULL;
    char *arguments = mx_join_for_cd(inp_line);
    int count_var = mx_my_count_words(arguments, '~');

    if (inp_line[1]) {
        buff_arg = mx_strnew(mx_strlen(arguments));
        buff_arg = mx_strcpy(buff_arg, arguments);
        reverse_spaces(buff_arg);
        splited_arg = mx_mystrsplit(buff_arg, ' ');
        change_spaces(splited_arg);
        mx_parse_flags_cd(splited_arg, flags_cd);
        if (count_var == 1) {
            mx_change_pwd_in_cd(splited_arg);
            mx_change_old_pwd_in_cd(splited_arg);
            change_home_dir(splited_arg);
        }
        call_err_func(splited_arg, errors, flags_cd);
        e_free_mem_err_cd(buff_arg, arguments);
    }
    return splited_arg;
}
