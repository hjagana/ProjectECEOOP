#include "UpdateDisplay.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>

UpdateDisplay::UpdateDisplay(std::string _name, Creature* _owner):CreatureAction(_owner) {
    std::string name = _name;
    // Creature* owner = _owner;
    // std::cout << "UpdateDisplay::UpdateDisplay(std::string _name, Creature _owner):CreatureAction(_owner)" << std::endl;
}