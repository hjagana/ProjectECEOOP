#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Displayable {
    public:
        Displayable();
        void draw();
        void setInvisible();
        void setVisible();
        void setMaxhit(int maxHit);
        void setHpMove(int hpMoves);
        void setHp(int Hp);
        void setType(char t);
        void setIntValue(int v);
        void setPosX(int x);
        void setPosY(int y);
        void setWidth(int x);
        void setHeight(int y);
        void addDisplay(Displayable * display);
        void freeDisplayables();
        int getPosX();
        int getPosY();
        int getHeight();
        int getWidth();
    private:
        std::vector<Displayable *> displayableVector;
        int displayCount = 0;
        int posX; // position x
        int posY; // position y
        int w; // width
        int h; // height
};

#endif