/*
** EPITECH PROJECT, 2024
** place_robot_in_arena
** File description:
** create the arena where the robots will fight and place them in it
*/
#include "../../include/corewar.h"

void place_robot(robot_t *robot, memory_t *memory)
{
    int index = robot->start_index_in_memory;

    for (unsigned int i = 0; i < robot->prog_size; i++) {
        if (index >= MEM_SIZE)
            return;
        memory[index].memory = robot->program[i];
        memory[index].author = robot->name;
        index += 1;
    }
}

char *place_robot_in_arena(corewar_t *corewar)
{
    int space = MEM_SIZE / corewar->nbr_robots;

    for (int i = 0; corewar->robots[i] != NULL; i++) {
        if (corewar->robots[i]->start_index_in_memory == -1) {
            corewar->robots[i]->start_index_in_memory = space * i;
            corewar->robots[i]->read_index = space * i;
        }
    }
    for (int i = 0; corewar->robots[i] != NULL; i++) {
        place_robot(corewar->robots[i], corewar->memory);
    }
    return NULL;
}
