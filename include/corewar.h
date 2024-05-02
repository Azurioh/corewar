/*
** EPITECH PROJECT, 2024
** corewar.h
** File description:
** All include, struct and protos of the corewar project
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "my.h"
    #include "op.h"
    #include "robot.h"
    #include <stdlib.h>

typedef struct corewar_s {
    char *memory;
    char *registers;
    robot_t **robots;
} corewar_t;

corewar_t *init_corewar(void);
int corewar(void);
#endif
