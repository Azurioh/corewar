/*
** EPITECH PROJECT, 2024
** init_corewar.c
** File description:
** Function to init the corewar struct
*/

#include "../../include/corewar.h"

static memory_t *allocate_memory(void)
{
    memory_t *memory_arena = malloc(sizeof(memory_t) * MEM_SIZE);

    if (!memory_arena) {
        my_puterr("allocate_memory_arena: Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        memory_arena[i].memory = 0;
        memory_arena[i].author = NULL;
    }
    return memory_arena;
}

corewar_t *init_corewar(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (!corewar) {
        my_puterr("init_corewar: Memory allocation failed\n");
        return NULL;
    }
    corewar->memory = allocate_memory();
    corewar->robots = NULL;
    corewar->nbr_cycle = CYCLE_TO_DIE;
    corewar->nbr_robots = 0;
    corewar->dump_nbr = -1;
    return corewar;
}
