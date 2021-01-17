/*
 * Copyright (C) 2021 Sora Tonami
 *
 * This file is part of Emerald OS.
 *
 * Emerald OS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Emerald OS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Emerald OS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "error.h"

void main(int argc, char **argv) {
    char *lang = "en_US";

    int opt;
    char **argstr;
    while((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
            case 'h':
                printf("\n");
                exit(EMOS_SUCCESS);
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }
    for(int i = 0; optind < argc; i++, optind++)
        sprintf(argstr[i], argv[optind]);
    initscr();
    start_color();
    init_color(COLOR_GREEN, 0, 1000, 250);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    noecho();
    cbreak();
    keypad(stdscr, true);
    box(stdscr, ACS_VLINE, ACS_HLINE);
    attrset(COLOR_PAIR(2));
    mvprintw(1, 3, "Welcome to Emerald OS!");
    attrset(COLOR_PAIR(1));
    mvprintw(3, 3, "Version : %s", VERSION);
    mvprintw(4, 3, "Language: %s", lang);
    mvprintw(LINES - 2, 3, "Press any button...");
    refresh();
    getch();
    clear();
    refresh();
    endwin();
    exit(EMOS_SUCCESS);
}