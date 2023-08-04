#ifndef HPEFFECT_H
#define HPEFFECT_H

#include "TowerEffect.h"

/**
 * Class represents an HP effect applied to a tower.
 * Inherits from the TowerEffect class.
 */
class HpEffect : public TowerEffect {
public:
    /**
     * Constructor for HpEffect class.
     * @param[in] type The type of the effect.
     * @param[in] cost The cost of the effect.
     * @param[in] name The name of the effect.
     */
    HpEffect(char type, unsigned int cost, string name);

    /**
     * Applies the HP effect to the given tower.
     * @param[in] tower Pointer to the tower object.
     */
    void apply(Tower * tower) override;

    /**
     * Removes the HP effect from the given tower.
     * @param[in] tower Pointer to the tower object.
     */
    void remove(Tower * tower) override;
};

#endif //HPEFFECT_H
