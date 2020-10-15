#include "AdvancedHero.h"
#include <cmath>


int AdvancedHero::xpHatar = 100;

AdvancedHero::AdvancedHero(const std::string& name, int hp, const int dmg) : Hero(name, hp, dmg), xp(0), maxHp(hp){
    
}