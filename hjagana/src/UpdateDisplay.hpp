#ifndef UPDATEDISPLAY_H_
#define UPDATEDISPLAY_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class UpdateDisplay : public CreatureAction {
    UpdateDisplay(std::string _name, Creature* _owner);
};

#endif