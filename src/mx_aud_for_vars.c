#include "ush.h"

char *mx_res_aud_str(char *res_str, char *buffer_replace) {
    free(res_str);
    res_str = mx_strnew(mx_strlen(buffer_replace));
    res_str = mx_strcpy(res_str, buffer_replace);
    free(buffer_replace);
    return res_str;
}
