/*
** EPITECH PROJECT, 2023
** my_printf_var.h
** File description:
** All global variables used
*/

#ifndef MY_PRINTF_VAR
    #define MY_PRINTF_VAR
    #include "../lib_includes/my_printf.h"
    #include <stddef.h>
detect_flag_t flag_indicator;
const conversions_t CONVERSIONS[] = {
    {'d', &display_int},
    {'i', &display_int},
    {'s', &display_string},
    {'c', &display_char},
    {'%', &display_percentage},
    {'f', &display_double},
    {'F', &display_double},
    {'x', &display_hexa_min},
    {'X', &display_hexa_maj},
    {'o', &display_octal},
    {'u', &display_int_unsigned},
    {'n', &display_nb_char_show},
    {'p', &display_pointer},
    {'m', &display_errno},
    {0, NULL},
};
#endif
