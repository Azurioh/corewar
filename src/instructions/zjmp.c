/*
** EPITECH PROJECT, 2024
** zjmp
** File description:
** zjmp instruction
*/
#include "../../include/corewar.h"

void zjmp(corewar_t *corewar, robot_t *robot)
{
    int value;

    if (robot->carry == 0) {
        robot->read_index = get_address(robot->read_index + 3);
        return;
    }
    value = convert_2bytes(corewar->memory, robot->read_index);
    if (value > 32767)
        value -= 65536;
    value = value % IDX_MOD;
    robot->read_index = get_address(robot->read_index + value);
    return;
}
