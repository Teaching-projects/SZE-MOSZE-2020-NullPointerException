#include "AdvancedHero.h"
#include <iostream>
#include <cmath>


int AdvancedHero::xpHatar = 100;

AdvancedHero::AdvancedHero(const std::string& name, int hp, const int dmg, const double as) : Hero(name, hp, dmg, as), maxHp(hp){
}

AdvancedHero AdvancedHero::parseUnit(const std::string& filename){
    Hero Unit = Hero::parseUnit(filename);
    return AdvancedHero(Unit.getName(), Unit.getHP(), Unit.getDmg(), Unit.getAttackCooldown());
}

void AdvancedHero::advancedBattle(AdvancedHero* target){
    double w1 = this->getAttackCooldown();
    double w2 = target->getAttackCooldown();
    double tempw1 = 0;
    double tempw2 = 0;
    
    this->advancedDamage(target);
    
    while(!this->isDead() && !target->isDead()){
        
        w1 = this->getAttackCooldown();
        w2 = target->getAttackCooldown();
        
        if(w1+tempw1 < w2+tempw2){
            tempw1 += w1;
            this->advancedDamage(target);
        }else if(w1+tempw1 > w2+tempw2){
            tempw2 += w2;
            target->advancedDamage(this);
        }else{ //Alapertelmezett utes ha mindkettojuknek egyforma az attackspeed
            tempw1 += w1;
            this->advancedDamage(target);
        }
    }
}

void AdvancedHero::advancedDamage(AdvancedHero* enemy){
    xp += std::min(dmg, enemy->getHP());
    this->damaging(enemy);
    levelup(this->xp / xpHatar);
}

void AdvancedHero::levelup(int levelcount){
    for(int i=0; i<levelcount; i++){
        maxHp = (int)round((double)maxHp * 1.1);
        dmg = (int)round((double)dmg * 1.1);
        attackspeed = getAttackCooldown()*0.9;
        hp = maxHp;
        lvl++;
        xp -= xpHatar;
    }
}

std::string AdvancedHero::status() const{
        
    return name + ": HP:" + std::to_string(hp) + " DMG: " + std::to_string(dmg)
    + " XP: " + std::to_string(xp) + " LVL: " + std::to_string(lvl) + "AS: " + std::to_string(attackspeed);
}
