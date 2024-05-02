/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int cpt = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return cpt;
}
