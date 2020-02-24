#ifndef ONECHAIEV_H
#define ONECHAIEV_H

/* структура для переменных среды, которую принимаем перед
инициализацией ush, передаем в нее и меняем, если это делает оригиная
функция */
typedef struct s_envp {
    char *name;
    char *val;
    struct s_envp *next;
} t_envp;

//------main part------
//заполнение структуры переменных среды
t_envp *mx_envp_fill(char **envp);
//выделение памяти и зануление следующего елемента s_envp
void mx_envp_add(t_envp **res, char *data);
//замена текущего элемента s_envp
void mx_envp_replace(t_envp **res, char *data);
void mx_ush_init(t_envp *var);
void mx_get_command(char **command);
void mx_run_cd(char *args);
void mx_push_var();

//------builtins------
int mx_run_exit(char *com);

//------exec------
void mx_run_exec(char **com);
void mx_exec_err_out(char *com, int err);

#endif
