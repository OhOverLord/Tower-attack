#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Screen.h"

class MenuScreen : public Screen {
public:
    /**
     * Displays the menu screen and returns the selected option.
     * @return The selected option.
     */
    virtual unsigned int show() override;

    /**
     * Displays the menu options.
     * @param option The currently selected option.
     */
    void menu(const unsigned int option = 0) const;

private:
    /**
     * The messages for the menu options.
     */
    vector<string> messages = {"New game", "Saved", "Exit"};
};


#endif //MENUSCREEN_H
