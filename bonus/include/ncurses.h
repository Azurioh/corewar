/*
** EPITECH PROJECT, 2024
** ncurses
** File description:
** All struct, include and protos for the ncurses functions
*/

#ifndef NCURSES_H
    #define NCURSES_H
    #include <ncurses.h>
    #include "corewar.h"

    #define R1_TEXT COLOR_PAIR(1)
    #define R2_TEXT COLOR_PAIR(2)
    #define R3_TEXT COLOR_PAIR(3)
    #define R4_TEXT COLOR_PAIR(4)

    #define ALIVE_TEXT COLOR_PAIR(5)
    #define DEAD_TEXT COLOR_PAIR(6)

    #define READ_MEMORY COLOR_PAIR(7)
    #define R1_MEMORY COLOR_PAIR(8)
    #define R2_MEMORY COLOR_PAIR(9)
    #define R3_MEMORY COLOR_PAIR(10)
    #define R4_MEMORY COLOR_PAIR(11)
    #define MEMORY_COLOR COLOR_PAIR(12)

bool check_if_robot_is_dead(robot_t **robots, unsigned char *robot_name);
bool check_if_robot_is_alive(robot_t **robots, unsigned char *robot_name);
int get_nb_process(robot_t **robots, unsigned char *robot_name);
robot_t *get_robot_by_name(robot_t **robots, unsigned char *robot_name);

void display_highlight_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window);
void display_text_color_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window);
void hide_hightlight_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window);
void hide_text_color_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window);

void display_robots_information(robot_t **robots, WINDOW **windows);
WINDOW **init_ncurses(void);
void display_ncurses(corewar_t *corewar);
#endif /* !NCURSES_H */
