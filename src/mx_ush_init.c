#include "ush.h"

void mx_ush_init(void) {
    char *input_line;
    size_t bufsize;
    char **com;

    while (1) {
        printf("u$h> ");
        getline(&input_line, &bufsize, stdin);
        com = mx_strsplit(input_line, ';');
        for (int i = 0; com[i]; i++) {
            mx_get_command(com[i]);
        }
    }
}
