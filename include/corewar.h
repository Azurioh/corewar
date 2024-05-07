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
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct corewar_s {
    char *memory;
    char *registers;
    robot_t **robots;
    int nbr_cycle;
    int dump_nbr;
    int nbr_robots;
} corewar_t;

corewar_t *init_corewar(void);
int corewar(int argc, char **argv);
int read_file(char *filepath, char **buff);
int parse_args(int argc, char **argv, corewar_t *corewar);
int my_str_isnum(char const *str);
int is_corfile(char *str);
int is_file_exist(char *filepath);
int fill_robots(char **argv, corewar_t *corewar);
#endif
