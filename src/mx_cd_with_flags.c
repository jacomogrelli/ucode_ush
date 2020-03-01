#include "ush.h"

static char *join_res_dir(char **splited_arg, char *linked) {
    char *res_dir = NULL;
    char *buff_str = NULL;
    int count = 0;

    for (int i = mx_strlen(splited_arg[1]) - 1; i >= 0; i--) {
        if (splited_arg[1][i] == '/') {
            count = i + 1;
            break;
        }
    }
    buff_str = mx_strnew(count);
    for (int i = 0; i < count; i++)
        buff_str[i] = splited_arg[1][i];
    if (linked[0] != '/')
        res_dir = mx_strjoin(buff_str, linked);
    else {
        res_dir = mx_strnew(mx_strlen(linked));
        res_dir = mx_strcpy(res_dir, linked);
    }
    free(buff_str);
    return res_dir;
}

static void check_lnk_p_flag (char **splited_arg, t_dirs_cd *dirs_cd) {
    struct stat buf;
    char linked[500];
    char *path_in_lnk = NULL;
    if (splited_arg[1][mx_strlen(splited_arg[1]) - 1] == '/')
        splited_arg[1][mx_strlen(splited_arg[1]) - 1] = '\0';

    lstat(splited_arg[1], &buf);
    if (S_ISLNK(buf.st_mode)) {
        readlink(splited_arg[1], linked, 500);
        path_in_lnk = join_res_dir(splited_arg, linked);
        chdir(path_in_lnk);
        setenv("OLDPWD", dirs_cd->get_pwd, 1);
        setenv("PWD", path_in_lnk, 1);
        mx_set_correct_path();
        free(path_in_lnk);
    }
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
        mx_set_correct_path();
    }
}

static void cd_with_min_flag(t_dirs_cd *dirs_cd) {
    char *buff_pwd = mx_strnew(mx_strlen(dirs_cd->get_pwd));

    buff_pwd = mx_strcpy(buff_pwd, dirs_cd->get_pwd);
    chdir(dirs_cd->get_old_pwd);
    setenv("PWD", dirs_cd->get_old_pwd, 1);
    setenv("OLDPWD", buff_pwd, 1);
    mx_set_correct_path();
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
            check_lnk_p_flag(splited_arg, dirs_cd);
        }
    }
}
