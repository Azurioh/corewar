/*
** EPITECH PROJECT, 2024
** sti
** File description:
** sti instruction
*/
#include "../../include/corewar.h"

int get_register_value(robot_t *robot, int index)
{
    int register_value;

    if (register_is_valid(index) == false) {
        return -1;
    }
    register_value = robot->registers[index - 1];
    return register_value;
}

int get_nparameter_value(robot_t *robot, unsigned char *memory, char c_byte,
    int *index)
{
    int value;

    if (c_byte == T_REG) {
        value = get_register_value(robot,
            get_address_value(memory, robot->read_index + *index));
        *index += 1;
        if (value == -1)
            return -1;
    } else {
        value = convert_2bytes(memory, *index - 1);
        *index += 2;
    }
    return value;
}

int get_sti_address_to_stock(robot_t *robot, unsigned char *memory,
    char *c_byte, int *param_size)
{
    int first_value;
    int second_value;

    first_value = get_nparameter_value(robot, memory, c_byte[1], param_size);
    second_value = get_nparameter_value(robot, memory, c_byte[2], param_size);
    return (first_value + second_value) % IDX_MOD;
}

void sti_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(corewar->memory[robot->read_index + 1]);
    int param_size = 3;
    int value_to_store = get_register_value(robot,
        get_address(robot->read_index + 2));
    int address = get_sti_address_to_stock(robot, corewar->memory, c_byte,
        &param_size);

    robot->read_index = get_address(robot->read_index + param_size);
    if (value_to_store == -1)
        return;
    corewar->memory[get_address(address)] = value_to_store;
    return;
}
