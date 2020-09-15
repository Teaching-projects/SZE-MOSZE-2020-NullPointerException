#include <string>
#include <iostream>
#include "Hero.h"


Hero::Hero(const std::string name, const int hp, const int dmg) : name(name), hp(hp), dmg(dmg){
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
}

std::string Hero::getName(){
    return name;
    
}
void Hero::setName(std::string name){
    this->name = name;
    
}
int Hero::getHP(){
    return hp;
    
}
void Hero::setHP(int hp){
    this->hp = hp;
    
}
int Hero::getDmg(){
    return dmg;
    
}
void Hero::setDmg(int dmg){
    this->dmg = dmg;
    
}

bool Hero::isDead(){
    if(getHP()<=0){
        return true;
    }else{
        return false;
    }
    
}

void Hero::damaging(Hero *enemy){
    if(hp > 0){
        std::cout << name << " is damaging "<< enemy->name << " with: " << dmg << " dmg" << std::endl;
        if((enemy->hp - dmg) > 0){
            enemy->hp -= dmg;
        }else{
            enemy->hp = 0;
        }
    }
    
}

Hero::~Hero(){}


