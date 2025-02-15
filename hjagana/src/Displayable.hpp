#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>
#include <vector>

// #include "ObjectDisplayGrid.hpp"
#include "GridChar.hpp"

// class ObjectDisplayGrid;
class Displayable{
    private:
    // std::vector< Displayable * > displayable; 
    // int displayCount = 0;
    int width;
    int height;
    int xpos;
    int ypos;
    bool visible = false;
    int maxHit;
    int hitPoints;
    int itemNum;
    // ObjectDisplayGrid *grid;
    // friend class ObjectDisplayGrid;
    

    public:
        // ObjectDisplayGrid *grid;
        Displayable();
        virtual void setInvisible();
        virtual void setVisible();
        virtual bool getVisible();
        virtual bool getInvisible();
        virtual void setMaxHit(int _maxHit);
        virtual int getMaxHit();
        virtual void setHpMove(int hpMoves);
        virtual std::string getName();
        virtual void setItemNum(int _itemNum);
        virtual int getItemNum();
        // virtual int getHpMove();
        virtual void setHp(int Hp);
        virtual int getHp();
        virtual void setType(char t);
        virtual void setIntValue(int v);
        virtual void setXPos(int x);
        virtual void setYPos(int y);
        virtual void setWidht(int x);
        virtual void setHeight(int y);

        virtual int getWidth();
        virtual int getHeight();
        virtual int getXPos();
        virtual int getYPos();
        virtual void Draw();
        // virtual void update();
        // virtual void addObjectToDisplay(GridChar* ch, int x, int y);
        // virtual void writeLine(int line, std::string message);

        // void addDisplay(Displayable * display);
};

#endif /* DISPLAYABLE_H_ */