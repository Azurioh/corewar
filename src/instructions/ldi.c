/*
** EPITECH PROJECT, 2024
** ldi
** File description:
** ldi instruction
*/

#include "../../include/corewar.h"

static int *parse_ldi_args(unsigned char *memory, robot_t *robot,
    char *coding_byte)
{
    int *arguments = malloc(sizeof(int) * 4);
    int move = 0;

    if (!arguments) {
        my_puterr("read_and_args: Memory allocation failed\n");
        free(coding_byte);
        return false;
    }
    move++;
    for (int i = 0; i < 2; i++) {
        arguments[i] = read_parameters_with_cbyte(memory, coding_byte[i],
            robot->read_index + move);
        move += get_movement_size_with_cbyte(coding_byte[i]);
    }
    arguments[2] = get_address_value(memory, robot->read_index + move);
    arguments[3] = move + 2;
    return arguments;
}

static int first_read_ldi(corewar_t *corewar, robot_t *robot, int *arguments)
{
    int index = robot->read_index + arguments[0] % IDX_MOD;
    int result = 0;

    for (int i = 0; i < IND_SIZE; i++) {
        result += get_address_value(corewar->memory, index + i);
    }
    result += arguments[1];
    return result;
}

static int second_read_ldi(corewar_t *corewar, robot_t *robot,
    int previous_result)
{
    int index = robot->read_index + previous_result % IDX_MOD;
    int result = 0;

    for (int i = 0; i < REG_SIZE; i++) {
        result += get_address_value(corewar->memory, index + i);
    }
    return result;
}

void ldi_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(robot->read_index + 1);
    int *args = parse_ldi_args(corewar->memory, robot, c_byte);
    int result = 0;

    robot->carry = 0;
    if (!args) {
        free(c_byte);
        return;
    }
    result = first_read_ldi(corewar, robot, args);
    result = second_read_ldi(corewar, robot, result);
    robot->registers[0] = result;
    if (result == 0) {
        robot->carry = 1;
    }
    robot->read_index += args[3];
}
