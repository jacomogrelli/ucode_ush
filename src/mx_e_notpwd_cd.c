#include "ush.h"

void mx_e_notpwd_cd (char **splited_arg) {
    int count = 0;
    char *env_str = getenv("PWD");

    while (splited_arg[count]) {
        count++;
    }
    if (count == 2) {
        
    }
    
}
