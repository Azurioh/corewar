/*
** EPITECH PROJECT, 2024
** create_robot
** File description:
** create a robot from a .cor file
*/
#include "../../include/corewar.h"

static bool init_registers(robot_t *robot)
{
    char *registers = malloc(sizeof(char) * REG_NUMBER);

    if (!registers) {
        my_puterr("init_registers: Memory allocation failed\n");
        robot->registers = NULL;
        return false;
    }
    for (int i = 0; i < REG_NUMBER; i++) {
        registers[i] = 0;
    }
    robot->registers = registers;
    return true;
}

static bool load_robot_informations(robot_t *robot, char *buffer, int start,
    int number) {
    static unsigned int nb_player = 0;

    robot->name = my_strndup(&(buffer[4]), PROG_NAME_LENGTH);
    if (robot->name == false)
        return false;
    if (init_registers(robot) == false)
        return false;
    robot->start_index_in_memory = start;
    robot->is_alive = false;
    robot->is_dead = false;
    if (number != -1) {
        robot->nb_player = number;
    } else {
        robot->nb_player = nb_player;
        nb_player++;
    }
    return true;
}

robot_t *create_robot(char *filepath, int start, int number)
{
    robot_t *robot = malloc(sizeof(robot_t));
    char *buffer = NULL;

    if (!robot) {
        return NULL;
    }
    if (read_file(filepath, &buffer) == -1) {
        free_robot(robot);
        return NULL;
    }
    if (load_robot_informations(robot, buffer, start, number) == false) {
        free_robot(robot);
        return NULL;
    }
    return robot;
}
