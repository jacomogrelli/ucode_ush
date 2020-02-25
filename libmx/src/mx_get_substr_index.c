#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(!str || !sub)
        return -2;
    for(int i = 0; str[i]; i++) {
        if(str[i] == sub[0]) {
            for(int j = 0, k = i; str[k] && sub[j] == str[k]; k++, j++) {
                if (sub[j + 1] == '\0')
                    return i;
            }
        }
    }
    return -1;
}
