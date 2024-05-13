/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

int live(robot_t *robot)
{
    my_printf("The player %d(%s)is alive.", robot->nb_player, robot->name);
    robot->is_alive = 1;
    return 0;
}
