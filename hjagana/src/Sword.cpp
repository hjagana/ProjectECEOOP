#include "Sword.hpp"
#include <iostream>

Sword::Sword(std::string name) {
    // std::cout << "Sword::Sword(std::stirng name)" << std::endl;
}

void Sword::setID(int room, int serial) {
    // std::cout << "Sword::setID(int room, int serial)" << std::endl;
}

void Sword::draw() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = ')';
    grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
    grid -> update();
}