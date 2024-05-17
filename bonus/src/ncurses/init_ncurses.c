/*
** EPITECH PROJECT, 2024
** init_ncurses
** File description:
** Function to init the ncurses elements
*/

#include "../../include/corewar.h"
#include "../../include/ncurses.h"

static WINDOW **init_ncurses_windows(void)
{
    WINDOW **windows = malloc(sizeof(WINDOW *) * 6);
    int size = getmaxx(stdscr) / 4;

    windows[0] = newwin(5, size, 0, (size * 0) + (size / 4));
    windows[1] = newwin(5, size, 0, (size * 1) + (size / 4));
    windows[2] = newwin(5, size, 0, (size * 2) + (size / 4));
    windows[3] = newwin(5, size, 0, (size * 3) + (size / 4));
    windows[4] = newwin(1, getmaxx(stdscr), 6, 0);
    windows[5] = newwin(getmaxy(stdscr) - 8, getmaxx(stdscr), 8, 0);
    return windows;
}

static void init_text_colors(void)
{
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
}

static void init_highlight_colors(void)
{
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
    init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(9, COLOR_BLACK, COLOR_BLUE);
    init_pair(10, COLOR_BLACK, COLOR_YELLOW);
    init_pair(11, COLOR_BLACK, COLOR_CYAN);
    init_pair(12, COLOR_WHITE, COLOR_BLACK);
}

WINDOW **init_ncurses(void)
{
    WINDOW **windows;

    initscr();
    start_color();
    init_text_colors();
    init_highlight_colors();
    windows = init_ncurses_windows();
    return windows;
}
