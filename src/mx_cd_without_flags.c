#include "ush.h"

void mx_cd_without_flags(char **splited_arg, t_dirs_cd *dirs_cd) {
    if (!splited_arg) {
        chdir(dirs_cd->get_home);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", dirs_cd->get_home, 1);
    }
}
