#include "Displayable.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

Displayable::Displayable(){
}

void Displayable::setInvisible(){
    visible = true;
}

void Displayable::setVisible(){
    visible = true;
}

bool Displayable::getVisible(){
    return visible;
}

bool Displayable::getInvisible(){
    return visible;
}

void Displayable::setMaxHit(int _maxHit){
    maxHit = _maxHit;
}
int Displayable::getMaxHit(){
    int randNum = rand() % (maxHit + 1) + 0;
    return randNum;
}

void Displayable::setHpMove(int hpMoves){

}
std::string Displayable::getName(){

}

void Displayable::setItemNum(int _itemNum){
    itemNum = _itemNum;
}

int Displayable::getItemNum(){
    return itemNum;
}

void Displayable::setHp(int Hp){
    hitPoints = Hp;
}

int Displayable::getHp(){
    return hitPoints;
}

void Displayable::setType(char t){
}

void Displayable::setIntValue(int v){
}

void Displayable::setXPos(int x){
    xpos = x;
}

int Displayable::getXPos(){
    return xpos;
}

void Displayable::setYPos(int y){
    ypos = y;
}

int Displayable::getYPos(){
    return ypos;
}

void Displayable::setWidht(int x){
    width = x;
}

int Displayable::getWidth(){
    return width;
}

void Displayable::setHeight(int y){
    height = y;
}

int Displayable::getHeight(){
    return height;
}
void Displayable::Draw(){

}