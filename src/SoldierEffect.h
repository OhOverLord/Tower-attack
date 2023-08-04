#ifndef SOLDIEREFFECT_H
#define SOLDIEREFFECT_H

#include <string>
#include "Soldier.h"

using namespace std;

class SoldierEffect {
public:
    /**
     * Constructs a SoldierEffect object with the specified type, cost, and name.
     * @param type The type of the effect.
     * @param cost The cost of the effect.
     * @param name The name of the effect.
     */
    SoldierEffect(char type, unsigned int cost, string name);

    /**
     * Applies the effect to the specified soldier.
     * @param soldier The soldier to apply the effect to.
     */
    virtual void apply(Soldier* soldier) = 0;

    /**
     * Removes the effect from the specified soldier.
     * @param soldier The soldier to remove the effect from.
     */
    virtual void remove(Soldier* soldier) = 0;

    char type;              /** The type of the effect. */
    unsigned int cost;      /** The cost of the effect. */
    string name;            /** The name of the effect. */
    Soldier* soldier;       /** The soldier the effect is applied to. */
};

#endif // SOLDIEREFFECT_H
