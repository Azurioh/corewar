/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** append
*/

#include "../lib_includes/str_functions.h"
#include <stdlib.h>

void append(char *dest, char new)
{
    char *tmp;

    tmp = malloc(sizeof(char) * my_strlen(dest) + 2);
    if (my_strlen(dest) != 0) {
        my_strncpy(tmp, dest, my_strlen(dest) + 1);
        tmp[my_strlen(tmp)] = new;
        tmp[my_strlen(tmp)] = '\0';
        free(dest);
        dest = my_strdup(tmp);
    } else {
        dest[0] = new;
        dest[1] = '\0';
    }
    free(tmp);
}
