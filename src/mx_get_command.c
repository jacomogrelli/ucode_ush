#include "ush.h"


void mx_get_command(t_envp *var, char **com) {
    //List of builtin commands in MX_BIN in onechaiev.h
        // t_envp *head = var;
        // printf("size =%zu\n", malloc_size(var));

    //     for (t_envp *head = var; head; head = head->next) {
    //         printf("%s=", head->name);
    //         printf("%s\n", head->val);
    //     }
    // exit(0);

    char *bin[] = {"exit", NULL};
    void (*builtin_func[])() = {&mx_run_exit};

    for (int i = 0; bin[i]; i++) {
        if (!strcmp(com[0], bin[i])) {
            (*builtin_func[i])(var, com);
            return;
        }
    }
    mx_run_exec(com, var);
    return;
}

    /* OLD VERSION */
    // if (!strcmp("cd", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("export", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("unset", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("fg", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("exit", com[0])) {
    //     mx_run_exit(var, com);
    //     return;
    // }
    // if (!strcmp("env", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("pwd", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("which", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("echo", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // if (!strcmp("./ush", com[0])) {
    //     printf("command - %s\n", com[0]);
    //     return;
    // }
    // else {
    //     //mx_run_exec(com, var);
    //     return;
    // }
