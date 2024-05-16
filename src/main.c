/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main function for the corewar project
*/

#include "../include/corewar.h"

int error_handling(int argc)
{
    if (argc < 2)
        return 84;
    return 0;
}

// int main(int argc, char **argv)
// {
//     if (error_handling(argc) == 84)
//         return 84;
//     return corewar(argc, argv);
// }

int main(void)
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
    my_printf("RESULT: %d\n", result);
}
