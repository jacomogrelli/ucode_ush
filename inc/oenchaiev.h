#ifndef ONECHAIEV_H
#define ONECHAIEV_H

#define MX_BIN {"cd", "echo"}
#define MX_FLAGS "echo"

//------main part------
void mx_ush_init(void);
void mx_get_command(char **command);
void mx_run_cd(char *args);
void mx_push_var();

//------builtins------
int mx_run_exit(char *com);

//------exec------
void mx_run_exec(char **com);
void mx_exec_err_out(char *com, int err);

#endif
