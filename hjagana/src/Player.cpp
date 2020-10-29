#include "Player.hpp"
#include <iostream>

void Player::setWeapon(Item sword) {
    // std::cout << "Player::setWeapon(Item sword)" << std::endl;
}
void Player::setArmor(Item armor) {
    // std::cout << "Player::setArmor(Item armor)" << std::endl;
}
void Player::draw() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    char c = '@';
    grid -> addObjectToDisplay(new GridChar(c), xPos, yPos);
    grid -> update();
}

void Player::movePlayerUp() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int x = this->getPosX();
    int y = this->getPosY();
    grid->removeFromVector(x, y);
    grid -> update();

    this->setPosY(y-1);
    int newY = this->getPosY();
    int newX = this->getPosX();
    char c = '@';
    grid -> addObjectToDisplay(new GridChar(c), newX, newY);
    grid -> update();
}
void Player::movePlayerDown() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int x = this->getPosX();
    int y = this->getPosY();
    grid->removeFromVector(x, y);
    grid -> update();

    this->setPosY(y+1);
    int newY = this->getPosY();
    int newX = this->getPosX();
    char c = '@';
    grid -> addObjectToDisplay(new GridChar(c), newX, newY);
    grid -> update();
}
void Player::movePlayerRight() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int x = this->getPosX();
    int y = this->getPosY();
    grid->removeFromVector(x, y);
    grid -> update();

    this->setPosX(x+1);
    int newX = this->getPosX();
    int newY = this->getPosY();
    char c = '@';
    grid -> addObjectToDisplay(new GridChar(c), newX, y);
    grid -> update();
}
void Player::movePlayerLeft() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int x = this->getPosX();
    int y = this->getPosY();
    grid->removeFromVector(x, y);
    grid -> update();

    this->setPosX(x-1);
    int newX = this->getPosX();
    // int newY = this->getPosY();
    char c = '@';
    grid -> addObjectToDisplay(new GridChar(c), newX, y);
    grid -> update();
}

// void Player::movePlayerX(int d) {
//     ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
//     grid->writeLine(2, "HERE1");
//     // grid -> removeFromVector(this->getPosX(), this -> getPosY());
//     this -> setPosX((this->getPosX()) + d);
//     // char c = '@';
//     // grid -> addObjectToDisplay(new GridChar(c), this -> getPosX(), this -> getPosY());
//     // grid -> update();
// }
// void Player::movePlayerY(int d) {
//     // ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
//     // grid -> removeFromVector(this->getPosX(), this -> getPosY());
//     this -> setPosY((this->getPosY()) + d);
//     char c = '@';
//     // grid -> addObjectToDisplay(new GridChar(c), this -> getPosX(), this -> getPosY());
//     // grid -> update();
// }