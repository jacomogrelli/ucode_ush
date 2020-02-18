#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int len = 0;
    int i = 0;

    if (!arr || !delim)
        return;
    while(arr[len] != NULL) {
        len++;
    }
    while(i < len - 1) {
        mx_printstr(arr[i]);
        mx_printstr(delim);
        i++;
    }
    mx_printstr(arr[i]);
    mx_printchar('\n');
}

