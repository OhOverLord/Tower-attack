#include "StartScreen.h"

unsigned int StartScreen::show() {
    noecho();
    curs_set(FALSE);

    string welcome_message = "I Can Only Show You The Door.";
    string intro_message = "You Are The One That Has To Walk Through It.";

    mvwprintw(window, getmaxy(window) / 2 - 2, (getmaxx(window) - welcome_message.size()) / 2, "%s", welcome_message.c_str());
    mvwprintw(window, getmaxy(window) / 2, (getmaxx(window) - intro_message.size()) / 2, "%s", intro_message.c_str());

    wrefresh(window);
    wgetch(window);
    endwin();

    return 0;
}
