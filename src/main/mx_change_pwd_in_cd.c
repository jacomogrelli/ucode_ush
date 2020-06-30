#include "ush.h"

void mx_change_pwd_in_cd(char **splited_arg) {
    int count = 0;
    char *buff_str = NULL;
    char *get_home_dir = getenv("PWD");
    char *buff = NULL;

    while (splited_arg[count]) {
        if (strstr(splited_arg[count], "~+")) {
            buff_str = mx_strnew(mx_strlen(splited_arg[count]));
            buff_str = mx_strcpy(buff_str, splited_arg[count]);
            free(splited_arg[count]);
            buff = mx_my_repl_substr(buff_str, "~+", get_home_dir);
            splited_arg[count] = mx_strnew(mx_strlen(buff));
            splited_arg[count] = mx_strcpy(splited_arg[count], buff);
            if (mx_strcmp(buff, get_home_dir) == 0)
                free(buff);
            free(buff_str);
        }
        count++;
    }
}

void mx_change_old_pwd_in_cd(char **splited_arg) {
    int count = 0;
    char *buff_str = NULL;
    char *get_home_dir = getenv("OLDPWD");
    char *buff = NULL;

    while (splited_arg[count]) {
        if (strstr(splited_arg[count], "~-")) {
            buff_str = mx_strnew(mx_strlen(splited_arg[count]));
            buff_str = mx_strcpy(buff_str, splited_arg[count]);
            free(splited_arg[count]);
            buff = mx_my_repl_substr(buff_str, "~-", get_home_dir);
            splited_arg[count] = mx_strnew(mx_strlen(buff));
            splited_arg[count] = mx_strcpy(splited_arg[count], buff);
            if (mx_strcmp(buff, get_home_dir) == 0)
                free(buff);
            free(buff_str);
        }
        count++;
    }
}
