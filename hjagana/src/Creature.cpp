#include "Creature.hpp"
#include <iostream>

Creature::Creature() {
    // std::cout << "Creature::Creature()" << std::endl;
}

void Creature::setHp(int h) {
    // std::cout << "Creature::setHp(int h)" << std::endl;
}
void Creature::setHpMoves(int hpm) {
    // std::cout << "Creature::setHpMoves(int hpm)" << std::endl;
}
void Creature::setDeathAction(CreatureAction da) {
    // std::cout << "Creature::setDeathAction(CreatureAction da)" << std::endl;
}
void Creature::setHitAction(CreatureAction ha) {
    // std::cout << "Creature::setHitAction(CreatureAction ha)" << std::endl;
}

void Creature::draw() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = 'C';
    grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
    grid -> update();
}