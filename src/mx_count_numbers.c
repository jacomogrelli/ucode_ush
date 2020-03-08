#include "ush.h"

int mx_count_numbers(int number) {
    int res = 0;
    if (number == 0)
        return 1;
    while (number != 0) {
        number = number / 10;
        res++;
    }
    return res;
}
