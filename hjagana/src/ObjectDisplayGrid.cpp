#include "ObjectDisplayGrid.hpp"
#include <iostream>
#include <string>
#include <atomic> 
#include <thread>
#include <sstream>

// std::atomic_bool isRunning(true);
ObjectDisplayGrid* ObjectDisplayGrid::objGrid = NULL;
ObjectDisplayGrid* ObjectDisplayGrid::getGrid(int _width, int _height, int _messages) {
	if (objGrid == NULL) {
		objGrid = new ObjectDisplayGrid(_width, _height, _messages);
	}
	return objGrid;
}
ObjectDisplayGrid* ObjectDisplayGrid::getGrid() {
	// if (objGrid == NULL) {
		// return some error message!
	// }
	return objGrid;
}

std::vector<GridChar>** ObjectDisplayGrid::getGridStack() {
	return objGridStack;
}

int ObjectDisplayGrid::getObjectDisplayGrid(int gameHeight, int width, int topHeight) {
    std::cout << "ObjectDisplayGrid::getObjectDisplayGrid(int gameHeight, int width, int topHeight)" << std::endl;
	return 1;// <-- change later
}
void ObjectDisplayGrid::setTopMessageHeight(int topHeight) {
    std::cout << "ObjectDisplayGrid::setTopMessageHeight(int topHeight)" << std::endl;
}

ObjectDisplayGrid::ObjectDisplayGrid(int _width, int _height, int _messages) : width(_width), height(_height), messages(_messages) {	
	// create the 2D array of grid characters
	// note if you want to write messages instead, ncurses
	// objectGrid = new GridChar**[width];
	objGridStack = new std::vector<GridChar>*[width];
	for (int i = 0; i < width; i++) {
		objGridStack[i] = new std::vector<GridChar>[height];
		// objectGrid[i] = new GridChar*[height];
		// for (int j = 0; j < height; j++) {
		// 	objectGrid[i][j] = NULL;
		// }
	}

	// initialize ncurses

	// set command window size if running on windows, useful when running in Visual Studio
	// as far as I am aware, no way to do this on linux
	#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD size = { (short)width, (short)(height + messages) };
		SMALL_RECT DisplayArea = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1) };
		SetConsoleScreenBufferSize(handle, size);
		SetConsoleWindowInfo(handle, TRUE, &DisplayArea);
	#endif
	
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak(); 
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
}

void ObjectDisplayGrid::removeFromVector(int x, int y) {
	if ((0 <= x) && (x < width))  {
		if ((0 <= y) && (y < height))  {
			if (!objGridStack[x][y].empty()) {
				objGridStack[x][y].pop_back();
				if (!objGridStack[x][y].empty()){
					GridChar ch = objGridStack[x][y].back();
					mvaddch(y, x, ch.getChar());
				} else {
					// GridChar ch = ' ';
					mvaddch(y, x, ' ');
				}	
			}
		}
	}
}

ObjectDisplayGrid::~ObjectDisplayGrid() {
	// free memory from the dynamically sized object grid
	for (int i = 0; i < width; i++) {
		// delete all character objects in the grid
		// for (int j = 0; j < height; j++) {
		// 	delete objectGrid[i][j];
		// }
		// delete the column
		// delete[] objectGrid[i];
		delete[] objGridStack[i];
	}
	// delete the array of columns
	// delete[] objectGrid;
	delete[] objGridStack;
	// objectGrid = NULL;
	objGridStack = NULL;
	// free ncurses data
	endwin();
	// endwin();
}

void ObjectDisplayGrid::addObjectToDisplay(GridChar* ch, int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < width)) { // 150 should be "width"
		// y between 0 and height
		if ((0 <= y) && (y < height)) { // 41 should be "height"
			// delete existing character if present
			// if (objectGrid[x][y] != NULL) {
			// 	//objGridStack[x][y].push_back(*ch);
			// 	//delete objectGrid[x][y];
			// 	// pop from stack
			// }
			// add new character to the internal character list
			// objectGrid[x][y] = ch;
			objGridStack[x][y].push_back(*ch);
			// else push to stack
			// draws the character on the screen, note it is relative to 0,0 of the terminal
			mvaddch(y, x, ch->getChar());
		}
	}
}

void ObjectDisplayGrid::update() {
	// refreshes ncurses
	refresh();
}

void ObjectDisplayGrid::writeLine(int line, std::string message) {
	// messages start from 0, height and go until width,(height + messages)
	mvaddstr(height + line, 0, message.c_str());
	// clear after what we wrote to EOL
	clrtoeol();
}

