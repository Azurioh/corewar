/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

static bool check_if_robots_exist(corewar_t *corewar, int index_robot)
{
    if (index_robot < 0 || index_robot > corewar->nbr_robots) {
        return false;
    }
    if (corewar->robots[index_robot]->is_dead == true) {
        return false;
    }
    return true;
}

static void update_live_status(corewar_t *corewar, robot_t *robot,
    int index_robot)
{
    if (corewar->robots[index_robot]->nb_player == robot->nb_player) {
        robot->is_alive = true;
        my_printf("The player %d(%s) is alive.\n", robot->nb_player,
            robot->name);
    } else {
        corewar->robots[index_robot]->is_alive = true;
        my_printf("The player %d(%s) is alive.\n",
            corewar->robots[index_robot]->nb_player,
            corewar->robots[index_robot]->name);
    }
    corewar->nbr_live++;
}

void live(corewar_t *corewar, robot_t *robot)
{
    int nb_player;
    int index_robot;

    nb_player = convert_4bytes(corewar->memory, robot->read_index);
    index_robot = get_index_robot(corewar->robots, nb_player);
    robot->read_index += 5;
    if (check_if_robots_exist(corewar, index_robot) == false) {
        return;
    }
    update_live_status(corewar, robot, index_robot);
}
