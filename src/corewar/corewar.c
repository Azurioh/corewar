/*
** EPITECH PROJECT, 2024
** corewar.c
** File description:
** Function to begin the program
*/

#include "../../include/corewar.h"

int corewar(void)
{
    corewar_t *corewar = init_corewar();

    if (!corewar) {
        return 84;
    }
    return 0;
}
