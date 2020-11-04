#ifndef BLESSCURSEOWNER_H_
#define BLESSCURSEOWNER_H_

#include <string>
#include <vector>

#include "ItemAction.hpp"

class Creature;
class BlessCurseOwner: public ItemAction{
    private:
    // Creature *owner;

    public:
        BlessCurseOwner(Creature *owner);
        
};

#endif /* BLESSCURSEOWNER_H_ */