#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str)
        return NULL;
    char *s = mx_strnew(mx_strlen(str));
	char *rez;
    if (s)
        for (int k = 0; *str; s[k++] = *(str++))
            if (mx_isspace(*str)){
                for (s[k++] = ' '; mx_isspace(*str); ++str);
                if (!(*str))
                    break;
            }
    rez = mx_strtrim(s);
    free(s);
    return rez;
}
