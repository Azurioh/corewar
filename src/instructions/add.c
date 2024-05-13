/*
** EPITECH PROJECT, 2024
** add
** File description:
** Add instruction
*/

#include "../../include/corewar.h"

static bool check_if_add_registers_are_valid(int reg1, int reg2, int reg3)
{
    if (reg1 < 1 || reg1 > REG_NUMBER) {
        return false;
    }
    if (reg2 < 1 || reg2 > REG_NUMBER) {
        return false;
    }
    if (reg3 < 1 || reg3 > REG_NUMBER) {
        return false;
    }
    return true;
}

void add(corewar_t *corewar, robot_t *robot)
{
    int reg1 = corewar->memory[robot->reading_index + 2] - 1;
    int reg2 = corewar->memory[robot->reading_index + 3] - 1;
    int reg3 = corewar->memory[robot->reading_index + 4] - 1;
    int result = 0;

    if (check_if_add_registers_are_valid(reg1, reg2, reg3) == true) {
        result = robot->registers[reg1] + robot->registers[reg2];
        robot->registers[reg3 - 1] = result;
    }
    if (result == 0) {
        corewar->carry = 1;
    } else {
        corewar->carry = 0;
    }
    robot->reading_index += 5;
    robot->nb_cycles_to_wait = get_operation_info("add").nbr_cycles;
    return;
}
