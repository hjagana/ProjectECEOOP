#include "Passage.hpp"
#include <iostream>

Passage::Passage() {
    std::cout << "Passage::Passage()" << std::endl; 
}

void Passage::setName(std::string n) {
    std::cout << "Passage::setName(std::string n)" << std::endl;
}
void Passage::setID(int room1, int room2) {
    std::cout << "Passage::setID(int room1, int room2)" << std::endl;
}

void Passage::addPassage (Passage *  passage) {
        passageVector[passageCount++] = passage;

}
void Passage::freePassage(){

    for(std::vector<Passage *>::iterator passage = passageVector.begin(); passage != passageVector.end(); ++passage) { 
        delete *passage; 
    }
    passageVector.clear();
}