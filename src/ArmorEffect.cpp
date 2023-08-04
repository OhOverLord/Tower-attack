#include "ArmorEffect.h"

ArmorEffect::ArmorEffect(char type, unsigned int cost, string name)
        : SoldierEffect(type, cost, name) {}

void ArmorEffect::apply(Soldier* soldier) {
    soldier->set_armor(soldier->get_armor() + 100);
}

void ArmorEffect::remove(Soldier* soldier) {
}