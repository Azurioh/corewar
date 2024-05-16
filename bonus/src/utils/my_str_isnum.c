/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** str_isnum
*/
int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('0' <= str[i] && str[i] <= '9')
            i++;
        else
            return 1;
    }
    return 0;
}
