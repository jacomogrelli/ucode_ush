#include "ush.h"

static int *fill_single_indexes(int count_single, char *str) {
    int *single_indexes = (int *)malloc(sizeof(int) * count_single);
    int count = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\'') {
            single_indexes[count] = i;
            count++;
        }
    }
    return single_indexes;
}

static int init_single_indexes(char *str) {
    int count_single = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\'')
            count_single++;
    }
    if (count_single % 2 != 0)
        count_single--;
    return count_single;
}

static t_ignored_symb init_ignored_struct() {
    t_ignored_symb ignored_struct;

    ignored_struct.count = 0;
    ignored_struct.ign_count = 0;
    ignored_struct.first_index_no_ign = 0;
    ignored_struct.last_index_no_ign = 0;

    return ignored_struct;
}

static char **init_ignored_inp(char **splited_inp) {
    int count = 0;
    char **ignored_inp = (char **) malloc((sizeof(char *)) * 10);
    if (splited_inp)
    while (count < 10) {
        //ignored_inp[count] = (char *)malloc(sizeof(char) * 10);
        ignored_inp[count] = mx_strnew(1000);
        count++;
    }
    // printf("%d", count);
    ignored_inp[10] = NULL;
    return ignored_inp;
}

char **mx_ignore_symb (char **splited_inp) {
    char **ignored_inp = init_ignored_inp(splited_inp);
    t_ignored_symb ignored_struct = init_ignored_struct();
    int count_single = 0;
    int *single_indexes = NULL;
    int j = 0;

    while (splited_inp[ignored_struct.count]) {
        ignored_struct.ign_count = 0;
        j = 0;
        count_single = init_single_indexes(splited_inp[ignored_struct.count]);
        single_indexes = fill_single_indexes(count_single, splited_inp[ignored_struct.count]);
        // while (splited_inp[ignored_struct.count]) {
        //             count_single = init_single_indexes(splited_inp[ignored_struct.count]);
        //             single_indexes = fill_single_indexes(count_single, splited_inp[ignored_struct.count]);
        //     for (int i = 0; i < count_single; i++) {
        //         printf("%d ", single_indexes[i]);
        //     }
        //     printf("%s\n", splited_inp[ignored_struct.count]);
        //     ignored_struct.count++;
        // }
        //exit(0);
        for (int i = 0; i < mx_strlen(splited_inp[ignored_struct.count]); i++) {
                // if (i == single_indexes[j + 1] && j < count_single)
                //     j++;
                // if (i > single_indexes[j] && i < single_indexes[j + 1]) {
                //     ignored_inp[ignored_struct.count][ignored_struct.ign_count] = 
                //     splited_inp[ignored_struct.count][i];
                //     ignored_struct.ign_count++;
                //     continue;
                // }
            // if (splited_inp[ignored_struct.count][i] == '\\') {
            //     switch (splited_inp[ignored_struct.count][i]) {
            //         default: {
            //             i++;
            //             ignored_inp[ignored_struct.count][ignored_struct.ign_count] = 
            //                 splited_inp[ignored_struct.count][i];
            //             ignored_struct.ign_count++;
            //         break;
            //         }
            //     break;
            //     }
            // }
            // else {
                ignored_inp[ignored_struct.count][ignored_struct.ign_count] = 
                    splited_inp[ignored_struct.count][i];
                 //printf("%c", ignored_inp[ignored_struct.count][i]);
                ignored_struct.ign_count++;
            // }
        }
        //printf("%c", '\n');
        // printf("%s", ignored_inp[ignored_struct.count]);
        ignored_struct.count++;
        //free(single_indexes);
    }
    // for(int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 11; j++) {
    //         printf("%c", ignored_inp[i][j]);
    //     }
    //     printf("%c", '\n');
    // }
    // printf("%c", '\n');
    int t = 0;
    while (ignored_inp[t] != NULL) {
        printf("%s", ignored_inp[t]);
        t++;
    }
    printf("%c", '\n');
    // printf("0 :%s\n", ignored_inp[0]);
    // printf("1 :%s\n", ignored_inp[1]);
    // printf("2 :%s\n", ignored_inp[2]);
    // printf("3 :%s\n", ignored_inp[3]);
    // printf("4 :%s\n", ignored_inp[4]);
    // printf("5 :%s\n", ignored_inp[5]);
    // printf("6 :%s\n", ignored_inp[6]);
    // printf("7 :%s\n", ignored_inp[7]);
    // printf("8 :%s\n", ignored_inp[8]);
    // printf("9 :%s\n", ignored_inp[9]);
     exit(0);
    return ignored_inp;
}
