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
    #include <stddef.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>

typedef struct corewar_s {
    unsigned char *memory;
    robot_t **robots;
    robot_t *last_robot_alive;
    int carry;
    int nbr_cycle;
    int dump_nbr;
    int nbr_robots;
} corewar_t;

corewar_t *init_corewar(void);
int corewar(int argc, char **argv);
int read_file(char *filepath, unsigned char **buff);
int parse_args(int argc, char **argv, corewar_t *corewar);
int my_str_isnum(char const *str);
int is_corfile(char *str);
int is_file_exist(char *filepath);
int fill_robots(char **argv, corewar_t *corewar);
char *read_coding_byte(int byte);

int manage_cycles(corewar_t *corewar);

op_t get_operation_info(char *name);
void read_instruction(corewar_t *corewar, robot_t *robot);
int get_address(int index);
int get_address_value(unsigned char *memory, int index);
char *place_robot_in_arena(corewar_t *corewar);

void live(corewar_t *corewar, robot_t *robot);
void add(corewar_t *corewar, robot_t *robot);
void sub(corewar_t *corewar, robot_t *robot);
void st_instruction(corewar_t *corewar, robot_t *robot);
#endif
