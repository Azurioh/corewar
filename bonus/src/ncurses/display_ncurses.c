/*
** EPITECH PROJECT, 2024
** display_ncurses.c
** File description:
** Function to display the ncurses elements
*/

#include "../../include/corewar.h"
#include "../../include/ncurses.h"

static void display_cycles(corewar_t *corewar)
{
    mvwprintw(corewar->windows[4], 0, getmaxx(stdscr) / 4 - 14,
        "Cycle to die: %d  /  %d", corewar->actual_cycle, corewar->nbr_cycle);
    mvwprintw(corewar->windows[4], 0, getmaxx(stdscr) / 2 - 9,
        "Total cycle: %d", corewar->total_cycles);
    mvwprintw(corewar->windows[4], 0, getmaxx(stdscr) / 4 * 3 - 9,
        "Nb live: %d  /  40", corewar->nbr_live);
    wrefresh(corewar->windows[4]);
}

static int *get_read_indexes(corewar_t *corewar)
{
    int *indexes = malloc(sizeof(int) * corewar->nbr_robots);

    for (int i = 0; corewar->robots[i]; i++) {
        indexes[i] = corewar->robots[i]->read_index;
    }
    return indexes;
}

static bool is_readed(corewar_t *corewar, int *read_indexes, int index)
{
    for (int i = 0; i < corewar->nbr_robots; i++) {
        if (index == read_indexes[i]) {
            return true;
        }
    }
    return false;
}

static void display_memory_element(corewar_t *corewar, int *read_indexes,
    int i, WINDOW *window)
{
    memory_t *memory = corewar->memory;
    robot_t **robots = corewar->robots;
    robot_t *robot;

    if (memory[i].author && is_readed(corewar, read_indexes, i) == false) {
        robot = get_robot_by_name(robots, memory[i].author);
        display_highlight_of_robot(robots, robot->name, window);
    }
    if (is_readed(corewar, read_indexes, i) == true)
        wattron(window, READ_MEMORY);
    if (!memory[i].author && is_readed(corewar, read_indexes, i) == false)
        wattron(window, MEMORY_COLOR);
    if (memory[i].memory < 0x10)
        wprintw(window, "0");
    wprintw(window, "%x", memory[i].memory);
    if (memory[i].author && is_readed(corewar, read_indexes, i) == false)
        hide_hightlight_of_robot(robots, robot->name, window);
    if (is_readed(corewar, read_indexes, i) == true)
        wattroff(window, READ_MEMORY);
    if (!memory[i].author && is_readed(corewar, read_indexes, i) == false)
        wattroff(window, MEMORY_COLOR);
}

static void display_memory(corewar_t *corewar)
{
    int *read_indexes = get_read_indexes(corewar);
    WINDOW *window = corewar->windows[5];

    for (int i = 0; i < MEM_SIZE; i++) {
        display_memory_element(corewar, read_indexes, i, window);
            wprintw(window, " ");
        if (i % 90 == 0 && i != 0) {
            wprintw(window, "\n");
        }
    }
    wrefresh(window);
}

void display_ncurses(corewar_t *corewar)
{
    for (int i = 0; i < 6; i++) {
        werase(corewar->windows[i]);
    }
    display_robots_information(corewar->robots, corewar->windows);
    display_cycles(corewar);
    display_memory(corewar);
}
