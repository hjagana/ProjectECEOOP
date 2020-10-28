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
void Dungeon::addPlayer(Player* pR) {
    p = pR;
}
void Dungeon::addMonster(Monster *m) {
    monsters.push_back(m);
}
void Dungeon::addArmor(Armor *a) {
    armors.push_back(a);
}
void Dungeon::addSword(Sword *s) {
    swords.push_back(s);
}
void Dungeon::addScroll(Scroll *s) {
    scrolls.push_back(s);
}
void Dungeon::setWidth(int w) {
    width = w;
}
void Dungeon::setGameHeight(int gH){
    gameHeight  = gH;
}
void Dungeon::setTopHeight(int tH){
    topHeight = tH;
}
void Dungeon:: setBottomHeight(int bH) {
    bottomHeight = bH;
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
Player* Dungeon::getPlayer() {
    return p;
}
std::vector<Monster*> Dungeon::getMonsters() {
    return monsters;
}

std::vector<Armor*> Dungeon::getArmors() {
    return armors;
}
std::vector<Scroll*> Dungeon::getScrolls() {
    return scrolls;
}
std::vector<Sword*> Dungeon::getSwords() {
    return swords;
}
int Dungeon::getWidth() {
    return width;
}
int Dungeon::getGameHeight() {
    return gameHeight;
}
int Dungeon::getTopHeight(){
    return topHeight;
}
int Dungeon::getBottomHeight(){
    return bottomHeight;
}

void Dungeon::draw(Dungeon *d) {
    std::vector<Room*> roomsVec = d -> getRooms();
    std::vector<Creature*> creaturesVec = d -> getCreatures();
    std::vector<Monster*> monstersVec = d -> getMonsters();
    std::vector<Passage*> passagesVec = d -> getPassages();
    // std::vector<Item*> itemsVec = d -> getItems();
    std::vector<Armor*> armorsVec = d -> getArmors();
    std::vector<Scroll*> scrollsVec = d -> getScrolls();
    std::vector<Sword*> swordsVec = d -> getSwords();

    for (Room* r: roomsVec) {
        r -> draw();
    }
    for (Passage* p: passagesVec) {
        p -> draw();
    }
    Player *playuh = d -> getPlayer();
    playuh -> draw();
    for (Creature* c: creaturesVec){
        c -> draw();
    }
    for (Monster*m : monstersVec) {
        m -> draw();
    }
    // for (Item* i: itemsVec) {
    //     i -> draw();
    // }
    for (Armor* a: armorsVec) {
        a -> draw();
    }
    for (Scroll* s: scrollsVec) {
        s -> draw();
    }
    for (Sword* s: swordsVec) {
        s -> draw();
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