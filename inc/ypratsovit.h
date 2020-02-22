#ifndef YPRATSOVIT_H
#define YPRATSOVIT_H

// typedef struct s_errors_cd {

// } t_errors_cd;

bool mx_errors_cd(char * arguments);
char **mx_mystrsplit(const char *s, char c);
void mx_e_too_many_arg_cd (char **splited_arg);
int mx_dirorfile(const char *obj);
void mx_e_no_dirorfile_cd (char **splited_arg);
void mx_e_notpwd_cd(char **splited_arg);
void mx_e_nodir_after_split_pwd_cd(char **splited_arg);
char *mx_my_repl_substr_cd(char *dst, char *src);

#endif
