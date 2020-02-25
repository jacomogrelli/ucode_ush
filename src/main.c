#include "ush.h"

int main(int argc, char **argv, char **envp) {
    t_errors_cd *errors = (t_errors_cd *)malloc(sizeof(t_errors_cd));
    errors->returned_value = 0;
    
    t_envp *var = mx_envp_fill(envp);
    if (argc && argv && envp)
      mx_ush_init(var);
    return 0;
}

