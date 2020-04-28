#include "ush.h"

static int count_logical(char *ignored_brack) {
    int res = 1;

    for (int i =0; i < mx_strlen(ignored_brack); i++) {
        if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
            && ignored_brack[i + 2] == ' ')
            res++;
        if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
            && ignored_brack[i + 2] == ' ')
            res++;
    }
    return res;
}

static void fill_splited_logi(char **splited_logi, char *ignored_brack) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < mx_strlen(ignored_brack); i++, j++) {
        if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
            && ignored_brack[i + 2] == ' ') {
            i = i + 2;
            count++;
            j = 0;
        }
        if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
            && ignored_brack[i + 2] == ' ') {
            i = i + 2;
            count++;
            j = 0;
        }
        splited_logi[count][j] = ignored_brack[i];
    }
}

int *mx_fill_logical_arr(char *ignored_brack) {
    int count_logi = count_logical(ignored_brack) - 1;
    int *logical_arr = (int *)malloc(sizeof(int) * (count_logi + 1));
    int j = 0;

    for (int i = 0; i < mx_strlen(ignored_brack); i++) {
        if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
            && ignored_brack[i + 2] == ' ') {
            logical_arr[j] = 1;
            j++;
        }
        if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
            && ignored_brack[i + 2] == ' ') {
            logical_arr[j] = 2;
            j++;
        }
    }
    logical_arr[j] = 0;
    return logical_arr;
}

char **mx_or_and(char *ignored_brack) {
    int count_logi = count_logical(ignored_brack);
    char **splited_logi = (char **)malloc(sizeof(char*) * count_logi + 1);

    for(int i = 0; i < count_logi; i++)
        splited_logi[i]= mx_strnew(mx_strlen(ignored_brack));
    fill_splited_logi(splited_logi, ignored_brack);
    splited_logi[count_logi] = NULL;
    return splited_logi;
}
