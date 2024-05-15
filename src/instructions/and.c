/*
** EPITECH PROJECT, 2024
** and
** File description:
** And instruction
*/

#include "../../include/corewar.h"

static int *read_and_args(unsigned char *memory, robot_t *robot,
    char *coding_byte)
{
    int *arguments = malloc(sizeof(int) * 4);
    int move = 0;

    if (!arguments) {
        my_puterr("read_and_args: Memory allocation failed\n");
        free(coding_byte);
        return NULL;
    }
    move++;
    for (int i = 0; i < 2; i++) {
        arguments[i] = read_parameters_with_cbyte(memory, coding_byte[i],
            robot->read_index + move);
        if (coding_byte[i] == T_IND)
            arguments[i] = robot->read_index + arguments[i] % IDX_MOD;
        move += get_movement_size_with_cbyte(coding_byte[i]);
    }
    arguments[2] = get_address_value(memory, robot->read_index + move);
    robot->read_index += move + 2;
    return arguments;
}

static bool check_and_args_are_valid(int *args, char *c_byte)
{
    for (int i = 0; i < 2; i++) {
        if (c_byte[i] == T_REG && register_is_valid(args[i]) == false) {
            return false;
        }
    }
    if (register_is_valid(args[2]) == false) {
        return false;
    }
    return true;
}

void and_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(corewar->memory[robot->read_index + 1]);
    int *args = read_and_args(corewar->memory, robot, c_byte);
    int result;

    if (!args) {
        return;
    }
    if (check_and_args_are_valid(args, c_byte) == false) {
        free(c_byte);
        free(args);
        return;
    }
    result = args[0] & args[1];
    robot->registers[args[2]] = result;
    robot->carry = 0;
    if (result == 0) {
        robot->carry = 1;
    }
    free(c_byte);
    free(args);
}
