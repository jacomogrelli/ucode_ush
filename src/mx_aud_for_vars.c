#include "ush.h"

char *mx_res_aud_str(char *res_str, char *buffer_replace) {
    free(res_str);
    res_str = mx_strnew(mx_strlen(buffer_replace));
    res_str = mx_strcpy(res_str, buffer_replace);
    free(buffer_replace);
    return res_str;
}

int mx_count_buf_aud(int buffer_count, char *buffer, char *ignored_com, int i) {
    buffer[buffer_count] = ignored_com[i];
    buffer_count++;
    buffer[buffer_count] = '|';
    buffer_count++;
    return buffer_count;
}

char **buffer_split_aud(char **buffer_split, t_buffer_aud_vars st_buffer_aud_vars, char **change_var) {
    while (buffer_split[st_buffer_aud_vars.te]) {
        for (int i = 0; i < mx_strlen(buffer_split[st_buffer_aud_vars.te]); i++) {
            if (buffer_split[st_buffer_aud_vars.te][i] != '$'
                && buffer_split[st_buffer_aud_vars.te][i] != '{'
                && buffer_split[st_buffer_aud_vars.te][i] != '}'
                && buffer_split[st_buffer_aud_vars.te][i] != ' ') {
                change_var[st_buffer_aud_vars.te][st_buffer_aud_vars.small_count] 
                    = buffer_split[st_buffer_aud_vars.te][i];
                st_buffer_aud_vars.small_count++;
            }
        }
        st_buffer_aud_vars.te++;
        st_buffer_aud_vars.small_count = 0;
    }
    return buffer_split;
}

void mx_main_loop_aud(t_ignored_symb ignored_struct, int *single_indexes, int *indexes_double_bracks,
                      t_buffer_aud counters_aud, char **splited_inp, char **ignored_inp) {
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
}
