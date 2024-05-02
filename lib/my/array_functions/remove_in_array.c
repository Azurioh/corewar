/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** remove_in_array
*/

#include "../lib_includes/array_functions.h"
#include "../lib_includes/str_functions.h"
#include "../lib_includes/my_printf.h"
#include <stdlib.h>

char **remove_in_array(char **array, int index)
{
    char **new_array;
    int j = 0;

    if (!array || index > my_arraylen(array))
        return array;
    new_array = malloc(sizeof(char *) * (my_arraylen(array)));
    for (int i = 0; array[i]; i++) {
        if (i == index) {
            continue;
        }
        new_array[j] = my_strdup(array[i]);
        j++;
    }
    if (index < 0)
        j--;
    new_array[j] = NULL;
    free_arrays(1, array);
    return new_array;
}
