/*
** EPITECH PROJECT, 2024
** manage_cycles.c
** File description:
** File to manage robots cycles
*/

#include "../../include/corewar.h"

static void exec_robots_instruction(corewar_t *corewar, int cycle_tot)
{
    for (int i = 0; i < corewar->nbr_robots; i++) {
        read_instruction(corewar, corewar->robots[i]);
    }
    if (corewar->nbr_live >= 40) {
        corewar->nbr_live = 0;
        corewar->nbr_cycle -= CYCLE_DELTA;
    }
    if (cycle_tot == corewar->dump_nbr) {
        dump_memory(corewar);
        corewar->is_dump = 1;
    }
}

static bool check_if_program_is_not_ended(corewar_t *corewar)
{
    static int program_started = 0;
    int nb_robots_alive = get_number_of_robots_alive(corewar->robots);
    int nb_robots_not_dead = get_number_of_robots_not_dead(corewar->robots);

    if (nb_robots_alive <= 1 && program_started == 1) {
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

static void update_state_of_robots(robot_t *robot)
{
    if (robot->is_dead) {
        return;
    }
    if (robot->is_alive == false) {
        robot->is_dead = true;
    }
}

static void display_winner(corewar_t *corewar)
{
    if (!corewar->last_robot_alive) {
        my_printf("No winner !\n");
    } else {
        my_printf("The player %d(%s) win!\n",
            corewar->last_robot_alive->registers[0],
            corewar->last_robot_alive->name);
    }
}

static void exec_loop(corewar_t *corewar, int *cycle_tot)
{
    for (int i = 1; i <= corewar->nbr_cycle; i++) {
        exec_robots_instruction(corewar, *cycle_tot);
        if (corewar->is_dump == 1)
            return;
        *cycle_tot += 1;
    }
    return;
}

int manage_cycles(corewar_t *corewar)
{
    int cycle_tot = 1;

    corewar->is_dump = 0;
    while (check_if_program_is_not_ended(corewar) == true) {
        for (int i = 0; i < corewar->nbr_robots; i++) {
            corewar->robots[i]->is_alive = false;
        }
        exec_loop(corewar, &cycle_tot);
        for (int i = 0; i < corewar->nbr_robots; i++) {
            update_state_of_robots(corewar->robots[i]);
        }
        if (corewar->is_dump == 1)
            break;
    }
    display_winner(corewar);
    return 0;
}
