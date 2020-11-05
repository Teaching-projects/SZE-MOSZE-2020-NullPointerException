/**
 * \class Character
 *
 * \brief Character class
 *
 * This class declares the Character object, which has four parameters at the moment. The Character has many functions and datas, including his/her healthpoint, damage, name, attackspeed. He can take a damage, or set to an automatized Battle with his/her target according to the attackspeed. The Character class can also read from a JSON file.
 *
 * \author NullPointerException
 *
 * \version 2.0
 *
 * \date 2020/11/05 19:00
 *
 */

#ifndef Character_h
#define Character_h
#include <string>

//This is the class of the Characteres
class Character{
protected:
    const std::string name; ///< This is the name of the Character
    int hp; ///< The health of the Character, always changing during the fight
    int dmg; ///< The amount of damage he can hits with
    double attackspeed; ///< This is the attackspeed of the Character

    /**
     * \brief Taking a simple hit to a Character enemy if the Character's health not zero 
     *
     * \param He waits for a Character type enemy
     */
    void hit(Character &enemy);
    
    /**
     * \brief This is a virtual void. He can take a simple hit to a target Character.
     *
     * \param He waits for a Character type enemy
     */
    virtual void damaging(Character &enemy);
    
public:
    Character(const std::string&, int, int, double); ///< This is the constructor. The constructor sets the parameters of the Character

    const std::string& getName() const; ///< Const getter of the Character's name
    int getHealthPoints() const; ///< Const getter of the Character's health
    int getDamage() const; ///< Const getter of the Character's damage
    double getAttackCoolDown() const; ///< Const getter of the Character's attackspeed
    
    /**
     * \brief This checks if the unit is alive or not
     *
     * \return If unit health point is zero or higher. If higher than zero, returns with true. Else false.
     */
    bool isAlive();
    
    /**
     * \brief This is an automatized Battle method. It takes damages to the target (with the damaging method) depending on the Character's attackspeed.
     *
     * \param Target Character
     */
    void fightTilDeath(Character&);
    
    /**
     * \brief Unit parsing from a JSON file.
     *
     * \param The string of the filename
     *
     * \return Returns with a Character type, with Character parameters.
     */
    static Character parseUnit(const std::string& fileName);
    
};

#endif /* Character_h */
