/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** free_arrays
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void free_arrays(int nb_arrays, ...)
{
    va_list list;
    char **array;

    va_start(list, nb_arrays);
    for (int i = 0; i < nb_arrays; i++) {
        array = va_arg(list, char **);
        if (array == NULL)
            continue;
        for (int j = 0; array[j] != NULL; j++) {
            free(array[j]);
        }
        free(array);
    }
    va_end(list);
}
