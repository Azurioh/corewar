/*
** EPITECH PROJECT, 2024
** read_parameters_with_cbyte
** File description:
** Function to read a parameters depending of the coding byte
*/

#include "../../include/corewar.h"

int read_parameters_with_cbyte(unsigned char *memory, char coding_byte,
    int read_index)
{
    if (coding_byte == T_IND) {
        return convert_2bytes(memory, read_index);
    } else if (coding_byte == T_DIR) {
        return convert_4bytes(memory, read_index);
    } else {
        return get_address_value(memory, read_index);
    }
}
