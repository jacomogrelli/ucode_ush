#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *res = b;

    while(len > 0) {
        *res++ = c;
        len--;
    }
    return b;
}
