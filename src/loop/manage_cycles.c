/*
** EPITECH PROJECT, 2024
** manage_cycles.c
** File description:
** File to manage robots cycles
*/

#include "../../include/corewar.h"

static void exec_robots_instruction(corewar_t *corewar)
{
    for (int i = 0; i < corewar->nbr_robots; i++) {
        if (corewar->robots[i]->nb_cycles_to_wait == 0) {
            exec_robot_command(corewar->robots[i], corewar);
        }
    }
}

int manage_cycles(corewar_t *corewar)
{
    for (int i = 0; i < corewar->nbr_cycle; i++) {
        exec_robots_instruction(corewar);
    }
    return 0;
}
