#ifndef HALLUCINATE_H_
#define HALLUCINATE_H_

#include <string>
#include <vector>

#include "ItemAction.hpp"
// #include "Creature.hpp"
// #include "Item.hpp"

class Creature;
class Hallucinate: public ItemAction{
    private:

    public:
        Hallucinate(Creature* owner);
        //Item owner;
};

#endif /* HALLUCINATE_H_ */