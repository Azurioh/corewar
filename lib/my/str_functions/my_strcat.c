/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Concatenate two strings
*/

#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"
#include <stdlib.h>
#include <stddef.h>

char *my_strcat(char *dest, char const *str)
{
    char *new_str;
    int j = 0;

    if (!dest)
        return NULL;
    new_str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(str) + 1));
    if (!new_str) {
        my_puterr("my_strcat: Memory allocation failed\n");
        return NULL;
    }
    for (; j < my_strlen(dest); j++)
        new_str[j] = dest[j];
    for (int i = 0; i < my_strlen(str); i++) {
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    free(dest);
    return new_str;
}
