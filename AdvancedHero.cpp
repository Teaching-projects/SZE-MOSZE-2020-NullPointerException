#include "AdvancedHero.h"
#include <cmath>


int AdvancedHero::xpHatar = 100;

AdvancedHero::AdvancedHero(const std::string& name, int hp, const int dmg) : Hero(name, hp, dmg), xp(0), maxHp(hp){
    
}

AdvancedHero AdvancedHero::parseUnit(const std::string& filename){
    Hero Unit = Hero::parseUnit(filename);
    return AdvancedHero(Unit.getName(), Unit.getHP(), Unit.getDmg());
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