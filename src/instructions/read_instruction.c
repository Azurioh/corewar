/*
** EPITECH PROJECT, 2024
** read_instruction
** File description:
** Function to read the memory and get the right instruction
*/

#include "../../include/corewar.h"
#include "../../include/instructions_list.h"

void read_instruction(corewar_t *corewar, robot_t *robot)
{
    if (!corewar || !robot) {
        return;
    }
    if (robot->is_dead == true) {
        return;
    }
    if (robot->nb_cycles_to_wait > 0) {
        robot->nb_cycles_to_wait--;
        return;
    }
    for (int i = 0; INSTRUCTIONS_LIST[i].id != 0; i++) {
        if (corewar->memory[robot->read_index] == INSTRUCTIONS_LIST[i].id) {
            INSTRUCTIONS_LIST[i].function(corewar, robot);
            return;
        }
    }
    robot->is_alive = false;
    robot->is_dead = true;
    return;
}
