#include "ush.h"

void mx_print_e_for_echo(char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '\\') {
            switch (str[i + 1])
            {
            case 'n': {
                printf("%c", '\n');
                i++;
                break;
            }
            case 'a': {
                printf("%c", '\a');
                i++;
                break;
            }
            case 'v': {
                printf("%c", '\v');
                i++;
                break;
            }
            case 't': {
                printf("%c", '\t');
                i++;
                break;
            }
            case 'b': {
                printf("%c", '\b');
                i++;
                break;
            }
            case 'f': {
                printf("%c", '\f');
                i++;
                break;
            }
            case 'r': {
                printf("%c", '\f');
                i++;
                break;
            }
            default: {
                i++;
                printf("%c", str[i]);
                break;
            }
            break;
            }
        }
        else
            printf("%c", str[i]);
    }
}