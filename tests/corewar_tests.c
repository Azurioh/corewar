/*
** EPITECH PROJECT, 2024
** corewar_tests
** File description:
** All unit tests for the corewar project
*/

#include <criterion/criterion.h>
// #include <criterion/new/assert.h>
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
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 2;
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
    corewar->robots[1]->registers[0] = 3;
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
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 2;
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
    corewar->robots[1]->registers[0] = 3;
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
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(and_instruction, and_instruction_successfull_4)
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
    corewar->memory[2] = 1;
    corewar->memory[3] = 0;
    corewar->memory[4] = 0;
    corewar->memory[5] = 5;
    robot->registers[0] = 0;
    robot->registers[4] = 20;
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 1);
    cr_assert_eq(robot->registers[4], result);
}
Test(and_instruction, and_instruction_successfull_5)
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
    corewar->memory[2] = 1;
    corewar->memory[3] = 12;
    corewar->memory[4] = 32;
    corewar->memory[5] = 24;
    corewar->memory[6] = 5;
    robot->registers[4] = 20;
    val1 = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    val2 = robot->read_index + convert_2bytes(corewar->memory, 3) % IDX_MOD;
    result = val1 & val2;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(and_instruction, and_instruction_with_wrong_register_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 20;
    robot->registers[4] = 20;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 20);
}
Test(and_instruction, and_instruction_with_wrong_register_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 20;
    robot->registers[4] = 5;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}
Test(and_instruction, and_instruction_with_wrong_register_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 212;
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 5;
    robot->registers[4] = 5;
    and_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}

Test(or_instruction, or_instruction_successfull_1)
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
    result = val1 | val2;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(or_instruction, or_instruction_successfull_2)
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
    result = val1 | val2;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(or_instruction, or_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 5;
    robot->registers[4] = 20;
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 | val2;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(or_instruction, or_instruction_successfull_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 1;
    corewar->memory[3] = 0;
    corewar->memory[4] = 0;
    corewar->memory[5] = 5;
    robot->registers[0] = 0;
    robot->registers[4] = 20;
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 | val2;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 1);
    cr_assert_eq(robot->registers[4], result);
}
Test(or_instruction, or_instruction_successfull_5)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 244;
    corewar->memory[2] = 1;
    corewar->memory[3] = 12;
    corewar->memory[4] = 32;
    corewar->memory[5] = 24;
    corewar->memory[6] = 5;
    robot->registers[4] = 20;
    val1 = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    val2 = robot->read_index + convert_2bytes(corewar->memory, 3) % IDX_MOD;
    result = val1 | val2;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(or_instruction, or_instruction_with_wrong_register_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 20;
    robot->registers[4] = 20;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 20);
}
Test(or_instruction, or_instruction_with_wrong_register_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 20;
    robot->registers[4] = 5;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}
Test(or_instruction, or_instruction_with_wrong_register_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 212;
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 5;
    robot->registers[4] = 5;
    or_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}

Test(xor_instruction, xor_instruction_successfull_1)
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
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(xor_instruction, xor_instruction_successfull_2)
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
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[4], result);
    cr_assert_eq(robot->carry, 0);
}
Test(xor_instruction, xor_instruction_successfull_3)
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
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(xor_instruction, xor_instruction_successfull_4)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int result;
    int val1;
    int val2;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 116;
    corewar->memory[2] = 1;
    corewar->memory[3] = 0;
    corewar->memory[4] = 0;
    corewar->memory[5] = 5;
    robot->registers[0] = 0;
    robot->registers[4] = 20;
    val1 = robot->registers[get_address_value(corewar->memory, 2) - 1];
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 1);
    cr_assert_eq(robot->registers[4], result);
}
Test(xor_instruction, xor_instruction_successfull_5)
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
    corewar->memory[2] = 1;
    corewar->memory[3] = 12;
    corewar->memory[4] = 32;
    corewar->memory[5] = 24;
    corewar->memory[6] = 5;
    robot->registers[4] = 20;
    val1 = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    val2 = robot->read_index + convert_2bytes(corewar->memory, 3) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], result);
}
Test(xor_instruction, xor_instruction_with_wrong_register_1)
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
    corewar->memory[5] = 20;
    robot->registers[4] = 20;
    val1 = get_address_value(corewar->memory, 2);
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 20);
}
Test(xor_instruction, xor_instruction_with_wrong_register_2)
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
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 20;
    robot->registers[4] = 5;
    val1 = get_address_value(corewar->memory, 2);
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}
Test(xor_instruction, xor_instruction_with_wrong_register_3)
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
    corewar->memory[1] = 212;
    corewar->memory[2] = 25;
    corewar->memory[3] = 18;
    corewar->memory[4] = 25;
    corewar->memory[5] = 5;
    robot->registers[4] = 5;
    val1 = get_address_value(corewar->memory, 2);
    val2 = robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    result = val1 ^ val2;
    xor_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->carry, 0);
    cr_assert_eq(robot->registers[4], 5);
}

