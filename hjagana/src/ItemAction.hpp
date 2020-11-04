#ifndef ITEMACTION_H_
#define ITEMACTION_H_

#include <string>
#include <vector>

// #include "Creature.hpp"
#include "Action.hpp"

class Creature;
class ItemAction: public Action{
    private:

    public:
        ItemAction(Creature *owner);
};

#endif /* ITEMACTION_H_ */