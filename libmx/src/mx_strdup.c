#include "libmx.h"

char *mx_strdup(const char *str) {
    const int size = mx_strlen(str);
    char *dup = mx_strnew(size);
    dup = mx_strcpy(dup, str);
    return dup;
}
