/**
 * \class Hero
 *
 * \brief Hero class
 *
 * This class declares the Hero object, which has the paramters of the basic Hero object. Added to that he has 2 new features added, heroxp and levels.
 *
 * \author NullPointerException
 *
 * \version 2.0
 *
 * \date 2020/10/31 17:00
 *
 */

#include "Character.h"
#include "Monster.h"

#ifndef Hero_h
#define Hero_h

//This is the class of the Advanced Hero
class Hero : public Character {
private:
    int xpHatar; ///< This is the ammount of xp the hero has to collect to level up
    int hpBonus, dmgBonus;///< This gets from the JSON files. These describes the Hero's healthpoint and damage bonuses when he level up
    double CDBonus; ///< This is an AttackCooldown bonus when he level up.
    int maxHp = hp; ///< This is the max health of the Hero, which increases with the level
    int xp = 0; ///< The xp starts at 0, and with each battle he collects xp
    int lvl = 1; ///< The hero starts at level 1, and according to the xp earned, he can level up to be more powerful
    Hero(const std::string& name, int hp, int dmg, double as,int xpHatar, int hpBonus, int dmgBonus, double CDBonus); ///< This is the contrustor. The constructor sets the parameters of the hero
    /**
     * \brief This method is used to increase the heros attributes when levelling up
     *
     * \param The hero's actual level
     */
    void levelup(int);
    
    /**
     * \brief This method gains the XP when he take a hit
     *
     * \param a Character type enemy
     */
    void gainXP(Character& enemy);
    
public:
    int getLevel() const { return lvl; }; ///< Const getter of the hero's level
    int getxp() const { return xp; };///< Const getter of the hero's xp
    int getMaxHealthPoints() const { return maxHp; }
    
    /**
     * \brief Taking damage to a target Hero
     *
     * \param He waits for a Hero type enemy
     */
    void damaging(Character &enemy) override; ///< This method damages the enemy and increases the hero's xp
    

    /**
     * \brief Unit parsing from a JSON file.
     *
     * \param The string of the filename
     *
     * \return Returns with an Hero type, with Hero parameters.
     */
    static Hero parse(const std::string&);
    
    std::string status() const; ///< Writes out the current status of the game
    
};


#endif /* Hero_h */
