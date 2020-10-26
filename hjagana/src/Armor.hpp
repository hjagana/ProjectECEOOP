#ifndef ARMOR_H_
#define ARMOR_H_

#include "Item.hpp"
#include <string>

class Armor: public Item {
    public:
        Armor(std::string name);
        void setName(std::string n);
        void setID(int room, int serial);
    private:
};

#endif