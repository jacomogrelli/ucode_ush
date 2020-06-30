#include "ush.h"

static void trim_input(char **splited_inp) {
    int count = 0;

    while (splited_inp[count]) {
        splited_inp[count] = mx_strtrim(splited_inp[count]);
        count++;
    }   
}

char **mx_main_parse (char **splited_inp) {
    char **res_inp = NULL;
    trim_input(splited_inp);
    res_inp = mx_ignore_symb(splited_inp);
    return res_inp;
}

