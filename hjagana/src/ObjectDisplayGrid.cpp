#include "ObjectDisplayGrid.hpp"
#include <iostream>
#include <string>
#include <atomic> 
#include <thread>
#include <sstream>

// std::atomic_bool isRunning(true);

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
	objectGrid = new GridChar**[width];
	for (int i = 0; i < width; i++) {
		objectGrid[i] = new GridChar*[height];
		for (int j = 0; j < height; j++) {
			objectGrid[i][j] = NULL;
		}
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

ObjectDisplayGrid::~ObjectDisplayGrid() {
	// free memory from the dynamically sized object grid
	for (int i = 0; i < width; i++) {
		// delete all character objects in the grid
		for (int j = 0; j < height; j++) {
			delete objectGrid[i][j];
		}
		// delete the column
		delete[] objectGrid[i];
	}
	// delete the array of columns
	delete[] objectGrid;
	objectGrid = NULL;

	// free ncurses data
	endwin();
}

void ObjectDisplayGrid::addObjectToDisplay(GridChar* ch, int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < 150)) { // 150 should be "width"
		// y between 0 and height
		if ((0 <= y) && (y < 41)) { // 41 should be "height"
			// delete existing character if present
			if (objectGrid[x][y] != NULL) {
				delete objectGrid[x][y];
			}

			// add new character to the internal character list
			objectGrid[x][y] = ch;
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

// void ObjectDisplayGrid::runDisplay(ObjectDisplayGrid* grid, Dungeon* d) {
//     std::vector<Room*> rVector = d->getRooms();

//     for (Room* x: rVector) {

//         // int w = x -> getWidth();
//         // int h = x -> getHeight();
//         // int xPos = x -> getPosX();
//         // int yPos = x -> getPosY();
//         // // std::vector<Creature*> cVector = x->getCreature(); // uses Room to get creature Vector
//         // // std::vector<Creature*> cVector = d->getCreatures(); // uses Creature to get crature Vector
//         // for (int i = 0; i < w; i++) {
//         //     for (int j = 0; j < h; j++) {
//         //         char c;
//         //         if (i == 0 || i == (w-1) || j == 0 || j == (h-1)) {
//         //             c = 'X';
//         //         }
//         //         else {
//         //             c = ' ';
//         //         }
//                 grid->addObjectToDisplay(new GridChar(c), i + xPos, j + yPos);
//         //     }
//         // }
//         // // update the grid
//         // grid->update();
//         // // wait a bit to rejoin
//         // // wait in a few steps to update faster on keypress
//         // for (int i = 0; (isRunning && i < 5); i++) {
//         //     std::this_thread::sleep_for(std::chrono::milliseconds(400));
//         // }
//     }
// }