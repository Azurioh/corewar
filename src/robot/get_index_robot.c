/*
** EPITECH PROJECT, 2024
** get_index_robot
** File description:
** return the index of the robot from his player number
*/
#include "../../include/corewar.h"

unsigned int get_index_robot(robot_t **robots, unsigned int player_number)
{
    for (unsigned int i = 0; robots[i] != NULL; i++) {
        if (robots[i]->registers[0] == (int)player_number)
            return i;
    }
    return -1;
}
