/*
** EPITECH PROJECT, 2023
** display_int
** File description:
** Display an int and return his len
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/utils_functions.h"
#include "../lib_includes/writing_functions.h"

int display_int_unsigned(va_list *l, int p, detect_flag_t *f, int *c)
{
    int value = 0;
    int len = 0;

    c = c;
    f = f;
    value = va_arg(*l, int);
    if (my_uns_int_len(value) < p) {
        for (int i = my_uns_int_len(value); i < p; i++) {
            my_putchar('0');
            len++;
        }
    }
    my_putnbr_uns(value);
    len += my_uns_int_len(value);
    return len;
}
