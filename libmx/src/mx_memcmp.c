#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const char *s1_buf = s1;
    const char *s2_buf = s2;
    return mx_strncmp(s1_buf, s2_buf,(int)n);
}
