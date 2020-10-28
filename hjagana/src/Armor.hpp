#ifndef ARMOR_H_
#define ARMOR_H_

#include "Item.hpp"
#include <string>

class Armor: public Item {
    public:
        Armor(std::string name);
        void setName(std::string n);
        void setID(int room, int serial);
        std::string getName();
        std::string armorName;
        virtual void draw();
    private:
};

#endif