Test(ld_instruction, ld_instruction_direct)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 144;
    corewar->memory[2] = 0;
    corewar->memory[3] = 0;
    corewar->memory[4] = 0;
    corewar->memory[5] = 34;
    corewar->memory[6] = 3;
    ld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[2], 34);
}
Test(ld_instruction, ld_instruction_indirect)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 0;
    corewar->memory[3] = 6;
    corewar->memory[4] = 1;
    corewar->memory[6] = 3;
    ld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 3);
    cr_assert_eq(robot->carry, 0);
}
Test(ld_instruction, ld_instruction_carry_equal_one)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 0;
    corewar->memory[3] = 6;
    corewar->memory[4] = 1;
    corewar->memory[6] = 0;
    ld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 0);
    cr_assert_eq(robot->carry, 1);
}
Test(ld_instruction, ld_instruction_too_big_indirect)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 2;
    corewar->memory[3] = 88;
    corewar->memory[4] = 1;
    corewar->memory[88] = 3;
    ld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 3);
    cr_assert_eq(robot->carry, 0);
}

Test(lld_instruction, lld_instruction_direct)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 144;
    corewar->memory[2] = 0;
    corewar->memory[3] = 0;
    corewar->memory[4] = 0;
    corewar->memory[5] = 34;
    corewar->memory[6] = 3;
    lld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[2], 34);
}
Test(lld_instruction, lld_instruction_indirect)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 0;
    corewar->memory[3] = 6;
    corewar->memory[4] = 1;
    corewar->memory[6] = 3;
    lld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 3);
    cr_assert_eq(robot->carry, 0);
}
Test(lld_instruction, lld_instruction_carry_equal_one)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 0;
    corewar->memory[3] = 6;
    corewar->memory[4] = 1;
    corewar->memory[6] = 0;
    lld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 0);
    cr_assert_eq(robot->carry, 1);
}
Test(lld_instruction, lld_instruction_too_big_indirect)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 208;
    corewar->memory[2] = 2;
    corewar->memory[3] = 88;
    corewar->memory[4] = 1;
    corewar->memory[600] = 3;
    lld_instruction(corewar, robot);
    cr_assert_eq(robot->registers[0], 3);
    cr_assert_eq(robot->carry, 0);
}

Test(aff, aff_star, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 64;
    corewar->memory[2] = 2;
    robot->registers[1] = '*';
    aff(corewar, robot);
    cr_assert_stdout_eq_str("*");
}
Test(aff, aff_big_t, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 64;
    corewar->memory[2] = 2;
    robot->registers[1] = 340;
    aff(corewar, robot);
    cr_assert_stdout_eq_str("T");
}

Test(zjmp, zjmp_carry_zero)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->carry = 0;
    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 0;
    corewar->memory[2] = 10;
    zjmp(corewar, robot);
    cr_assert_eq(robot->read_index, 3);
}
Test(zjmp, zjmp_ten)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->carry = 1;
    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[1] = 0;
    corewar->memory[2] = 10;
    zjmp(corewar, robot);
    cr_assert_eq(robot->read_index, 10);
}
Test(zjmp, zjmp_negative)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->carry = 1;
    robot->read_index = 3;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    corewar->memory[4] = 255;
    corewar->memory[5] = 253;
    zjmp(corewar, robot);
    cr_assert_eq(robot->read_index, 0);
}

Test(sti_instruction, sti_instruction_direct)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[1] = 74;
    corewar->memory[1] = 104;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 0;
    corewar->memory[6] = 5;
    sti_instruction(corewar, robot);
    cr_assert_eq(corewar->memory[10], 74);
    cr_assert_eq(robot->read_index, 7);
}

Test(sti_instruction, sti_instruction_direct_and_register)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[1] = 74;
    robot->registers[4] = 2;
    corewar->memory[1] = 100;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    sti_instruction(corewar, robot);
    cr_assert_eq(corewar->memory[7], 74);
    cr_assert_eq(robot->read_index, 6);
}

