/**
 * \class AdvancedHero
 *
 * \brief AdvancedHero class
 *
 * This class declares the AdvancedHero object, which has the paramters of the basic Hero object. Added to that he has 2 new features added, heroxp and levels.
 *
 * \author NullPointerException
 *
 * \version 1.0
 *
 * \date 2020/10/31 17:00
 *
 */

#include "Hero.h"

#ifndef AdvancedHero_h
#define AdvancedHero_h

//This is the class of the Advanced Hero
class AdvancedHero : public Hero {
private:
    int maxHp; ///< This is the max health of the Hero, which increases with the level
    int xp = 0; ///< The xp starts at 0, and with each battle he collects xp
    static int xpHatar; ///< This is the ammount of xp the hero has to collect to level up
    int lvl = 1; ///< The hero starts at level 1, and according to the xp earned, he can level up to be more powerful
    
    /**
     * \brief This method is used to increase the heros attributes when levelling up
     *
     * \param The hero's actual level
     */
    void levelup(int);
    
public:
    AdvancedHero(const std::string&,int,const int,const double); ///< This is the contrustor. The constructor sets the parameters of the hero
    int getLvl() const; ///< Const getter of the hero's level
    int getxp() const;///< Const getter of the hero's xp
    
    /**
     * \brief Taking damage to a target Hero
     *
     * \param He waits for a Hero type enemy
     */
    void advancedDamage(AdvancedHero* enemy); ///< This method damages the enemy and increases the hero's xp
    
    /**
     * \brief This is an automatized Battle method. It takes damages to the target (with the advancedDamage method) depending on the Hero's attackspeed.
     *
     * \param Target hero
     */
    void advancedBattle(AdvancedHero* target);

    /**
     * \brief Unit parsing from a JSON file.
     *
     * \param The string of the filename
     *
     * \return Returns with an AdvancedHero type, with AdvancedHero parameters.
     */
    static AdvancedHero parseUnit(const std::string&);
    std::string status() const; ///< Writes out the current status of the game
    
};


#endif /* AdvancedHero_h */
