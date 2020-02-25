#include "ush.h"

void mx_exec_err_out(char *com, int err) {
    char *buf = mx_strjoin("ush: ", com);

    if (mx_get_char_index(com, '/') < 0) {
        mx_printerr(buf);
        mx_printerr(": command not found\n");
        return;
    }
    errno = err;
    perror(buf);
    free(buf);
}
