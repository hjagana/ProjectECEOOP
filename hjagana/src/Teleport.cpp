#include "Teleport.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>

Teleport::Teleport(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name =  _name;
    // Creature* owner = _owner;
    std::cout << "Teleport::Teleport(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}