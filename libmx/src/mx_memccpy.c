#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    const char *src_buf = src;
    char *dst_buf = dst;
    size_t i = 0;
    
    while (i < n) {
        *dst_buf = *src_buf;
        if (*dst_buf == (char)c) return dst = dst_buf + 1;
        i++, dst_buf++, src_buf++;
    }
    if (i == n) return NULL;
    return dst = dst_buf;
}
