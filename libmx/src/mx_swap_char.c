#include "libmx.h"

void mx_swap_char(char *s1, char *s2) {
    if (!s1 || !s2)
        return;
    char buf = *s1;
    *s1 = *s2;
    *s2 = buf;
}

