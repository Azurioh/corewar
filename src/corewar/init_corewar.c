/*
** EPITECH PROJECT, 2024
** init_corewar.c
** File description:
** Function to init the corewar struct
*/

#include "../../include/corewar.h"

static char *allocate_memory(void)
{
    char *memory_arena = malloc(sizeof(char) * MEM_SIZE);

    if (!memory_arena) {
        my_puterr("allocate_memory_arena: Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        memory_arena[i] = 0;
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
    corewar->registers = NULL;
    corewar->robots = NULL;
    return corewar;
}
