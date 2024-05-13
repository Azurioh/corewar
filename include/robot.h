/*
** EPITECH PROJECT, 2024
** robot.h
** File description:
** All struct and protos of the robot
*/

#ifndef ROBOT_H
    #define ROBOT_H

typedef struct instruction_s {
    char *mnemonique;
    int nbr_cycles;
} instruction_t;

typedef struct robot_s {
    unsigned int nb_player;
    char *name;
    char *binary_code;
    char *registers;
    unsigned int size;
    unsigned int is_alive;
    unsigned int start_index_in_memory;
    unsigned int end_index_in_memory;
    unsigned int nb_cycles_to_wait;
    instruction_t **instructions;
} robot_t;

robot_t *init_robot(void);
robot_t *create_robot(char *filepath, int start, int number);
unsigned int get_index_robot(robot_t **robots, unsigned int player_number);
#endif
