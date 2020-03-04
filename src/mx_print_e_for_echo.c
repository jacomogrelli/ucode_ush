#include "ush.h"

void mx_print_e_for_echo(char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\\') {
            switch (str[i + 1])
            {
            case 'n': {
                printf("%c", '\n');
                i++;
            }
            default: {
                i++;
                printf("%c", str[i]);
            }
            break;
            }
        }
        else
            printf("%c", str[i]);
    }
}
