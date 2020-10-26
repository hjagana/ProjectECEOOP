#ifndef DROPPACK_H_
#define DROPPACK_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class DropPack : public CreatureAction {
    DropPack(std::string _name, Creature* _owner);
};

#endif