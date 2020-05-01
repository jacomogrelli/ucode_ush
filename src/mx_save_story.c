#include "ush.h"

t_history *mx_init_story() {
    t_history *history = (t_history *)malloc(sizeof(t_history));
    history->spaces_first = 2;
    history->spaces_second = 2;
    history->nuber_line = 1;
    history->value = NULL;
    history->count = 0;

    history->value = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000; i++) {
        history->value[i] = NULL;
    }
    history->value[1000] = NULL;
    return history;
}

void mx_save_story(char *input_line, t_history *history) {
    history->value[history->count] = mx_strnew(mx_strlen(input_line));
    history->value[history->count] = mx_strcpy(history->value[history->count],
                                               input_line);
    history->count++;
}

void mx_print_strory(t_envp *var, t_history *history) {
    int longest_numbers = mx_count_numbers(history->nuber_line);
    int spaces = 0;
    history->nuber_line = 1;

    for (int i = 0; i < history->count; i++) {
        spaces = longest_numbers - mx_count_numbers(i);
        for (int j = 0; j < history->spaces_first + spaces + 1; j++){
            printf("%c", ' ');
        }
        printf("%d", history->nuber_line);
        for (int j = 0; j < history->spaces_second; j++){
            printf("%c", ' ');
        }
        printf("%s", history->value[i]);
        history->nuber_line++;
    }
    mx_envp_replace(&var, "?=0");
}
