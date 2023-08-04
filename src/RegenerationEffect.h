#ifndef REGENERATIONEFFECT_H
#define REGENERATIONEFFECT_H

#include "SoldierEffect.h"

class RegenerationEffect : public SoldierEffect {
public:
    /**
     * Constructs a RegenerationEffect object with the specified type, cost, and name.
     * @param type The type of the effect.
     * @param cost The cost of the effect.
     * @param name The name of the effect.
     */
    RegenerationEffect(char type, unsigned int cost, string name);

    /**
     * Applies the regeneration effect to the given soldier.
     * Increases the soldier's HP by 100.
     * @param soldier The soldier to apply the effect to.
     */
    void apply(Soldier* soldier) override;

    /**
     * Removes the regeneration effect from the given soldier.
     * This effect does not have any removal action.
     * @param soldier The soldier to remove the effect from.
     */
    void remove(Soldier* soldier) override;
};

#endif //REGENERATIONEFFECT_H
