#ifndef Hero_h
#define Hero_h
#include <string>
#include <iostream>

class Hero{
private:
    const std::string name;
    int hp;
    const int dmg;
    
public:
    //Ctor, Dtor
    Hero(const std::string&, int, const int);
    //Karakter Alapadatok, Get-Set - Név, HP, DMG
    const std::string& getName();
    const int& getHP();
    const int& getDmg();
    bool isDead();
    void damaging(Hero *enemy);
    
};

#endif /* Hero_h */
