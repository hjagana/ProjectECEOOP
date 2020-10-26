#include "EndGame.hpp"
#include <iostream>


EndGame::EndGame(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    std::cout << "EndGame::EndGame(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}