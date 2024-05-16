/*
** EPITECH PROJECT, 2024
** ld
** File description:
** load instruction
*/
#include "../../include/corewar.h"

int get_lld_value(memory_t *memory, robot_t *robot, int *index_reg)
{
    char *type_tab = read_coding_byte(memory[robot->read_index + 1].memory);
    int index;

    if (type_tab[0] == T_DIR) {
        free(type_tab);
        *index_reg += 4;
        return convert_4bytes(memory, robot->read_index + 1);
    }
    index = convert_2bytes(memory, robot->read_index + 1);
    index += robot->read_index;
    *index_reg += 2;
    return convert_4bytes(memory, get_address(index - 1));
}

void lld_instruction(corewar_t *corewar, robot_t *robot)
{
    int value;
    int index_of_reg_nb = 2;
    int register_index;

    value = get_lld_value(corewar->memory, robot, &index_of_reg_nb);
    register_index = get_address_value(corewar->memory,
        robot->read_index + index_of_reg_nb);
    robot->registers[register_index - 1] = value;
    robot->read_index = get_address(robot->read_index + index_of_reg_nb + 1);
    robot->carry = 0;
    if (value == 0)
        robot->carry = 1;
    return;
}
