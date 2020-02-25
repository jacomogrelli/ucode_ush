#include "ush.h"

void mx_exec_err_out(char *com, int err) {
    char *buf = mx_strjoin("ush: ", com);

    errno = err;
    perror(buf);
    free(buf);
}
