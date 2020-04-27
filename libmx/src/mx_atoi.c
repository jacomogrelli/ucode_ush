#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int sing = 1;
    int res = 0;

    while (mx_isspace(str[i])) {
        i++;
    }
    if (str[i] == '-') {
        sing = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    while (str[i] && !mx_isspace(str[i]) && mx_isdigit(str[i])) {
        res = res * 10 + str[i] -'0';
        i++;
    }
    return res * sing;
}
