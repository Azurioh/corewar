/*
** EPITECH PROJECT, 2023
** display_int
** File description:
** Display an int and return his len
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/utils_functions.h"
#include "../lib_includes/writing_functions.h"

int display_int(va_list *list, int prec, detect_flag_t *flag, int *cpt)
{
    int value = 0;
    int len = 0;

    cpt = cpt;
    value = va_arg(*list, int);
    get_int_flag(flag, &len, value);
    if (my_int_len(value) < prec) {
        for (int i = my_int_len(value); i < prec; i++) {
            my_putchar('0');
            len++;
        }
    }
    my_putnbr(value);
    len += my_int_len(value);
    return len;
}
