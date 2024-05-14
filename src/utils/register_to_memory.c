/*
** EPITECH PROJECT, 2024
** register_to_memory
** File description:
** Function to write a register value into the memory
*/

#include "../../include/corewar.h"

void regsiter_to_memory(corewar_t *corewar, int index, int value)
{
    int *value_shifted = convert_to_4bytes(value);

    for (int i = 0; i < 4; i++) {
        corewar->memory[get_address(index + i)] = value_shifted[i];
    }
}
