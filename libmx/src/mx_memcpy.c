#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    const char *src_buf = src;
    char *dst_buf = dst;
    dst_buf = mx_strncpy(dst_buf, src_buf, n);
    return dst;
}
