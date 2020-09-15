#ifndef Hero_h
#define Hero_h
#include <string>


class Hero{
private:
    std::string name;
    int hp;
    int dmg;
    
public:
    //Ctor, Dtor
    Hero(const std::string, const int, const int);
    ~Hero();
    //Karakter Alapadatok, Get-Set - Név, HP, DMG
    std::string getName();
    void setName(std::string name);
    int getHP();
    void setHP(int hp);
    int getDmg();
    void setDmg(int dmg);
    bool isDead();
    void damaging(Hero *enemy);
    
};

#endif /* Hero_h */
