#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>

using namespace std;

class Screen {
public:
    /**
     * Constructs a Screen object.
     */
    Screen();

    /**
     * Destroys the Screen object and releases associated resources.
     */
    virtual ~Screen();

    /**
     * Displays the screen and handles user input.
     * @return The selected option.
     */
    virtual unsigned int show() = 0;

    /**
     * Shows an error message on the screen.
     * @param idx The error index to display the corresponding message.
     */
    void show_error(int idx);

protected:
    WINDOW* window;
    int max_x = 0;
    int max_y = 0;
};
#endif //SCREEN_H