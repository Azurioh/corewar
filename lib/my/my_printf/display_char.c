/*
** EPITECH PROJECT, 2023
** display_char
** File description:
** Display a character and return 1
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/writing_functions.h"

int display_char(va_list *list, int prec, detect_flag_t *flag, int *cpt)
{
    my_putchar(va_arg(*list, int));
    prec = prec;
    flag = flag;
    cpt = cpt;
    return 1;
}
