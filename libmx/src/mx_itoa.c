#include "libmx.h"

//according with auditor

static int num_len(int number) {
    unsigned int num = number;
    int count;

    count = num <= 0 ? 1 : 0;

    while (num > 0) {
        count++;
        num = num / 10;
    }
    return count;
}
char *mx_itoa(int number) {
    unsigned int num = number;
    int i = 0;
    int sign;
    int len;
    char *str;

    len = num_len(number);
    str = mx_strnew(len);
    if ((sign = num) < 0)
        num = -num;
    for (;i < len; i++) {
        str[i] = num % 10 + '0';
        num = num / 10;
    }
    if (sign < 0)
        str[i++] = '-';
    mx_str_reverse(str);
    return str;
}
