#include "ush.h"

// static int count_logical(char *ignored_brack) {
//     int res = 0;

//     for (int i =0; i < mx_strlen(ignored_brack); i++) {
//         if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
//             && ignored_brack[i + 2] == ' ')
//             res++;
//         if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
//             && ignored_brack[i + 2] == ' ')
//             res++;
//     }
//     return res;
// }

// static int *fill_or_and_arr(char *ignored_brack) {
//     int count_logi = count_logical(ignored_brack);
//     int *logical_arr = (int *)malloc(sizeof(int) * (count_logi));
//     int j = 0;

//     for (int i = 0; i < mx_strlen(ignored_brack); i++) {
//         if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
//             && ignored_brack[i + 2] == ' ') {
//             logical_arr[j] = 1;
//             j++;
//         }
//         if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
//             && ignored_brack[i + 2] == ' ') {
//             logical_arr[j] = 2;
//             j++;
//         }
//     }
//     return logical_arr;
// }

// static void fill_splited_logi(char **splited_logi, char *ignored_brack) {
//     int count = 0;
//     int j = 0;

//     for (int i = 0; i < mx_strlen(ignored_brack); i++, j++) {
//         if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
//             && ignored_brack[i + 2] == ' ') {
//             i = i + 2;
//             count++;
//             j = 0;
//         }
//         if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
//             && ignored_brack[i + 2] == ' ') {
//             i = i + 2;
//             count++;
//             j = 0;
//         }
//         splited_logi[count][j] = ignored_brack[i];
//     }
// }

// int *mx_fill_logical_arr(char *ignored_brack) {
//     int count_logi = count_logical(ignored_brack);
//     int *logical_arr = (int *)malloc(sizeof(int) * (count_logi + 1));
//     int j = 0;

//     for (int i = 0; i < mx_strlen(ignored_brack); i++) {
//         if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
//             && ignored_brack[i + 2] == ' ') {
//             logical_arr[j] = i + 1;
//             j++;
//         }
//         if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
//             && ignored_brack[i + 2] == ' ') {
//             logical_arr[j] = i + 1;
//             j++;
//         }
//     }
//     logical_arr[count_logi] = 1000;
//     return logical_arr;
// }

static char *fill_res_arr(char *ignored_brack) {
    int res_count = 0;
    bool first_add = true;
    char *buffer = mx_strnew(2000);

    for (int i = 0; i < mx_strlen(ignored_brack); i++) {
        if(ignored_brack[i] == '|' && ignored_brack[i + 1] == '|'
            && ignored_brack[i + 2] == ' ') {
            first_add = false;
            if (buffer[res_count - 1] != '|') {
                buffer[res_count] = '|';
                res_count++;
            }
            i += 2;
        }
        if(ignored_brack[i] == '&' && ignored_brack[i + 1] == '&'
            && ignored_brack[i + 2] == ' ') {
            first_add = true;
            if (buffer[res_count - 1] != '|') {
                buffer[res_count] = '|';
                res_count++;
            }
            i += 2;
        }
        if (first_add) {
            buffer[res_count] = ignored_brack[i];
            res_count++;
        }
    }
     if (buffer[mx_strlen(buffer) - 1] == '|') {
         buffer[mx_strlen(buffer) - 1] = '\0';
     }
    return buffer;
}

char **mx_or_and(char *ignored_brack) {
    char *buffer = fill_res_arr(ignored_brack);
    char **splited_logi = mx_strsplit(mx_strtrim(buffer), '|');

    return splited_logi;
}
