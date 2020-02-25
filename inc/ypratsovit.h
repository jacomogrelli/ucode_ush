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

void mx_errors_cd (char **inp_line, t_errors_cd *errors);
char **mx_mystrsplit(const char *s, char c);
void mx_e_too_many_arg_cd (char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
int mx_dirorfile(const char *obj);
void mx_e_no_dirorfile_cd (char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
void mx_e_notpwd_cd(char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
void mx_e_nodir_after_split_pwd_cd(char **splited_arg, t_errors_cd *errors, t_flags_cd *flags_cd);
char *mx_my_repl_substr_cd(char *dst, char *src);
char *mx_my_repl_substr(char *main_str, char *dst, char *src);
void mx_errors_for_comands(char **splited_input);
char *mx_join_for_cd (char **splited_inp);
void mx_change_pwd_in_cd(char **splited_arg);
void mx_change_old_pwd_in_cd(char **splited_arg);
int mx_my_count_words(const char *str, char c);
t_flags_cd * mx_parse_flags_cd (char **splited_arg);

#endif
