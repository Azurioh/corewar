/*
** EPITECH PROJECT, 2023
** display_percentage
** File description:
** Display a percentage and return 1
*/

#include "../lib_includes/my_printf.h"

int display_pointer(va_list *l, int p, detect_flag_t *f, int *c)
{
    void *ptr = va_arg(*l, void *);

    p = p;
    f = f;
    c = c;
    return (my_printf("%#x", ptr));
}
