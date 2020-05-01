#include "ush.h"

void mx_pwd_replace(char **iline) {
    *iline = mx_replace_substr(*iline, "$(pwd)", "$PWD");
    *iline = mx_replace_substr(*iline, "`echo \\`pwd\\``", "$PWD");
}
