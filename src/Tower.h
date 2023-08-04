#ifndef TOWER_H
#define TOWER_H

#include "Cell.h"

class TowerEffect;

class Tower : public Cell{
public:
    /**
     * Tower default constructor.
     */
    Tower();
    /**
     * Tower constructor.
     * @param[in] cost Cost of the tower.
     * @param[in] type Type of the tower.
     * @param[in] radius Radius of the tower's attack.
     * @param[in] hp Hit points of the tower.
     * @param[in] attack Attack power of the tower.
     */
    Tower(const int cost, const char type, const int radius, const int hp, const int attack);

    /**
     * Get the hit points of the tower.
     * @return The hit points of the tower.
     */
    int get_hp() const;

    /**
     * Set the hit points of the tower.
     * @param[in] hp The hit points to set.
     */
    void set_hp(int hp);

    /**
     * Get the cost of the tower.
     * @return The cost of the tower.
     */
    unsigned int get_cost() const;

    /**
     * Get the attack power of the tower.
     * @return The attack power of the tower.
     */
    unsigned int get_attack() const;

    /**
     * Get the radius of the tower's attack.
     * @return The radius of the tower's attack.
     */
    unsigned int get_radius() const;

    /**
     * Set the radius of the tower's attack.
     * @param[in] radius The radius of the tower's attack to set.
     */
    void set_radius(int radius);

    /**
     * Set the attack power of the tower.
     * @param[in] attack The attack power to set.
     */
    void set_attack(int attack);

    /**
     * Get the string representation of the tower.
     * @return The string representation of the tower.
     */
    string output();

    /**
     * Damage the tower by reducing its hit points.
     * @param[in] damage The amount of damage to inflict.
     * @return true if the tower is still alive after taking damage, false otherwise.
     */
    bool damage(int damage);

    /**
     * Check if the tower is still alive.
     * @return true if the tower has positive hit points, false otherwise.
     */
    bool is_alive();

    /**
     * Set the tower to a "dead" state by setting its hit points, cost, and attack power to 0 and type to '%'.
     */
    void die();

    vector<shared_ptr<TowerEffect>> effects;
    char default_type;
private:
    unsigned int cost = 0, attack = 0, radius = 1;
    int hp = 0;
};

#endif //TOWER_H
