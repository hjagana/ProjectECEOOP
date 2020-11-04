#ifndef CREATURE_H_
#define CREATURE_H_

#include <string>
#include <vector>

#include "Displayable.hpp"
#include "CreatureAction.hpp"
#include "ObjectDisplayGrid.hpp"

class Creature: public Displayable{
    private:
    // ObjectDisplayGrid * grid;

    public:
        Creature();
        virtual void setHpMoves(int hpm);
        virtual void setDeathAction(CreatureAction *da);
        virtual void setHitAction(int ha);
        
        virtual void Draw();
};

#endif /* STRUCTURE_H_ */