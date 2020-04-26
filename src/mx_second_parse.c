#include "ush.h"

char *mx_del_brack(char * ignored_com) {
    char *ignored_brack = mx_strnew(mx_strlen(ignored_com));
    int count = 0;

    for (int i = 0; i < mx_strlen(ignored_com); i++) {
        if (ignored_com[i] == '\"' || ignored_com[i] == '\'' 
            || ignored_com[i] == '`')
                continue;
        else
            ignored_brack[count] = ignored_com[i];
        count++;
    }
    return ignored_brack;
}

char *mx_second_parse(char *ignored_com) {
    char *result_com = NULL;

    result_com = mx_del_brack(ignored_com);
    return result_com;
}
