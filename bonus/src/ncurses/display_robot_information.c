/*
** EPITECH PROJECT, 2024
** display_robot_information.c
** File description:
** Function to display the robot informations
*/

#include "../../include/corewar.h"
#include "../../include/ncurses.h"

static void display_robot_state(WINDOW *window, bool is_alive, bool is_dead)
{
    if (is_alive == true) {
        wattron(window, ALIVE_TEXT);
        wprintw(window, "alive");
        wattroff(window, ALIVE_TEXT);
        wprintw(window, "\n");
        return;
    }
    wattron(window, DEAD_TEXT);
    if (is_dead == false) {
        wprintw(window, "not alive");
    } else {
        wprintw(window, "dead");
    }
    wattroff(window, DEAD_TEXT);
    wprintw(window, "\n");
}

static void display_robot(robot_t **robots, robot_t *robot, WINDOW *window)
{
    bool is_alive = check_if_robot_is_alive(robots, robot->name);
    bool is_dead = check_if_robot_is_dead(robots, robot->name);
    int nb_process = get_nb_process(robots, robot->name);

    display_text_color_of_robot(robots, robot->name, window);
    wprintw(window, (char *)robot->name);
    hide_text_color_of_robot(robots, robot->name, window);
    wprintw(window, "\n\nlive state: ");
    display_robot_state(window, is_alive, is_dead);
    wprintw(window, "nb of process: %d\n", nb_process);
    wrefresh(window);
}

void display_robots_information(robot_t **robots, WINDOW **windows)
{
    for (int i = 0; robots[i] && i < 4; i++) {
        display_robot(robots, robots[i], windows[i]);
    }
}
