/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

static bool check_if_robots_exist(corewar_t *corewar, int index_robot)
{
    if (index_robot < 0) {
        return false;
    }
    if (corewar->robots[index_robot]->is_dead == true) {
        return false;
    }
    return true;
}

static void update_live_status(corewar_t *corewar, robot_t *robot,
    int index_robot, int nb_player)
{
    if (nb_player == robot->registers[0]) {
        robot->is_alive = true;
        corewar->last_robot_alive = robot;
    } else {
        corewar->robots[index_robot]->is_alive = true;
        corewar->last_robot_alive = corewar->robots[index_robot];
    }
    corewar->nbr_live++;
}

void live(corewar_t *corewar, robot_t *robot)
{
    int nb_player;
    int index_robot;

    nb_player = convert_4bytes(corewar->memory, robot->read_index);
    index_robot = get_index_robot(corewar->robots, nb_player);
    robot->read_index = get_address(robot->read_index + 5);
    if (check_if_robots_exist(corewar, index_robot) == false
        && robot->registers[0] != nb_player) {
        return;
    }
    update_live_status(corewar, robot, index_robot, nb_player);
}
