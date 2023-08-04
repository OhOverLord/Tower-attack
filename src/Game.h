#ifndef GAME_H
#define GAME_H

#include <memory>
#include <unistd.h>
#include <cstdlib>

#include "Map.h"
#include "Soldier.h"
#include "Tower.h"
#include "TowerEffect.h"
#include "SoldierEffect.h"

class Game {
public:
    /**
    Default constructor for the Game class.
    **/
    Game();
    /**
    Starts a new game using the specified file.
    @param file_name The name of the file containing the game map.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int new_game(string file_name);
    /**
    Reads the game settings from a file.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int read_settings();
    /**
    Reads the saved game settings from a file.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int read_saved_settings();
    /**
    Adds a new soldier to the game.
    @param type The type of soldier to be added.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int add_new_soldier(char type);
    /**
    Adds a new tower to the game.
    @param type The type of tower to be added.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int add_new_tower(char type);
    /**
    Cleans the game map.
    */
    void clean_map();
    /**
    Exits the game.
    */
    void exit_game();
    /**
    Moves the soldiers in the game.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int move_soldiers();
    /**
    Adds the towers to the game map.
    */
    void added_towers();
    /**
    Clears the obstacles on the game map.
    */
    void clear_obstacles();
    /**
    Adds a soldier effect to the game.
    @param type The type of soldier effect to be added.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int add_soldier_effect(char type);
    /**
    Adds a tower effect to the game.
    @param type The type of tower effect to be added.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int add_tower_effect(int type);
    /**
    Saves the current game state.
    @returns Unsigned integer indicating the result of the operation.
    */
    unsigned int save_game();
    Map game_map; // The game map.
    unsigned int round = 0; // The current round.
    unsigned int money = 500; // The amount of money available.
    unsigned int towers_cnt = 0; // The count of towers.
    unsigned int army_cnt = 0; // The count of soldiers in the army.
    unsigned int alive_soldiers = 0; // The count of alive soldiers.
    unsigned int score = 0; // The game score.

    vector<Soldier> soldiers; // List of soldiers in the game.
    vector<Tower> towers; // List of towers in the game.

    vector<shared_ptr<Soldier>> army; // The army of soldiers.
    vector<shared_ptr<Tower>> defense; // The towers used for defense.

    vector<shared_ptr<SoldierEffect>> soldiers_effects; // List of soldier effects.
    vector<shared_ptr<TowerEffect>> towers_effects; // List of tower effects.
    vector<vector<char>> mapCopy; // Copy of the game map.
};


#endif //GAME_H
