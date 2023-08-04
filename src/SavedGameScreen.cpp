#include "SavedGameScreen.h"

SavedGameScreen::SavedGameScreen() : GameScreen() {}

unsigned int SavedGameScreen::show() {
    unsigned int res = game.new_game("examples/game_map.txt");
    unsigned int read_saved_settings = game.read_saved_settings();

    if(!res || !read_saved_settings)
    {
        show_error(1);
        wgetch(window);
        return 0;
    }
    unsigned int height = show_map();
    show_info();
    show_army(0, 5);
    show_input(height, 5);
    wclear(window);
    wrefresh(window);
    return 0;
}