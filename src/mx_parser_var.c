#include "ush.h"

static char *var_reg(int i, char *line) {
    char *buf = mx_strnew(1024);
    int j = i + 1;

    for (int k = 0; ((line[j] > 64 && line[j] < 91)
         || (line[j] > 96 && line[j] < 123) || line[j] == 95)
         && line[j]; j++, k++) {
        buf = realloc(buf, k + 1);
        buf[k] = line[j];
    }
    char *tmp = getenv(buf);
    if (tmp) {
        buf = mx_strjoin("$", buf);
        line = mx_replace_substr(line, buf, tmp);
    }
    free(buf);
    return line;
}

static char *var_curly(int i, char *line) {
    char *buf = mx_strnew(1024);
    int j = i + 2;

    for (int k = 0; line[j] != '}' && line[j]; j++, k++) {
        buf[k] = line[j];
        if (line[j + 1] == '}') {
            char *tmp = getenv(buf);
            if (tmp) {
                buf = mx_strjoin("${", buf);
                buf = mx_strjoin(buf, "}");
                line = mx_replace_substr(line, buf, tmp);
            }
            free(buf);
            break;
        }
    }
    return line;
}

char *mx_parser_var(char *line) {
    for (int i = 1; line[i]; i++) {
        if (line[i] == '$' && line[i - 1] != '\\') {
            if (line[i + 1] == '{')
                line = var_curly(i, line);
            else
                line = var_reg(i, line);
        }
    }
    return line;
}
