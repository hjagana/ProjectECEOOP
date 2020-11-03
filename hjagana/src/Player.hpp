#ifndef PLAYER_H_
#define PLAYER_H_

#include "Creature.hpp"
#include "Item.hpp"
#include <string>

class Item;

class Player: public Creature {
    public:
        void setWeapon(Item sword);
        void setArmor(Item armor);
        void draw();
        //void movePlayerX(int d);
        //void movePlayerY(int d);
        virtual void setName(std::string _name);
        virtual std::string getName(); 
        virtual void movePlayerUp();
        virtual void movePlayerDown();
        virtual void movePlayerLeft();
        virtual void movePlayerRight();
        virtual void addItemToPack(Item *item);
        virtual void removeItemFromPack(Item *item);
        virtual std::vector<Item *> getItemPack();
    private:
        std::string name;
        std::vector<Item*> itemsPack;
};

#endif