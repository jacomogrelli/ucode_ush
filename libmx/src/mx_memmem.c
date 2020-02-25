#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const char *big_buf = big;
    const char *little_buf = little;

    if (big_len < little_len || !big_len || !little_len) {
        return NULL;
    }
    for (size_t i = 0; i < big_len;) {
        if (big_buf[i] == little_buf[0]) {
            for (size_t j = 1, k = i + 1; j < little_len 
            && big_buf[k] == little_buf[j]; j++, k++) {
                if (j + 1 == little_len) {
                    big = big_buf + k - j;
                    return (void *)big;
                }
            }
        }
        i++;
    }
    return NULL;
}
