/*
** EPITECH PROJECT, 2024
** dump_memory
** File description:
** display the actual state of the arena
*/

#include "../../include/corewar.h"

void conv_hexa(unsigned int nb, char *str)
{
    int rslt;

    if (nb == 0)
        return;
    else {
        rslt = nb % 16;
        if (rslt > 9)
            rslt += 'A' - 58;
        conv_hexa((nb / 16), str);
        append(str, rslt + 48);
    }
}

void display_hexa(int nb)
{
    char *str = my_strdup("");

    if (nb == 0) {
        my_putchar('0');
        my_putchar('0');
        free(str);
        return;
    }
    conv_hexa(nb, str);
    for (int i = my_strlen(str); i < 2; i++) {
        my_putchar('0');
    }
    my_putstr(str);
    return;
}

void dump_memory(corewar_t *corewar)
{
    char unsigned *memory = corewar->memory;

    if (memory == NULL)
        return;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0)
            my_putchar('\n');
        display_hexa(memory[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}
