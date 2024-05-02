/*
** EPITECH PROJECT, 2023
** display_double
** File description:
** Display a double and return the size of double
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/utils_functions.h"
#include "../lib_includes/writing_functions.h"

void get_decimal(double nb, int precision, int *nb_char)
{
    double mul = my_pow(10, precision);
    double tmp = 0;
    int nb_zero = 0;

    if (nb < 0)
        nb *= -1;
    nb *= mul;
    nb_zero = precision - my_int_len(nb);
    tmp = nb - get_double_entire(nb);
    if ((tmp * 10) > 5)
        nb += 1;
    if (nb >= 10)
        nb_zero--;
    for (int i = 0; i < nb_zero; i++) {
        my_putchar('0');
        *nb_char += 1;
    }
    my_putnbr(nb);
    *nb_char += my_int_len(nb);
}

int display_double(va_list *list, int prec, detect_flag_t *flag, int *cpt)
{
    double number = va_arg(*list, double);
    double entire = get_double_entire(number);
    int nb_char = my_int_len(entire);

    get_int_flag(flag, &nb_char, number);
    if (prec != 0) {
        my_putnbr(entire);
        my_putchar('.');
        nb_char ++;
        get_decimal(number - entire, prec == -1 ? 6 : prec, &nb_char);
    } else {
        number -= entire;
        number *= 10;
        if (number > 5)
            my_putnbr(entire + 1);
        else
            my_putnbr(entire);
    }
    cpt = cpt;
    return nb_char;
}
