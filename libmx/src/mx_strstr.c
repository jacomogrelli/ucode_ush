#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int i = 0;

    if (!haystack)
        return NULL;
    if (!needle || needle[0] == '\0') 
        return (char*)haystack;
    while (haystack[i]) {
        if (haystack[i] == needle[0]) {
            for(int j = 1, k = i + 1; needle[j] && needle[j] == haystack[k]; j++, k++) {
                if (needle[j + 1] == '\0')
                return (char*)haystack + k - j;
            }
        }
        i++;
    }
    return NULL;
}

