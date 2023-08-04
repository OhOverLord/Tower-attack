#include "HpEffect.h"

HpEffect::HpEffect(char type, unsigned int cost, string name) : TowerEffect(type, cost, name) {}

void HpEffect::apply(Tower * tower) {
    if (tower != nullptr) {
        tower->set_hp(tower->get_hp() + 100);
    } else {
    }
}

void HpEffect::remove(Tower * tower) {
    if (tower != nullptr) {
        tower->set_hp(tower->get_hp() - 100);
    } else {
    }
}