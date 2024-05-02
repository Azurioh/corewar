/*
** EPITECH PROJECT, 2024
** Project
** File description:
** add_char_in_str
*/

#include "../lib_includes/str_functions.h"
#include "../lib_includes/my_printf.h"
#include "../lib_includes/writing_functions.h"
#include <stdlib.h>
#include <stddef.h>

void add_in_string(char *str, char *new_str, int index, char character)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == index) {
            new_str[j] = character;
            j++;
        }
        new_str[j] = str[i];
        j++;
    }
    if (index < 0 || index == my_strlen(str)) {
        new_str[j] = character;
        j++;
    }
    new_str[j] = '\0';
}

char *add_char_in_str(char *str, char character, int index)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 2));

    if (!new_str) {
        my_puterr("add_char_in_str: Memory allocation failed\n");
        return NULL;
    }
    add_in_string(str, new_str, index, character);
    free(str);
    return new_str;
}
