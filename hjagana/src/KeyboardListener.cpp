#include "KeyboardListener.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid) : grid(_grid) {}

void KeyboardListener::run() {
	grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());

		switch (input) {
		// press X to stop
		case 'x':
			running = false;
			grid->writeLine(2, "Exiting...");
			break;
		case 'e':
			grid->writeLine(2, "You found the easter egg, congrats");
			break;
		case '?':
			grid->writeLine(2, "h, l, k, j, i, ?, H, c, d, p, R, T, w, E, 0-9. H <cmd> for more info");
			break;
		// case 'H':
		// 	grid->writeLine(2, "")
		case 'h':
			grid->writeLine(2, "Left 1 Space");
			break;
		case 'l':
			grid->writeLine(2, "Right 1 Space");
			break;
		case 'k':
			grid->writeLine(2, "Up 1 Space");
			break;
		case 'j':
			grid->writeLine(2, "Down 1 Space");
			break;
		case 'i':
			grid->writeLine(2, "Show pack contents");
			break;
		case 'c':
			grid->writeLine(2, "Take off/Change Armor");
			break;
		case 'd':
			grid->writeLine(2, "Drop <item number> item from pack");
			break;
		case 'p':
			grid->writeLine(2, "Pick up item under player and put into the pack");
			break;
		case 'r':
			grid->writeLine(2, "<item in pack number>: read the scroll which is item number <item in pack number> in pack");
			break;
		case 't':
			grid->writeLine(2, "take out weapon from pack");
			break;
		case 'w':
			grid->writeLine(2, "take out thearmor which is item number <item number in pack> in the pack and put it on");
			break;
		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (running && input != EOF);
}