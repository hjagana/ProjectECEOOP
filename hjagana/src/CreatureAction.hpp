#ifndef CREATUREACTION_H_
#define CREATUREACTION_H_

#include "Action.hpp"
#include "Creature.hpp"

class Creature;
class CreatureAction : public Action {
    public:
        CreatureAction(Creature* _owner);
};

#endif