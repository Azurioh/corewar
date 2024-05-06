/*
** EPITECH PROJECT, 2024
** create_robot
** File description:
** create a robot from a .cor file
*/
#include "../../include/corewar.h"

robot_t *create_robot(char *filepath)
{
    robot_t *robot = init_robot();
    char *buffer = NULL;
    static unsigned int nb_player = 0;

    if (robot == NULL || read_file(filepath, &buffer) == -1)
        return robot;
    robot->name = my_strndup(&(buffer[4]), PROG_NAME_LENGTH);
    robot->nb_player = nb_player;
    nb_player += 1;
    return robot;
}
