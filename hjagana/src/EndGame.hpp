#ifndef ENDGAME_H_
#define ENDGAME_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class EndGame: public CreatureAction{
    private:

    public:
        EndGame(std::string name, Creature *owner);
};

#endif /* ENDGAME_H_ */