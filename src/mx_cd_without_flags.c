#include "ush.h"

static void cd_with_one_arg(char **splited_arg, t_dirs_cd *dirs_cd) {
        struct stat buf;

        lstat(splited_arg[0], &buf);
        chdir(splited_arg[0]);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", splited_arg[0], 1);
        if (!(S_ISLNK(buf.st_mode)))
            mx_set_correct_path();
}

void mx_cd_without_flags(char **splited_arg, t_dirs_cd *dirs_cd) {
    if (!splited_arg) {
        chdir(dirs_cd->get_home);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", dirs_cd->get_home, 1);
        mx_set_correct_path();
    }
    else
        cd_with_one_arg(splited_arg, dirs_cd);
}
