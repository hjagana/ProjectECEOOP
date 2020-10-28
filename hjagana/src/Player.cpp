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