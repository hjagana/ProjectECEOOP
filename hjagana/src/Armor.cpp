#include "Armor.hpp"
#include <iostream>

Armor::Armor(std::string name) {
    // std::cout << "Armor::Armor(std::string name)" << std::endl;
}

void Armor::setName(std::string n) {
    armorName = n;
    // std::cout << "Armor::setName(std::string n)" << std::endl;  
}

void Armor::setID(int room, int serial) {
    // std::cout << "Armor::setID(int room, int serial)" << std::endl;
}

std::string Armor::getName() {
    return armorName;
}

void Armor::draw() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = ']';
    grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
    grid -> update();
}