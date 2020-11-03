#include "KeyboardListener.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid, Player* _p, Dungeon* _d) : grid(_grid), p(_p), d(_d) {}

void KeyboardListener::run() {
	grid->writeTopLine(0, "HP: " + std::to_string(p->getHp()));
	grid->writeLine(0, "Press 'x' to exit");
	grid->writeLine(8, "Pack: ");
	grid->writeLine(10, "Info: ");
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
		case 'h':
			if (d->checkMove(p->getPosX()-1, p->getPosY())) {
				p -> movePlayerLeft();
				grid->writeLine(2, "Left 1 Space");
			} else if (d->checkCollision(p->getPosX()-1, p->getPosY())){
				int playerHP = p->getHp();
				if(playerHP <= 0){
					// running = false;
					grid->writeLine(1, " ");
					grid->writeLine(3, " ");
					grid->writeLine(4, " ");
					grid->writeLine(6, " ");
					grid->writeLine(7, " ");
					grid->writeLine(8, "Pack: ");
					grid->writeLine(9, " ");
					grid->writeLine(10, "Info: ");
					grid->writeLine(5, "You Died! GAME OVER!");
				}
				// grid->writeLine(3, "Damage: " + std::to_string(p->getMaxhit()));
				grid->writeTopLine(0, "HP: " + std::to_string(p->getHp()));
			} else {
				grid->writeLine(2, "Can't move left anymore!");
			}
			// p -> movePlayerLeft();
			// grid->writeLine(2, "Left 1 Space");
			break;
		case 'l':
			if (d->checkMove(p->getPosX()+1, p->getPosY())) {
				p -> movePlayerRight();
				grid->writeLine(2, "Right 1 Space");
			} else if (d->checkCollision(p->getPosX() + 1, p->getPosY())){
				// player->getMaxHit();
				int playerHP = p->getHp();
				if(playerHP <= 0){
					// running = false;
					grid->writeLine(1, " ");
					grid->writeLine(3, " ");
					grid->writeLine(4, " ");
					grid->writeLine(6, " ");
					grid->writeLine(7, " ");
					grid->writeLine(8, "Pack: ");
					grid->writeLine(9, " ");
					grid->writeLine(10, "Info: ");
					grid->writeLine(5, "You Died! GAME OVER!");
				}
				// grid->writeLine(3, "Damage: " + std::to_string(p->getMaxhit()));
				grid->writeTopLine(0, "HP: " + std::to_string(p->getHp()));
				//write this to the screen
			} else {
				grid->writeLine(2, "Can't move right anymore!");
			}
			// p -> movePlayerRight();
			// grid->writeLine(2, "Right 1 Space");
			break;
		case 'k':
			if (d->checkMove(p->getPosX(), p->getPosY()-1)) {
				p -> movePlayerUp();
				grid->writeLine(2, "Up 1 Space");
			} else if (d->checkCollision(p->getPosX(), p->getPosY() - 1)){
				// player->getMaxHit();
				// player->getHp();
				int playerHP = p->getHp();
				if(playerHP <= 0){
					// running = false;
					grid->writeLine(1, " ");
					grid->writeLine(3, " ");
					grid->writeLine(4, " ");
					grid->writeLine(6, " ");
					grid->writeLine(7, " ");
					grid->writeLine(8, "Pack: ");
					grid->writeLine(9, " ");
					grid->writeLine(10, "Info: ");
					grid->writeLine(5, "You Died! GAME OVER!");
				}
				// grid->writeLine(3, "Damage: " + std::to_string(p->getMaxhit()));
				grid->writeTopLine(0, "HP: " + std::to_string(p->getHp()));
				//write this to the screen
			} else {
				grid->writeLine(2, "Can't move up anymore!");
			}	
			// p -> movePlayerUp();
			// grid->writeLine(2, "Up 1 Space");
			break;
		case 'j':
			if (d->checkMove(p->getPosX(), p->getPosY()+1)) {
				p -> movePlayerDown();
				grid->writeLine(2, "Down 1 Space");
			} else if (d->checkCollision(p->getPosX(), p->getPosY() + 1)){
				// player->getMaxHit();
				int playerHP = p->getHp();
				if(playerHP <= 0) {
					// running = false;
					

					grid->writeLine(5, "You Died! GAME OVER!");
				}
				// grid->writeLine(3, "Damage: " + std::to_string(p->getMaxhit()));
				grid->writeTopLine(0, "HP: " + std::to_string(p->getHp()));
				//write this to the screen
			} else {
				grid->writeLine(2, "Can't move down anymore!");
			}
			// p -> movePlayerDown();
			// grid->writeLine(2, "Down 1 Space");
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
			grid->writeLine(2, "take out the armor which is item number <item number in pack> in the pack and put it on");
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