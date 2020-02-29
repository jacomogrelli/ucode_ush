#include "ush.h"

static void check_lnk_p_flag (char **splited_arg, t_dirs_cd *dirs_cd,
                            t_errors_cd *errors) {
    struct stat buf;
    char linked[500];

    lstat(splited_arg[1], &buf);
    if (S_ISLNK(buf.st_mode)) {
        readlink(splited_arg[1], linked, 500);
    }
    errors = NULL;
    dirs_cd = NULL;
    exit(0);

}

static void check_lnk_s_flag(char **splited_arg, t_dirs_cd *dirs_cd,
                            t_errors_cd *errors) {
    struct stat buf;
    lstat(splited_arg[1], &buf);
    if (S_ISLNK(buf.st_mode)) {
        mx_printerr("cd: not a directory: ");
        mx_printerr(splited_arg[1]);
        mx_printerr("\n");
        errors->returned_value = 1;
    }
    else {
        chdir(splited_arg[1]);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", splited_arg[1], 1);
    }
}

static void cd_with_min_flag(t_dirs_cd *dirs_cd) {
    char *buff_pwd = mx_strnew(mx_strlen(dirs_cd->get_pwd));

    buff_pwd = mx_strcpy(buff_pwd, dirs_cd->get_pwd);
    chdir(dirs_cd->get_old_pwd);
    setenv("PWD", dirs_cd->get_old_pwd, 1);
    setenv("OLDPWD", buff_pwd, 1);
}

void mx_cd_with_flags(char **splited_arg, t_dirs_cd *dirs_cd,
                    t_flags_cd *flags_cd, t_errors_cd *errors) {
    if (splited_arg) {
        if (flags_cd->min_flag) {
            cd_with_min_flag(dirs_cd);
        }
        else if (flags_cd->s_flag) {
            check_lnk_s_flag(splited_arg, dirs_cd, errors);
        }
        else {
            check_lnk_p_flag(splited_arg, dirs_cd, errors);
        }
    }
    splited_arg = NULL;
    dirs_cd = NULL;
}
