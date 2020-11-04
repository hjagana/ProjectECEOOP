#ifndef TELEPORT_H_
#define TELEPORT_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class Teleport: public CreatureAction{
    private:

    public:
        Teleport(std::string name, Creature *owner);
};

#endif /* TELEPORT_H_ */