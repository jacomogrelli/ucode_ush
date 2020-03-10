#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if (*haystack == *needle)
            if (!mx_strncmp(haystack, needle, mx_strlen(needle)))
                return (char *)haystack;
        haystack++;
    }
    return NULL;
}
