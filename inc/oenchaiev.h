#ifndef ONECHAIEV_H
#define ONECHAIEV_H

#include "libmx.h"

#define MX_PARS_PAIR "\"'{}"
#define MX_PARS_ERR "`()"
#define MX_PARS_TSTOP " \n\t\r\v\f/"

#define MX_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)  /* 'd'irectory */
#define MX_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)  /* 'l'symbolic link */

typedef struct s_comm {
    char **com;
    char logic;
    int status;
    struct s_comm *next;
}              t_comm;

typedef struct s_ush_init {
    size_t bufsize;
    char *iline;
    char **com;
    char **solo_com;
    char **ignored_com;
    char *ignored_brack;
    char **splited_or_and;
    int *logical_arr;
    int count_logic;
    int do_whith_logic;
    int i;
    t_comm *argv;
}              t_ush_init;

/* структура для переменных среды, которую принимаем перед
инициализацией ush, передаем в нее и меняем, если это делает оригиная
функция */
typedef struct s_envp {
    char *name;
    char *val;
    struct s_envp *next;
}              t_envp;

//структура для which
typedef struct s_wh {
    char **path;
    char *flags;
    int pos;
    bool key_s;
    t_envp *find;
}              t_wh;

//структура для env
typedef struct s_nv {
    int i;
    int u;
    int p;
    t_list *exp;
    t_list *unset;
    t_list *path;
    char **com;
}              t_nv;

//------parser------
void mx_parser(char *line, t_comm **res, char c, t_envp *var);
void mx_parser_line(char *line, t_comm **res, t_envp *var);
void mx_parser_cleaner(t_comm **res);
void mx_ush_rescleaner(t_ush_init **res);
t_ush_init *mx_ush_struct_init();
char **mx_parser_paris(t_envp *var, char *line);
int mx_parser_pais(t_envp *var, char *line);
char *mx_parser_tilda(char *line);
void mx_parser_err(t_envp *var, char c, int flag);



//------main part------
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

//------envp------
t_envp *mx_envp_i_fill(void); //filling if empty env
//заполнение структуры переменных среды
t_envp *mx_envp_fill(char **envp);
//выделение памяти и зануление следующего елемента s_envp
void mx_envp_add(t_envp **res, char *data);
//замена текущего элемента s_envp
void mx_envp_replace(t_envp **res, char *data);
void mx_print_var(t_envp *var, char *com);
t_envp *mx_envp_sort(t_envp *var);
void mx_envp_shlvl(t_envp *var);
void mx_export_run(t_envp *var, char **com);

//------set/unset------
void mx_unset_run(t_envp *var, char **com);
void mx_set_run(t_envp *var, char **com);

//------export------
void mx_export_run(t_envp *var, char **com);
void mx_export_new_var(t_envp *var, char *com);
void mx_export_argfree(t_envp *var);
void mx_export_from_envp(t_envp *var, char *com);

//------env------
void mx_env_run(t_envp *var, char **com);
void mx_env_func(t_envp *var, char **com);
void mx_env_getp(t_nv *res, char **com);

//------signal------
// void mx_signal_run(t_envp *var);
// void mx_sighandler();
// void mx_sighandler(int key, t_envp *var);

#endif
