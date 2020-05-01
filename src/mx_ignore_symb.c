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
    char **ignored_inp = NULL;

    while (splited_inp[count]) {
        count++;
    }
    ignored_inp = (char **) malloc((sizeof(char *)) * count + 1);
    for (int i = 0; i < count; i++)
        ignored_inp[i] = mx_strnew(1000);
    ignored_inp[count] = NULL;
    return ignored_inp;
}

char **mx_ignore_symb (char **splited_inp) {
    char **ignored_inp = init_ignored_inp(splited_inp);
    int *single_indexes = NULL;
    int *indexes_double_bracks = NULL;

    t_buffer_aud counters_aud = mx_init_aud_struct();
    t_ignored_symb ignored_struct = init_ignored_struct();
    while (splited_inp[ignored_struct.count]) {
        counters_aud.count_single = 0;
        counters_aud.j = 0;
        ignored_struct.ign_count = 0;
        indexes_double_bracks = mx_indexes_double_bracks(splited_inp[ignored_struct.count]);
        counters_aud.count_single = init_single_indexes(splited_inp[ignored_struct.count]);
        single_indexes = fill_single_indexes(counters_aud.count_single, splited_inp[ignored_struct.count]);
        for (int i = 0; i < mx_strlen(splited_inp[ignored_struct.count]); i++) {
            if (i == single_indexes[counters_aud.j + 1] && counters_aud.j < counters_aud.count_single)
                counters_aud.j++;
            if (i > single_indexes[counters_aud.j] && i < single_indexes[counters_aud.j + 1]) {
                ignored_struct.ign_count = mx_aud_for_ignore(ignored_inp, splited_inp, 
                                            ignored_struct.count, ignored_struct.ign_count, i);
                continue;
            }
            if (splited_inp[ignored_struct.count][i] == '\\') {
                if (mx_check_main_if_aud(i, indexes_double_bracks, counters_aud.count_double_bracks,
                    ignored_struct.count, splited_inp)) {
                ignored_struct.ign_count = mx_aud_for_ignore(ignored_inp, splited_inp, 
                    ignored_struct.count, ignored_struct.ign_count, i);
            }
            else {
                if (splited_inp[ignored_struct.count][i + 1] == ' ' 
                    && splited_inp[ignored_struct.count][i - 1] != '\\' ) {
                    i++;
                    ignored_inp[ignored_struct.count][ignored_struct.ign_count] = '#';
                    ignored_struct.ign_count++;
                }
                else {
                    i++;
                    ignored_struct.ign_count = mx_aud_for_ignore(ignored_inp, splited_inp, 
                        ignored_struct.count, ignored_struct.ign_count, i);
                    }
                }
            }
            else {
                ignored_struct.ign_count = mx_aud_for_ignore(ignored_inp, splited_inp, 
                    ignored_struct.count, ignored_struct.ign_count, i);
            }
        }
        free(indexes_double_bracks);
        ignored_struct.count++;
        free(single_indexes);
    }
    return ignored_inp;
}
