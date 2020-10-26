#ifndef MONSTER_H_
#define MONSTER_H_

#include "Creature.hpp"
#include <string>

class Monster: public Creature {
    public:
        Monster();
        void setName(std::string n);
        void setID(int room, int serial);
    private:
};

#endif