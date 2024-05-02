/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_strncmp
*/

#include <stddef.h>

int my_strncmp(char *s1, char *s2, int limit)
{
    int index = 0;

    if (s1 == NULL)
        return s2 == NULL ? 0 : -1;
    if (s2 == NULL)
        return 1;
    while (s1[index] == s2[index] && s1[index] != '\0' && index < limit) {
        index++;
    }
    if (s1[index] == s2[index] || index == limit) {
        return 0;
    }
    if (s1[index] < s2[index]) {
        return -1;
    } else {
        return 1;
    }
}
