/*
** EPITECH PROJECT, 2024
** sti
** File description:
** sti instruction
*/
#include "../../include/corewar.h"

int get_register_value(robot_t *robot, unsigned char *memory, int index)
{
    int register_index;
    int register_value;

    if (register_is_valid(memory[get_address(robot->read_index + index)])
        == false) {
        return -1;
    }
    register_index = get_address_value(memory,
        get_address(robot->read_index + index));
    register_value = robot->registers[register_index];
    return register_value;
}

int get_nparameter_value(robot_t *robot, unsigned char *memory, char c_byte,
    int *index)
{
    int value;

    if (c_byte == T_REG) {
        value = get_register_value(robot, memory,
            get_address(robot->read_index + *index));
        if (value == -1)
            return -1;
        *index += 4;
    } else {
        value = get_address_value(memory,
            get_address(robot->read_index + *index));
        *index += 7;
    }
    return value;
}

int get_sti_address_to_stock(robot_t *robot, unsigned char *memory,
    char *c_byte, int *param_size)
{
    int first_value;
    int second_value;
    int index = 3;

    if (c_byte[1] == T_REG)
        *param_size += 1;
    else
        *param_size += 2;
    if (c_byte[2] == T_REG)
        *param_size += 1;
    else
        *param_size += 2;
    first_value = get_nparameter_value(robot, memory, c_byte[1], &index);
    second_value = get_nparameter_value(robot, memory, c_byte[2], &index);
    return first_value + second_value;
}

void sti_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(corewar->memory[robot->read_index + 1]);
    int param_size = 3;
    int value_to_store = get_register_value(robot, corewar->memory,
        get_address(robot->read_index + 2));
    int address = get_sti_address_to_stock(robot, corewar->memory, c_byte,
        &param_size);

    robot->read_index = get_address(robot->read_index + param_size);
    corewar->memory[get_address(address)] = value_to_store;
    return;
}
