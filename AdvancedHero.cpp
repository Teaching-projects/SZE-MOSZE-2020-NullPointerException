#include "AdvancedHero.h"
#include <cmath>


int AdvancedHero::xpHatar = 100;

AdvancedHero::AdvancedHero(const std::string& name, int hp, const int dmg, const double as) : Hero(name, hp, dmg, as), maxHp(hp){
}

AdvancedHero AdvancedHero::parseUnit(const std::string& filename){
    Hero Unit = Hero::parseUnit(filename);
    return AdvancedHero(Unit.getName(), Unit.getHP(), Unit.getDmg(), Unit.getAttackSpeed());
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
        hp = maxHp;
        lvl++;
        xp -= xpHatar;
    }
    
}

std::string AdvancedHero::status() const{
        
    return name + ": HP:" + std::to_string(hp) + " DMG: " + std::to_string(dmg)
    + " XP: " + std::to_string(xp) + " LVL: " + std::to_string(lvl);
}
