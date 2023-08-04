#include "EnhancementEffect.h"

EnhancementEffect::EnhancementEffect(char type, unsigned int cost, string name) : TowerEffect(type, cost, name){}

void EnhancementEffect::apply(Tower * tower) {
    if (tower != nullptr) {
        int new_attack = tower->get_attack();
        tower->set_attack(new_attack + new_attack * 0.5);
    } else {
    }
}

void EnhancementEffect::remove(Tower * tower) {
    if (tower != nullptr) {
        int new_attack = tower->get_attack();
        tower->set_attack(new_attack - new_attack * 0.5);
    } else {
    }
}