/*
** EPITECH PROJECT, 2024
** get_operation_info
** File description:
** Get the op_t struct matching with the name wanted
*/

#include "../../include/corewar.h"

op_t get_operation_info(char *name)
{
    int i = 0;

    for (; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(name, op_tab[i].mnemonique) == 0) {
            return op_tab[i];
        }
    }
    return op_tab[i];
}
