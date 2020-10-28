#include "Scroll.hpp"
#include <iostream>

Scroll::Scroll(std::string name) {
    // std::cout << "Scroll::Scroll(std::string name)" << std::endl;
}

void Scroll::setID(int room, int serial) {
    // std::cout << "Scroll::setID(int room, int serial)" << std::endl;
}

void Scroll::draw(){
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = '?';
    grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
    grid -> update();
}
