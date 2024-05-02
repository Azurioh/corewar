/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_putnbr_uns
*/

#include "../lib_includes/writing_functions.h"

void my_putnbr_uns(unsigned int nb)
{
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_putnbr_uns(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}