Test(ldi_instruction, ldi_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    corewar->memory[1] = 228;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    corewar->memory[6] = 5;
    corewar->memory[7] = 5;
    corewar->memory[8] = 1;
    corewar->memory[9] = 2;
    corewar->memory[10] = 114;
    index = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    read = get_address(convert_xbytes(corewar->memory, index - 1, IND_SIZE) + convert_4bytes(corewar->memory, 3));
    corewar->memory[read] = 25;
    corewar->memory[get_address(read + 1)] = 54;
    corewar->memory[get_address(read + 2)] = 18;
    corewar->memory[get_address(read + 3)] = 12;
    result = convert_xbytes(corewar->memory, get_address(robot->read_index + read % IDX_MOD - 1), REG_SIZE);
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 9);
    cr_assert_eq(robot->registers[0], result);
}
Test(ldi_instruction, ldi_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    corewar->memory[1] = 244;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    corewar->memory[6] = 1;
    corewar->memory[7] = 2;
    corewar->memory[8] = 114;
    index = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    read = convert_xbytes(corewar->memory, index - 1, IND_SIZE) + convert_2bytes(corewar->memory, 3);
    corewar->memory[read] = 25;
    corewar->memory[read + 1] = 54;
    corewar->memory[read + 2] = 18;
    corewar->memory[read + 3] = 12;
    result = convert_xbytes(corewar->memory, (robot->read_index + read % IDX_MOD) - 1, REG_SIZE);
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[0], result);
}
Test(ldi_instruction, ldi_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 1;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    index = robot->read_index + robot->registers[corewar->memory[2] - 1];
    read = convert_xbytes(corewar->memory, index - 1, IND_SIZE);
    read += robot->read_index + convert_2bytes(corewar->memory, 2) % IDX_MOD;
    read = get_address(read);
    corewar->memory[read] = 25;
    corewar->memory[get_address(read + 1)] = 54;
    corewar->memory[get_address(read + 2)] = 18;
    corewar->memory[get_address(read + 3)] = 12;
    result = convert_xbytes(corewar->memory, (robot->read_index + read % IDX_MOD) - 1, REG_SIZE);
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], result);
}
Test(ldi_instruction, ldi_instruction_wrong_parameters_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 18;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], 25);
}
Test(ldi_instruction, ldi_instruction_wrong_parameters_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 18;
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], 25);
}
Test(ldi_instruction, ldi_instruction_wrong_parameters_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 100;
    corewar->memory[2] = 5;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 25;
    corewar->memory[6] = 38;
    corewar->memory[7] = 18;
    ldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 8);
    cr_assert_eq(robot->registers[4], 25);
}

Test(lldi_instruction, lldi_instruction_successfull_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    corewar->memory[1] = 228;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    corewar->memory[6] = 5;
    corewar->memory[7] = 5;
    corewar->memory[8] = 1;
    corewar->memory[9] = 2;
    corewar->memory[10] = 114;
    index = robot->read_index + convert_2bytes(corewar->memory, 1);
    read = convert_xbytes(corewar->memory, index - 1, IND_SIZE);
    read += convert_4bytes(corewar->memory, 3);
    read = get_address(read);
    corewar->memory[read] = 25;
    corewar->memory[get_address(read + 1)] = 54;
    corewar->memory[get_address(read + 2)] = 18;
    corewar->memory[get_address(read + 3)] = 12;
    result = convert_xbytes(corewar->memory, robot->read_index + read - 1, REG_SIZE);
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 9);
    cr_assert_eq(robot->registers[0], result);
}
Test(lldi_instruction, lldi_instruction_successfull_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    corewar->memory[1] = 244;
    corewar->memory[2] = 2;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    corewar->memory[6] = 1;
    corewar->memory[7] = 2;
    corewar->memory[8] = 114;
    index = robot->read_index + convert_2bytes(corewar->memory, 1) % IDX_MOD;
    read = convert_xbytes(corewar->memory, index - 1, IND_SIZE) + convert_2bytes(corewar->memory, 3);
    corewar->memory[read] = 25;
    corewar->memory[read + 1] = 54;
    corewar->memory[read + 2] = 18;
    corewar->memory[read + 3] = 12;
    result = convert_xbytes(corewar->memory, (robot->read_index + read % IDX_MOD) - 1, REG_SIZE);
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 7);
    cr_assert_eq(robot->registers[0], result);
}
Test(lldi_instruction, lldi_instruction_successfull_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));
    int index;
    int read;
    int result;

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 1;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    index = robot->read_index + robot->registers[corewar->memory[2] - 1];
    read = convert_xbytes(corewar->memory, index - 1, IND_SIZE) + convert_2bytes(corewar->memory, 3);
    corewar->memory[read] = 25;
    corewar->memory[read + 1] = 54;
    corewar->memory[read + 2] = 18;
    corewar->memory[read + 3] = 12;
    result = convert_xbytes(corewar->memory, (robot->read_index + read % IDX_MOD) - 1, REG_SIZE);
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], result);
}
Test(lldi_instruction, lldi_instruction_wrong_parameters_1)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 18;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 5;
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], 25);
}
Test(lldi_instruction, lldi_instruction_wrong_parameters_2)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 116;
    corewar->memory[2] = 5;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 18;
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 6);
    cr_assert_eq(robot->registers[4], 25);
}
Test(lldi_instruction, lldi_instruction_wrong_parameters_3)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->read_index = 0;
    robot->registers = malloc(sizeof(int) * REG_NUMBER);
    robot->registers[0] = 1;
    robot->registers[4] = 25;
    corewar->memory[1] = 100;
    corewar->memory[2] = 5;
    corewar->memory[3] = 0;
    corewar->memory[4] = 2;
    corewar->memory[5] = 25;
    corewar->memory[6] = 38;
    corewar->memory[7] = 18;
    lldi_instruction(corewar, robot);
    cr_assert_eq(robot->read_index, 8);
    cr_assert_eq(robot->registers[4], 25);
}

