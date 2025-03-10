/*
** EPITECH PROJECT, 2024
** parse_args
** File description:
** parse arguments
*/
#include "../../include/corewar.h"

int get_nbr_cycle(char **argv, int *i, corewar_t *corewar)
{
    if (argv[*i + 1] != NULL && my_str_isnum(argv[*i + 1]) == 0) {
        corewar->dump_nbr = my_getnbr(argv[*i + 1]);
        if (corewar->dump_nbr < 0) {
            my_printf("[-dump]: argument must be positive\n");
            return 84;
        }
        *i += 1;
        return 0;
    } else {
        my_printf("[-dump]: argument must be a number\n");
        return 84;
    }
    return 0;
}

int parse_loop(char **argv, int *i, corewar_t *corewar)
{
    if (my_strcmp(argv[*i], "-dump") == 0) {
        return get_nbr_cycle(argv, i, corewar);
    }
    if (is_corfile(argv[*i]) == 0) {
        if (is_file_exist(argv[*i]) == 1) {
            my_printf("Can't open %s\n", argv[*i]);
            return 84;
        }
        corewar->nbr_robots += 1;
        return 0;
    }
    if (argv[*i][0] == '-')
        return 0;
    if (argv[*i - 1][0] == '-' && my_str_isnum(argv[*i]) == 0)
        return 0;
    return 84;
}

int parse_args(int argc, char **argv, corewar_t *corewar)
{
    for (int i = 1; i < argc; i++) {
        if (parse_loop(argv, &i, corewar) == 84)
            return 84;
    }
    if (corewar->nbr_robots > 4 || corewar->nbr_robots <= 1) {
        my_printf("Number of robots must be between 2 and 4\n");
        return 84;
    }
    corewar->robots = malloc(sizeof(robot_t *) * (corewar->nbr_robots + 1));
    if (fill_robots(argv, corewar) == 84)
        return 84;
    return 0;
}
