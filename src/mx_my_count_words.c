
#include "ush.h"

int mx_count_words(const char *str, char c) {
    int res_count = 0;
    int count_symb = 0;

    if(!str || !c) {
        return -1;
    }
    for(int i = 0; i < mx_strlen(str); i++) 
        if(str[i] == c) {
            count_symb = 0;
        }
        else if(count_symb == 0) {
            res_count++;
            count_symb = 1;
        }
    return res_count;
}
