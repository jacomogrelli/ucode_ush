#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;

    if (!str)
        return -1;
    while (*str) {
        if (*str == c)
            while (*str == c && *str)
                str++;
        if (*str != c && *str) {
            while (*str != c && *str) 
                str++;
            count++;
        }
    }
    return count;
}
