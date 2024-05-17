/*
** EPITECH PROJECT, 2024
** get_colors
** File description:
** function to get the right colors
*/

#include "../../include/corewar.h"
#include "../../include/ncurses.h"

void display_highlight_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window)
{
    int i = 0;

    for (; i < 4; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0) {
            break;
        }
    }
    if (i == 0)
        wattron(window, R1_MEMORY);
    if (i == 1)
        wattron(window, R2_MEMORY);
    if (i == 2)
        wattron(window, R3_MEMORY);
    if (i == 3)
        wattron(window, R4_MEMORY);
}

void hide_hightlight_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window)
{
    int i = 0;

    for (; i < 4; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0) {
            break;
        }
    }
    if (i == 0)
        wattroff(window, R1_MEMORY);
    if (i == 1)
        wattroff(window, R2_MEMORY);
    if (i == 2)
        wattroff(window, R3_MEMORY);
    if (i == 3)
        wattroff(window, R4_MEMORY);
}

void display_text_color_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window)
{
    int i = 0;

    for (; i < 4; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0) {
            break;
        }
    }
    if (i == 0)
        wattron(window, R1_TEXT);
    if (i == 1)
        wattron(window, R2_TEXT);
    if (i == 2)
        wattron(window, R3_TEXT);
    if (i == 3)
        wattron(window, R4_TEXT);
}

void hide_text_color_of_robot(robot_t **robots, unsigned char *robot_name,
    WINDOW *window)
{
    int i = 0;

    for (; i < 4; i++) {
        if (my_uns_strcmp(robot_name, robots[i]->name) == 0) {
            break;
        }
    }
    if (i == 0)
        wattroff(window, R1_TEXT);
    if (i == 1)
        wattroff(window, R2_TEXT);
    if (i == 2)
        wattroff(window, R3_TEXT);
    if (i == 3)
        wattroff(window, R4_TEXT);
}