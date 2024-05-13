/*
** EPITECH PROJECT, 2024
** get_number_of_robots_alive
** File description:
** Function to get the number of robots alive
*/

#include "../../include/robot.h"

int get_number_of_robots_alive(robot_t **robots)
{
    int nb_robots_alive = 0;

    if (!robots) {
        return 0;
    }
    for (int i = 0; robots[i]; i++) {
        if (robots[i]->is_alive == true) {
            nb_robots_alive++;
        }
    }
    return nb_robots_alive;
}
