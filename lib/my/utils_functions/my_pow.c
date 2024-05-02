/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_pow
*/

int my_pow(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    } else if (p == 1) {
        return nb;
    } else {
        return nb * my_pow(nb, p - 1);
    }
}
