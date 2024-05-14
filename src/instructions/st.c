/*
** EPITECH PROJECT, 2024
** st
** File description:
** st instruction
*/

#include "../../include/corewar.h"

static char *parse_st_args(unsigned char *memory, char *coding_byte,
    int read_index)
{
    char *arguments = malloc(sizeof(char) * 4);

    if (!arguments) {
        my_puterr("parse_st_args: Memory allocation failed\n");
        return NULL;
    }
    arguments[0] = get_address_value(memory, read_index + 2);
    arguments[1] = get_address_value(memory, read_index + 3);
    if (coding_byte[1] == T_IND) {
        arguments[1] = (arguments[1] << 8);
        arguments[1] += get_address_value(memory, read_index + 4);
    }
    arguments[2] = 0;
    free(coding_byte);
    return arguments;
}

static void store_st_result(unsigned char *memory, char *arguments,
    char *coding_byte,
    robot_t *robot)
{
    if (coding_byte[1] == T_IND) {
        memory[robot->read_index + arguments[1] % IDX_MOD] = arguments[0];
        robot->read_index = get_address(robot->read_index + 5);
    } else {
        robot->registers[(int)arguments[1]] = arguments[0];
        robot->read_index = get_address(robot->read_index + 4);
    }
}

void st_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(corewar->memory[robot->read_index + 1]);
    char *arguments = parse_st_args(corewar->memory, c_byte,
        robot->read_index);

    if (!arguments) {
        if (c_byte[1] == T_IND) {
            robot->read_index = get_address(robot->read_index + 5);
        } else {
            robot->read_index += get_address(robot->read_index + 4);
        }
        free(c_byte);
        return;
    }
    store_st_result(corewar->memory, arguments, c_byte, robot);
    free(arguments);
    free(c_byte);
}
