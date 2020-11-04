#ifndef UPDATEDISPLAY_H_
#define UPDATEDISPLAY_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class UpdateDisplay: public CreatureAction{
    private:

    public:
        UpdateDisplay(std::string name, Creature *owner);
};

#endif /* UPDATEDISPLAY_H_ */