#include "ush.h"

void mx_uniq_prompt() {
    char *get_prompt = getenv("PROMPT");

    if (!get_prompt)
        printf("u$h> ");
    else {
        printf("%s", get_prompt);
        printf("%s", "> ");
    }
}
