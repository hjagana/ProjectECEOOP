#ifndef CHANGEDDISPLAYEDTYPE_H_
#define CHANGEDDISPLAYEDTYPE_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class ChangedDisplayedType : public CreatureAction {
    ChangedDisplayedType(std::string _name, Creature* _owner);
};

#endif