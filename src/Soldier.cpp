#include "Soldier.h"

Soldier::Soldier() = default;

Soldier::Soldier(const int cost, const char type, const int hp, const int attack) :
        Cell(type), cost(cost), hp(hp), attack(attack) {
    this->default_type = type;
}

int Soldier::get_hp() const {
    return this->hp;
}

unsigned int Soldier::get_cost() const {
    return this->cost;
}

unsigned int Soldier::get_attack() const {
    return this->attack;
}

bool Soldier::damage(int damage) {
    if(!is_alive())
        return false;
    if(this->armor > 0)
        this->armor -= damage;
    if(this->armor < 0)
    {
        this->hp += this->armor;
    }
    else
        this->hp -= damage;
    return true;
}

bool Soldier::is_alive() {
    if(this->hp > 0)
        return true;
    return false;
}

void Soldier::die() {
    this->hp = 0;
    this->cost = 0;
    this->attack = 0;
    this->type = 'X';
}

string Soldier::output() {
    stringstream ss;
    ss << type << " " << cost << " " << hp << " " << attack;
    return ss.str();
}

void Soldier::set_armor(unsigned int armor) {
    this->armor = armor;
}

unsigned int Soldier::get_armor() {
    return this->armor;
}

int Soldier::get_x() const {
    return x;
}

void Soldier::set_x(int x) {
    this->x = x;
}

int Soldier::get_y() const {
    return y;
}

void Soldier::set_y(int y) {
    this->y = y;
}

int Soldier::get_path_index() const {
    return path_index;
}

void Soldier::set_path_index(int index) {
    this->path_index = index;
}

void Soldier::set_hp(unsigned int hp) {
    this->hp = hp;
}