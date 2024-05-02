/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_putnbr
*/

#include "../lib_includes/writing_functions.h"

void my_putnbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}
