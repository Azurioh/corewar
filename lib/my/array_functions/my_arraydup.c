/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** my_arraydup
*/

#include "../lib_includes/array_functions.h"
#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"
#include <stdlib.h>

char **my_arraydup(char **array)
{
    char **new_array;
    int size = my_arraylen(array);
    int i = 0;

    if (!array) {
        return NULL;
    }
    new_array = malloc(sizeof(char *) * (size + 1));
    if (!new_array) {
        my_puterr("my_arraydup: Memory allocation error\n");
        return NULL;
    }
    for (; i < size; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    new_array[i] = NULL;
    return new_array;
}
