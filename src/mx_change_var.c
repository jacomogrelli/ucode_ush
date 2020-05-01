#include "ush.h"

static int count_vars(char *ignored_com) {
    int res = 0;

    for (int i = 0; i < mx_strlen(ignored_com); i++) {
        if ((ignored_com[i] == '$' && ignored_com[i + 1] != ' ' 
            && ignored_com[i + 1] && ignored_com[i + 1] != '}') 
            || (ignored_com[i] == '$' && i == 0) 
            || (ignored_com[i] == '$' && ignored_com[i - 1] == ' '))
                res++;
    }
    return res;
}

static char **init_buff1_vars(int vars) {
    char **res = (char**)malloc(sizeof(char *) * vars);

    for (int i = 0; i < vars; i++) {
        res[i] = mx_strnew(2000);
    }
    res[vars] = NULL;
    return res;
} 

// static char **init_buff_vars(int vars) {
//     char **change_var = (char**)malloc(sizeof(char *) * vars);

//     for (int i = 0; i < vars; i++) {
//         change_var[i] = mx_strnew(2000);
//     }
//     change_var[vars] = NULL;
//     return change_var;
// } 

static char **fill_vars_arr(char **change_var, char *ignored_com, char **buffer_vars) {
    int buffer_count = 0;
    bool check = false;
    char *buffer = mx_strnew(2000);
    int small_count = 0;
    int te = 0;
    char **buffer_split = NULL;

    for (int i = 0; i < mx_strlen(ignored_com); i++) {
        if (ignored_com[i] == '$' && ignored_com[i + 1] != ' ' && ignored_com[i + 1] != '#') {
            check = true;
        }
        while(check) {
            if (ignored_com[i] == '}' || ignored_com[i] == ' ' || ignored_com[i] == '\0') {
            buffer[buffer_count] = ignored_com[i];
            check = false;
            buffer_count++;
            buffer[buffer_count] = '|';
            buffer_count++;
            break;

            } else {
                buffer[buffer_count] = ignored_com[i];
                i++;
                buffer_count++;
            } 
        }
    }
     if (buffer[mx_strlen(buffer) - 1] == '|')
        buffer[mx_strlen(buffer) - 1] = '\0';

    buffer_split = mx_strsplit(buffer, '|');
    // te = 0;
    // while (buffer_split[te]) {
    //     buffer_vars[te] = mx_strcpy(buffer_vars[te], buffer_split[te]);
    //     printf("%s\n", buffer_split[0]);
    //     te++;
    // }
    // te = 0;
    //small_count = 0;
    while (buffer_split[te]) {
        for (int i = 0; i < mx_strlen(buffer_split[te]); i++) {
            if (buffer_split[te][i] != '$' && buffer_split[te][i] != '{' 
                && buffer_split[te][i] != '}' && buffer_split[te][i] != ' ') {
                change_var[te][small_count] = buffer_split[te][i];
                small_count++;
            }
        }
        te++;
        small_count = 0;
    }
    buffer_vars = NULL;
    return buffer_split;
    }

char *mx_change_var(char *ignored_com, t_envp *var) {
    char test[mx_strlen(ignored_com)];
    for (int i = 0; i <= mx_strlen(ignored_com); i++) {
        test[i] = ignored_com[i];
    }

    t_vars st_vars;
    st_vars.vars = count_vars(test);
    st_vars.change_var = init_buff1_vars(st_vars.vars);
    st_vars.buffer_vars = fill_vars_arr(st_vars.change_var, test, st_vars.buffer_vars);
    st_vars.res_str = mx_strnew(mx_strlen(test));
    st_vars.buffer_replace = NULL;
    st_vars.get_from_env = NULL;
    st_vars.res_str = mx_strcpy(st_vars.res_str, test);
    for (int i = 0; i < st_vars.vars; i++) {
        st_vars.get_from_env = getenv(st_vars.change_var[i]);
        if (st_vars.get_from_env)
            st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, mx_strtrim(st_vars.buffer_vars[i]), st_vars.get_from_env);
        else {
            if (mx_strcmp(st_vars.change_var[i], "?") == 0) {
                for (t_envp *head = var; head; head = head->next) {
                    if (!mx_strcmp(head->name, "?"))
                        st_vars.buffer_replace = mx_replace_substr(st_vars.res_str, mx_strtrim(st_vars.buffer_vars[i]), head->val);
                }
            }
            else
                st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, mx_strtrim(st_vars.buffer_vars[i]), "");
        }   
        free(st_vars.res_str);
        st_vars.res_str = mx_strnew(mx_strlen(st_vars.buffer_replace));
        st_vars.res_str = mx_strcpy(st_vars.res_str, st_vars.buffer_replace);
        free(st_vars.buffer_replace);
    }
    return st_vars.res_str;
}
