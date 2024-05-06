/*
** EPITECH PROJECT, 2024
** corewar.c
** File description:
** Function to begin the program
*/

#include "../../include/corewar.h"

int my_putcorefile(char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        my_printf("%x\n", buffer[i]);
    }
    return 0;
}

int corewar(char **argv)
{
    corewar_t *corewar = init_corewar();

    if (!corewar) {
        return 84;
    }
    corewar->robots = malloc(sizeof(robot_t *) * 2);
    corewar->robots[0] = create_robot(argv[1]);
    corewar->robots[1] = NULL;
    return 0;
}