Test(read_coding_byte, read_coding_byte_1)
{
    char *coding_byte = read_coding_byte(152);
    char result[4] = {T_DIR, T_REG, T_DIR, 0};

    cr_assert_eq(my_strcmp(coding_byte, result), 0);
}
Test(read_coding_byte, read_coding_byte_2)
{
    char *coding_byte = read_coding_byte(84);
    char result[4] = {T_REG, T_REG, T_REG, 0};

    cr_assert_eq(my_strcmp(coding_byte, result), 0);
}
Test(read_coding_byte, read_coding_byte_3)
{
    char *coding_byte = read_coding_byte(236);
    char result[4] = {T_IND, T_DIR, T_IND, 0};

    cr_assert_eq(my_strcmp(coding_byte, result), 0);
}
Test(read_coding_byte, read_coding_byte_4)
{
    char *coding_byte = read_coding_byte(180);
    char result[4] = {T_DIR, T_IND, T_REG, 0};

    cr_assert_eq(my_strcmp(coding_byte, result), 0);
}
Test(read_coding_byte, read_coding_byte_5)
{
    char *coding_byte = read_coding_byte(116);
    char result[4] = {T_REG, T_IND, T_REG, 0};

    cr_assert_eq(my_strcmp(coding_byte, result), 0);
}
Test(read_coding_byte, read_invalid_coding_byte_1)
{
    char *coding_byte = read_coding_byte(256);

    cr_assert_eq(coding_byte, NULL);
}
Test(read_coding_byte, read_invalid_coding_byte_2)
{
    char *coding_byte = read_coding_byte(0);

    cr_assert_eq(coding_byte[0], 0);
}

Test(my_str_isnum, my_str_is_num_1)
{
    cr_assert_eq(my_str_isnum("25000"), 0);
}
Test(my_str_isnum, my_str_is_num_2)
{
    cr_assert_eq(my_str_isnum("0"), 0);
}
Test(my_str_isnum, my_str_is_num_3)
{
    cr_assert_eq(my_str_isnum("2950824702830380"), 0);
}
Test(my_str_isnum, my_str_is_not_num_1)
{
    cr_assert_eq(my_str_isnum("dozhdqozdzq"), 1);
}
Test(my_str_isnum, my_str_is_not_num_2)
{
    cr_assert_eq(my_str_isnum("-42"), 1);
}
Test(my_str_isnum, my_str_is_not_num_3)
{
    cr_assert_eq(my_str_isnum("25802330dozqd"), 1);
}

Test(is_corfile, check_if_file_is_corfile_1)
{
    cr_assert_eq(is_corfile("abel.cor"), 0);
}
Test(is_corfile, check_if_file_is_corfile_2)
{
    cr_assert_eq(is_corfile("mike_tyson.cor"), 0);
}
Test(is_corfile, check_if_file_is_corfile_3)
{
    cr_assert_eq(is_corfile("I am a great robot.cor"), 0);
}
Test(is_corfile, check_if_file_is_not_corfile_1)
{
    cr_assert_eq(is_corfile("abel.co"), 1);
}
Test(is_corfile, check_if_file_is_not_corfile_2)
{
    cr_assert_eq(is_corfile("abel.core"), 1);
}
Test(is_corfile, check_if_file_is_not_corfile_3)
{
    cr_assert_eq(is_corfile("abel"), 1);
}

Test(read_file, read_a_file)
{
    unsigned char *buffer;
    int size_readed = read_file("tests/file_to_read.txt", &buffer);

    cr_assert_eq(size_readed, my_strlen("bonsoir"));
}
Test(read_file, read_empty_file)
{
    unsigned char *buffer;
    int size_readed = read_file("tests/empty_file.txt", &buffer);

    cr_assert_eq(size_readed, 0);
}
Test(read_file, read_non_existant_file, .init = redirect_all_std)
{
    unsigned char *buffer;
    int size_readed = read_file("qjdipozdjzdpqzjd", &buffer);

    cr_assert_eq(size_readed, -1);
}
Test(read_file, read_NULL_file)
{
    int size_readed = read_file(NULL, NULL);
}

Test(is_file_exist, check_if_file_exist)
{
    cr_assert_eq(is_file_exist("Makefile"), 0);
}
Test(is_file_exist, check_if_file_doesnt_exist)
{
    cr_assert_eq(is_file_exist("dozhdoqzidhqzd"), 1);
}

