#include "Item.hpp"

#include <string>
#include <iostream>

Item::Item(){
}

void Item::setOwner(Creature* _owner){
    owner = _owner;
}

Creature* Item::getOwner(){
    return owner;
}

// void Item::Draw(){
//     // int width = this->getWidth();
//     // int height = this->getHeight();
//     int x = this->getXPos();
//     int y = this->getYPos();
//     // Creature * owner = this->getOwner();
//     // std::cout << "item" << std::endl;
//     // owner.get
//     char c = 'I';
//     ObjectDisplayGrid::addObjectToDisplay(new GridChar(c), x, y);

//     ObjectDisplayGrid::update();
// }