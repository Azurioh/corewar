/*
** EPITECH PROJECT, 2024
** register_is_valid
** File description:
** Check if register number is valid
*/

#include "../../include/corewar.h"

bool register_is_valid(int register_nb)
{
    if (register_nb < 1) {
        return false;
    }
    if (register_nb > REG_NUMBER) {
        return false;
    }
    return true;
}
