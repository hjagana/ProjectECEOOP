#include "Room.hpp"
#include <iostream>
#include <string>

Room::Room(std::string r) {
    std::cout << "Room::Room(std::string r)" << std::endl;
}
void Room::setId(int room) {
    std::cout << "Room::setId(int room)" << std::endl;
}
void Room::setCreature(Creature Monster) {
    std::cout << "Room::setCreature(Creature Monster)" << std::endl;
}

std::vector<Creature*> Room::getCreature() {
    return creatureVector;
}

void Room::addRoom (Room * room) {
        roomVector[roomCount++] = room;

}
void Room::freeRoom(){

    for(std::vector<Room *>::iterator room = roomVector.begin(); room != roomVector.end(); ++room) { 
        delete *room; 
    }
    roomVector.clear();
}

