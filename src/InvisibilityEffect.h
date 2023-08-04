#ifndef INVISIBILITYEFFECT_H
#define INVISIBILITYEFFECT_H

#include "SoldierEffect.h"

/**
 * Class represents an invisibility effect applied to a soldier.
 * Inherits from the SoldierEffect class.
 */
class InvisibilityEffect : public SoldierEffect {
public:
    /**
     * Constructor for InvisibilityEffect class.
     * @param[in] type The type of the effect.
     * @param[in] cost The cost of the effect.
     * @param[in] name The name of the effect.
     */
    InvisibilityEffect(char type, unsigned int cost, string name);

    /**
     * Applies the invisibility effect to the given soldier.
     * @param[in] soldier Pointer to the soldier object.
     */
    void apply(Soldier* soldier) override;

    /**
     * Removes the invisibility effect from the given soldier.
     * @param[in] soldier Pointer to the soldier object.
     */
    void remove(Soldier* soldier) override;
};

#endif //INVISIBILITYEFFECT_H
