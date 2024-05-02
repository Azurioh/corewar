/*
** EPITECH PROJECT, 2023
** display_nb_char_show
** File description:
** Edit a pointer to attributes the number of characters
*/

#include "../lib_includes/my_printf.h"

int display_nb_char_show(va_list *l, int p, detect_flag_t *f, int *c)
{
    int *ptr;

    p = p;
    f = f;
    ptr = va_arg(*l, int *);
    *ptr = *c;
    return 0;
}
