#include "ush.h"

bool mx_errors_cd (char *arguments) {
    char **splited_arg = mx_strsplit(arguments, " ");
    int count = 0;

    while (splited_arg[count]) {
        printf("%s ", splited_arg[count]);
        count++;
    }
    arguments = NULL;
}