Test(convert_4bytes, convert_4bytes_to_int_1)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 4);

    memory[0] = 25;
    memory[1] = 25;
    memory[2] = 25;
    memory[3] = 25;
    cr_assert_eq(convert_4bytes(memory, -1), 421075225);
}
Test(convert_4bytes, convert_4bytes_to_int_2)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 4);

    memory[0] = 48;
    memory[1] = 0;
    memory[2] = 187;
    memory[3] = 32;
    cr_assert_eq(convert_4bytes(memory, -1), 805354272);
}

Test(convert_xbytes, convert_xbytes_to_int_1)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 3);

    memory[0] = 18;
    memory[1] = 0;
    memory[2] = 12;
    cr_assert_eq(convert_xbytes(memory, -1, 3), 1179660);
}
Test(convert_xbytes, convert_xbytes_to_int_2)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 3);

    memory[0] = 25;
    memory[1] = 25;
    memory[2] = 25;
    cr_assert_eq(convert_xbytes(memory, -1, 3), 1644825);
}

Test(convert_to_4bytes, convert_value_to_4bytes_1)
{
    int value = 25;
    int *converted = convert_to_4bytes(value);

    cr_assert_eq(converted[0], 0);
    cr_assert_eq(converted[1], 0);
    cr_assert_eq(converted[2], 0);
    cr_assert_eq(converted[3], 25);
}
Test(convert_to_4bytes, convert_value_to_4bytes_2)
{
    int value = 18;
    int *converted = convert_to_4bytes(value);

    cr_assert_eq(converted[0], 0);
    cr_assert_eq(converted[1], 0);
    cr_assert_eq(converted[2], 0);
    cr_assert_eq(converted[3], 18);
}

Test(convert_2bytes, convert_2bytes_to_int_1)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 2);

    memory[0] = 25;
    memory[1] = 30;
    cr_assert_eq(convert_2bytes(memory, -1), 6430);
}
Test(convert_2bytes, convert_2bytes_to_int_2)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * 2);

    memory[0] = 210;
    memory[1] = 87;
    cr_assert_eq(convert_2bytes(memory, -1), 53847);
}

Test(place_robot_in_arena, place_2_robots_in_arena)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));

    robot1->program = malloc(sizeof(unsigned char) * 5);
    robot1->program[0] = 1;
    robot1->program[1] = 2;
    robot1->program[2] = 3;
    robot1->program[3] = 4;
    robot1->program[4] = 5;
    robot1->prog_size = 5;
    robot1->start_index_in_memory = -1;
    robot2->program = malloc(sizeof(unsigned char) * 5);
    robot2->program[0] = 6;
    robot2->program[1] = 7;
    robot2->program[2] = 8;
    robot2->program[3] = 9;
    robot2->program[4] = 10;
    robot2->prog_size = 5;
    robot2->start_index_in_memory = -1;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = NULL;
    corewar->nbr_robots = 2;
    corewar->robots = robots;
    place_robot_in_arena(corewar);
    cr_assert_eq(corewar->memory[0], 1);
    cr_assert_eq(corewar->memory[1], 2);
    cr_assert_eq(corewar->memory[2], 3);
    cr_assert_eq(corewar->memory[3], 4);
    cr_assert_eq(corewar->memory[4], 5);
    cr_assert_eq(corewar->memory[3072], 6);
    cr_assert_eq(corewar->memory[3073], 7);
    cr_assert_eq(corewar->memory[3074], 8);
    cr_assert_eq(corewar->memory[3075], 9);
    cr_assert_eq(corewar->memory[3076], 10);
}
Test(place_robot_in_arena, place_robot_in_end_of_arena)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));

    robot1->program = malloc(sizeof(unsigned char) * 5);
    robot1->program[0] = 1;
    robot1->program[1] = 2;
    robot1->program[2] = 3;
    robot1->program[3] = 4;
    robot1->program[4] = 5;
    robot1->prog_size = 5;
    robot1->start_index_in_memory = MEM_SIZE - 3;
    robots[0] = robot1;
    robots[1] = NULL;
    corewar->nbr_robots = 1;
    corewar->robots = robots;
    place_robot_in_arena(corewar);
    cr_assert_eq(corewar->memory[MEM_SIZE - 3], 1);
    cr_assert_eq(corewar->memory[MEM_SIZE - 2], 2);
    cr_assert_eq(corewar->memory[MEM_SIZE - 1], 3);
}

