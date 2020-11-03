#include "Monster.hpp"
#include <iostream>
#include <string>

Monster::Monster(){
    // std::cout << "Monster::Monster()" << std::endl;
}
void Monster::setName(std::string n) {
    name = n;
    // std::cout << "Monster::setName(std::string n)" << std::endl;
}
void Monster::setID(int room, int serial) {
    // std::cout << "Monster::setID(int room, int serial)" << std::endl;
}
std::string Monster::getName() {
    return name;
}


bool Monster::checkCollision(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    int monsterX = this->getPosX();
    int monsterY = this->getPosY();

    if(x == monsterX && y == monsterY){
        // grid->gridStack[x][y].pop_back();
        return true;
    }
    return false;

}

void Monster::draw() {
    std::string typeofMonster = this -> getName();
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    if (typeofMonster.compare("Troll") == 0) {
        int xPos = this -> getPosX();
        int yPos = this -> getPosY();
        char c = 'T';
        grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
        grid -> update();
    } else if (typeofMonster.compare("Snake") == 0) {
        int xPos = this -> getPosX();
        int yPos = this -> getPosY();
        char c = 'S';
        grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
        grid -> update();
    } else if (typeofMonster.compare("Hobgoblin") == 0) {
        int xPos = this -> getPosX();
        int yPos = this -> getPosY();
        char c = 'H';
        grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
        grid -> update();
    } //else {
    //     std::cout << "ERROR MONSTER TYPE NOT FOUND!" <<std::endl;
    // }
}