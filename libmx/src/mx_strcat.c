#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len = 0;
    int i = 0;
    if (s1 && s2) {
        while(s1[len]) {
            len++;
        }
        for(; s2[i] != '\0'; i++) {
            s1[len + i] = s2[i];
        }
    }
    s1[i + len] = '\0';
    return s1;
}
