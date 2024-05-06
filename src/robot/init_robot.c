/*
** EPITECH PROJECT, 2024
** init_robot
** File description:
** init robot struct
*/
#include "../../include/corewar.h"

robot_t *init_robot(void)
{
    robot_t *robot = malloc(sizeof(robot_t));

    if (robot == NULL)
        return NULL;
    robot->binary_code = NULL;
    robot->end_index_in_memory = 0;
    robot->instructions = NULL;
    robot->is_alive = 0;
    robot->nb_cycles_to_wait = 0;
    robot->registers = NULL;
    robot->size = 0;
    robot->start_index_in_memory = 0;
    return robot;
}
