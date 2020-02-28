#include "ush.h"

void mx_parse_flags_cd (char **splited_arg, t_flags_cd *flags_cd) {

    if (splited_arg[0][0] != '-') {
        flags_cd->act_flag = false;
        return;
    }
    if (splited_arg[0][0] == '-' && !splited_arg[0][1]) {
        flags_cd->act_flag = true;
        flags_cd->min_flag = true;
    }
    else {
        flags_cd->act_flag = true;
        for (int i = 1; i < mx_strlen(splited_arg[0]); i++) {
            if (splited_arg[0][i] == 'P')
                flags_cd->p_flag = true;
            else if (splited_arg[0][i] == 's')
                flags_cd->s_flag = true;
            else {
                flags_cd->act_flag = false;
                return;
            }
        }
    }
}
