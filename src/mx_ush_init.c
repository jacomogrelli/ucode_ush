#include "ush.h"

void mx_ush_init(void) {
    char *input_line;
    size_t bufsize;
    char **com;

    while (1) {
        printf("u$h> ");
        getline(&input_line, &bufsize, stdin);
        com = mx_strsplit(mx_strtrim(input_line), ';');
        for (int i = 0; com[i]; i++) {
            mx_get_command(com[i]);
        }
        mx_del_strarr(&com);
        mx_strdel(&input_line);
        // system("leaks -q ush");
    }
}
