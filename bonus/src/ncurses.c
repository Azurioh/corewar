/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ncurses
*/

#include <ncurses.h>
#include <stdlib.h>

static void print_robot_information(WINDOW *win1,
    WINDOW *win2, WINDOW *win3, WINDOW *win4)
{
    wattron(win1, COLOR_PAIR(1));
    wattron(win2, COLOR_PAIR(2));
    wattron(win3, COLOR_PAIR(3));
    wattron(win4, COLOR_PAIR(4));
    wprintw(win1, "pdd");
    wprintw(win2, "zork");
    wprintw(win3, "tyler");
    wprintw(win4, "abel");
    wattroff(win1, COLOR_PAIR(1));
    wattroff(win2, COLOR_PAIR(2));
    wattroff(win3, COLOR_PAIR(3));
    wattroff(win4, COLOR_PAIR(4));
    wprintw(win1, "\n\nlive state: alive\n");
    wprintw(win2, "\n\nlive state: alive\n");
    wprintw(win3, "\n\nlive state: alive\n");
    wprintw(win4, "\n\nlive state: alive\n");
    wprintw(win1, "nb of process: 1\n");
    wprintw(win2, "nb of process: 1\n");
    wprintw(win3, "nb of process: 1\n");
    wprintw(win4, "nb of process: 1\n");
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);
}

static void print_cycles(WINDOW *win)
{
    mvwprintw(win, 0, getmaxx(stdscr) / 4 - 14, "Cycle to die: 0  /  1531");
    mvwprintw(win, 0, getmaxx(stdscr) / 2 - 9, "Total cycle: 0");
    mvwprintw(win, 0, getmaxx(stdscr) / 4 * 3 - 9, "Nb live: 0  /  40");
    wrefresh(win);
}

static void display_memory(WINDOW *win)
{
    int *memory = malloc(sizeof(int) * (6 * 1024));

    for (int i = 0; i < (6 * 1024); i++) {
        memory[i] = 0;
    }
    for (int i = 1; i < 6 * 1024; i++) {
        if (memory[i] < 0x10) {
            wprintw(win, "0");
        }
        wprintw(win, "%x", memory[i]);
        wprintw(win, " ");
        if (i % 90 == 0 && i != 0) {
            wprintw(win, "\n");
        }
    }
    wrefresh(win);
}

int main(void)
{
    WINDOW *win1;
    WINDOW *win2;
    WINDOW *win3;
    WINDOW *win4;
    WINDOW *win5;
    WINDOW *win6;
    int ch;
    int size;

    initscr();
    start_color();
    size = getmaxx(stdscr) / 4;
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    win1 = newwin(5, size, 0, (size * 0) + (size / 4));
    win2 = newwin(5, size, 0, (size * 1) + (size / 4));
    win3 = newwin(5, size, 0, (size * 2) + (size / 4));
    win4 = newwin(5, size, 0, (size * 3) + (size / 4));
    win5 = newwin(1, getmaxx(stdscr), 6, 0);
    win6 = newwin(getmaxy(stdscr) - 8, getmaxx(stdscr), 8, 0);
    refresh();
    print_robot_information(win1, win2, win3, win4);
    print_cycles(win5);
    display_memory(win6);
    ch = getch();
    while ((ch != 'q') && (ch != 'Q'));
    endwin();
    return 0;
}
