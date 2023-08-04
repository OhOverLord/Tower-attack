#include "InvisibilityEffect.h"

InvisibilityEffect::InvisibilityEffect(char type, unsigned int cost, string name) : SoldierEffect(type, cost, name) {}

void InvisibilityEffect::apply(Soldier* soldier) {
    soldier->invisibility = true;
}

void InvisibilityEffect::remove(Soldier* soldier) {
    soldier->invisibility = false;
}