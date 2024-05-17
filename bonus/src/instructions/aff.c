/*
** EPITECH PROJECT, 2024
** aff
** File description:
** aff instruction
*/
#include "../../include/corewar.h"

void aff(corewar_t *corewar, robot_t *robot)
{
    (void) corewar;
    robot->read_index = get_address(robot->read_index + 3);
    return;
}
