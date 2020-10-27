#include "Displayable.hpp"
#include <iostream>

Displayable::Displayable() {
    // std::cout << "Displayable::Displayable()" << std::endl;
}
void Displayable::setInvisible() {
    // std::cout << "Displayable::setInvisible()" << std::endl;
}
void Displayable::setVisible() {
    // std::cout << "Displayable::setVisible()" << std::endl;
}
void Displayable::setMaxhit(int maxHit){
    // std::cout << "Displayable::setMaxhit(int maxHit)" << std::endl;
}
void Displayable::setHpMove(int hpMoves) {
    // std::cout << "Displayable::setHpMove(int hpMoves)" << std::endl;
}
void Displayable::setHp(int Hp) {
    // std::cout << "Displayable::setHp(int Hp)" << std::endl;
}
void Displayable::setType(char t) {
    // std::cout << "Displayable::setType(char t)" << std::endl;
}
void Displayable::setIntValue(int v) {
    // std::cout << "Displayable::setIntValue(int v)" << std::endl;
}
void Displayable::setPosX(int x) {
    posX = x;
    // std::cout << "Displayable::setPosX(int x)" << std::endl;
}
void Displayable::setPosY(int y) {
    posY = y;
    // std::cout << "Displayable::setPosY(int y)" << std::endl;
}
void Displayable::setWidth(int x) {
    w = x;
    // std::cout << "Displayable::setWidth(int x)" << std::endl;
}
void Displayable::setHeight(int y) {
    h = y;
    // std::cout << "Displayable::setHeight(int y)" << std::endl;
}

int Displayable::getPosX() {
    return posX;
    // std::cout << "Displayable::getPosX()" << std::endl;
}
int Displayable::getPosY() {
    return posY;
    // std::cout << "Displayable::getPosY()" << std::endl;
}
int Displayable::getHeight() {
    return h;
    // std::cout << "Displayable::getHeight()" << std::endl;
}
int Displayable::getWidth() {
    return w;
    // std::cout << "Displayable::getWidth()" << std::endl;
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

// void Displayable::update() {
// 	// refreshes ncurses
// 	refresh();
// }

// void Displayable::addObjectToDisplay(GridChar* ch, int x, int y) {
// 	// note grid objects start from 0,0 and go until width,height
// 	// x between 0 and width
//     int width = this -> getWidth();
//     int height = this -> getHeight();
// 	if ((0 <= x) && (x < width)) {
// 		// y between 0 and height
// 		if ((0 <= y) && (y < height)) {
// 			// delete existing character if present
// 			if (objectGrid[x][y] != NULL) {
// 				delete objectGrid[x][y];
// 			}

// 			// add new character to the internal character list
// 			objectGrid[x][y] = ch;
// 			// draws the character on the screen, note it is relative to 0,0 of the terminal
// 			mvaddch(y, x, ch->getChar());
// 		}
// 	}
// }

// void Displayable::draw() {
// }

