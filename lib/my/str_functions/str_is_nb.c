/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** str_is_nb
*/

int str_is_nb(char const *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
    }
    return 0;
}
