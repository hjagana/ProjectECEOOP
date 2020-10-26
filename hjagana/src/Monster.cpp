#include "Monster.hpp"
#include <iostream>

Monster::Monster(){
    std::cout << "Monster::Monster()" << std::endl;
}
void Monster::setName(std::string n) {
    std::cout << "Monster::setName(std::string n)" << std::endl;
}
void Monster::setID(int room, int serial) {
    std::cout << "Monster::setID(int room, int serial)" << std::endl;
}