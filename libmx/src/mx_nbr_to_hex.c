#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *res = NULL;
    int i = 0;
    int size = 0;
    unsigned long temp = nbr;
    
    if (nbr == 0) return "0";
    while(temp != 0) {
        temp = temp / 16;
        size++;
    }
    res = mx_strnew(size);
    while(nbr != 0) {
        int buf = nbr % 16;
        nbr = nbr / 16;
        if (buf < 10)
            res[i] = buf + 48;
        else
            res[i] = buf + 87;
        i++;
    }
    mx_str_reverse(res);
    return res;
}
