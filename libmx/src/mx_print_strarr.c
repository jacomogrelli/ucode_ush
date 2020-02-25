#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if ((delim) && (arr)) {
        while (*arr) {
            mx_printstr(*arr++);
            if (*arr)
                mx_printstr(delim);
        }
        mx_printchar('\n');
    }
}
