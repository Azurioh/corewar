/*
** EPITECH PROJECT, 2024
** Project
** File description:
** my_word_array_to_str
*/

#include "../lib_includes/array_functions.h"
#include "../lib_includes/str_functions.h"
#include <stddef.h>
#include <stdlib.h>

char *convert_array_to_str(char **word_array, char *separator, int size,
    char *str)
{
    int i = 0;

    if (size > 0) {
        for (; word_array[i + 1]; i++) {
            str = my_strcat(str, word_array[i]);
            str = my_strcat(str, separator);
        }
        str = my_strcat(str, word_array[i]);
        str[size - 1] = '\0';
    }
    return str;
}

char *my_word_array_to_str(char **word_array, char *separator)
{
    int size = 0;
    char *str;

    if (!word_array)
        return NULL;
    if (my_arraylen(word_array) == 1)
        return my_strdup(word_array[0]);
    for (int i = 0; word_array[i]; i++)
        size += my_strlen(word_array[i]) + my_strlen(separator);
    str = my_strdup("");
    str = convert_array_to_str(word_array, separator, size, str);
    return str;
}
