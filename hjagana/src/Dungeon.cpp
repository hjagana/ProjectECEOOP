#include "Dungeon.hpp"

#include <string>
#include <iostream>

Dungeon::Dungeon(){
}

Dungeon* Dungeon::dungeonCreated = nullptr;
Dungeon& Dungeon::getDungeon(std::string name, int width, int gameHeight){
    if (dungeonCreated == NULL){
        dungeonCreated = new Dungeon();
    }
    return *dungeonCreated;
}

void Dungeon::addRoom(Room *room) {
    rooms.push_back(room);
}

std::vector<Room *> Dungeon::getRooms() {
    return rooms;
}

void Dungeon::addPlayer(Player *_player){
    player = _player;
}

Player* Dungeon::getPlayer(){
    return player;
}

void Dungeon::addCreatue(Monster *creature) {
    creatures.push_back(creature);
}

std::vector<Monster *> Dungeon::getCreatures() {
    return creatures;
}

void Dungeon::addPassage(Passage *passage) {
    passages.push_back(passage);
}
std::vector<Passage *> Dungeon::getPassages() {
    return passages;
}

void Dungeon::addItem(Item *item) {
    items.push_back(item);
}

std::vector<Item *> Dungeon::getItems() {
    return items;
}

void Dungeon::setwidth(int _width){
    width = _width;
}

int Dungeon::getwidth(){
    return width;
}

void Dungeon::setTopHeight(int _topHeight){
    topHeight = _topHeight;
}

int Dungeon::getTopHeight(){
    return topHeight;
}

void Dungeon::setGameHeight(int _gameHeight){
    gameHeight = _gameHeight;
}

int Dungeon::getGameHeight(){
    return gameHeight;
}

void Dungeon::setBottomHeight(int _bottomHeight){
    bottomHeight = _bottomHeight;
}

int Dungeon::getBottomHeight(){
    return bottomHeight;
}

bool Dungeon::checkMove(int x, int y){
    std::vector<Room *> roomVector = this->getRooms();
    std::vector<Monster *> creatureVector = this->getCreatures();
    std::vector<Item *> itemVector = this->getItems();
    std::vector<Passage *> passageVector = this->getPassages();
    bool pass = false;

    for (Room* room : roomVector) {
        pass = room->checkMove(x, y);
        if (pass == true){
            break;
        }
    }
    
    for(Passage* passage: passageVector){
        pass = passage->checkMove(x,y);
        if (pass == true){
            break;
        }
    }    
    return pass;
}

bool Dungeon::checkCollision(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    Player *player = this->getPlayer();
    std::vector<Monster *> creatureVector = this->getCreatures();
    bool pass = false;
    for(Monster* creature: creatureVector){
        pass = creature->checkCollision(x, y);
        //there is a monster in the position of the player (or the position that they want to move to??)
        if (pass == true){
            int hit = creature->getMaxHit();
            grid->writeLine(11, "      " + creature->getName() + " did " + std::to_string(hit) + " damage!");
            int playerHealth = player->getHp();
            player->setHp(playerHealth-hit);

            int playerhit = player->getMaxHit();
            grid->writeLine(10, "Info: " + (std::string) "Player" + " did " + std::to_string(playerhit) + " damage!");
            int monsterHealth = creature->getHp();
            creature->setHp(monsterHealth - playerhit);
            if (creature->getHp() <= 0 ){
                grid->removeFromVector(x, y);
                grid->writeLine(11, "      " + creature->getName() + " died.");   
            }
            if(player->getHp() <= 0){
                grid->writeLine(11, "      " + creature->getName() + " killed you!");
            }
            return pass;
        }
    }
    return pass;
}

bool Dungeon::addItemToPack(int x, int y){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    Player *player = this->getPlayer();
    std::vector<Item *> itemVector = this->getItems();
    bool pass = false;
    for(Item* item: itemVector){
        int itemX = item->getXPos();
        int itemY = item->getYPos();
        
        if(x == itemX && y == itemY){
            player->addItemToPack(item);
            grid->gridStack[x][y].pop_back();
            return true;
        }
    }
    return pass;
}

bool Dungeon::dropItemFromPack(int itemNum){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    Player *player = this->getPlayer();
    std::vector<Item *> itemPack = player->getItemPack();
    bool pass = false;
    // grid->writeLine(3, std::to_string(itemNum));

    for(Item* item: itemPack){
        if(item->getItemNum() == (itemNum - 49)){
            int playerX = player->getXPos();
            int playerY = player->getYPos();
            std::string name = item->getName();
            char ch = '\0';
            if (name == "Sword"){
                ch = ')';
            }
            else if(name == "Armor"){
                ch = ']';
            }
            else if (name == "Scroll"){
                ch = '?';
            }
            grid->gridStack[playerX][playerY].pop_back();
            grid->gridStack[playerX][playerY].push_back(ch);
            grid->gridStack[playerX][playerY].push_back('@');
            player->removeItemFromPack(itemNum - 48); //remove item from the player pack
            int counter = 0;
            for(Item* item: itemPack){
                item->setItemNum(counter);
                counter++;
            }
            return true;
        }
    }
    return pass;
}

void Dungeon::displayItemsInPack(){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    Player *player = this->getPlayer();
    std::vector<Item *> itemPack = player->getItemPack();
    int counter = 1;
    std::string itemString;
    for (Item* item: itemPack){
        itemString += std::to_string(counter) + ":" + item->getName() + "   ";
        item->setItemNum(counter - 1);
        counter++;
    }
    grid->writeLine(1, " ");
    grid->writeLine(3, " ");
    grid->writeLine(4, " ");
    grid->writeLine(6, " ");
    grid->writeLine(7, " ");
    grid->writeLine(8, "Pack: " + itemString);
    grid->writeLine(9, " ");
    grid->writeLine(10, "Info: ");
}

bool Dungeon::checkArmor(){
    Player *player = this->getPlayer();
    if(player->getArmor()){
        Item* armor = player->getArmor();
        player->addItemToPack(armor);
        player->setArmor(NULL);
        return true;
    }

    return false;
}

bool Dungeon::checkArmorInPack(int armorNum){
    ObjectDisplayGrid *grid = ObjectDisplayGrid::getGrid();
    Player *player = this->getPlayer();
    std::vector<Item *> itemPack = player->getItemPack();
    bool pass = false;

    for(Item* item: itemPack){
        if(item->getItemNum() == (armorNum - 49)){
            player->setArmor(item);
            return true;
        }
    }
    return pass;

}
void Dungeon::Draw() {
    std::vector<Room *> roomVector = this->getRooms();
    std::vector<Monster *> creatureVector = this->getCreatures();
    std::vector<Item *> itemVector = this->getItems();
    std::vector<Passage *> passageVector = this->getPassages();
    
    for (Room* room : roomVector) {
        room->Draw();
    }

    for(Item* item: itemVector){
        item->Draw();
    }
    
    for(Passage* passage: passageVector){
        passage->Draw();
    }

    for(Monster* creature: creatureVector){
        creature->Draw();
    }
    Player *player = this->getPlayer();
    player->Draw();
}
