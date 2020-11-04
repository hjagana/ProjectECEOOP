#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>

#include "Creature.hpp"
// #include "Item.hpp"
#include "ObjectDisplayGrid.hpp"


class Item;
class Player: public Creature{
    private:
        std::string name;
        // Item * creatureSword;
        Item *creatureArmor = NULL;
        std::vector<Item * > itemsPack; 

    public:
        Player();
        virtual void setWeapon(Item* sword);
        virtual void setArmor(Item* armor);
        virtual Item* getArmor();  
        virtual void setName(std::string _name);
        virtual std::string getName();   
        virtual void Draw(); 
        virtual void movePlayerLeft();
        virtual void movePlayerRight();
        virtual void movePlayerUp();
        virtual void movePlayerDown();
        virtual void addItemToPack(Item *item);
        virtual void removeItemFromPack(int itemNum);
        virtual std::vector<Item *> getItemPack();
};

#endif /* PLAYER_H_ */