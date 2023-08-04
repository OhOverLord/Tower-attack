#ifndef ARMOREFFECT_H
#define ARMOREFFECT_H

#include "SoldierEffect.h"

class ArmorEffect : public SoldierEffect {
public:
    /**
    * Constructor for the ArmorEffect class.
    * @param type The type of the effect.
    * @param cost The cost of the effect.
    * @param name The name of the effect.
    */
    ArmorEffect(char type, unsigned int cost, string name);
    /**
     * Applies the armor effect to the specified soldier.
     * Increases the soldier's armor by 100.
     * @param soldier Pointer to the soldier to apply the effect to.
     */
    void apply(Soldier* soldier) override;
    /**
     * Removes the armor effect from the specified soldier.
     * This function is empty for the ArmorEffect class.
     * @param soldier Pointer to the soldier to remove the effect from.
     */
    void remove(Soldier* soldier) override;
};

#endif //ARMOREFFECT_H
