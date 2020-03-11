#include "ush.h"

static void tilda_user(int i, char *line, char **head) {
    char *buf = mx_strnew(0);
    struct passwd *pw;

    for (int j = i, k = 0; line[j]; j++, k++) {
        if (mx_get_char_index(MX_PARS_TSTOP, line[j]) >= 0)
            break;
        buf = realloc(buf, k + 1);
        buf[k] = line[j];
    }
    pw = getpwnam(buf + 1);
    if (pw) {
        *head = mx_replace_substr(line, buf, pw->pw_dir);
    }
}

static void tilda(char **head, char *line, char flag) {
    if (flag == 'd') {
        if (!getenv("HOME")) {
            struct passwd *buf = getpwuid(getuid());
            *head = mx_replace_substr(line, "~", buf->pw_dir);
            }
        else
            *head = mx_replace_substr(line, "~", getenv("HOME"));
    }
    if (flag == '+')
        *head = mx_replace_substr(line, "~+", getenv("PWD"));
    if (flag == '-')
        *head = mx_replace_substr(line, "~-", getenv("OLDPWD"));
}

char *mx_parser_tilda(char *line) {
    char *head = NULL;

    for (int i = 0; line[i]; i++)
        if (line[i] == '~') {
            if (line[i + 1] == '\0') {
                tilda(&head, line, 'd');
                break;
            }
            if (line[i + 1]) {
                if (mx_get_char_index(MX_PARS_TSTOP, line[i + 1]) >= 0) {
                    tilda(&head, line, 'd');
                    break;
                }
                if (line[i + 1] == '+' || line[i + 1] == '-') {
                    tilda(&head, line, line[i + 1]);
                    break;
                }
            tilda_user(i, line, &head);
            }
        }
    return (!head) ? line : head;
}
