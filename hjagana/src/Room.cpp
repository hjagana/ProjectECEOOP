#include "Room.hpp"
#include <iostream>
#include <string>

Room::Room(std::string r) {
    // std::cout << "Room::Room(std::string r)" << std::endl;
}
void Room::setId(int room) {
    // std::cout << "Room::setId(int room)" << std::endl;
}
void Room::setCreature(Creature Monster) {
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

void Room::draw() {
    int w = this -> getWidth();
    int h = this -> getHeight();
    int xPos = this -> getPosX();
    int yPos = this -> getPosY();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            char c;
            if (i == 0 || i == (w-1) || j == 0 || j == (h-1)) {
                c = 'X';
            }
            else {
                c = ' ';
            }
            ObjectDisplayGrid::addObjectToDisplay(new GridChar(c), i + xPos, j + yPos);
        }
    }
    ObjectDisplayGrid::update();
}

