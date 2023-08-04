#ifndef SOLDIER_H
#define SOLDIER_H

#include "Cell.h"

class SoldierEffect;

class Soldier : public Cell {
public:
    /**
     * Constructs a Soldier object.
     */
    Soldier();

    /**
     * Constructs a Soldier object with the specified attributes.
     * @param cost The cost of the soldier.
     * @param type The type of the soldier.
     * @param hp The hit points (HP) of the soldier.
     * @param attack The attack value of the soldier.
     */
    Soldier(const int cost, const char type, const int hp, const int attack);

    /**
     * Retrieves the hit points (HP) of the soldier.
     * @return The hit points (HP) of the soldier.
     */
    int get_hp() const;

    /**
     * Retrieves the cost of the soldier.
     * @return The cost of the soldier.
     */
    unsigned int get_cost() const;

    /**
     * Retrieves the attack value of the soldier.
     * @return The attack value of the soldier.
     */
    unsigned int get_attack() const;

    /**
     * Retrieves the x-coordinate of the soldier's position.
     * @return The x-coordinate of the soldier's position.
     */
    int get_x() const;

    /**
     * Sets the x-coordinate of the soldier's position.
     * @param x The x-coordinate to set.
     */
    void set_x(int x);

    /**
     * Retrieves the y-coordinate of the soldier's position.
     * @return The y-coordinate of the soldier's position.
     */
    int get_y() const;

    /**
     * Sets the y-coordinate of the soldier's position.
     * @param y The y-coordinate to set.
     */
    void set_y(int y);

    /**
     * Retrieves the path index of the soldier.
     * @return The path index of the soldier.
     */
    int get_path_index() const;

    /**
     * Sets the path index of the soldier.
     * @param index The path index to set.
     */
    void set_path_index(int index);

    /**
     * Sets the armor value of the soldier.
     * @param armor The armor value to set.
     */
    void set_armor(unsigned int armor);

    /**
     * Sets hp value of the soldier.
     * @param armor The armor value to set.
     */
    void set_hp(unsigned int hp);

    /**
     * Retrieves the armor value of the soldier.
     * @return The armor value of the soldier.
     */
    unsigned int get_armor();

    /**
     * Checks if the soldier is alive.
     * @return True if the soldier is alive, false otherwise.
     */
    bool is_alive();

    /**
     * Kills the soldier, setting its HP, cost, and attack values to 0.
     */
    void die();

    /**
     * Inflicts damage to the soldier.
     * @param damage The amount of damage to inflict.
     * @return True if the soldier is still alive after taking damage, false otherwise.
     */
    bool damage(int damage);

    /**
     * Generates a string representation of the soldier's attributes.
     * @return A string representation of the soldier's attributes.
     */
    string output();

    vector<shared_ptr<SoldierEffect>> effects;
    char default_type;
    bool invisibility = false;

private:
    unsigned int cost = 0, attack = 0, x = 0, y = 0, path_index = 1;
    int hp = 0, armor = 0;
};


#endif //SOLDIER_H
