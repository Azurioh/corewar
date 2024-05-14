/*
** EPITECH PROJECT, 2024
** get_address_value
** File description:
** Function to get the value at a specific address
*/

#include "../../include/corewar.h"

int get_address(int index)
{
    if (index >= MEM_SIZE) {
        while (index >= MEM_SIZE) {
            index -= MEM_SIZE;
        }
    }
    if (index < 0) {
        while (index < 0) {
            index += MEM_SIZE;
        }
    }
    return index;
}

int get_address_value(unsigned char *memory, int index)
{
    int value;

    if (index >= MEM_SIZE) {
        while (index >= MEM_SIZE) {
            index -= MEM_SIZE;
        }
    }
    if (index < 0) {
        while (index < 0) {
            index += MEM_SIZE;
        }
    }
    value = memory[index];
    return value;
}
