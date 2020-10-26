#ifndef YOUWIN_H_
#define YOUWIN_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class YouWin : public CreatureAction {
    YouWin(std::string _name, Creature* _owner);
};

#endif