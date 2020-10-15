#include "Hero.h"

#ifndef AdvancedHero_h
#define AdvancedHero_h

class AdvancedHero : public Hero {
private:
    int maxHp;
    int xp;
    static int xpHatar;
    int lvl = 1;
    void levelup(int);
    
public:
    AdvancedHero(const std::string&,int,const int);
    int getLvl() const;
    int getxp() const;
    void advancedDamage(AdvancedHero*);
    static AdvancedHero parseUnit(const std::string&);
    std::string status() const;
    
};


#endif /* AdvancedHero_h */