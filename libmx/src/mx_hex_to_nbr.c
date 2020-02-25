#include "libmx.h"

static double mx_pow_rec(int n, unsigned int pow);

unsigned long mx_hex_to_nbr(const char *hex){
    int len = 0;
    unsigned long res = 0;
    int i = 0;
    
    if (!hex)
        return 0;
    while(hex[len] != '\0') {
        len++;
    }
    while (i < len) {
        if (hex[i] > 47 && hex[i] < 58) {
            res += (hex[i] - 48) * mx_pow_rec(16,len - i - 1);
        }
        if (hex[i] > 96 && hex[i] < 123) {
                 res += (hex[i] - 87) * mx_pow_rec(16,len - i - 1);
        }
        else if (hex[i] > 64 && hex[i] < 91) {
            res += (hex[i] - 55) * mx_pow_rec(16,len - i - 1);
        }
        i++;
    }
    return res;
}

static double mx_pow_rec(int n, unsigned int pow) {
    if (pow == 0) {
        return 1;
    }
    return n * mx_pow_rec(n, pow-1);
}

