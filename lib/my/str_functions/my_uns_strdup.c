/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_uns_strdup
*/

#include "../lib_includes/str_functions.h"
#include <stdlib.h>

unsigned char *my_uns_strdup(unsigned char const *str)
{
    unsigned char *new_str;

    if (!str) {
        new_str = malloc(sizeof(unsigned char));
        new_str[0] = '\0';
        return new_str;
    }
    new_str = malloc(sizeof(unsigned char) * (my_uns_strlen(str) + 1));
    for (int i = 0; i <= my_uns_strlen(str); i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
