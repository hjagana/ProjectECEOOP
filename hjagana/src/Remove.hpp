#ifndef REMOVE_H_
#define REMOVE_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class Remove: public CreatureAction{
    private:

    public:
        Remove(std::string name, Creature *owner);
};

#endif /* REMOVE_H_ */