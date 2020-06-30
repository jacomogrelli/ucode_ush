#include "ush.h"

static void get_dirs_cd(t_dirs_cd *dirs_cd) {
    dirs_cd->get_home = getenv("HOME");
    dirs_cd->get_old_pwd = getenv("OLDPWD");
    dirs_cd->get_pwd = getenv("PWD");
}

static void init_flags_cd(t_flags_cd *flags_cd) {
    flags_cd->min_flag = false;
    flags_cd->p_flag = false;
    flags_cd->s_flag = false;
    flags_cd->act_flag = false;
}


static void free_mem(char **splited_arg, t_flags_cd *flags_cd,
                    t_errors_cd *errors, t_dirs_cd *dirs_cd) {
    int count = 0;
    if (splited_arg) {
        while (splited_arg[count]) {
                free(splited_arg[count]);
            count++;
        }
        free(splited_arg);
    }
    free(flags_cd);
    free(errors);
    free(dirs_cd);
}

void mx_run_cd_commnd(t_envp *var, char **splited_input) {
        t_flags_cd *flags_cd = (t_flags_cd *)malloc(sizeof(t_flags_cd));
        t_errors_cd *errors = (t_errors_cd *)malloc(sizeof(t_errors_cd));
        t_dirs_cd *dirs_cd = (t_dirs_cd *)malloc(sizeof(t_dirs_cd));
        char **splited_arg = NULL;

        init_flags_cd(flags_cd);
        get_dirs_cd(dirs_cd);
        splited_arg = mx_errors_for_comands(splited_input, flags_cd, errors);
        if (errors->returned_value == 0) {
            if (!flags_cd->act_flag) {
                mx_cd_without_flags(splited_arg, dirs_cd);
            }
            else {
                mx_cd_with_flags(splited_arg, dirs_cd, flags_cd, errors);
            }
            mx_envp_replace(&var, "?=0");
        }
        else
            mx_envp_replace(&var, "?=1");
            free_mem(splited_arg, flags_cd, errors, dirs_cd);
}
