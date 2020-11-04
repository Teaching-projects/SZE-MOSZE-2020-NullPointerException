#include "Hero.h"
#include <iostream>
#include <cmath>


int Hero::xpHatar = 100;

Hero::Hero(const std::string& name, int hp, int dmg, double as) : Character(name, hp, dmg, as), maxHp(hp){
}

Hero Hero::parse(const std::string& filename){
    Character Unit = Character::parseUnit(filename);
    return Hero(Unit.getName(), Unit.getHealthPoints(), Unit.getDamage(), Unit.getAttackCoolDown());
}

void Hero::damaging(Hero* enemy){
    xp += std::min(dmg, enemy->getHealthPoints());
    this->damaging(enemy);
    levelup(this->xp / xpHatar);
}

void Hero::levelup(int levelcount){
    for(int i=0; i<levelcount; i++){
        maxHp = (int)round((double)maxHp * 1.1);
        dmg = (int)round((double)dmg * 1.1);
        attackspeed = getAttackCoolDown()*0.9;
        hp = maxHp;
        lvl++;
        xp -= xpHatar;
    }
}

std::string Hero::status() const{
        
    return name + ": HP:" + std::to_string(hp) + " DMG: " + std::to_string(dmg)
    + " XP: " + std::to_string(xp) + " LVL: " + std::to_string(lvl) + "AS: " + std::to_string(attackspeed);
}
