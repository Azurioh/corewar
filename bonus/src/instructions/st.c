/*
** EPITECH PROJECT, 2024
** st
** File description:
** st instruction
*/

#include "../../include/corewar.h"

static int *parse_st_args(memory_t *memory, char *coding_byte,
    int read_index)
{
    int *arguments = malloc(sizeof(int) * 4);

    if (!arguments) {
        my_puterr("parse_st_args: Memory allocation failed\n");
        return NULL;
    }
    arguments[0] = get_address_value(memory, read_index + 2);
    arguments[1] = get_address_value(memory, read_index + 3);
    if (coding_byte[1] == T_IND) {
        arguments[1] = arguments[1] << 8;
        arguments[1] += get_address_value(memory, read_index + 4);
    }
    arguments[2] = 0;
    return arguments;
}

static void move_robot_index_st_command(char *coding_byte, robot_t *robot)
{
    if (coding_byte[1] == T_IND) {
        robot->read_index = get_address(robot->read_index + 5);
    } else {
        robot->read_index = get_address(robot->read_index + 4);
    }
}

static void store_st_result(corewar_t *corewar, int *arguments,
    char *coding_byte, robot_t *robot)
{
    int value;

    if (register_is_valid((int)arguments[0]) == false) {
        return;
    }
    value = robot->registers[(int)arguments[0] - 1];
    if (coding_byte[1] == T_IND) {
        register_to_memory(corewar,
            robot->read_index + (int)arguments[1] % IDX_MOD, value);
    } else {
        if (register_is_valid((int)arguments[1]) == false) {
            return;
        }
        robot->registers[(int)arguments[1] - 1] = value;
    }
}

void st_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(corewar->memory[robot->read_index + 1].memory);
    int *arguments = parse_st_args(corewar->memory, c_byte,
        robot->read_index);

    if (!arguments) {
        move_robot_index_st_command(c_byte, robot);
        free(c_byte);
        return;
    }
    store_st_result(corewar, arguments, c_byte, robot);
    move_robot_index_st_command(c_byte, robot);
    free(arguments);
    free(c_byte);
}
