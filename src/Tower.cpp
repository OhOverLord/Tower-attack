#include "Tower.h"

Tower::Tower() = default;

Tower::Tower(const int cost, const char type, const int radius, const int hp, const int attack)
            : Cell(type), cost(cost), radius(radius), hp(hp), attack(attack){
    this->default_type = type;
}

int Tower::get_hp() const {
    return this->hp;
}

unsigned int Tower::get_cost() const {
    return this->cost;
}

unsigned int Tower::get_attack() const {
    return this->attack;
}

bool Tower::damage(int damage) {
    if(!is_alive())
        return false;
    this->hp -= damage;
    return true;
}

bool Tower::is_alive() {
    if(this->hp > 0)
        return true;
    return false;
}

unsigned int Tower::get_radius() const {
    return this->radius;
}

string Tower::output() {
    stringstream ss;
    ss << type << " " << cost << " " << hp << " " << attack;
    return ss.str();
}

void Tower::set_radius(int radius) {
    this->radius = radius;
}

void Tower::set_attack(int attack) {
    this->attack = attack;
}

void Tower::set_hp(int hp) {
    this->hp = hp;
}

void Tower::die() {
    this->hp = 0;
    this->cost = 0;
    this->attack = 0;
    this->type = '%';
}