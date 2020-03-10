#include "ush.h"

char **mx_parser_paris(t_envp *var, char *line) {
    char **res = NULL;

    if (!mx_parser_pais(var, line))
        return NULL;
    line = mx_parser_tilda(line);
    return res;
}

int mx_parser_pais(t_envp *var, char *line) {
    int b = 0;
    int e = strlen(line);

    for (;line[b] != ' '; b++)
        if (line[b] == '\0')
            return 1;
    for (;b != e && line[b] != '\0'; b++) {
        if (mx_get_char_index(MX_PARS_ERR, line[b]) >= 0
            && line[b - 1] != '\\') {
            mx_parser_err(var, line[b], 1);
            return 1;
        }
        if (mx_get_char_index(MX_PARS_PAIR, line[b]) >= 0
            && line[b - 1] != '\\') {
            for (; e != b; e--) {
                if (e == b + 1) {
                    mx_parser_err(var, line[b], 2);
                    return 1;
                }
                if (line[e] == line[b] && line[e -1] != '\\') {
                    e--;
                    break;
                }
            }
        }
    }
    return 0;
}

void mx_parser_err(t_envp *var, char c, int flag) {
    if (flag == 1) {
        mx_printerr("ush: command substitution is not supported\n");
        mx_printerr("     Do not use symbols ` and ()\n");
        mx_envp_replace(&var, "?=1");
    }
    if (flag == 2) {
        mx_printerr("ush: multiline command input is not supported\n");
        mx_printerr("     Use pair symbols in pair\n");
        mx_envp_replace(&var, "?=1");
    }
    if(c)
    return;
}
