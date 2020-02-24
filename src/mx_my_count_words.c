
#include "ush.h"

int mx_my_count_words(const char *str, char c) {
    int res_count = 0;

    if(!str || !c) {
        return -1;
    }
    for(int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == c)
            res_count++;
    }
    return res_count;
}
