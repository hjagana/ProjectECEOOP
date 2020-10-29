#ifndef ROOM_H_
#define ROOM_H_

#include "ObjectDisplayGrid.hpp"
#include "Structure.hpp"
#include "Creature.hpp"
#include <string>
#include <vector>

class Room: public Structure {
    public:
        Room(std::string r);
        void setId(int room);
        void setCreature(Creature* Monster);
        void addRoom(Room * room);
        void freeRoom();
        std::vector <Creature*> getCreature();
        void drawRoom(std::vector<Room*> r);
        void draw();
        bool checkMove(int x, int y);

    private:
        int roomCount = 0;
        std::vector <Room *> roomVector;
        // std::vector <Creature*> creatureVector;
        // std::vector <Item*> itemVector; 
        Room* room;
};

#endif