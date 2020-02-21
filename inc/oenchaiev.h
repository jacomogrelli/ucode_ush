#ifndef ONECHAIEV_H
#define ONECHAIEV_H

#define MX_BIN {"cd", "echo"}
#define MX_FLAGS "echo"

//------main part------
void mx_ush_init(void);
void mx_get_command(char *command);
void mx_run_cd(char *args);

//------builtins------
int mx_run_exit(char *command);

#endif
