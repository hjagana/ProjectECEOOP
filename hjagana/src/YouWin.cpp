#include "YouWin.hpp"
#include "Creature.hpp"
#include <iostream>
#include <string>

YouWin::YouWin(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    std::cout << "YouWin::YouWin(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}