#include "RegenerationEffect.h"

RegenerationEffect::RegenerationEffect(char type, unsigned int cost, string name) : SoldierEffect(type, cost, name) {}

void RegenerationEffect::apply(Soldier* soldier) {
    // Increase the soldier's HP by 100
    soldier->set_hp(soldier->get_hp() + 100);
}

void RegenerationEffect::remove(Soldier* soldier) {
    // This effect does not have any removal action
    // No implementation needed
}