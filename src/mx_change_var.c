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

static t_buffer_aud_vars init_struct_aud_vars() {
    t_buffer_aud_vars st_buffer_aud_vars;

    st_buffer_aud_vars.check = 0;
    st_buffer_aud_vars.te = 0;
    st_buffer_aud_vars.small_count = 0;

    return st_buffer_aud_vars;
}

static char **fill_vars_arr(char **change_var, char *ignored_com, char **buffer_vars) {
    t_buffer_aud_vars st_buffer_aud_vars = init_struct_aud_vars();
    int buffer_count = 0;
    char *buffer = mx_strnew(2000);
    char **buffer_split = NULL;

    for (int i = 0; i < mx_strlen(ignored_com); i++) {
        if (ignored_com[i] == '$' && ignored_com[i + 1] != ' ' && ignored_com[i + 1] != '#') {
            st_buffer_aud_vars.check = true;
        }
        while(st_buffer_aud_vars.check) {
            if (ignored_com[i] == '}' || ignored_com[i] == ' ' || ignored_com[i] == '\0') {
                buffer_count =  mx_count_buf_aud(buffer_count, buffer, ignored_com, i);
                st_buffer_aud_vars.check = false;
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
    buffer_split = buffer_split_aud(buffer_split, st_buffer_aud_vars, change_var);
    buffer_vars = NULL;
    return buffer_split;
}

static t_vars init_vars_aud_struct(char *test) {
    t_vars st_vars;

    st_vars.vars = count_vars(test);
    st_vars.change_var = init_buff1_vars(st_vars.vars);
    st_vars.buffer_vars = fill_vars_arr(st_vars.change_var, test, st_vars.buffer_vars);
    st_vars.res_str = mx_strnew(mx_strlen(test));
    st_vars.buffer_replace = NULL;
    st_vars.get_from_env = NULL;
    st_vars.res_str = mx_strcpy(st_vars.res_str, test);
    return st_vars;
}

char *mx_change_var(char *ignored_com, t_envp *var) {
    t_vars st_vars;
    char test[mx_strlen(ignored_com)];

    for (int i = 0; i <= mx_strlen(ignored_com); i++)
        test[i] = ignored_com[i];
    st_vars = init_vars_aud_struct(test);
    for (int i = 0; i < st_vars.vars; i++) {
        st_vars.get_from_env = getenv(st_vars.change_var[i]);
        if (st_vars.get_from_env)
            st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, 
                mx_strtrim(st_vars.buffer_vars[i]), st_vars.get_from_env);
        else {
            if (mx_strcmp(st_vars.change_var[i], "?") == 0) {
                for (t_envp *head = var; head; head = head->next)
                    if (!mx_strcmp(head->name, "?"))
                        st_vars.buffer_replace = mx_replace_substr(st_vars.res_str, 
                            mx_strtrim(st_vars.buffer_vars[i]), head->val);
            }
            else
                st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, 
                    mx_strtrim(st_vars.buffer_vars[i]), "");
        }   
        st_vars.res_str = mx_res_aud_str(st_vars.res_str, st_vars.buffer_replace);
    }
    return st_vars.res_str;
}
