/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

int live(corewar_t *corewar, int robot_index)
{
    robot_t *robot = corewar->robots[robot_index];
    char *number_string = NULL;
    int index_robot;
    int nb_player;

    number_string = my_strndup(&corewar->memory[robot->reading_index + 2], 4);
    nb_player = my_getnbr(number_string);
    free(number_string);
    robot->nb_cycles_to_wait = op_tab[0].nbr_cycles;
    robot->reading_index += 6;
    index_robot = get_index_robot(corewar->robots, nb_player);
    corewar->robots[index_robot]->is_alive = 1;
    my_printf("The player %d(%s)is alive.", nb_player,
        corewar->robots[index_robot]->name);
    corewar->last_robot_alive = corewar->robots[index_robot];
    return 0;
}
