#include "Hero.h"



Hero::Hero(const std::string& name, int hp, const int dmg) : name(name), hp(hp), dmg(dmg){}

const std::string& Hero::getName(){
    return name;
    
}

const int& Hero::getHP(){
    return hp;
    
}

const int& Hero::getDmg(){
    return dmg;
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
        if((enemy->hp - dmg) > 0){
            enemy->hp -= dmg;
        }else{
            enemy->hp = 0;
        }
    }
    
}


