#include <ncurses.h>
#include <ctime>
#include <csignal>

#include "StartScreen.h"
#include "MenuScreen.h"
#include "GameScreen.h"
#include "SavedGameScreen.h"

void handleSIGINT(int signal)
{}


int main(int argc, char ** argv)
{
    // Set the seed for random number generation
    std::srand(std::time(0));

    signal(SIGINT, handleSIGINT);

    // Initialize the ncurses library
    initscr();

    // Enable color support
    start_color();

    // Initialize a color pair with white text on a cyan background
    init_pair(3, COLOR_WHITE, COLOR_CYAN);

    // Create an instance of the StartScreen class
    StartScreen startScreen;

    // Show the start screen
    startScreen.show();

    // Create an instance of the MenuScreen class
    MenuScreen menuScreen;

    // Refresh the screen
    refresh();

    // Enter the main loop
    while (true) {
        // Show the menu screen and get the selected option
        unsigned int option = menuScreen.show();

        // Check the selected option
        if (option == 0) {
            // Create a new instance of the GameScreen class
            GameScreen newGameScreen;

            // Show the game screen
            newGameScreen.show();
        }
        else if (option == 1) {
            // Create a new instance of the SavedGameScreen class
            SavedGameScreen savedGameScreen;

            // Show the saved game screen
            savedGameScreen.show();
        }
        else {
            // End the ncurses mode and break out of the loop
            endwin();
            break;
        }
    }

    // End the ncurses mode
    endwin();

    // Exit the program
    return 0;
}