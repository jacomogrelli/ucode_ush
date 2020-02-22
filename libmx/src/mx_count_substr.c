#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int sub_len = 0;

    if(!str || !sub)
        return -1;
    sub_len = mx_strlen(sub);
    for(int i = 0; str[i]; i++) {
        if (str[i] == sub[0]) {
            if (mx_strncmp(str + i, sub, sub_len) == 0) {
                count++;
                i += sub_len - 1;
            }
        }
    }
    return count;
}
