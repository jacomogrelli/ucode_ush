#include "ush.h"

void mx_parser_tilda(t_envp *var, char **line) {
    char *head = *line;

    for (int i = 0; head[i]; i++) {
        if (head[i] == '~' && i == 0) {
            if (head[i + 1]) {
                if (mx_get_char_index(MX_PARS_TSTOP, head[i + 1]) < 0) {
                    
                }
            }
        }
    }
}
