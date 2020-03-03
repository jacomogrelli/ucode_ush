#ifndef ONECHAIEV_H
#define ONECHAIEV_H

#include "libmx.h"

#define MX_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)  /* 'l'symbolic link */

/* структура для переменных среды, которую принимаем перед
инициализацией ush, передаем в нее и меняем, если это делает оригиная
функция */
typedef struct s_envp {
    char *name;
    char *val;
    struct s_envp *next;
} t_envp;

//структура для which
typedef struct s_wh {
    char **path;
    char *flags;
    int pos;
    bool key_s;
    t_envp *find;
} t_wh;

//delete me

//------main part------
//заполнение структуры переменных среды
t_envp *mx_envp_fill(char **envp);
//выделение памяти и зануление следующего елемента s_envp
void mx_envp_add(t_envp **res, char *data);
//замена текущего элемента s_envp
void mx_envp_replace(t_envp **res, char *data);
void mx_ush_init(t_envp *var);
void mx_get_command(t_envp *var, char **com);
void mx_run_cd(char *args);
void mx_push_var();

//------builtins------
//------exit------
void mx_run_exit(t_envp *var, char **com);
//------pwd------
void mx_pwd_run(t_envp *var, char **com);
//------which------
void mx_which_run(t_envp *var, char **com);
void mx_which_add_back(t_envp **res, char *name, char *val);
void mx_which_err(char c, t_envp *var, int flag);
t_wh *mx_which_res_init(void);
t_wh *mx_which_get_fp(t_envp *var, char **com, t_wh *res);
void mx_which_cleaner(t_envp *var, t_wh *res, int flag);
void mx_which_out(t_envp *var, t_wh *res, char **com);
void mx_which_finder(t_envp *var, t_wh *res, char **com);

//------exec------
void mx_run_exec(char **com, t_envp *var);
void mx_exec_err_out(char *com, int err, t_envp *var);

#endif
