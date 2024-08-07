/*
** EPITECH PROJECT, 2024
** corewar.c
** File description:
** Function to begin the program
*/

#include "../../include/corewar.h"
#include <stdio.h>

int my_putcorefile(char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        my_printf("%x\n", buffer[i]);
    }
    return 0;
}

int corewar(int argc, char **argv)
{
    corewar_t *corewar = init_corewar();

    if (!corewar) {
        return 84;
    }
    if (parse_args(argc, argv, corewar) == 84)
        return 84;
    place_robot_in_arena(corewar);
    manage_cycles(corewar);
    return 0;
}
