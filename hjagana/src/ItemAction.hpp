#ifndef ITEMACTION_H_
#define ITEMACTION_H_

#include "Action.hpp"
#include "Creature.hpp"

class Creature;
class ItemAction : public Action {
    public:
        ItemAction(Creature* owner);
};

#endif