Test(get_number_of_robots_alive, get_number_of_robots_alive_in_corewar_1)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_alive = true;
    robot2->is_alive = false;
    robot3->is_alive = true;
    robot4->is_alive = true;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_alive(robots), 3);
}
Test(get_number_of_robots_alive, get_number_of_robots_alive_in_corewar_2)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_alive = true;
    robot2->is_alive = true;
    robot3->is_alive = true;
    robot4->is_alive = true;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_alive(robots), 4);
}
Test(get_number_of_robots_alive, get_number_of_robots_alive_in_corewar_3)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_alive = false;
    robot2->is_alive = false;
    robot3->is_alive = false;
    robot4->is_alive = false;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_alive(robots), 0);
}
Test(get_number_of_robots_alive, get_number_of_NULL_robots_alive)
{
    cr_assert_eq(get_number_of_robots_alive(NULL), 0);
}

Test(get_number_of_robots_not_dead, get_number_of_robots_not_dead_in_corewar_1)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_dead = true;
    robot2->is_dead = false;
    robot3->is_dead = true;
    robot4->is_dead = true;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_not_dead(robots), 1);
}
Test(get_number_of_robots_not_dead, get_number_of_robots_not_dead_in_corewar_2)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_dead = true;
    robot2->is_dead = true;
    robot3->is_dead = true;
    robot4->is_dead = true;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_not_dead(robots), 0);
}
Test(get_number_of_robots_not_dead, get_number_of_robots_not_dead_in_corewar_3)
{
    robot_t **robots = malloc(sizeof(robot_t *) * 5);
    robot_t *robot1 = malloc(sizeof(robot_t));
    robot_t *robot2 = malloc(sizeof(robot_t));
    robot_t *robot3 = malloc(sizeof(robot_t));
    robot_t *robot4 = malloc(sizeof(robot_t));

    robot1->is_dead = false;
    robot2->is_dead = false;
    robot3->is_dead = false;
    robot4->is_dead = false;
    robots[0] = robot1;
    robots[1] = robot2;
    robots[2] = robot3;
    robots[3] = robot4;
    robots[4] = NULL;
    cr_assert_eq(get_number_of_robots_not_dead(robots), 4);
}
Test(get_number_of_robots_not_dead, get_number_of_NULL_robots_not_dead)
{
    cr_assert_eq(get_number_of_robots_not_dead(NULL), 0);
}

Test(free_robot, free_robot_1)
{
    robot_t *robot = malloc(sizeof(robot_t));
    int *registers = malloc(sizeof(int));

    robot->name = my_strdup("");
    robot->registers = registers;
    free_robot(robot);
}
Test(free_robot, free_robot_2)
{
    robot_t *robot = malloc(sizeof(robot_t));
    int *registers = malloc(sizeof(int));

    robot->name = NULL;
    robot->registers = registers;
    free_robot(robot);
}
Test(free_robot, free_robot_3)
{
    robot_t *robot = malloc(sizeof(robot_t));
    int *registers = malloc(sizeof(int));

    robot->name = my_strdup("");
    robot->registers = NULL;
    free_robot(robot);
}
Test(free_robot, free_robot_4)
{
    robot_t *robot = malloc(sizeof(robot_t));
    int *registers = malloc(sizeof(int));

    robot->name = NULL;
    robot->registers = NULL;
    free_robot(robot);
}
Test(free_robot, free_NULL_robot)
{
    free_robot(NULL);
}

Test(create_robot, create_robot_with_cor_file_1)
{
    robot_t *robot = create_robot("tests/abel.cor", -1, -1);
    
    cr_assert_not_null(robot);
}
Test(create_robot, create_robot_with_cor_file_2)
{
    robot_t *robot = create_robot("tests/pdd.cor", 25, -1);
    
    cr_assert_not_null(robot);
}
Test(create_robot, create_robot_with_cor_file_3)
{
    robot_t *robot = create_robot("tests/bill.cor", -1, 25);
    
    cr_assert_not_null(robot);
}
Test(create_robot, create_robot_with_cor_file_4)
{
    robot_t *robot = create_robot("tests/tyron.cor", 983, 2938);
    
    cr_assert_not_null(robot);
}
Test(create_robot, create_robot_with_invalid_file)
{
    robot_t *robot = create_robot("dzqhjdiqzphqz", 0, 0);

    cr_assert_null(robot);
}
Test(create_robot, create_robot_with_NULL_path)
{
    robot_t *robot = create_robot(NULL, 0, 0);
}

