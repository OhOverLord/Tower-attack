#include "MenuScreen.h"
#include "GameScreen.h"

void MenuScreen::menu(const unsigned int option) const {
    int height = -2;
    wattroff(window, COLOR_PAIR(3));

    // Display each menu option
    for (unsigned int i = 0; i < messages.size(); i++) {
        if (i == option) {
            wattron(window, COLOR_PAIR(3));
        }
        mvwaddstr(window, getmaxy(window) / 2 + height, (getmaxx(window) - messages[i].size()) / 2, messages[i].c_str());
        height += 2;
        if (i == option) {
            wattroff(window, COLOR_PAIR(3));
        }
    }

    wrefresh(window);
}

unsigned int MenuScreen::show() {
    wrefresh(window);
    wclear(window);
    keypad(window, TRUE);
    menu();
    unsigned int option = 0;

    while (true) {
        int sch = wgetch(window);

        switch (sch) {
            case KEY_UP: {
                // Move up to the previous option
                option--;
                if (option == -1) {
                    option = 2;
                }
                break;
            }
            case KEY_DOWN: {
                // Move down to the next option
                option++;
                if (option == 3) {
                    option = 0;
                }
                break;
            }
            case 10: {
                // Enter key pressed, return the selected option
                switch (option) {
                    case 0:
                        return 0;
                    case 1:
                        return 1;
                    case 2:
                        return 2;
                }
            }
        }
        menu(option);
    }
}