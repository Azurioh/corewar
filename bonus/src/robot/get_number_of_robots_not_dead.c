/*
** EPITECH PROJECT, 2024
** get_number_of_robots_not_dead
** File description:
** Function to get the number of robots that are not dead
*/

#include "../../include/robot.h"

int get_number_of_robots_not_dead(robot_t **robots)
{
    int nb_robots_not_dead = 0;

    if (!robots) {
        return 0;
    }
    for (int i = 0; robots[i]; i++) {
        if (robots[i]->is_dead == false) {
            nb_robots_not_dead++;
        }
    }
    return nb_robots_not_dead;
}
