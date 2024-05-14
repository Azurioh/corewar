/*
** EPITECH PROJECT, 2024
** corewar_tests
** File description:
** All unit tests for the corewar project
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "../include/corewar.h"

Test (add, add_instrcution_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[2] = 1;
    corewar->memory[3] = 2;
    corewar->memory[4] = 3;
    robot->registers[0] = 12;
    robot->registers[1] = 25;
    add(corewar, robot);
    cr_assert_eq(robot->registers[0], 12);
    cr_assert_eq(robot->registers[1], 25);
    cr_assert_eq(robot->registers[2], 37);
    cr_assert_eq(robot->read_index, 5);
    cr_assert_eq(corewar->carry, 0);
}
Test (add, add_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[27] = 5;
    corewar->memory[28] = 8;
    corewar->memory[29] = 3;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 38 + 80);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(corewar->carry, 0);
}
Test(add, add_instrctuion_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 58;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[60] = 3;
    corewar->memory[61] = 3;
    corewar->memory[62] = 2;
    robot->registers[2] = 38;
    add(corewar, robot);
    cr_assert_eq(robot->registers[2], 38);
    cr_assert_eq(robot->registers[1], 38 * 2);
    cr_assert_eq(robot->read_index, 63);
    cr_assert_eq(corewar->carry, 0);
}
Test(add, add_instruction_successfull_edit_carry_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[2] = 1;
    corewar->memory[3] = 2;
    corewar->memory[4] = 3;
    robot->registers[0] = -10;
    robot->registers[1] = 10;
    add(corewar, robot);
    cr_assert_eq(robot->registers[0], -10);
    cr_assert_eq(robot->registers[1], 10);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 5);
    cr_assert_eq(corewar->carry, 1);
}
Test(add, add_instruction_successfull_edit_carry_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[27] = 5;
    corewar->memory[28] = 8;
    corewar->memory[29] = 3;
    robot->registers[4] = -38;
    robot->registers[7] = 38;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], -38);
    cr_assert_eq(robot->registers[7], 38);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(corewar->carry, 1);
}
Test(add, add_instruction_with_wrong_registers_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[27] = 5;
    corewar->memory[28] = 8;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(corewar->carry, 1);
}
Test(add, add_instruction_with_wrong_registers_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(char) * REG_SIZE);
    corewar->memory[27] = 5;
    corewar->memory[28] = 18;
    corewar->memory[29] = 7;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(corewar->carry, 1);
}