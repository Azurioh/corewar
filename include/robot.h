/*
** EPITECH PROJECT, 2024
** robot.h
** File description:
** All struct and protos of the robot
*/

#ifndef ROBOT_H
    #define ROBOT_H
    #include <stdbool.h>

typedef struct robot_s {
    unsigned int nb_player;
    char *name;
    char *registers;
    bool is_alive;
    bool is_dead;
    unsigned int start_index_in_memory;
    unsigned int end_index_in_memory;
    unsigned int nb_cycles_to_wait;
    unsigned int reading_index;
} robot_t;

robot_t *create_robot(char *filepath, int start, int number);
unsigned int get_index_robot(robot_t **robots, unsigned int player_number);
void free_robot(robot_t *robot);
#endif
