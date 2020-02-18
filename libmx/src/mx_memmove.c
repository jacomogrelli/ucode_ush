#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *res = dst;
    //const char *src_b = src;
    char *buf = NULL;

    if (len == 0)
        return NULL;
    buf = mx_strnew(len);
    mx_memcpy(buf, src, len);
    for (size_t i = 0; i < len; i++) {
        res[i] = buf[i];
    }
    free(buf);
    return dst;
}
