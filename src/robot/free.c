/*
** EPITECH PROJECT, 2024
** free.c
** File description:
** Free function for the robot struct
*/

#include "../../include/corewar.h"

void free_robot(robot_t *robot)
{
    if (!robot) {
        return;
    }
    if (robot->name) {
        free(robot->name);
    }
    if (robot->registers) {
        free(robot->registers);
    }
    free(robot);
}
