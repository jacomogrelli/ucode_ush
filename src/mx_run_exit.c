#include "ush.h"

static int get_exit_status(char **com, int count, bool *err) {
    if (count == 1)
        return 0;
    if (count != 1) {
        for (int i = 0; com[1][i]; i++) {
            if (com[1][0] == '+' || com[1][0] == '-')
                continue;
            if (!isdigit(com[1][i])) {
                *err = true;
                return -1;
            }
        }
        if (count == 2)
            return atoi(com[1]);
    }
        *err = true;
        return 1;
}

void mx_run_exit(t_envp *var, char **command) {
    bool err = false;
    int count = 0;

     while (command[count])
        count++;
    int i = get_exit_status(command, count, &err);
    if (isatty(0))
    if (count != 1 && err) {
        mx_envp_replace(&var, "?=1");
        return;
    }
    exit (i);
}

/*
bash-3.2$ exit 0 asdf 	                    // doesn’t exit
exit
bash: exit: too many arguments
bash-3.2$ echo $?
1

bash-3.2$ exit 10 10                        // doesn’t exit
exit
bash: exit: too many arguments
bash-3.2$ echo $?
1

bash-3.2$ exit
exit
➜  ~ echo $?
0

bash-3.2$ exit /asdf
exit
bash: exit: /asdf: numeric argument required       //exit with -1
➜  ~ echo $?
255

bash-3.2$ exit asdf asdf
exit
bash: exit: asdf: numeric argument required      //exit with -1
➜  ~ echo $?
255

bash-3.2$ exit asdf 10
exit
bash: exit: asdf: numeric argument required
➜  ~ echo $?
255
 */
