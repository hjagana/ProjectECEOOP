#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <string>
#include <vector>
#include "Room.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Passage.hpp"
#include "ObjectDisplayGrid.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Armor.hpp"
#include "Sword.hpp"
#include "Scroll.hpp"

class Dungeon {
    public:
        static Dungeon* getDungeon(std::string name, int width, int gameHeight);
        std::vector<Room*> getRooms();
        std::vector<Creature*> getCreatures();
        std::vector<Passage*> getPassages();
        std::vector<Item*> getItems();
        Player* getPlayer();
        std::vector<Monster*> getMonsters();
        std::vector<Armor*> getArmors();
        std::vector<Scroll*> getScrolls();
        std::vector<Sword*> getSwords();
        void setWidth(int w);
        void setGameHeight(int gH);
        void setTopHeight(int tH);
        void setBottomHeight(int bH);
        int getWidth();
        int getGameHeight();
        int getTopHeight();
        int getBottomHeight();
        void draw(Dungeon* d);
        void addRoom(Room* r);
        void addCreature(Creature* c);
        void addPassage(Passage* p);
        void addItem(Item* i);
        void addPlayer(Player* p);
        void addMonster(Monster *m);
        void addArmor(Armor *a);
        void addSword(Sword *s);
        void addScroll(Scroll *s);
        std::vector<Dungeon*> dungeon;
        std::vector<Room*> rooms;
        std::vector<Creature*> creatures;
        std::vector<Passage*> passages;
        std::vector<Item*> items;
        std::vector<Monster*> monsters;
        std::vector<Armor*> armors;
        std::vector<Scroll*> scrolls;
        std::vector<Sword*> swords;
        Player* p;
        // int roomCount = 0;
        // int creatureCount = 0;
        // int passageCount = 0;
        // int itemCount = 0;
        static Dungeon* dungeonR;
        int width;
        int gameHeight;
        int topHeight;
        int bottomHeight;

    private:
}; 

#endif
