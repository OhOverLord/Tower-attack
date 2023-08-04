#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <unistd.h>

#include "Screen.h"
#include "Game.h"


/** Class represents a game screen that extends the base Screen class. **/
class GameScreen : public Screen {
public:
    /**
    * Default constructor for the GameScreen class.
    **/
    GameScreen();
    /**
     * Destructor for the GameScreen class.
     */
    ~GameScreen();
    /**
     * Overrides the show() method from the Screen class to display the game screen.
     * @return An unsigned integer indicating the result of the screen display.
     */
    virtual unsigned int show() override;
    /**
     * Displays the game map on the screen.
     * @return The height of the displayed map.
     */
    unsigned int show_map();
    /**
     * Displays the game information on the screen.
     */
    void show_info();
    /**
     * Draws the game map on the screen.
     * @return The height of the drawn map.
     */
    unsigned int draw_map();
    /**
     * Displays the army of soldiers on the screen.
     * @param height The starting height of the display.
     * @param padding The padding for the display.
     * @return The updated height after displaying the army.
     */
    unsigned int show_army(unsigned int height, unsigned int padding);
    /**
     * Displays the user input prompt on the screen and handles user input.
     * @param height The starting height of the display.
     * @param padding The padding for the display.
     * @return The updated height after displaying the user input.
     */
    unsigned int show_input(unsigned int height, unsigned int padding);
    /**
     * Executes the user input command.
     * @param input The user input command.
     * @return An unsigned integer indicating the result of executing the command.
     */
    unsigned int execute_input(string input);
    /**
     * Removes effects from soldiers.
     */
    void removeEffectsFromSoldiers();
    /**
     * Applies effects to soldiers.
     */
    void applyEffectsFromSoldiers();
    /**
     * Removes effects from soldiers.
     */
    void remove_soldiers_effects();
    /**
     * Removes effects from towers.
     */
    // void remove_towers_effects();
    /**
     * Adds effects to towers.
     */
    void add_towers_effects();

    Game game; // An instance of the Game class representing the game state.
};


#endif //GAMESCREEN_H
