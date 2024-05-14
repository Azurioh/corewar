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
    unsigned char *program;
    unsigned int prog_size;
    unsigned int nb_player;
    int *registers;
    unsigned char *name;
    bool is_alive;
    bool is_dead;
    int start_index_in_memory;
    unsigned int end_index_in_memory;
    unsigned int nb_cycles_to_wait;
    unsigned int read_index;
} robot_t;

robot_t *create_robot(char *filepath, int start, int number);
unsigned int get_index_robot(robot_t **robots, unsigned int player_number);
void free_robot(robot_t *robot);

int get_number_of_robots_alive(robot_t **robots);
int get_number_of_robots_not_dead(robot_t **robots);
#endif
