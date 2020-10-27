#ifndef CREATURE_H_
#define CREATURE_H_

#include "Displayable.hpp"
#include "CreatureAction.hpp"
#include "ObjectDisplayGrid.hpp"

class CreatureAction;
class Creature: public Displayable {
    public:
        Creature();
        void setHp(int h);
        void setHpMoves(int hpm);
        void setDeathAction(CreatureAction da);
        void setHitAction(CreatureAction ha);
        void draw();
    private:
};

#endif