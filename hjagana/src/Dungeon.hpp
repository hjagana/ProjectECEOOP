#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <string>
#include <vector>
#include "Room.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Passage.hpp"


class Dungeon {
    public:
        static Dungeon* getDungeon(std::string name, int width, int gameHeight);
        std::vector<Room*> getRooms();
        std::vector<Creature*> getCreatures();
        std::vector<Passage*> getPassages();
        std::vector<Item*> getItems();
        void addRoom(Room* r);
        void addCreature(Creature* c);
        void addPassage(Passage* p);
        void addItem(Item* i);
        std::vector<Dungeon*> dungeon;
        std::vector<Room*> rooms;
        std::vector<Creature*> creatures;
        std::vector<Passage*> passages;
        std::vector<Item*> items;
        // int roomCount = 0;
        // int creatureCount = 0;
        // int passageCount = 0;
        // int itemCount = 0;
        static Dungeon* dungeonR;


    private:
}; 

#endif
