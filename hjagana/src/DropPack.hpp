#ifndef DROPPACK_H_
#define DROPPACK_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class DropPack: public CreatureAction{
    private:

    public:
        DropPack(std::string name, Creature *owner);
};

#endif /* DROPPACK_H_ */