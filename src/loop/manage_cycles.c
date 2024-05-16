/*
** EPITECH PROJECT, 2024
** manage_cycles.c
** File description:
** File to manage robots cycles
*/

#include "../../include/corewar.h"

static void exec_robots_instruction(corewar_t *corewar, int cycle_tot)
{
    if (cycle_tot == corewar->dump_nbr)
        dump_memory(corewar);
    for (int i = 0; i < corewar->nbr_robots; i++) {
        read_instruction(corewar, corewar->robots[i]);
    }
    if (corewar->nbr_live >= 40) {
        corewar->nbr_live = 0;
        corewar->nbr_cycle -= CYCLE_DELTA;
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
            corewar->last_robot_alive->nb_player,
            corewar->last_robot_alive->name);
    }
}

int manage_cycles(corewar_t *corewar)
{
    int cycle_tot = 1;

    while (check_if_program_is_not_ended(corewar) == true) {
        for (int i = 0; i < corewar->nbr_robots; i++) {
            corewar->robots[i]->is_alive = false;
        }
        for (int i = 0; i < corewar->nbr_cycle; i++) {

            my_printf("cycle n°%d,  %d / %d,    nbr_live: %d\n", cycle_tot, i + 1, corewar->nbr_cycle, corewar->nbr_live);
            exec_robots_instruction(corewar, cycle_tot);
            cycle_tot += 1;
        }
        for (int i = 0; i < corewar->nbr_robots; i++) {
            update_state_of_robots(corewar->robots[i]);
        }
    }
    display_winner(corewar);
    return 0;
}
