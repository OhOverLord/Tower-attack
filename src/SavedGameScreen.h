#ifndef SAVEDGAMESCREEN_H
#define SAVEDGAMESCREEN_H

#include "GameScreen.h"

class SavedGameScreen : public GameScreen {
public:
    /**
     * Constructs a SavedGameScreen object.
     */
    SavedGameScreen();

    /**
     * Displays the saved game screen and handles user input.
     * @return The selected option.
     */
    virtual unsigned int show() override;
};

#endif //SAVEDGAMESCREEN_H
