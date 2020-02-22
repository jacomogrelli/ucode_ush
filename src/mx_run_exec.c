#include "ush.h"

void mx_run_exec(char *com) {
    char *comm[] = {"ls", "-l", "libmx", (char *)0};
    // pid_t pid;

    if (com) // УБРАТЬ!
    execvp(comm[0], comm);


}
