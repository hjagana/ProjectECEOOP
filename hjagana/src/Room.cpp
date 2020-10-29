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
    int offX = this->getPosX();
    int offY = this->getPosY();
    int w = this -> getWidth();
    int h = this -> getHeight();
    if (x == (w) || x == (w+offX) || y == (h) || y == (h+offY)) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (x == (w) || x == (w+offX) || y == (h) || y == (h+offY)) {
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

