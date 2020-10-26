#ifndef TELEPORT_H_
#define TELEPORT_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class Teleport : public CreatureAction {
    Teleport(std::string _name, Creature* _owner);
};

#endif