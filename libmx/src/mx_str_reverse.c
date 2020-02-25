#include "libmx.h"

void mx_str_reverse(char *s) {
    int len = 0;

    if (!s)
        return;
    while(s[len]) {
        len++;
    }
    for(int i = 0; i < len / 2; i++) {
        mx_swap_char(&s[len - i - 1], &s[i]);
    }
 }
