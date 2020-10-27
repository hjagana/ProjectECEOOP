#include "Dungeon.hpp"
#include <iostream>

Dungeon* Dungeon::dungeonR = NULL;

Dungeon* Dungeon::getDungeon(std::string name, int width, int gameHeight) {
    // std::cout << "Dungeon::getDungeon(std::string name, int width, int gameHeight)" << std::endl;
    if (dungeonR == NULL) {
        dungeonR = new Dungeon();
    }
    return dungeonR;
}
void Dungeon::addRoom(Room* r) {
    rooms.push_back(r);
    // std::cout << "Dungeon::addRoom(Room)" << std::endl;
}
void Dungeon::addCreature(Creature* c){
    creatures.push_back(c);
    // std::cout << "Dungeon::addCreature(Creature)" << std::endl;
}
void Dungeon::addPassage(Passage* p) {
    passages.push_back(p);
    // std::cout << "Dungeon::addPassage(Passage passage)" << std::endl;
}
void Dungeon::addItem(Item* i){
    items.push_back(i);
    // std::cout << "Dungeon::addItem(Item)" << std::endl;
}
std::vector<Room*> Dungeon::getRooms() {
    return rooms;
}
std::vector<Creature*> Dungeon::getCreatures() {
    return creatures;
}
std::vector<Passage*> Dungeon::getPassages() {
    return passages;
}
std::vector<Item*> Dungeon::getItems() {
    return items;
}

void Dungeon::draw(Dungeon *d) {
    std::vector<Room*> roomsVec = d -> getRooms();
    std::vector<Creature*> creaturesVec = d -> getCreatures();
    std::vector<Passage*> passagesVec = d -> getPassages();
    std::vector<Item*> itemsVec = d -> getItems();
    for (Room* r: roomsVec) {
        r -> draw();
    }
    for (Creature* c: creaturesVec){
        c -> draw();
    }
    for (Passage* p: passagesVec) {
        p -> draw();
    }
    for (Item* i: itemsVec) {
        i -> draw();
    }
}

// void Dungeon::drawRoom(std::vector<Room*> r) {
//     for (auto x: r) {
//         int w = x -> getWidth();
//         int h = x -> getHeight();
//         int xPos = x -> getPosX();
//         int yPos = x -> getPosY();
//         // std::vector<Creature*> cVector = x->getCreature(); // uses Room to get creature Vector
//         // std::vector<Creature*> cVector = d->getCreatures(); // uses Creature to get crature Vector
//         //for (int step = 1; (isRunning && step < w / 2); step *= 2) {
//             // grid -> writeLine(1, "Step " + std::to_string(step));
//             for (int i = 0; i < w; i++) {
//                 for (int j = 0; j < h; j++) {
//                     char c;
//                     if (i == 0 || i == (w-1) || j == 0 || j == (h-1)) {
//                         c = 'X';
//                     }
//                     else {
//                         c = ' ';
//                     }
//                     grid->addObjectToDisplay(new GridChar(c), i + xPos, j + yPos);
//                 }
//             }
//             // update the grid
//             grid->update();
//             // wait a bit to rejoin
//             // wait in a few steps to update faster on keypress
//             for (int i = 0; (isRunning && i < 5); i++) {
//                 std::this_thread::sleep_for(std::chrono::milliseconds(400));
//             }
//         //}
//     }
// }