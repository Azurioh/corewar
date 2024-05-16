/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main function for the corewar project
*/

#include "../include/corewar.h"

int error_handling(int argc)
{
    if (argc < 2)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    if (error_handling(argc) == 84)
        return 84;
    return corewar(argc, argv);
}
