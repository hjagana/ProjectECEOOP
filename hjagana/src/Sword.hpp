#ifndef SWORD_H_
#define SWORD_H_

#include "Item.hpp"
#include <string>

class Sword: public Item {
    public:
        Sword(std::string name);
        void setID(int room, int serial);
    private:
};

#endif