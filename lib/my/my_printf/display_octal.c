/*
** EPITECH PROJECT, 2023
** conv_dec_hexa
** File description:
** convert an unsigned int into hexadecimal and display it
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/utils_functions.h"
#include "../lib_includes/writing_functions.h"

void conv_dec_octal(unsigned int nb, int *nb_char, int *value)
{
    int rslt;

    *nb_char += 1;
    if (nb == 0)
        return;
    else {
        rslt = nb % 8;
        if (nb / 8 != 0) {
            conv_dec_octal((nb / 8), nb_char, value);
        }
        *value = *value * 10 + rslt;
    }
}

int display_octal(va_list *list, int prec, detect_flag_t *flag, int *cpt)
{
    unsigned int nb = va_arg(*list, unsigned int);
    int nb_char = 0;
    int value = 0;

    if (flag->hashtag == 1) {
        my_putstr("0");
        nb_char += 1;
    }
    conv_dec_octal(nb, &nb_char, &value);
    if (my_int_len(value) < prec) {
        for (int i = my_int_len(value); i < prec; i++) {
            my_putchar('0');
            nb_char++;
        }
    }
    cpt = cpt;
    my_putnbr(value);
    return nb_char;
}
