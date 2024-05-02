/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** nbr_to_str
*/

#include "../lib_includes/utils_functions.h"
#include <stdlib.h>

char *my_nbr_to_str(int nb)
{
    char *str;
    int divise = my_pow(10, my_int_len(nb) - 1);
    int i = 0;

    str = malloc(sizeof(char) * my_int_len(nb) + 1);
    while (divise > 0) {
        str[i] = '0' + (nb / divise);
        nb -= (nb / divise) * divise;
        divise /= 10;
        i++;
    }
    return str;
}
