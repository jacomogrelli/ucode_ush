#include "libmx.h"

void mx_strdel(char **str) {
    if (str && *str != NULL) {
        free(*str);
        *str = NULL;
    }
}

