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

static char **init_buff_vars(int vars) {
    char **change_var = (char**)malloc(sizeof(char *) * vars);

    for (int i = 0; i < vars; i++) {
        change_var[i] = mx_strnew(2000);
    }
    change_var[vars] = NULL;
    return change_var;
} 

static void fill_vars_arr(char **change_var, char *ignored_com, char **buffer_vars) {
    int count = 0;
    int small_count = 0;
    int buffer_count = 0;

    for (int i = 0; i < mx_strlen(ignored_com); i++) {
        if ((ignored_com[i] == '$' && ignored_com[i + 1] != ' ' 
        && ignored_com[i + 1] && ignored_com[i + 1] != '}') 
        || (ignored_com[i] == '$' && i == 0) 
        || (ignored_com[i] == '$' && ignored_com[i - 1] == ' ')) {
            buffer_count = 0;
            buffer_vars[count][buffer_count] = ignored_com[i];
            buffer_count++;
            i++;
            small_count = 0;
            while (true) {
                if (ignored_com[i] == '{') {
                    buffer_vars[count][buffer_count] = ignored_com[i];
                    buffer_count++;
                    i++;
                }
                if (ignored_com[i] == ' ' || ignored_com[i] == '\0' || ignored_com[i] == '}') {
                    if (ignored_com[i] == '}') {
                        buffer_vars[count][buffer_count] = ignored_com[i];
                        buffer_count++;                        
                    }
                    break;
                }
                buffer_vars[count][buffer_count] = ignored_com[i];
                change_var[count][small_count] = ignored_com[i];
                i++;
                small_count++;
                buffer_count++;
            }
            count++;
        }
    }
}

char *mx_change_var(char *ignored_com) {
    t_vars st_vars;
    st_vars.vars = count_vars(ignored_com);
    st_vars.change_var = init_buff_vars(st_vars.vars);
    st_vars.buffer_vars = init_buff_vars(st_vars.vars);
    fill_vars_arr(st_vars.change_var, ignored_com, st_vars.buffer_vars);
    st_vars.res_str = mx_strnew(mx_strlen(ignored_com));
    st_vars.buffer_replace = NULL;
    st_vars.get_from_env = NULL;
    st_vars.res_str = mx_strcpy(st_vars.res_str, ignored_com);
    for (int i = 0; i < st_vars.vars; i++) {
        st_vars.get_from_env = getenv(st_vars.change_var[i]);
        if (st_vars.get_from_env)
            st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, st_vars.buffer_vars[i], st_vars.get_from_env);
        else {
            // if (mx_strcmp(st_vars.change_var[i], "?") == 0) {
            //     st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, st_vars.buffer_vars[i], mx_itoa());
            // }
            st_vars.buffer_replace =  mx_replace_substr(st_vars.res_str, st_vars.buffer_vars[i], "");
        }   
        free(st_vars.res_str);
        st_vars.res_str = mx_strnew(mx_strlen(st_vars.buffer_replace));
        st_vars.res_str = mx_strcpy(st_vars.res_str, st_vars.buffer_replace);
        free(st_vars.buffer_replace);
    }
    return st_vars.res_str;
}
