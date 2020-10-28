#ifndef PLAYER_H_
#define PLAYER_H_

#include "Creature.hpp"
#include "Item.hpp"
#include <string>

class Player: public Creature {
    public:
        void setWeapon(Item sword);
        void setArmor(Item armor);
        void draw();
    private:
};

#endif