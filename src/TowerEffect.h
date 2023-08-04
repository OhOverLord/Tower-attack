#ifndef TOWER_EFFECT_H
#define TOWER_EFFECT_H

#include <string>
#include "Tower.h"

using namespace std;


class TowerEffect {
public:
    /**
     * TowerEffect constructor.
     * @param[in] type Type of the effect.
     * @param[in] cost Cost of the effect.
     * @param[in] name Name of the effect.
     */
    TowerEffect(char type, unsigned int cost, string name);

    /**
     * Apply the effect to a tower.
     * @param[in] tower The tower to apply the effect to.
     */
    virtual void apply(Tower* tower) = 0;

    /**
     * Remove the effect from a tower.
     * @param[in] tower The tower to remove the effect from.
     */
    virtual void remove(Tower* tower) = 0;

    char type;
    unsigned int cost;
    string name;
};

#endif //TOWER_EFFECT_H



