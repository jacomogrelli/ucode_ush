#include "ush.h"

static void cd_with_one_arg(char **splited_arg, t_dirs_cd *dirs_cd) {
    if (splited_arg[0] && !splited_arg[1]) {
        chdir(splited_arg[0]);
        if (mx_strcmp(splited_arg[0], ".") != 0
            && mx_strcmp(splited_arg[0], "./") != 0) {
            setenv("OLDPWD", dirs_cd->get_pwd, 1);
            setenv("PWD", splited_arg[0], 1);
        }
        else {
            setenv("OLDPWD", dirs_cd->get_pwd, 1);
        }
        printf("%s ", getenv("PWD"));
    }
}

void mx_cd_without_flags(char **splited_arg, t_dirs_cd *dirs_cd) {
    if (!splited_arg) {
        chdir(dirs_cd->get_home);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", dirs_cd->get_home, 1);
    }
    else
        cd_with_one_arg(splited_arg, dirs_cd);
}
