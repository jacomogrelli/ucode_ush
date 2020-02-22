#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const char *s_buf = s;
    
    for(size_t i = 0; i < n; i++, s_buf++) {
        if(*s_buf == c)
            return (void*)s_buf;
    }
    return NULL;
}
