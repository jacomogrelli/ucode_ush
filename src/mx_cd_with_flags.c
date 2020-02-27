#include "ush.h"

static void cd_with_min_flag(t_dirs_cd *dirs_cd) {
    char *buff_pwd = mx_strnew(mx_strlen(dirs_cd->get_pwd));

    buff_pwd = mx_strcpy(buff_pwd, dirs_cd->get_pwd);
    setenv("PWD", dirs_cd->get_old_pwd, 1);
    setenv("OLDPWD", buff_pwd, 1);
}

void mx_cd_with_flags(char **splited_arg, t_dirs_cd *dirs_cd, t_flags_cd *flags_cd) {
    if (splited_arg) {
        if (flags_cd->min_flag) {
            cd_with_min_flag(dirs_cd);
        }
    }
    splited_arg = NULL;
    dirs_cd = NULL;
}
