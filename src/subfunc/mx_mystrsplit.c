#include "ush.h"

char **mx_forstr(const char *s, char c) {
    int count = 0;
    char **n = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    int fors = 0;

    for (int i = 0; i < mx_strlen(s); i++) {
        count = 0;
        while (s[i] == c) {
            i++;
        }
        while (s[i] != c && s[i] != '\0') {
            count++;
            i++;
        }
        if (count != 0) {
            n[fors++] = mx_strnew(count);
        }
    }
    n[fors] = NULL;
    return n;
}

char **mx_mystrsplit(const char *s, char c) {
    int i = 0;
    int k = 0;
    char **n = mx_forstr(s, c);
    int l = 0;

    if (s == NULL)
        return NULL;
    for (k = 0; k < mx_count_words(s, c); k++) {
        while (s[l] == c) {
            l++;
        }
        for (i = 0; s[l] != c && s[l] != '\0'; i++, l++) {
            n[k][i] = s[l];
        }
    }
    return n;
}
