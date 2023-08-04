#include "DispersionEffect.h"

DispersionEffect::DispersionEffect(char type, unsigned int cost, string name) : TowerEffect(type, cost, name) {}

void DispersionEffect::apply(Tower * tower) {
    if (tower != nullptr) {
        tower->set_radius(tower->get_radius() + 2);
    } else {
    }
}

void DispersionEffect::remove(Tower * tower) {
    if (tower != nullptr) {
        tower->set_radius(tower->get_radius() - 2);
    } else {
    }
}