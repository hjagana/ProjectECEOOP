#include "ChangedDisplayedType.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>


ChangedDisplayedType::ChangedDisplayedType(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    // std::cout << "ChangedDisplayedType::ChangedDisplayedType(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}