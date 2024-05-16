/*
** EPITECH PROJECT, 2024
** dump_memory
** File description:
** display the actual state of the arena
*/

#include "../../include/corewar.h"

void conv_hexa(unsigned int nb, char *str)
{
    int calcul = nb;
    int tmp;
    int j = 0;

    while (calcul != 0) {
        tmp = calcul % 16;
        if (tmp < 10) {
            str[j] = '0' + tmp;
            j++;
        } else {
            str[j] = 'A' + (tmp - 10);
            j++;
        }
        str[j] = '\0';
        calcul /= 16;
    }
    return;
}

void display_hexa(int nb)
{
    char *str = malloc(sizeof(char) * 100);

    if (nb == 0) {
        my_putchar('0');
        my_putchar('0');
        free(str);
        return;
    }
    conv_hexa(nb, str);
    str = my_revstr(str);
    if (my_strlen(str) < 2) {
        for (int i = my_strlen(str); i < 2; i++) {
            my_putchar('0');
        }
    }
    for (int i = 0; i < my_strlen(str); i++) {
        my_putchar(str[i]);
    }
    return;
}

void dump_memory(corewar_t *corewar)
{
    char unsigned *memory = corewar->memory;

    if (memory == NULL)
        return;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i != 0 && i % 32 == 0)
            my_putchar('\n');
        display_hexa(memory[i]);
        if ((i + 1) % 32 != 0) {
            my_putchar(' ');
        }
    }
    my_putchar('\n');
}
