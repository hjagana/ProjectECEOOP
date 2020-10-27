#include "Action.hpp"
#include <string>
#include <iostream>

void Action::setMessage(std::string msg) {
    //std::cout << "Action::setMessage(std::string msg)" << std::endl;
}
void Action::setIntValue(int v) {
    //std::cout << "Action::setIntValue(int v)" << std::endl;
}
void Action::setCharValue(char c) {
    // std::cout << "Action::setCharValue(char c)" << std::endl;
}

void Action::addAction (Action *  action) {
        actionVector[actionCount++] = action;

}
void Action::freeAction(){

    for(std::vector<Action *>::iterator action = actionVector.begin(); action != actionVector.end(); ++action) { 
        delete *action; 
    }
    actionVector.clear();
}