/*
** EPITECH PROJECT, 2024
** live
** File description:
** Indicate that a robot is alive
*/
#include "../../include/corewar.h"

void live(corewar_t *corewar, robot_t *robot)
{
    char *number_string = NULL;
    int nb_player;
    char value = get_address_value(corewar->memory, robot->read_index + 1);
    int index_robot;

    number_string = my_strndup(&value, 4);
    nb_player = my_getnbr(number_string);
    free(number_string);
    index_robot = get_index_robot(corewar->robots, nb_player);
    robot->nb_cycles_to_wait = get_operation_info("live").nbr_cycles;
    robot->read_index += 5;
    corewar->robots[index_robot]->is_alive = true;
    my_printf("The player %d(%s)is alive.", nb_player,
        corewar->robots[index_robot]->name);
    corewar->last_robot_alive = corewar->robots[index_robot];
    corewar->nbr_live += 1;
}
