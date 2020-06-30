#include "ush.h"

char *mx_my_repl_substr(char *main_str, char *dst, char *src) {
    int res_len = mx_strlen(main_str) - mx_strlen(dst) + mx_strlen(src);
    int first_find = strstr(main_str, dst) - main_str;
    int count = 0;
    char *res_str = NULL;

    if (strstr(main_str, dst)) {
        res_str = mx_strnew(res_len);
        for (int i = 0; i < res_len; i++) {
            if (i < first_find)
                res_str[i] = main_str[i];
            else if (count < mx_strlen(src)) {
                res_str[i] = src[count];
                count++;
            }
            else {
                for (count = first_find + mx_strlen(dst); count
                    < mx_strlen(main_str); count++, i++)
                    res_str[i] = main_str[count];
                break;
            }
        }
        return res_str;
    }
    if (strstr(main_str, dst))
        free(res_str);
    return main_str;
}
