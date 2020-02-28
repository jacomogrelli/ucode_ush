#ifndef YPRATSOVIT_H
#define YPRATSOVIT_H

#include "posix_lib.h"

typedef struct s_errors_cd {
    int returned_value;
} t_errors_cd;

typedef struct s_flags_cd {
    bool s_flag;
    bool p_flag;
    bool min_flag;
    bool act_flag;
} t_flags_cd;

typedef struct s_dirs_cd {
    char *get_home;
    char *get_pwd;
    char *get_old_pwd;
} t_dirs_cd;

char **mx_errors_cd (char **inp_line, t_errors_cd *errors, t_flags_cd *flags_cd);
char **mx_mystrsplit(const char *s, char c);
void mx_e_too_many_arg_cd (char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
int mx_dirorfile(const char *obj);
void mx_e_no_dirorfile_cd (char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
void mx_e_notpwd_cd(char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
void mx_e_nodir_after_split_pwd_cd(char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
char *mx_my_repl_substr_cd(char *dst, char *src);
char *mx_my_repl_substr(char *main_str, char *dst, char *src);
char **mx_errors_for_comands(char **splited_input, t_flags_cd *flags_cd, t_errors_cd *errors);
char *mx_join_for_cd (char **splited_inp);
void mx_change_pwd_in_cd(char **splited_arg);
void mx_change_old_pwd_in_cd(char **splited_arg);
int mx_my_count_words(const char *str, char c);
void mx_parse_flags_cd (char **splited_arg, t_flags_cd *flags_cd);
void mx_run_cd_commnd(t_envp *var, char **splited_input);
void mx_cd_without_flags(char **splited_arg, t_dirs_cd *dirs_cd);
void mx_cd_with_flags(char **splited_arg, t_dirs_cd *dirs_cd, t_flags_cd *flags_cd);

#endif
