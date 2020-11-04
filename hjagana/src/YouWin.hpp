#ifndef YOUWIN_H_
#define YOUWIN_H_

#include <string>
#include <vector>

#include "CreatureAction.hpp"

class Creature;
class YouWin: public CreatureAction{
    private:

    public:
        YouWin(std::string name, Creature *owner);
};

#endif /* YPUWIN_H_ */