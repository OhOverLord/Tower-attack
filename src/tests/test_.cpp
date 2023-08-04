#include "../Soldier.h"
#include "../Tower.h"
#include <cassert>

void testTowerDefaultConstructor() {
    Tower tower;
    assert(tower.get_cost() == 0);
    assert(tower.get_attack() == 0);
    assert(tower.get_hp() == 0);
    assert(tower.get_radius() == 1);
    assert(!tower.is_alive());
}

void testTowerParameterizedConstructor() {
    Tower tower(10, 'T', 3, 100, 20);
    assert(tower.get_cost() == 10);
    assert(tower.get_attack() == 20);
    assert(tower.get_hp() == 100);
    assert(tower.get_radius() == 3);
}

void testTowerDamage() {
    Tower tower(10, 'T', 3, 100, 20);
    assert(tower.is_alive());
    bool isAlive = tower.damage(50);
    assert(isAlive);
    assert(tower.get_hp() == 50);
    isAlive = tower.damage(100);
    assert(!tower.is_alive());
    tower.die();
    assert(tower.get_hp() == 0);
}

void testTowerDie() {
    Tower tower(10, 'T', 3, 100, 20);
    assert(tower.is_alive());
    tower.die();
    assert(!tower.is_alive());
    assert(tower.get_cost() == 0);
    assert(tower.get_attack() == 0);
    assert(tower.get_hp() == 0);
    assert(tower.get_radius() == 3);
}


void testDefaultConstructor() {
    Soldier soldier;
    assert(soldier.get_cost() == 0);
    assert(soldier.get_attack() == 0);
    assert(soldier.get_x() == 0);
    assert(soldier.get_y() == 0);
    assert(soldier.get_path_index() == 1);
    assert(soldier.get_hp() == 0);
    assert(soldier.get_armor() == 0);
    assert(!soldier.is_alive());
}

void testParameterizedConstructor() {
    Soldier soldier(10, 'A', 100, 20);
    assert(soldier.get_cost() == 10);
    assert(soldier.get_attack() == 20);
    assert(soldier.get_hp() == 100);
}

void testDamage() {
    Soldier soldier(10, 'A', 100, 20);
    assert(soldier.is_alive());
    bool isAlive = soldier.damage(50);
    assert(isAlive);
    assert(soldier.get_hp() == 50);
    isAlive = soldier.damage(100);
    assert(!soldier.is_alive());
    soldier.die();
    assert(soldier.get_hp() == 0);
}

void testDie() {
    Soldier soldier(10, 'A', 100, 20);
    assert(soldier.is_alive());
    soldier.die();
    assert(!soldier.is_alive());
    assert(soldier.get_cost() == 0);
    assert(soldier.get_attack() == 0);
    assert(soldier.get_hp() == 0);
}

int main() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testDamage();
    testDie();
    testTowerDefaultConstructor();
    testTowerParameterizedConstructor();
    testTowerDamage();
    testTowerDie();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}