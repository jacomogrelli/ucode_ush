#include "ush.h"

void mx_set_correct_path() {
    char cur_path[PATH_MAX];

    getwd(cur_path);
    setenv("PWD", cur_path, 1);
}
