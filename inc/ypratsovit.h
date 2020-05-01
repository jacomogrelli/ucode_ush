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

typedef struct s_flags_echo {
    bool n_flag;
    bool e_flag;
    bool E_flag;
    bool act_flag;
} t_flags_echo;

typedef struct s_history {
    int nuber_line;
    int count;
    char **value;
    int spaces_first;
    int spaces_second;
} t_history;

typedef struct s_ignored_symb {
    int count;
    int ign_count;
    int first_index_no_ign;
    int last_index_no_ign; 
} t_ignored_symb;

typedef struct s_vars {
    int vars;
    char **change_var;
    char **buffer_vars;
    char *res_str;
    char *buffer_replace;
    char *get_from_env;
} t_vars;

typedef struct s_buffer_aud {
    int count_single;
    int j;
    int count_double_bracks;
} t_buffer_aud;

typedef struct s_buffer_aud_vars {
    int te;
    bool check;
    int small_count;
} t_buffer_aud_vars;

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
void mx_cd_with_flags(char **splited_arg, t_dirs_cd *dirs_cd, 
                      t_flags_cd *flags_cd, t_errors_cd *errors);
void mx_set_correct_path();
void mx_run_echo_command(t_envp *var, char **splited_input);
void mx_print_e_for_echo(char *str);
t_history *mx_init_story();
void mx_save_story(char *input_line, t_history *history);
void mx_free_story(t_history *history);
void mx_print_strory(t_envp *var, t_history *history);
int mx_count_numbers(int number);
void mx_handler();
void mx_if_eof(t_envp *var, char **ex);
bool mx_cal_history(t_envp *var, t_ush_init *res, t_history *history);
void mx_uniq_prompt();
void mx_call_true(t_envp *var);
void mx_call_false(t_envp *var);
void mx_help_command(t_envp *var, char **com);
void mx_return_command(t_envp *var, char **com);
void mx_chdir_command(t_envp *var, char** com);
void mx_apropos_command(t_envp *var, char **com);
void mx_arch_command(t_envp *var, char** com);
char **mx_main_parse (char **splited_inp);
char **mx_ignore_symb (char **splited_inp);
char *mx_second_parse(char *ignored_com);
char *mx_del_brack(char * ignored_com);
char *mx_change_var(char *ignored_com, t_envp *var);
int *mx_indexes_double_bracks(char *str);
int mx_aud_for_ignore(char **ignored_inp, char **splited_inp, int first_count,
                      int second_count, int third_count);
bool mx_check_main_if_aud(int i, int *indexes_double_bracks, 
                          int count_double_bracks, int count, char **splited_inp);
t_buffer_aud mx_init_aud_struct();
char *mx_res_aud_str(char *res_str, char *buffer_replace);
int mx_count_buf_aud(int buffer_count, char *buffer, char *ignored_com, int i);
char **buffer_split_aud(char **buffer_split, t_buffer_aud_vars st_buffer_aud_vars, char **change_var);
void mx_main_loop_aud(t_ignored_symb ignored_struct, int *single_indexes, int *indexes_double_bracks,
                      t_buffer_aud counters_aud, char **splited_inp, char **ignored_inp);
#endif
