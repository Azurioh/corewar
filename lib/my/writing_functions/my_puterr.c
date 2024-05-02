/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_puterr
*/

#include "../lib_includes/str_functions.h"
#include <unistd.h>

void my_puterr(char const *str)
{
    if (!str)
        return;
    write(2, str, my_strlen(str));
}
