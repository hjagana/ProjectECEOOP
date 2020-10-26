#ifndef REMOVE_H_
#define REMOVE_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class Remove : public CreatureAction {
    Remove(std::string _name, Creature* _owner);
};

#endif