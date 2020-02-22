#include "ush.h"

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
            if (splited_arg[count][i] == '\t')
                splited_arg[count][i] = 1;
        }
        count++;
    }
}

static void e_free_mem_err_cd (char **splited_arg, char *buff_arg) {
    int count = 0;

    while (splited_arg[count]) {
        free(splited_arg[count]);
        count++;
    }
    free(splited_arg);
    free(buff_arg);
}

bool mx_errors_cd (char *arguments) {
    char **splited_arg = NULL;
    char *buff_arg = NULL;
    bool res = true;

    buff_arg = mx_strnew(mx_strlen(arguments));
    buff_arg = mx_strcpy(buff_arg, arguments);
    reverse_spaces(buff_arg);
    splited_arg = mx_mystrsplit(buff_arg, ' ');
    change_spaces(splited_arg);
    mx_e_too_many_arg_cd (splited_arg);
    mx_e_no_dirorfile_cd(splited_arg);
    mx_e_notpwd_cd(splited_arg);
    mx_e_nodir_after_split_pwd_cd(splited_arg);
    e_free_mem_err_cd(splited_arg, buff_arg);
    return res;
}
