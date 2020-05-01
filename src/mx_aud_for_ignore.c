#include "ush.h"

int mx_aud_for_ignore(char **ignored_inp, char **splited_inp, int first_count, 
                      int second_count, int third_count) {
    ignored_inp[first_count][second_count] = 
    splited_inp[first_count][third_count];
    second_count++;
    return second_count;
}

bool mx_check_main_if_aud(int i, int *indexes_double_bracks, 
                          int count_double_bracks, int count, char **splited_inp) {
    if (i > indexes_double_bracks[count_double_bracks] 
        && i < indexes_double_bracks[count_double_bracks + 1]
        && indexes_double_bracks[count_double_bracks] != 1000
        && indexes_double_bracks[count_double_bracks + 1] != 1000
        && splited_inp[count][i + 1] != '\\') {
            return true;
        }
        else 
            return false;

}

t_buffer_aud mx_init_aud_struct() {
    t_buffer_aud counters_aud;

    counters_aud.count_single = 0;
    counters_aud.j = 0;
    counters_aud.count_double_bracks = 0;

    return counters_aud;
}
