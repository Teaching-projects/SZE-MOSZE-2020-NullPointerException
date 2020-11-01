#include "Hero.h"

#ifndef AdvancedHero_h
#define AdvancedHero_h

class AdvancedHero : public Hero {
private:
    int maxHp;
    int xp = 0;
    static int xpHatar;
    int lvl = 1;
    void levelup(int);
    
public:
    AdvancedHero(const std::string&,int,const int,const double);
    int getLvl() const;
    int getxp() const;
    void advancedDamage(AdvancedHero* enemy);
    void advancedBattle(AdvancedHero* target);
    static AdvancedHero parseUnit(const std::string&);
    std::string status() const;
    
};


#endif /* AdvancedHero_h */