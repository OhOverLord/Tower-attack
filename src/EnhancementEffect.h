#ifndef ENHANCEMENTEFFECT_H
#define ENHANCEMENTEFFECT_H

#include "TowerEffect.h"

class EnhancementEffect : public TowerEffect {
public:
    /**
    * Constructor for the EnhancementEffect class.
    * @param type The type of the effect.
    * @param cost The cost of the effect.
    * @param name The name of the effect.
    */
    EnhancementEffect(char type, unsigned int cost, string name);
    /**
     * Applies the enhancement effect to the specified tower.
     * Increases the tower's attack by 50%.
     * @param tower Pointer to the tower to apply the effect to.
     */
    void apply(Tower * tower) override;
    /**
     * Removes the enhancement effect from the specified tower.
     * Decreases the tower's attack by 50%.
     * @param tower Pointer to the tower to remove the effect from.
     */
    void remove(Tower * tower) override;
};
#endif //ENHANCEMENTEFFECT_H
