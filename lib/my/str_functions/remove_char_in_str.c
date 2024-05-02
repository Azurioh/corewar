/*
** EPITECH PROJECT, 2024
** Project
** File description:
** add_char_in_str
*/

#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"
#include <stdlib.h>
#include <stddef.h>

void remove_in_string(char *str, char *new_str, int index)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == index) {
            i++;
        }
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
}

char *remove_char_in_str(char *str, int index)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str)));

    if (!new_str) {
        my_puterr("add_char_in_str: Memory allocation failed\n");
        return NULL;
    }
    if (index >= my_strlen(str)) {
        my_puterr("remove_char_in_str: The index provided is too big\n");
        return str;
    }
    remove_in_string(str, new_str, index);
    free(str);
    return new_str;
}
