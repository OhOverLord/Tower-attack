#ifndef DISPERSIONEFFECT_H
#define DISPERSIONEFFECT_H

#include "TowerEffect.h"

class DispersionEffect : public TowerEffect {
public:
    /**
    * Constructor for the DispersionEffect class.
    * @param type The type of the effect.
    * @param cost The cost of the effect.
    * @param name The name of the effect.
    */
    DispersionEffect(char type, unsigned int cost, string name);
    /**
     * Applies the dispersion effect to the specified tower.
     * Increases the tower's radius by 2.
     * @param tower Pointer to the tower to apply the effect to.
     */
    void apply(Tower * tower) override;
    /**
     * Removes the dispersion effect from the specified tower.
     * Decreases the tower's radius by 2.
     * @param tower Pointer to the tower to remove the effect from.
     */
    void remove(Tower * tower) override;
};
#endif //DISPERSIONEFFECT_H
