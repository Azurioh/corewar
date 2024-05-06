/*
** EPITECH PROJECT, 2024
** is_corfile
** File description:
** check if a string finish by ".cor"
*/
#include "../../include/corewar.h"

int is_corfile(char *str)
{
    char *core = my_strdup(".cor");
    int len = my_strlen(str) - 1;
    int cor_index = 3;

    for (int i = len; i != len - 4; i--) {
        if (str[i] != core[cor_index])
            return 1;
        cor_index -= 1;
    }
    return 0;
}
