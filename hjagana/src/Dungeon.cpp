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
bool Dungeon::checkMove(int x, int y) {
    std::vector<Room*> roomsVec = this -> getRooms();
    std::vector<Passage*> passageVec = this -> getPassages();
    std::vector<Monster*> monstersVec = this -> getMonsters();
    for (Room* r: roomsVec){
        if (r -> checkMove(x, y)) {
            return true;
        }
    }
    for (Passage* p: passageVec) {
        if (p -> checkMove(x, y)) {
            return true;
        }
    }
    return false;
}

bool Dungeon::checkCollision(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    std::vector<Monster*> creatureVector = this->getMonsters();
    bool pass = false;
    for (Monster* creature: creatureVector) {
        pass = creature->checkCollision(x, y);
        //there is a monster in the position of the player (or the position that they want to move to??)
        if (pass == true){
            int hit = creature->getMaxhit();
            grid->writeLine(11, "      " + creature->getName() + " did " + std::to_string(hit) + " damage!");
            // grid->writeLine(4, "Creature HP: " + std::to_string(creature->getHp()));
            // grid->writeLine(5, "Creature Hit: " + std::to_string(hit));
            int healthPoints = this->getPlayer()->getHp();
            this->getPlayer()->setHp(healthPoints-hit);
            // grid->writeLine(8, "HP-hit: " + std::to_string(healthPoints-hit));
            // grid->writeLine(9, "NewHP: " + std::to_string(this->getPlayer()->getHp()));

            int phit = this->getPlayer()->getMaxhit();
            grid->writeLine(10, "Info: " + (std::string) "Player" + " did " + std::to_string(phit) + " damage!");
            // grid->writeLine(7, "Player Hit: " + std::to_string(phit));
            int creatureHP = creature->getHp();
            // grid->writeLine(6, "Creature SetHP Parameter: " + std::to_string(creatureHP-phit));
            creature->setHp(creatureHP-phit);
            if (creature->getHp() <= 0) {
                grid->objGridStack[x][y].pop_back();
                grid->writeLine(11, "      " + creature->getName() + " died.");   
            }
            if (this->getPlayer()->getHp() <= 0) {
                grid->writeLine(11, "      " + creature->getName() + " killed you!");
            }
            break;
        }
    }
    return pass;
    //go through the creature list
    //see if they are at the position 5,4 or whatever
    //pass in player as parameter
    //check collisions functions
}

bool Dungeon::addItemToPack(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    std::vector<Item *> itemVector = this->getItems();
    bool pass = false;
    for(Item* item: itemVector){
        int itemX = item->getPosX();
        int itemY = item->getPosY();

        if(x == itemX && y == itemY){
            p->addItemToPack(item);
            grid->objGridStack[x][y].pop_back();
            return true;
        }
    }
    return pass;
}

bool Dungeon::removeItemToPack(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    std::vector<Item *> itemVector = this->getItems();
    if (!(grid->objGridStack[x][y].empty())){
        for(Item* item: itemVector){
        int itemX = item->getPosX();
        int itemY = item->getPosY();

        if(x == itemX && y == itemY){
            // player->removeItemFromPack(item);
            //find the name of the item
            //add it at the position
            // grid->gridStack[x][y].push_back(item);
            return true;
        }
    }
        //find the correct item from the pack
        //remove item from player stack
    }

    bool pass = false;
    // for(Item* item: itemVector){
    //     int itemX = item->getXPos();
    //     int itemY = item->getYPos();

    //     if(x == itemX && y == itemY){
    //         player->addItemToPack(item);
    //         grid->gridStack[x][y].pop_back();
    //         return true;
    //     }
    // }
    return pass;
}


void Dungeon::draw() {
    std::vector<Room*> roomsVec = this -> getRooms();
    std::vector<Creature*> creaturesVec = this -> getCreatures();
    std::vector<Monster*> monstersVec = this -> getMonsters();
    std::vector<Passage*> passagesVec = this -> getPassages();
    // std::vector<Item*> itemsVec = d -> getItems();
    std::vector<Armor*> armorsVec = this -> getArmors();
    std::vector<Scroll*> scrollsVec = this -> getScrolls();
    std::vector<Sword*> swordsVec = this -> getSwords();

    for (Room* r: roomsVec) {
        r -> draw();
    }
    for (Passage* p: passagesVec) {
        p -> draw();
    }
    Player *playuh = this -> getPlayer();
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