#include "ush.h"

char *mx_my_repl_substr_cd(char *dst, char *src) {
    char *env_str = getenv("PWD");
    int res_len = mx_strlen(env_str) - mx_strlen(dst) + mx_strlen(src);
    int first_find = strstr(env_str, dst) - env_str;
    int count = 0;
    char *res_str = mx_strnew(res_len);

    for (int i = 0; i < res_len; i++) {
        if (i < first_find)
            res_str[i] = env_str[i];
        else if (count < mx_strlen(src)) {
            res_str[i] = src[count];
            count++;
        }
        else {
            for (count = first_find + mx_strlen(dst); count
                < mx_strlen(env_str); count++, i++) {
                res_str[i] = env_str[count];
            }
            break;
        }
    }
    return res_str;
}
