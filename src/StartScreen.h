#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "Screen.h"

class StartScreen : public Screen {
public:
    /**
     * Displays the start screen and waits for user input.
     * @return 0 to indicate successful completion.
     */
    virtual unsigned int show() override;
};

#endif //STARTSCREEN_H
