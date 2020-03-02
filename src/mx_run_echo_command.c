#include "ush.h"

void mx_run_echo_command(char **splited_arg) {
    printf("%s ", splited_arg[0]);
    exit(0);
}
