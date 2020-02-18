#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *s_buf = s;
    size_t j = 1;
    
    while (j < n) s_buf++, j++;
    for(size_t i = n; i > 0; i--, s_buf--) {
        if(*s_buf == c)
            return (void *)s_buf;
    }
    return NULL;
}
