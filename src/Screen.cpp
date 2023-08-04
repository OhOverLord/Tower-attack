#include "Screen.h"

Screen::~Screen() {
    delwin(window);
}

Screen::Screen() : window(newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0)) {
    max_x = getmaxy(stdscr);
    max_y = getmaxx(stdscr);
}

void Screen::show_error(int idx) {
    string message;
    if (idx == 1) {
        message = "Loading of the game file has failed!";
    } else if (idx == 0) {
        message = "Game save has failed!";
    }
    mvwaddstr(window, 0, (getmaxx(window) - message.size()) / 2, message.c_str());
    wrefresh(window);
    wmove(window, 0, 0);
}