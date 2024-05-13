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
        read_instruction(corewar->robots[i], corewar->memory);
    }
}

static bool check_if_program_is_ended(corewar_t *corewar)
{
    static int program_started = 0;
    int nb_robots_alive = get_number_of_robots_alive(corewar->robots);
    int nb_robots_not_dead = get_number_of_robots_not_dead(corewar->robots);

    if (nb_robots_alive == 0 && program_started == 1) {
        return false;
    }
    if (program_started == 0) {
        program_started = 1;
    }
    if (nb_robots_not_dead == 0) {
        return false;
    }
    if (corewar->nbr_cycle <= 0) {
        return false;
    }
    return true;
}

int manage_cycles(corewar_t *corewar)
{
    while (check_if_program_is_ended(corewar) == true) {
        for (int i = 0; i < corewar->nbr_cycle; i++) {
            exec_robots_instruction(corewar);
        }
    }
    return 0;
}
