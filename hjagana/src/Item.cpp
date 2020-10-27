#include "Item.hpp"
#include <iostream>

void Item::setOwner(Creature owner) {
    // std::cout << "Item::setOwner(Creature owner)" << std::endl;
}

void Item::draw() {
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = 'I';
    ObjectDisplayGrid::addObjectToDisplay(new GridChar(c), xPos, yPos);
    ObjectDisplayGrid::update();
}