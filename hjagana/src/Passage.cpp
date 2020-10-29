#include "Passage.hpp"
#include <iostream>

Passage::Passage() {
    // std::cout << "Passage::Passage()" << std::endl; 
}

void Passage::setName(std::string n) {
    // std::cout << "Passage::setName(std::string n)" << std::endl;
}
void Passage::setID(int room1, int room2) {
    // std::cout << "Passage::setID(int room1, int room2)" << std::endl;
}

void Passage::addPassage (Passage *  passage) {
        passageVector[passageCount++] = passage;

}
void Passage::freePassage(){

    for(std::vector<Passage *>::iterator passage = passageVector.begin(); passage != passageVector.end(); ++passage) { 
        delete *passage; 
    }
    passageVector.clear();
}

void Passage::setPosX(int _x) {
    xVec.push_back(_x);
}
void Passage::setPosY(int _y) {
    yVec.push_back(_y);
}
bool Passage::checkMove(int x, int y) {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    if (!grid->objGridStack[x][y].empty()) {
        GridChar ch = grid->objGridStack[x][y].back();
        if (ch.getChar() == '#' || ch.getChar() == '+' || ch.getChar() == '.') {
            return true;
        }
    }
    return false;
}

void Passage::draw() {
    char c;
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    grid -> writeLine(1, std::to_string(xVec.size()) + " ");
    grid -> writeLine(2, std::to_string(yVec.size()));

    for (int i = 1; i < xVec.size(); i++) {
        int x1 = xVec[i - 1];
        int y1 = yVec[i - 1];
        int x2 = xVec[i];
        int y2 = yVec[i];

        if (x1 != x2) {
            int xSmall = 0;
            int xBig = 0;
            if (x1 < x2) {
                xSmall = x1;
                xBig = x2;
            } else {
                xBig = x1;
                xSmall = x2;
            }
            for (int b = xSmall; b <= xBig; b++) {
                c = '#';
                grid -> addObjectToDisplay(new GridChar(c), b, y1);
            }
        } else if (y1 != y2) {
            int ySmall = 0;
            int yBig = 0;
            if (y1 < y2) {
                ySmall = y1;
                yBig = y2;
            } else {
                yBig = y1;
                ySmall = y2;
            }
            for (int b = ySmall; b <= yBig; b++) {
                c = '#';
                grid -> addObjectToDisplay(new GridChar(c), x1, b);
            }
        }
        grid -> update();
    }
    c = '+';
    int c1 = xVec[0];
    int c2 = yVec[0];
    grid -> addObjectToDisplay(new GridChar(c), c1, c2);
    int c3 = xVec[xVec.size()-1];
    int c4 = yVec[yVec.size()-1];
    grid -> addObjectToDisplay(new GridChar(c), c3, c4);
    grid -> update();
}