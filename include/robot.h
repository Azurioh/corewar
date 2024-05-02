/*
** EPITECH PROJECT, 2024
** robot.h
** File description:
** All struct and protos of the robot
*/

#ifndef ROBOT_H
    #define ROBOT_H

typedef struct instruction_s {

} instruction_t;

typedef struct robot_s {
    char *binary_code;
    char *registers;
    unsigned int size;
    unsigned int is_alive;
    unsigned int start_index_in_memory;
    unsigned int end_index_in_memory;
    unsigned int nb_cycles_to_wait;
    instruction_t **instructions;
} robot_t;

#endif
