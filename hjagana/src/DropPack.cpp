#include "DropPack.hpp"
#include <string>
#include <iostream>


DropPack::DropPack(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    std::cout << "DropPack::DropPack(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}