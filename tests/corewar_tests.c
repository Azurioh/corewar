/*
** EPITECH PROJECT, 2024
** corewar_tests
** File description:
** All unit tests for the corewar project
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "../include/unittests.h"
#include "../include/corewar.h"

Test(add, add_instrcution_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
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
    cr_assert_eq(robot->carry, 0);
}
Test(add, add_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
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
    cr_assert_eq(robot->carry, 0);
}
Test(add, add_instrctuion_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 58;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[60] = 3;
    corewar->memory[61] = 3;
    corewar->memory[62] = 2;
    robot->registers[2] = 38;
    add(corewar, robot);
    cr_assert_eq(robot->registers[2], 38);
    cr_assert_eq(robot->registers[1], 38 * 2);
    cr_assert_eq(robot->read_index, 63);
    cr_assert_eq(robot->carry, 0);
}
Test(add, add_instruction_successfull_edit_carry_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
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
    cr_assert_eq(robot->carry, 1);
}
Test(add, add_instruction_successfull_edit_carry_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
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
    cr_assert_eq(robot->carry, 1);

}
Test(add, add_instruction_with_wrong_registers_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 0;
    corewar->memory[28] = 0;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 0;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 1;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 100;
    corewar->memory[28] = 1;
    corewar->memory[29] = 1;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_5)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 100;
    corewar->memory[29] = 1;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_6)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 1;
    corewar->memory[29] = 100;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_7)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 139;
    corewar->memory[28] = 159;
    corewar->memory[29] = 100;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(add, add_instruction_with_wrong_registers_8)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = -25;
    corewar->memory[28] = 0;
    corewar->memory[29] = -40;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    add(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}

Test(sub, sub_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[2] = 1;
    corewar->memory[3] = 2;
    corewar->memory[4] = 3;
    robot->registers[0] = 12;
    robot->registers[1] = 25;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[0], 12);
    cr_assert_eq(robot->registers[1], 25);
    cr_assert_eq(robot->registers[2], 12 - 25);
    cr_assert_eq(robot->read_index, 5);
    cr_assert_eq(robot->carry, 0);
}
Test(sub, sub_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 5;
    corewar->memory[28] = 8;
    corewar->memory[29] = 3;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 38 - 80);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(robot->carry, 0);
}
Test(sub, sub_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[2] = 1;
    corewar->memory[3] = 2;
    corewar->memory[4] = 3;
    robot->registers[0] = -10;
    robot->registers[1] = 10;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[0], -10);
    cr_assert_eq(robot->registers[1], 10);
    cr_assert_eq(robot->registers[2], -20);
    cr_assert_eq(robot->read_index, 5);
    cr_assert_eq(robot->carry, 0);
}
Test(sub, sub_instrctuion_successfull_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 1] = 1;
    corewar->memory[0] = 2;
    corewar->memory[1] = 3;
    robot->registers[0] = -10;
    robot->registers[1] = 10;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[0], -10);
    cr_assert_eq(robot->registers[1], 10);
    cr_assert_eq(robot->registers[2], -20);
    cr_assert_eq(robot->read_index, 2);
    cr_assert_eq(robot->carry, 0);
}
Test(sub, sub_instruction_successfull_edit_carry_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 58;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[60] = 3;
    corewar->memory[61] = 3;
    corewar->memory[62] = 2;
    robot->registers[2] = 38;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[2], 38);
    cr_assert_eq(robot->registers[1], 0);
    cr_assert_eq(robot->read_index, 63);
    cr_assert_eq(robot->carry, 1);
}
Test(sub, sub_instruction_successfull_edit_carry_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 5;
    corewar->memory[28] = 8;
    corewar->memory[29] = 3;
    robot->registers[4] = -38;
    robot->registers[7] = -38;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], -38);
    cr_assert_eq(robot->registers[7], -38);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
    cr_assert_eq(robot->carry, 1);

}
Test(sub, sub_instruction_with_wrong_registers_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 0;
    corewar->memory[28] = 0;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 0;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 1;
    corewar->memory[29] = 0;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 100;
    corewar->memory[28] = 1;
    corewar->memory[29] = 1;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_5)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 100;
    corewar->memory[29] = 1;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_6)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 1;
    corewar->memory[28] = 1;
    corewar->memory[29] = 100;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_7)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = 120;
    corewar->memory[28] = 138;
    corewar->memory[29] = 198;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}
Test(sub, sub_instruction_with_wrong_registers_8)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[27] = -100;
    corewar->memory[28] = -37;
    corewar->memory[29] = -90;
    robot->registers[4] = 38;
    robot->registers[7] = 80;
    robot->registers[2] = 0;
    sub(corewar, robot);
    cr_assert_eq(robot->registers[4], 38);
    cr_assert_eq(robot->registers[7], 80);
    cr_assert_eq(robot->registers[2], 0);
    cr_assert_eq(robot->read_index, 30);
}

Test(st_instruction, set_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 80;
    corewar->memory[2] = 2;
    corewar->memory[3] = 3;
    robot->registers[1] = 25;
    robot->registers[2] = 50;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[1], 25);
    cr_assert_eq(robot->registers[2], 25);
    cr_assert_eq(robot->read_index, 4);
}
Test(st_instruction, set_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 25;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[26] = 80;
    corewar->memory[27] = 4;
    corewar->memory[28] = 6;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 92);
    cr_assert_eq(robot->read_index, 29);
}
Test(st_instruction, set_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;
    int result;

    robot->read_index = 25;
    memory_index = get_address(robot->read_index + ((6 << 8) + 10) % IDX_MOD);
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[26] = 112;
    corewar->memory[27] = 4;
    corewar->memory[28] = 6;
    corewar->memory[29] = 10;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    result = convert_4bytes(corewar->memory, memory_index - 1);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(result, 92);
    cr_assert_eq(robot->read_index, 30);
}
Test(st_instruction, set_instruction_successfull_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 4;
    corewar->memory[0] = 6;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 92);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_successfull_5)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;

    robot->read_index = MEM_SIZE - 2;
    memory_index = get_address(robot->read_index + ((18 << 8) + 25) % IDX_MOD);
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    
    corewar->memory[MEM_SIZE - 1] = 112;
    corewar->memory[0] = 4;
    corewar->memory[1] = 18;
    corewar->memory[2] = 25;

    robot->registers[3] = 20;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 20);
    cr_assert_eq(convert_4bytes(corewar->memory, memory_index - 1), 20);
    cr_assert_eq(robot->read_index, 3);
}
Test(st_instruction, set_instruction_with_wrong_register_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 0;
    corewar->memory[0] = 6;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 49);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_with_wrong_register_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 1;
    corewar->memory[0] = 0;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 49);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_with_wrong_register_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 18;
    corewar->memory[0] = 1;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 49);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_with_wrong_register_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 1;
    corewar->memory[0] = 25;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 49);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_with_wrong_register_5)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 80;
    corewar->memory[MEM_SIZE - 1] = 28;
    corewar->memory[0] = 25;
    robot->registers[5] = 49;
    robot->registers[3] = 92;
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(robot->registers[5], 49);
    cr_assert_eq(robot->read_index, 1);
}
Test(st_instruction, set_instruction_with_wrong_register_6)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;

    robot->read_index = MEM_SIZE - 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[MEM_SIZE - 2] = 112;
    corewar->memory[MEM_SIZE - 1] = 4;
    corewar->memory[0] = 25;
    corewar->memory[1] = 29;
    robot->registers[3] = 92;
    memory_index = get_address(robot->read_index +
        ((corewar->memory[0] << 8) + (corewar->memory[1])) % IDX_MOD);
    st_instruction(corewar, robot);
    cr_assert_eq(robot->registers[3], 92);
    cr_assert_eq(convert_4bytes(corewar->memory, memory_index - 1), 92);
    cr_assert_eq(robot->read_index, 2);
}

Test(fork_instruction, fork_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};
    int new_read_index;

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = 0;
    list_robots[0] = robot;
    list_robots[1] = NULL;
    corewar->nbr_robots = 1;
    corewar->robots = list_robots;
    corewar->memory[1] = 25;
    corewar->memory[2] = 50;
    new_read_index = convert_2bytes(corewar->memory, robot->read_index);
    fork_instruction(corewar, robot);
    cr_assert_eq(corewar->nbr_robots, 2);
    cr_assert_not_null(corewar->robots[1]);
    cr_assert_eq(corewar->robots[1]->read_index, robot->read_index + new_read_index % IDX_MOD);
}
Test(fork_instruction, fork_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};
    int new_read_index;

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = MEM_SIZE - 2;
    list_robots[0] = robot;
    list_robots[1] = robot;
    list_robots[2] = robot;
    list_robots[3] = robot;
    list_robots[4] = NULL;
    corewar->nbr_robots = 4;
    corewar->robots = list_robots;
    corewar->memory[MEM_SIZE - 1] = 25;
    corewar->memory[0] = 50;
    new_read_index = convert_2bytes(corewar->memory, robot->read_index); 
    fork_instruction(corewar, robot);
    cr_assert_eq(corewar->nbr_robots, 5);
    cr_assert_not_null(corewar->robots[4]);
    cr_assert_eq(corewar->robots[4]->read_index, robot->read_index + new_read_index % IDX_MOD);
}
Test(lfork_instruction, lfork_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};
    int new_read_index;

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = 0;
    list_robots[0] = robot;
    list_robots[1] = NULL;
    corewar->nbr_robots = 1;
    corewar->robots = list_robots;
    corewar->memory[1] = 25;
    corewar->memory[2] = 50;
    new_read_index = convert_2bytes(corewar->memory, robot->read_index); 
    lfork_instruction(corewar, robot);
    cr_assert_eq(corewar->nbr_robots, 2);
    cr_assert_not_null(corewar->robots[1]);
    cr_assert_eq(corewar->robots[1]->read_index, robot->read_index + new_read_index);
}
Test(lfork_instruction, lfork_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};
    int new_read_index;

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = MEM_SIZE - 2;
    list_robots[0] = robot;
    list_robots[1] = robot;
    list_robots[2] = robot;
    list_robots[3] = robot;
    list_robots[4] = NULL;
    corewar->nbr_robots = 4;
    corewar->robots = list_robots;
    corewar->memory[MEM_SIZE - 1] = 25;
    corewar->memory[0] = 50;
    new_read_index = convert_2bytes(corewar->memory, robot->read_index);
    lfork_instruction(corewar, robot);
    cr_assert_eq(corewar->nbr_robots, 5);
    cr_assert_not_null(corewar->robots[4]);
    cr_assert_eq(corewar->robots[4]->read_index, robot->read_index + new_read_index);
}

Test(live, live_instruction_successfull_1, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));

    robot->name = (unsigned char *)"Nom du robot";
    robot->nb_player = 2;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->read_index = 0;
    list_robots[0] = robot;
    list_robots[1] = NULL;
    corewar->nbr_live = 0;
    corewar->robots = list_robots;
    corewar->memory[1] = 0;
    corewar->memory[2] = 0; 
    corewar->memory[3] = 0; 
    corewar->memory[4] = 2;
    live(corewar, robot);
    cr_assert_eq(robot->is_alive, true);
    cr_assert_eq(corewar->nbr_live, 1);
    cr_assert_eq(robot->read_index, 5);
}
Test(live, live_instruction_successfull_2, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = 0;
    list_robots[0] = robot;
    list_robots[1] = NULL;
    corewar->nbr_live = 0;
    corewar->robots = list_robots;
    corewar->memory[1] = 0;
    corewar->memory[2] = 0; 
    corewar->memory[3] = 0; 
    corewar->memory[4] = 3;
    corewar->nbr_robots = 1;
    fork_instruction(corewar, robot);
    corewar->robots[1]->nb_player = 3;
    live(corewar, robot);
    cr_assert_eq(robot->is_alive, false);
    cr_assert_eq(corewar->robots[1]->is_alive, true);
    cr_assert_eq(corewar->nbr_live, 1);
    cr_assert_eq(robot->read_index, 5);
}
Test(live, live_instruction_with_wrong_id_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->is_alive = false;
    list_robots[0] = NULL;
    corewar->nbr_live = 0;
    corewar->robots = list_robots;
    corewar->memory[1] = 0;
    corewar->memory[2] = 0; 
    corewar->memory[3] = 0; 
    corewar->memory[4] = 3;
    corewar->nbr_robots = 0;
    live(corewar, robot);
    cr_assert_eq(robot->is_alive, false);
}
Test(live, live_instruction_with_wrong_id_2)
{
    corewar_t *corewar = init_corewar();
    robot_t **list_robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));
    int registers[] = {2, 0, 0, 19, 0, 0, 14, 0, 0, 12, 0, 0, 0, 18, 0, 0};

    robot->name = (unsigned char *)"Nom du robot";
    robot->program = (unsigned char *)"";
    robot->prog_size = 25;
    robot->nb_player = 2;
    robot->registers = registers;
    robot->is_alive = false;
    robot->is_dead = false;
    robot->start_index_in_memory = 5;
    robot->end_index_in_memory = 10;
    robot->carry = 0;
    robot->read_index = 0;
    list_robots[0] = robot;
    list_robots[1] = NULL;
    corewar->nbr_live = 0;
    corewar->robots = list_robots;
    corewar->memory[1] = 0;
    corewar->memory[2] = 0; 
    corewar->memory[3] = 0; 
    corewar->memory[4] = 25;
    corewar->nbr_robots = 1;
    fork_instruction(corewar, robot);
    corewar->robots[1]->nb_player = 3;
    live(corewar, robot);
    cr_assert_eq(robot->is_alive, false);
}

Test(and_instruction, and_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;
    int val1;
    int val2;
    int result;

    robot->read_index = 0;
    memory_index = get_address(robot->read_index + ((18 << 8) + 25) % IDX_MOD);
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 244;
    corewar->memory[2] = 19;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 93;
    corewar->memory[6] = 5;
    robot->registers[4] = 20;
    val1 = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    val2 = robot->read_index + convert_2bytes(corewar->memory, 3) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(and_instruction, and_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    memory_index = get_address(robot->read_index + ((18 << 8) + 25) % IDX_MOD);
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 244;
    corewar->memory[2] = 19;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 93;
    corewar->memory[6] = 5;
    robot->registers[4] = 20;
    val1 = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    val2 = robot->read_index + convert_2bytes(corewar->memory, 3) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(and_instruction, and_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int memory_index;
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    memory_index = get_address(robot->read_index + ((18 << 8) + 25) % IDX_MOD);
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 5;
    robot->registers[4] = 20;
    val1 = get_address_value(corewar->memory, 2);
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], result);
}