Test(read_instruction, read_robot_instruction_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 2);
    robot_t *robot = malloc(sizeof(robot_t));

    corewar->memory[0] = 1;
    corewar->memory[1] = 0;
    corewar->memory[2] = 0;
    corewar->memory[3] = 0;
    corewar->memory[4] = 1;
    robot->is_dead = false;
    robot->nb_cycles_to_wait = 0;
    robot->read_index = 0;
    robot->registers = malloc(sizeof(int));
    robot->registers[0] = 1;
    robots[0] = robot;
    robots[1] = NULL;
    corewar->robots = robots;
    read_instruction(corewar, robot);
    cr_assert_eq(robot->nb_cycles_to_wait, op_tab[0].nbr_cycles);
    cr_assert_eq(robot->read_index, 5);
}
Test(read_instruction, read_robot_instruction_of_invalid_instruction)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    corewar->memory[0] = 0;
    robot->is_dead = false;
    robot->nb_cycles_to_wait = 0;
    robot->read_index = 0;
    read_instruction(corewar, robot);
    cr_assert_eq(robot->nb_cycles_to_wait, 0);
    cr_assert_eq(robot->read_index, 1);
}
Test(read_instruction, read_robot_instruction_that_must_to_wait)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->is_dead = false;
    robot->nb_cycles_to_wait = 5;
    read_instruction(corewar, robot);
    cr_assert_eq(robot->nb_cycles_to_wait, 4);
}
Test(read_instruction, read_robot_instruction_of_dead_robot)
{
    corewar_t *corewar = init_corewar();
    robot_t *robot = malloc(sizeof(robot_t));

    robot->is_dead = true;
    read_instruction(corewar, robot);
}
Test(read_instruction, read_robot_instruction_with_NULL_corewar)
{
    robot_t *robot = malloc(sizeof(robot_t));

    read_instruction(NULL, robot);
}
Test(read_instruction, read_robot_instruction_with_NULL_robot)
{
    corewar_t *corewar = init_corewar();

    read_instruction(corewar, NULL);
}
Test(read_instruction, read_robot_instruction_with_NULL_robot_and_NULL_corewar)
{
    read_instruction(NULL, NULL);
}

Test(get_operation_info, get_operation_info_1)
{
    op_t info = get_operation_info("live");

    cr_assert_eq(my_strcmp(info.mnemonique, op_tab[0].mnemonique), 0);
}
Test(get_operation_info, get_operation_info_2)
{
    op_t info = get_operation_info("lldi");

    cr_assert_eq(my_strcmp(info.mnemonique, op_tab[13].mnemonique), 0);
}
Test(get_operation_info, get_operation_info_3)
{
    op_t info = get_operation_info("aff");

    cr_assert_eq(my_strcmp(info.mnemonique, op_tab[15].mnemonique), 0);
}
Test(get_operation_info, get_operation_info_of_wrong_instruction)
{
    op_t info = get_operation_info("no");

    cr_assert_eq(info.mnemonique, 0);
}

Test(get_movement_size_with_cbyte, get_movement_size_with_cbyte_1)
{
    cr_assert_eq(get_movement_size_with_cbyte(T_REG), 1);
}
Test(get_movement_size_with_cbyte, get_movement_size_with_cbyte_2)
{
    cr_assert_eq(get_movement_size_with_cbyte(T_IND), 2);
}
Test(get_movement_size_with_cbyte, get_movement_size_with_cbyte_3)
{
    cr_assert_eq(get_movement_size_with_cbyte(T_DIR), 4);
}
Test(get_movement_size_with_cbyte, get_movement_size_with_invalid_cbyte)
{
    cr_assert_eq(get_movement_size_with_cbyte(0), 0);
}

Test(dump_memory, dump_corewar_memory_1, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();

    dump_memory(corewar);
}
Test(dump_memory, dump_corewar_memory_2, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();

    MEMORY[0] = 1;
    MEMORY[1] = 28;
    MEMORY[2] = 243;
    dump_memory(corewar);
}
Test(dump_memory, dump_empty_corewar_memory)
{
    corewar_t *corewar = init_corewar();

    free(corewar->memory);
    corewar->memory = NULL;
    dump_memory(corewar);
}

Test(fill_robots, fill_robots_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "tests/abel.cor", "tests/tyron.cor" };

    robots[2] = NULL;
    corewar->nbr_robots = 2;
    corewar->robots = robots;
    fill_robots(argv, corewar);
    cr_assert_not_null(corewar->robots[0]);
    cr_assert_not_null(corewar->robots[1]);
    cr_assert_eq(my_strcmp(corewar->robots[0]->name, "Abel"), 0);
    cr_assert_eq(my_strcmp(corewar->robots[1]->name, "Tyron"), 0);
}
Test(fill_robots, fill_robots_2)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "256", "tests/abel.cor", "-n", "123", "tests/tyron.cor" };

    robots[2] = NULL;
    corewar->nbr_robots = 2;
    corewar->robots = robots;
    fill_robots(argv, corewar);
    cr_assert_not_null(corewar->robots[0]);
    cr_assert_not_null(corewar->robots[1]);
    cr_assert_eq(my_strcmp(corewar->robots[0]->name, "Abel"), 0);
    cr_assert_eq(my_strcmp(corewar->robots[1]->name, "Tyron"), 0);
}
Test(fill_robots, fill_robots_3)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-a", "0", "tests/abel.cor", "-a", "25", "tests/tyron.cor" };

    robots[2] = NULL;
    corewar->nbr_robots = 2;
    corewar->robots = robots;
    fill_robots(argv, corewar);
    cr_assert_not_null(corewar->robots[0]);
    cr_assert_not_null(corewar->robots[1]);
    cr_assert_eq(my_strcmp(corewar->robots[0]->name, "Abel"), 0);
    cr_assert_eq(my_strcmp(corewar->robots[1]->name, "Tyron"), 0);
}
Test(fill_robots, invalid_fill_robots_1)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor" };

    robots[2] = NULL;
    corewar->nbr_robots = 2;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}
