#include "libmx.h"

char *mx_strtrim(const char *str) {
    int i = 0;
    int len = 0;
    char *res = NULL;

    if (!str)
        return NULL;
    while(mx_isspace(str[i])) i++;
    len = mx_strlen(str);
    if (len == i) 
        return res = mx_strnew(0);
    while(mx_isspace(str[len - 1])) len--;
    res = mx_strnew(len - i);
    for(int j = 0; i < len; i++, j++){
        res[j] = str[i];
    }
    return res;
}
