#ifndef HALLUCINATE_H_
#define HALLUCINATE_H_

#include "ItemAction.hpp"
#include "Creature.hpp"
#include <string>

class Hallucinate : public ItemAction {
    Hallucinate(Creature* _owner);
};


#endif