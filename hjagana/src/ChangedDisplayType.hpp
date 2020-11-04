#ifndef CHANGEDDISPLAYTYPE_H_
#define CHANGEDDISPLAYTYPE_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class ChangedDisplayType: public CreatureAction{
    private:

    public:
        ChangedDisplayType(std::string name, Creature *owner);
};

#endif /* CHANGEDDISPLAYTYPE_H_ */