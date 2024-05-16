/*
** EPITECH PROJECT, 2024
** ldi
** File description:
** ldi instruction
*/

#include "../../include/corewar.h"

static bool check_ldi_args(int *arguments, char *coding_byte, robot_t *robot)
{
    for (int i = 0; i < 2; i++) {
        if (coding_byte[i] == T_REG
            && register_is_valid(arguments[i]) == false) {
            return false;
        }
        if (coding_byte[i] == T_REG) {
            arguments[i] = robot->registers[arguments[i] - 1];
        }
        if (coding_byte[i] == T_IND) {
            arguments[i] = robot->read_index + arguments[i] % IDX_MOD;
        }
    }
    if (register_is_valid(arguments[2]) == false) {
        return false;
    }
    return true;
}

static int *parse_ldi_args(unsigned char *memory, robot_t *robot,
    char *coding_byte)
{
    int *arguments = malloc(sizeof(int) * 4);
    int move = 1;

    if (!arguments) {
        my_puterr("read_and_args: Memory allocation failed\n");
        free(coding_byte);
        return false;
    }
    for (int i = 0; i < 2; i++) {
        arguments[i] = read_parameters_with_cbyte(memory, coding_byte[i],
            robot->read_index + move);
        move += get_movement_size_with_cbyte(coding_byte[i]);
    }
    move++;
    arguments[2] = get_address_value(memory, robot->read_index + move);
    arguments[3] = move + 1;
    return arguments;
}

static int second_read_ldi(corewar_t *corewar, robot_t *robot,
    int previous_result)
{
    int index = get_address(robot->read_index + previous_result % IDX_MOD - 1);
    int result = 0;

    result = convert_xbytes(corewar->memory, index, REG_SIZE);
    return result;
}

static int first_read_ldi(corewar_t *corewar, robot_t *robot, int *arguments)
{
    int index = get_address(robot->read_index + arguments[0] % IDX_MOD - 1);
    int result = 0;

    result = convert_xbytes(corewar->memory, index, IND_SIZE);
    result += arguments[1];
    return second_read_ldi(corewar, robot, result);
}

void ldi_instruction(corewar_t *corewar, robot_t *robot)
{
    char *c_byte = read_coding_byte(get_address_value(MEMORY, READ_INDEX + 1));
    int *args = parse_ldi_args(corewar->memory, robot, c_byte);
    int result = 0;

    robot->carry = 0;
    if (!args) {
        free(c_byte);
        return;
    }
    if (check_ldi_args(args, c_byte, robot) == false) {
        robot->read_index = get_address(robot->read_index + args[3]);
        free(c_byte);
        free(args);
        return;
    }
    result = first_read_ldi(corewar, robot, args);
    robot->registers[args[2] - 1] = result;
    if (result == 0)
        robot->carry = 1;
    robot->read_index += args[3];
}
