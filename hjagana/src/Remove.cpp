#include "Remove.hpp"
#include "Creature.hpp"
#include <iostream>

Remove::Remove(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    // std::cout << "Remove::Remove(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}