#include "KeyboardListener.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid, Player *_player, Dungeon *_dungeon) : grid(_grid), player(_player), dungeon(_dungeon) {}

void KeyboardListener::run() {
	grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	do {
		input = std::tolower(getchar());
		int itemNum = 0;
		int armorNum = 0;

		switch (input) {
		case 'x':
			running = false;
			grid->writeLine(2, "Exiting...");
			break;
		case 'e':
			//change this to end the game
			grid->writeLine(2, "You found the easter egg, congrats");
			break;
        case 'h':
			if(dungeon->checkMove(player->getXPos() - 1, player->getYPos())){
				player->movePlayerLeft();
            	grid->writeLine(1, "LEFT");
			}
			else if (dungeon->checkCollision(player->getXPos() - 1, player->getYPos())){
				int playerHealth = player->getHp();
				if(playerHealth <= 0){
					grid->writeLine(1, " ");
					grid->writeLine(3, " ");
					grid->writeLine(4, " ");
					grid->writeLine(6, " ");
					grid->writeLine(7, " ");
					grid->writeLine(8, "Pack: ");
					grid->writeLine(9, " ");
					grid->writeLine(10, "Info: ");
					grid->writeLine(5, "You Died! GAME OVER!");
					grid->writeLine(5, "game over");
				}
				grid->writeTopLine(0, "HP: " + std::to_string(player->getHp()) + "     Score: 0");
			}
			else{
				grid->writeLine(1, "can not move left");
			}
			break;
        case 'l':
			if(dungeon->checkMove(player->getXPos() + 1, player->getYPos())){
				player->movePlayerRight();
            	grid->writeLine(1, "RIGHT");
			}
			else if (dungeon->checkCollision(player->getXPos() + 1, player->getYPos())){
				int playerHealth = player->getHp();
				if(playerHealth <= 0){
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
				grid->writeTopLine(0, "HP: " + std::to_string(player->getHp()) + "     Score: 0");
			}
			else{
				grid->writeLine(1, "can not move right");
			}
			break;
        case 'k':
			if(dungeon->checkMove(player->getXPos(), player->getYPos() - 1)){
				player->movePlayerUp();
            	grid->writeLine(1, "UP");
			}
			else if (dungeon->checkCollision(player->getXPos(), player->getYPos() - 1)){
				int playerHealth = player->getHp();
				if(playerHealth <= 0){
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
				grid->writeTopLine(0, "HP: " + std::to_string(player->getHp()) + "     Score: 0");
			}
			else{
				grid->writeLine(1, "can not move up");
			}
			break;
        case 'j':
			if(dungeon->checkMove(player->getXPos(), player->getYPos() + 1)){
				player->movePlayerDown();
            	grid->writeLine(1, "DOWN");
			}
			else if (dungeon->checkCollision(player->getXPos(), player->getYPos() + 1)){
				int playerHealth = player->getHp();
				if(playerHealth <= 0){
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
				grid->writeTopLine(0, "HP: " + std::to_string(player->getHp()) + "     Score: 0");
			}
			else{
				grid->writeLine(1, "can not move down");
			}
			break;
        case 'i':
			dungeon->displayItemsInPack();
			break;
        case 'c':
			if(dungeon->checkArmor()){
				grid->writeLine(1, "take off / change armor");
			}
			else{
				grid->writeLine(1, "no armor is worn");
			}
			break;
        case 'd':
			itemNum = std::tolower(getchar());
			if(itemNum - 48 == 0){
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: can not drop item from pack");
				break;
			}
			if(dungeon->dropItemFromPack(itemNum)){
				//add number to this
				itemNum = itemNum - 48;
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: drop item "  + std::to_string(itemNum) + " from the pack");
			}
			else{
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: can not drop item from pack");
			}
			break;
        case 'p':
			if (dungeon->addItemToPack(player->getXPos(), player->getYPos())){
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: item picked up and put into pack");
			}
			else{
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: no item to pick up");
			}
			break;
        case 'r':
            grid->writeLine(1, "read item from pack");
			break;
        case 't':
            grid->writeLine(1, "take out weapon from pack");
			break;
        case 'w':
			armorNum = std::tolower(getchar());
			if (dungeon->checkArmorInPack(armorNum)){
				grid->writeLine(1, "take out armor with " + std::to_string(armorNum - 48) + " number from pack");
			}
			else{
				grid->writeLine(1, " ");
				grid->writeLine(3, " ");
				grid->writeLine(4, " ");
				grid->writeLine(6, " ");
				grid->writeLine(7, " ");
				grid->writeLine(8, "Pack: ");
				grid->writeLine(9, " ");
				grid->writeLine(10, "Info: no armor to wear in the pack");
			}
			break;
		default:
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (running && input != EOF);
}