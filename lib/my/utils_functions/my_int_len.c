/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_int_len
*/

int my_int_len(int nb)
{
    int i = 0;

    if (nb < 0) {
        i++;
    }
    if (nb == 0) {
        return 1;
    }
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return i;
}
