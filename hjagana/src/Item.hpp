#ifndef ITEM_H_
#define ITEM_H_

#include "Displayable.hpp"
#include "Creature.hpp"

class Item: public Displayable {
    public:
        void setOwner(Creature owner);
    private:
};

#endif