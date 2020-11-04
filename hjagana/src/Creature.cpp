#include "Creature.hpp"

#include <string>
#include <iostream>

Creature::Creature(){
}

// void Creature::setHp(int h){
// }

void Creature::setHpMoves(int hpm){
}

void Creature::setDeathAction(CreatureAction *da){
}

void Creature::setHitAction(int ha){
}


void Creature::Draw(){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    //how to call monster or player
    // int width = this->getWidth();
    // int height = this->getHeight();
    int x = this->getXPos();
    int y = this->getYPos();
    char c = 'C';
    grid->addObjectToDisplay(new GridChar(c), x, y);

    grid->update();
}