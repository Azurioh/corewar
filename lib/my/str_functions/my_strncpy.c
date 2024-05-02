/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Copy the content of the src string to another string.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
