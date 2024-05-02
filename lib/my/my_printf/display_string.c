/*
** EPITECH PROJECT, 2023
** display_string
** File description:
** Display a string and return his len
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"
#include <stdlib.h>

int display_string(va_list *list, int prec, detect_flag_t *flag, int *cpt)
{
    char *new_str;
    int size;

    flag = flag;
    cpt = cpt;
    new_str = my_strdup(va_arg(*list, char *));
    if (my_strlen(new_str) > prec && prec != -1) {
        for (int i = 0; i < prec && new_str[i] != '\0'; i++) {
            my_putchar(new_str[i]);
        }
        free(new_str);
        return prec;
    } else {
        my_putstr(new_str);
        size = my_strlen(new_str);
        free(new_str);
        return size;
    }
}
