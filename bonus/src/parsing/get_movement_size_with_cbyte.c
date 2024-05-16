/*
** EPITECH PROJECT, 2024
** get_movement_size_with_cbyte
** File description:
** Function to get the number of byte to skip depending of coding byte
*/

#include "../../include/corewar.h"

int get_movement_size_with_cbyte(char coding_byte)
{
    switch (coding_byte) {
        case T_REG:
            return 1;
        case T_IND:
            return 2;
        case T_DIR:
            return 4;
        default:
            return 0;
    }
}
