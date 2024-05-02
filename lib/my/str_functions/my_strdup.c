/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_strdup
*/

#include "../lib_includes/str_functions.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *new_str;

    if (!str) {
        new_str = malloc(sizeof(char));
        new_str[0] = '\0';
        return new_str;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; i <= my_strlen(str); i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
