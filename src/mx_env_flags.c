#include "ush.h"

void mx_env_flag_p(t_envp *var, char **com, int *pos) {
    if (var)
    for (int i = 0; com[i]; i++) {
        if (strcmp(com[i], "-P") == 0) {
            if (!com[i + 1])
                mx_env_err_out('c', 2);
            setenv("PATH", com[i + 1], 1);
            mx_envp_replace(&var, mx_strjoin("PATH=", com[i + 1]));
            if ((*pos) < i + 1)
                (*pos) = i + 2;
        }
    }
}

void mx_env_flag_i(t_envp *var, char **com, int *pos) {
    extern char **environ;

    for (int i = 0; com[i]; i++) {
        if (strcmp(com[i], "-i") == 0) {
            for (int j = 0; environ[j]; j++) {
                char *env = strndup(environ[j],
                                    mx_get_char_index(environ[j], '='));
                unsetenv(env);
                free(env);
            }
            for (t_envp *head = var; head; head = head->next) {
                mx_strdel(&(head->name));
                mx_strdel(&(head->val));
            }
            free(var);
            (*pos) = i + 1;
        }
    }
}

void mx_env_flag_u(t_envp *var, char **com, int *pos) {
    for (int i = 0; com[i]; i++) {
        //finding all flags -u
        if (strcmp(com[i], "-u") == 0) {
            if ((*pos) <= i)
                (*pos) = i + 1;
            //cheking argv after -u, if they are env - make unset
            for (int j = i + 1; com[j]; j++) {
                if (!getenv(com[j]))
                    break;
                unsetenv(com[j]);
                var = mx_unset_envp_del(var, com[j]);
                (*pos) = j + 1;
            }
        }
    }
}
