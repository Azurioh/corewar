/*
** EPITECH PROJECT, 2024
** corewar.c
** File description:
** Function to begin the program
*/

#include "../../include/corewar.h"

int my_putcorefile(char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        my_printf("%x\n", buffer[i]);
    }
    return 0;
}

int corewar(int argc, char **argv)
{
    corewar_t *corewar = init_corewar();

    if (!corewar) {
        return 84;
    }
    if (parse_args(argc, argv, corewar) == 84)
        return 84;
    place_robot_in_arena(corewar);
    for (int i = 0; corewar->robots[i] != NULL; i++) {
        my_printf("%s: prog_number: %d, adress_load: %d\n",
            corewar->robots[i]->name, corewar->robots[i]->nb_player,
            corewar->robots[i]->start_index_in_memory);
    }
    my_printf("dump_nbr: %d, nbr_robots: %d\n", corewar->dump_nbr,
        corewar->nbr_robots);
    return 0;
}
