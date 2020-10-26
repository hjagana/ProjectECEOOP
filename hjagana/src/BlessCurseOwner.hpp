#ifndef BLESSCURSEOWNER_H_
#define BLESSCURSEOWNER_H_

#include "ItemAction.hpp"
#include "Creature.hpp"

class Creature;
class ItemAction;
class BlessCurseOwner : public ItemAction {
    public:
        BlessCurseOwner(Creature* _owner);
};

#endif