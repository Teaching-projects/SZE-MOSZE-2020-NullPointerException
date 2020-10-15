#ifndef Hero_h
#define Hero_h
#include <string>


class Hero{
private:
    const std::string name;
    int hp;
    const int dmg;
    const double attackspeed;

    void damaging(Hero *enemy);
    
public:
    //Ctor, Dtor
    Hero(const std::string&, int, const int);
    //Karakter Alapadatok, Get-Set - Név, HP, DMG
    const std::string& getName() const;
    int getHP() const;
    int getDmg() const;
    bool isDead();
    void damaging(Hero *enemy);
    static Hero parseUnit(const std::string& fileName);
    
};

#endif /* Hero_h */
