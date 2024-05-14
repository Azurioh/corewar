/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

void live(corewar_t *corewar, robot_t *robot)
{
    char *number_string = NULL;
    int nb_player;

    number_string = my_strndup(&corewar->memory[robot->reading_index + 2], 4);
    nb_player = my_getnbr(number_string);
    free(number_string);
    robot->nb_cycles_to_wait = get_operation_info("live").nbr_cycles;
    robot->reading_index += 5;
    robot->is_alive = true;
    my_printf("The player %d(%s)is alive.", nb_player, robot->name);
    corewar->last_robot_alive = robot;
}