Test(fill_robots, invalid_fill_robots_2)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-n" };

    robots[2] = NULL;
    corewar->nbr_robots = 3;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}
Test(fill_robots, invalid_fill_robots_3)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-a" };

    robots[2] = NULL;
    corewar->nbr_robots = 3;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}
Test(fill_robots, invalid_fill_robots_4)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-a", "-5" };

    robots[2] = NULL;
    corewar->nbr_robots = 3;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}
Test(fill_robots, invalid_fill_robots_5)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-a", "dozdnqodizn" };

    robots[2] = NULL;
    corewar->nbr_robots = 3;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}
Test(fill_robots, invalid_fill_robots_6)
{
    corewar_t *corewar = init_corewar();
    robot_t **robots = malloc(sizeof(robot_t *) * 3);
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-n", "dzqjdoiqzdd" };

    robots[2] = NULL;
    corewar->nbr_robots = 3;
    corewar->robots = robots;
    cr_assert_eq(fill_robots(argv, corewar), 84);
}

Test(get_address_value, get_the_value_of_an_address_1)
{
    unsigned char *memory = malloc(sizeof(unsigned char));

    memory[0] = 230;
    cr_assert_eq(get_address_value(memory, 0), 230);
}
Test(get_address_value, get_the_value_of_an_address_2)
{
    unsigned char *memory = malloc(sizeof(unsigned char));

    memory[0] = 80;
    cr_assert_eq(get_address_value(memory, MEM_SIZE), 80);
}
Test(get_address_value, get_the_value_of_an_address_3)
{
    unsigned char *memory = malloc(sizeof(unsigned char));

    memory[0] = 50;
    cr_assert_eq(get_address_value(memory, -MEM_SIZE), 50);
}

Test(init_corewar, init_the_corewar_struct)
{
    corewar_t *corewar = init_corewar();

    cr_assert_not_null(corewar);
    cr_assert_not_null(corewar->memory);
    cr_assert_null(corewar->robots);
    cr_assert_eq(corewar->nbr_cycle, CYCLE_TO_DIE);
    cr_assert_eq(corewar->nbr_robots, 0);
    cr_assert_eq(corewar->dump_nbr, -1);
}

Test(parse_args, parse_invalid_args_1, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();

    corewar->nbr_robots = 5;
    cr_assert_eq(parse_args(0, NULL, corewar), 84);
}
Test(parse_args, parse_invalid_args_2, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();

    corewar->nbr_robots = 1;
    cr_assert_eq(parse_args(0, NULL, corewar), 84);
}
Test(parse_args, parse_invalid_args_3, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    char *argv[] = { "-n", "tests/abel.cor", "-pozds", "5" "tests/tyron.cor", "-a", "dozdnqodizn" };

    corewar->nbr_robots = 2;
    cr_assert_eq(parse_args(0, argv, corewar), 84);
}
Test(parse_args, parse_invalid_args_4, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    char *argv[] = { "-dump", "-2" };

    cr_assert_eq(parse_args(2, argv, corewar), 84);
}
Test(parse_args, parse_invalid_args_5, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    char *argv[] = { "-dump", "ldnqkldsn" };

    cr_assert_eq(parse_args(2, argv, corewar), 84);
}
Test(parse_args, parse_invalid_args_6, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    char *argv[] = { "-dump", "25" };

    cr_assert_eq(parse_args(2, argv, corewar), 84);
}
Test(parse_args, parse_invalid_args_7, .init = redirect_all_std)
{
    corewar_t *corewar = init_corewar();
    char *argv[] = { "dqzdqzqz", "25" };

    cr_assert_eq(parse_args(2, argv, corewar), 84);
}

Test(corewar, start_corewar, .init = redirect_all_std)
{
    char *argv[] = { "./corewar", "tests/abel.cor", "tests/bill.cor" };

    cr_assert_eq(corewar(3, argv), 0);
}
Test(corewar, failed_start_corewar, .init = redirect_all_std)
{
    char *argv[] = { "./corewar", "tests/abel.cor", "-n", "-5", "bill.cor" };

    cr_assert_eq(corewar(3, argv), 84);
}


