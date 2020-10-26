#include "Displayable.hpp"
#include <iostream>

Displayable::Displayable() {
    std::cout << "Displayable::Displayable()" << std::endl;
}
void Displayable::setInvisible() {
    std::cout << "Displayable::setInvisible()" << std::endl;
}
void Displayable::setVisible() {
    std::cout << "Displayable::setVisible()" << std::endl;
}
void Displayable::setMaxhit(int maxHit){
    std::cout << "Displayable::setMaxhit(int maxHit)" << std::endl;
}
void Displayable::setHpMove(int hpMoves) {
    std::cout << "Displayable::setHpMove(int hpMoves)" << std::endl;
}
void Displayable::setHp(int Hp) {
    std::cout << "Displayable::setHp(int Hp)" << std::endl;
}
void Displayable::setType(char t) {
    std::cout << "Displayable::setType(char t)" << std::endl;
}
void Displayable::setIntValue(int v) {
    std::cout << "Displayable::setIntValue(int v)" << std::endl;
}
void Displayable::setPosX(int x) {
    posX = x;
    std::cout << "Displayable::setPosX(int x)" << std::endl;
}
void Displayable::setPosY(int y) {
    posY = y;
    std::cout << "Displayable::setPosY(int y)" << std::endl;
}
void Displayable::setWidth(int x) {
    w = x;
    std::cout << "Displayable::setWidth(int x)" << std::endl;
}
void Displayable::setHeight(int y) {
    h = y;
    std::cout << "Displayable::setHeight(int y)" << std::endl;
}

int Displayable::getPosX() {
    return posX;
    std::cout << "Displayable::getPosX()" << std::endl;
}
int Displayable::getPosY() {
    return posY;
    std::cout << "Displayable::getPosY()" << std::endl;
}
int Displayable::getHeight() {
    return h;
    std::cout << "Displayable::getHeight()" << std::endl;
}
int Displayable::getWidth() {
    return w;
    std::cout << "Displayable::getWidth()" << std::endl;
}

void Displayable::addDisplay (Displayable * display) {
        displayableVector[displayCount++] = display;

}
void Displayable::freeDisplayables(){

    for(std::vector<Displayable *>::iterator displayableD = displayableVector.begin(); displayableD != displayableVector.end(); ++displayableD) { 
        delete *displayableD; 
    }
    displayableVector.clear();
}

void Displayable::draw() {
    
}

