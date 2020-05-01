#include "ush.h"

int *mx_indexes_double_bracks(char *str) {
    int count_bracks = 0;

    int *res_arr = NULL;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\"')
            count_bracks++;
    }
    res_arr = (int *)malloc(sizeof(int) * (count_bracks + 1));
    res_arr[count_bracks + 1] = 1000;
    count_bracks = 0;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\"') {
            res_arr[count_bracks] = i;
            count_bracks++;
        }
    }
    if (count_bracks % 2 != 0 && count_bracks != 0)
        res_arr[count_bracks - 1] = 1000;
    return res_arr;
}
