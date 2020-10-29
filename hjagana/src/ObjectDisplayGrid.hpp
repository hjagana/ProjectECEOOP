#ifndef OBJECTDISPLAYGRID_H_
#define OBJECTDISPLAYGRID_H_
#include "GridChar.h"
//#include "Dungeon.hpp"
// #include "Displayable.hpp"
#include "Structure.hpp"
#include "Creature.hpp"
// #include "Room.hpp"
// #include "Passage.hpp"
#include <iostream>
#include "curses.h"
#include <typeinfo>

// static GridChar*** objectGrid;
// static std::vector<Displayable>** objGridStack;

class ObjectDisplayGrid {
    public:
        int getObjectDisplayGrid(int gameHeight, int width, int topHeight);
        void setTopMessageHeight(int topHeight);
        /**
         * Creates a new display grid using the given parameters and initializes ncurses.
         * Screen height will be grid height + messages
         * @param width     Screen width
         * @param height    Grid height
         * @param messages  Number of lines to reserve in the message area
         */
        std::vector<GridChar>** objGridStack;
        static ObjectDisplayGrid* objGrid;
        ObjectDisplayGrid(int width, int height, int messages);
        static ObjectDisplayGrid* getGrid(int w, int h, int m);
        static ObjectDisplayGrid* getGrid();
        /** Object deconstructor, to delete the grid character matrix and free ncurses data */
        virtual ~ObjectDisplayGrid();
        void removeFromVector(int x, int y) ;
        std::vector<GridChar>** getGridStack();

        /**
         * Refreshes the grid display
         */
        // virtual void update();
        virtual void update();
        /**
         * Adds an object to the display grid
         * @param ch  Object to display
         * @param x   X position
         * @param y   Y position
         */
        // virtual void addObjectToDisplay(GridChar* ch, int x, int y);
        virtual void addObjectToDisplay(GridChar* ch, int x, int y);
        /**
         * Writes a line of text to the screen at the given line relative to the bottom
         * @param line    line number
         * @param message message to write
         * @param update  If true, immediately updates the screen
         */
        virtual void writeLine(int line, std::string message);
        // void runDisplay(ObjectDisplayGrid* g, Dungeon* d);
        
        

    private:
        //std::vector<Displayable*>[height][width] objectGrid;
        // std::vector<Displayable*>[h][w] objectGrid;
        //std::vector<Displayable*> displayableVector;
        /** Keeps track of the consoles width and height */
        int height, width;
        // int h*;
        // int w*;

        /** Number of lines for message writing */
        int messages;
        
};

#endif