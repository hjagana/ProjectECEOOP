#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <vector>

#include "Displayable.hpp"
#include "ObjectDisplayGrid.hpp"

class Creature;
class Item: public Displayable{
    private:

    public:
        Item();
        virtual void setOwner(Creature* _owner);
        // virtual void Draw();
        virtual Creature* getOwner();
    protected:
        Creature * owner;
};

#endif /* ITEM_H_ */