#ifndef ENDGAME_H_
#define ENDGAME_H_

#include "CreatureAction.hpp"
#include "Creature.hpp"
#include <string>

class EndGame : public CreatureAction {
    EndGame(std::string _name, Creature* _owner);
};

#endif