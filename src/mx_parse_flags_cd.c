#include "ush.h"

static void init_flags_cd(t_flags_cd *flags_cd) {
    flags_cd->min_flag = false;
    flags_cd->p_flag = false;
    flags_cd->s_flag = false;
}

bool mx_parse_flags_cd (char **splited_arg) {
    bool res = false;
    t_flags_cd *flags_cd = (t_flags_cd *)malloc(sizeof(t_flags_cd));
    
    init_flags_cd(flags_cd);
    if (splited_arg[1][0] == '-') {
        if (!splited_arg[1][1])
            flags_cd->min_flag = true;
    }
    return res;
}
