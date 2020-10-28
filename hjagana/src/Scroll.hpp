#ifndef SCROLL_H_
#define SCROLL_H_

#include "Item.hpp"
#include <string>

class Scroll: public Item {
    public:
        Scroll(std::string name);
        void setID(int room, int serial);
        virtual void draw();
    private:
};

#endif