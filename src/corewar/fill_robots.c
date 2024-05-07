/*
** EPITECH PROJECT, 2024
** fill_robots
** File description:
** create robots with flag and .cor file
*/
#include "../../include/corewar.h"

int get_number_flag(char **argv, int *i, int *number)
{
    if (my_strcmp(argv[*i], "-n") != 0)
        return 0;
    if (argv[*i + 1] != NULL && my_str_isnum(argv[*i + 1]) == 0) {
        *number = my_getnbr(argv[*i + 1]);
        if (*number < 0) {
            my_printf("[-n]: argument must be positive\n");
            return 84;
        }
        *i += 1;
        return 0;
    } else {
        my_printf("[-n]: argument must be a number\n");
        return 84;
    }
    return 0;
}

int get_address_flag(char **argv, int *i, int *address)
{
    if (my_strcmp(argv[*i], "-a") != 0)
        return 0;
    if (argv[*i + 1] != NULL && my_str_isnum(argv[*i + 1]) == 0) {
        *address = my_getnbr(argv[*i + 1]);
        if (*address < 0) {
            my_printf("[-a]: argument must be positive\n");
            return 84;
        }
        *i += 1;
        return 0;
    } else {
        my_printf("[-a]: argument must be a number\n");
        return 84;
    }
    return 0;
}

int add_robot(char **argv, corewar_t *corewar, int *i, int *index_robot)
{
    int address = -1;
    int number = -1;

    for (; is_corfile(argv[*i]) != 0; *i += 1) {
        if (get_address_flag(argv, i, &address) == 84) {
            return 84;
        }
        if (get_number_flag(argv, i, &number) == 84) {
            return 84;
        }
    }
    corewar->robots[*index_robot] = create_robot(argv[1], address, number);
    *index_robot += 1;
    return 0;
}

int fill_robots(char **argv, corewar_t *corewar)
{
    int index_robot = 0;

    for (int i = 0; i < corewar->nbr_robots + 1; i++) {
        if (add_robot(argv, corewar, &i, &index_robot) == 84)
            return 84;
    }
    corewar->robots[index_robot] = NULL;
    return 0;
}
