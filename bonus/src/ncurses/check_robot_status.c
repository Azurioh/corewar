/*
** EPITECH PROJECT, 2024
** check_robot_status
** File description:
** Check if any process of robot is alive
*/

#include "../../include/corewar.h"

bool check_if_robot_is_dead(robot_t **robots, unsigned char *robot_name)
{
    for (int i = 0; robots[i]; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0
            && robots[i]->is_dead == true) {
            return true;
        }
    }
    return false;
}

bool check_if_robot_is_alive(robot_t **robots, unsigned char *robot_name)
{
    for (int i = 0; robots[i]; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0
            && robots[i]->is_alive == true) {
            return true;
        }
    }
    return false;
}

int get_nb_process(robot_t **robots, unsigned char *robot_name)
{
    int nb_process = 0;

    for (int i = 0; robots[i]; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0
            && robots[i]->is_dead == false) {
            nb_process++;
        }
    }
    return nb_process;
}
