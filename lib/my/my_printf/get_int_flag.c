/*
** EPITECH PROJECT, 2023
** get_int_flag
** File description:
** Display space or + flag
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/writing_functions.h"

void get_int_flag(detect_flag_t *flag, int *nb_char, double value)
{
    if (flag->plus == 0) {
        if (flag->space == 1 && value >= 0) {
            my_putchar(' ');
            *nb_char += 1;
        }
    } else {
        if (value >= 0) {
            my_putchar('+');
            *nb_char += 1;
        }
    }
}
