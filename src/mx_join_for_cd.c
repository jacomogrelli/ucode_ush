#include "ush.h"

char *mx_join_for_cd (char **splited_inp) {
    char *res = NULL;
    char * buff = NULL;
    int count = 1;

    while (splited_inp[count]) {
        buff = mx_strjoin(res, splited_inp[count]);
        free(res);
        res = mx_strjoin(buff, " ");
        free(buff);
        count++;
    }
    return res;
}
