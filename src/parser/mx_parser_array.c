#include "ush.h"

void mx_parser_array_delsh(char **line) {
    char *buf = *line;

    for (int i = 0; buf[i]; i++) {
        if (buf[i] == '\\')
            for (int j = i; buf[j]; j++) {
                if (!buf[j + 1]) {
                    buf[j] = '\0';
                    break;
                }
                buf[j] = buf[j + 1];
            }
        if (buf[i] == '\\')
            i++;
    }
}

void mx_parser_array_br(char *line, int *il, int *iar, char **res) {
    int count = 0;
    char *tmp = *res;

    for (int i = 0; line[i] != '\'' && line[i] != '\"' && line[i];
         count ++, (*il)++, i++);
    tmp = mx_strnew(count);
    tmp = strncpy(tmp, line, count);
    if (line[0] == '\"')
        for (int i = 0; tmp[i]; i++)
            if (tmp[i] == '\\' && (tmp[i + 1] == '$' || tmp[i + 1] == '\\'))
                for (int j = i; tmp[j]; j++) {
                    if (!tmp[j + 1]) {
                        tmp[j] = '\0';
                        break;
                    }
                    line[j] = line[j + 1];
                }
    (*iar)++;
}
void mx_parser_array_getfirst(char *line, int *il, int *iar, char **res) {
    int count = 0;
    char *tmp = *res;

    for (int i = 0; line[i] != '\0' && !isspace(line[i]); i++, count++, (*il)++)
        if (line[i] == '\\') {
            count++;
            (*il)++;
        }
    tmp = mx_strnew(count);
    tmp = strncpy(tmp, line, count);
    mx_parser_array_delsh(&tmp);
    (*iar)++;
}

void mx_parser_array(char *line, char ***res) {
    char **tmp = *res;
    int il = 0;
    int iar = 0;

    for (;line[il]; il++) {
        if (line[il] == '\'' || line[il] == '\"') {
            tmp = realloc(tmp, iar + 1);
            mx_parser_array_br(line + il, &il, &iar, &(tmp[iar]));
            tmp[iar] = NULL;
        }
        if (!isspace(line[il])) {
            tmp = realloc(tmp, iar + 1);
            mx_parser_array_getfirst(line + il, &il, &iar, &(tmp[iar]));
            tmp[iar] = NULL;
        }
    }
}
