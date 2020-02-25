#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *trimmed_str = NULL;
    int start_spaces_count = 0;
    int end_spaces_count = 0;
    int i = 0;
    int size = 0;

    if (!str)
        return NULL;
    while (mx_isspace(str[i++]))
        start_spaces_count++;
    if (start_spaces_count == mx_strlen(str))
        return mx_strnew(0);
    i = mx_strlen(str) - 1;
    while (mx_isspace(str[i--]))
        end_spaces_count++;
    size = mx_strlen(str) - (start_spaces_count + end_spaces_count);
    str += start_spaces_count;
    trimmed_str = mx_strnew(size);
    mx_strncpy(trimmed_str, str, size);
    return trimmed_str;
}
