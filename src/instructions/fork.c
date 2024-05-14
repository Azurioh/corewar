/*
** EPITECH PROJECT, 2024
** fork
** File description:
** Fork instruction
*/

#include "../../include/corewar.h"

static int *duplicate_registers(int *registers)
{
    int *duplicate_registers = malloc(sizeof(int) * REG_NUMBER);

    for (int i = 0; i < REG_NUMBER; i++) {
        duplicate_registers[i] = registers[i];
    }
    return duplicate_registers;
}

static robot_t *duplicate_robot(robot_t *robot)
{
    robot_t *new_robot = malloc(sizeof(robot_t));

    if (!new_robot) {
        my_puterr("duplicate_robot: Memory allocation failed\n");
        return NULL;
    }
    new_robot->name = my_uns_strdup(robot->name);
    new_robot->program = my_uns_strdup((unsigned char *)"");
    new_robot->prog_size = robot->prog_size;
    new_robot->nb_player = robot->nb_player;
    new_robot->registers = duplicate_registers(robot->registers);
    new_robot->is_alive = robot->is_alive;
    new_robot->is_dead = robot->is_dead;
    new_robot->start_index_in_memory = robot->start_index_in_memory;
    new_robot->end_index_in_memory = robot->end_index_in_memory;
    new_robot->carry = robot->carry;
    return new_robot;
}

static void insert_new_robots_in_corewar(corewar_t *corewar, robot_t *robot)
{
    robot_t **new_robots_list;

    corewar->nbr_robots++;
    new_robots_list = malloc(sizeof(robot_t *) * (corewar->nbr_robots + 1));
    if (!new_robots_list) {
        corewar->nbr_robots--;
        return;
    }
    for (int i = 0; i < corewar->nbr_robots - 1; i++) {
        new_robots_list[i] = corewar->robots[i];
    }
    new_robots_list[corewar->nbr_robots - 1] = robot;
    new_robots_list[corewar->nbr_robots] = NULL;
    free(corewar->robots);
    corewar->robots = new_robots_list;
}

void fork_instruction(corewar_t *corewar, robot_t *robot)
{
    int new_read_index = convert_2bytes(corewar->memory, robot->read_index);
    robot_t *new_robot = duplicate_robot(robot);

    if (!new_robot) {
        robot->read_index += 3;
        return;
    }
    insert_new_robots_in_corewar(corewar, new_robot);
    new_read_index = robot->read_index + new_read_index % IDX_MOD;
    new_robot->read_index = new_read_index;
    return;
}
