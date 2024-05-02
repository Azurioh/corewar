/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** insert_in_array
*/

#include "../lib_includes/array_functions.h"
#include "../lib_includes/str_functions.h"
#include <stddef.h>
#include <stdlib.h>

char **insert_in_array(char **array, char *str, int index)
{
    char **new_array;
    int j = 0;

    if (!array || !str || index > my_arraylen(array))
        return array;
    new_array = malloc(sizeof(char *) * (my_arraylen(array) + 2));
    for (int i = 0; array[i]; i++) {
        if (i == index) {
            new_array[j] = my_strdup(str);
            j++;
        }
        new_array[j] = my_strdup(array[i]);
        j++;
    }
    if (index < 0 || index == my_arraylen(array))
        new_array[j] = my_strdup(str);
    new_array[my_arraylen(array) + 1] = NULL;
    free_arrays(1, array);
    return new_array;
}
