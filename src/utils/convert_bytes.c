/*
** EPITECH PROJECT, 2024
** convert_bytes
** File description:
** Function to bitshift memory element
*/

#include "../../include/corewar.h"

int convert_4bytes(unsigned char *memory, int index)
{
    int bitshift = 0;

    for (int i = 0; i < 4; i++) {
        bitshift += get_address_value(memory,
            index + (i + 1)) << (4 * (4 - i));
    }
    return bitshift;
}

int convert_2bytes(unsigned char *memory, int index)
{
    int bitshift = 0;

    bitshift += get_address_value(memory, index + 1) << (4 * 2);
    bitshift += get_address_value(memory, index + 2);
    return bitshift;
}
