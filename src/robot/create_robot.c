/*
** EPITECH PROJECT, 2024
** create_robot
** File description:
** create a robot from a .cor file
*/
#include "../../include/corewar.h"

robot_t *create_robot(char *filepath, int start, int number)
{
    robot_t *robot = init_robot();
    char *buffer = NULL;
    static unsigned int nb_player = 0;

    if (robot == NULL || read_file(filepath, &buffer) == -1)
        return robot;
    robot->name = my_strndup(&(buffer[4]), PROG_NAME_LENGTH);
    robot->start_index_in_memory = start;
    if (number != -1)
        robot->nb_player = number;
    else {
        robot->nb_player = nb_player;
        nb_player += 1;
    }
    return robot;
}
