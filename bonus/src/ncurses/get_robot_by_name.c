/*
** EPITECH PROJECT, 2024
** get_robot_by_name
** File description:
** Get robot element by his name
*/

#include "../../include/corewar.h"

robot_t *get_robot_by_name(robot_t **robots, unsigned char *robot_name)
{
    for (int i = 0; i < 4; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0) {
            return robots[i];
        }
    }
    return NULL;
}
