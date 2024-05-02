/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** include_in_str
*/

#include "../lib_includes/str_functions.h"

int includes_in_str(char const *str, char to_find)
{
    if (!str)
        return 0;
    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == to_find) {
            return 1;
        }
    }
    return 0;
}
