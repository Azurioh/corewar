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

static bool load_robot_informations(robot_t *robot, char unsigned *buffer,
    int start, int number)
{
    static unsigned int nb_player = 0;

    robot->name = my_uns_strndup(&(buffer[4]), PROG_NAME_LENGTH);
    robot->program = my_uns_strndup(&(buffer[COMMENT_LENGTH + PROG_NAME_LENGTH
        + 16]), robot->prog_size);
    if (robot->name == false)
        return false;
    if (init_registers(robot) == false)
        return false;
    robot->start_index_in_memory = start;
    robot->read_index = start;
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
    unsigned char *buffer = NULL;
    int size = 0;

    if (!robot) {
        return NULL;
    }
    size = read_file(filepath, &buffer);
    if (size == -1) {
        free_robot(robot);
        return NULL;
    } else
        robot->prog_size = size - (COMMENT_LENGTH + PROG_NAME_LENGTH + 15);
    if (load_robot_informations(robot, buffer, start, number) == false) {
        free_robot(robot);
        return NULL;
    }
    return robot;
}
