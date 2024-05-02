/*
** EPITECH PROJECT, 2023
** display_errno
** File description:
** Display the output of strerror(errno)
*/

#include "../lib_includes/my_printf.h"
#include <errno.h>

int display_errno(va_list *l, int p, detect_flag_t *f, int *c)
{
    l = l;
    p = p;
    f = f;
    c = c;
    return my_printf("%d", errno);
}
