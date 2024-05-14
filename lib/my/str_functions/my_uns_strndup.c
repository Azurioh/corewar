/*
** EPITECH PROJECT, 2024
** B-CPE-200-MLH-2-1-robotfactory-nathan.callegari
** File description:
** my_strndup
*/
#include <stdlib.h>

unsigned char *my_uns_strndup(unsigned char *str, int n)
{
    unsigned char *new_str;
    int i = 0;

    new_str = malloc(sizeof(char) * (n + 1));
    i = 0;
    while (i != n) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}
