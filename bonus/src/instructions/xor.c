/*
** EPITECH PROJECT, 2024
** xor
** File description:
** xor instruction
*/

#include "../../include/corewar.h"

static int *read_xor_args(memory_t *memory, robot_t *robot,
    char *coding_byte)
{
    int *arguments = malloc(sizeof(int) * 4);
    int move = 1;

    if (!arguments) {
        my_puterr("read_xor_args: Memory allocation failed\n");
        free(coding_byte);
        return NULL;
    }
    for (int i = 0; i < 2; i++) {
        arguments[i] = read_parameters_with_cbyte(memory, coding_byte[i],
            robot->read_index + move);
        if (coding_byte[i] == T_IND) {
            arguments[i] = robot->read_index + arguments[i] % IDX_MOD;
        }
        move += get_movement_size_with_cbyte(coding_byte[i]);
    }
    move++;
    arguments[2] = get_address_value(memory, robot->read_index + move);
    arguments[3] = move + 1;
    return arguments;
}

static bool check_xor_args_are_valid(int *args, char *c_byte, robot_t *robot)
{
    for (int i = 0; i < 2; i++) {
        if (c_byte[i] == T_REG && register_is_valid(args[i]) == false) {
            return false;
        }
        if (c_byte[i] == T_REG) {
            args[i] = robot->registers[args[i] - 1];
        }
    }
    if (register_is_valid(args[2]) == false) {
        return false;
    }
    return true;
}

void xor_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(MEMORY[robot->read_index + 1].memory);
    int *args = read_xor_args(MEMORY, robot, c_byte);
    int result;

    if (!args)
        return;
    robot->carry = 0;
    if (check_xor_args_are_valid(args, c_byte, robot) == false) {
        robot->read_index = get_address(robot->read_index + args[3]);
        free(c_byte);
        free(args);
        return;
    }
    result = args[0] ^ args[1];
    robot->registers[args[2] - 1] = result;
    robot->read_index = get_address(robot->read_index + args[3]);
    if (result == 0)
        robot->carry = 1;
    free(c_byte);
    free(args);
}
