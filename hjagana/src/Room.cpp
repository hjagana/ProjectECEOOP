#include "Room.hpp"
#include <iostream>
#include <string>

Room::Room(std::string r) {
    // std::cout << "Room::Room(std::string r)" << std::endl;
}
void Room::setId(int room) {
    // std::cout << "Room::setId(int room)" << std::endl;
}
void Room::setCreature(Creature* Monster) {
    // std::cout << "Room::setCreature(Creature Monster)" << std::endl;
}

// std::vector<Creature*> Room::getCreature() {
//     return creatureVector;
// }

void Room::addRoom (Room * room) {
        roomVector[roomCount++] = room;

}
void Room::freeRoom(){

    for(std::vector<Room *>::iterator room = roomVector.begin(); room != roomVector.end(); ++room) { 
        delete *room; 
    }
    roomVector.clear();
}

bool Room::checkMove(int x, int y) {
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    int offX = this->getPosX();
    int offY = this->getPosY();
    int w = this -> getWidth();
    int h = this -> getHeight();
    if (x > (offX) && x < w+offX && y > (offY) && y < (h+offY)) {
        for (int i = offX; i < w + offX; i++) {
            for (int j = offY; j < h + offY; j++) {
                GridChar ch = grid->objGridStack[x][y].back();
                if(ch.getChar() == 'T' || ch.getChar() == 'H' || ch.getChar() == 'S'){
                    //don't move if there is a creature there
                    return false;
                }
                if (x == (offX) || x == (w+offX-1) || y == (offY) || y == (h+offY-1)) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    }
    return false;
}

void Room::draw() {
    ObjectDisplayGrid* grid = ObjectDisplayGrid::getGrid();
    int w = this -> getWidth();
    int h = this -> getHeight();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            char c;
            if (i == 0 || i == (w - 1) || j == 0 || j == (h - 1)) {
                c = 'X';
            }
            else {
                c = '.';
            }
            grid -> addObjectToDisplay(new GridChar(c), i + xPos, j + yPos);
        }
    }
    grid -> update();
}

