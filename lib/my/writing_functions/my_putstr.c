/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_putstr
*/

#include "../lib_includes/str_functions.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    if (!str)
        return;
    write(1, str, my_strlen(str));
}
