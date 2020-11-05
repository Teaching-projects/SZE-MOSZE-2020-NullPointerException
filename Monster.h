/**
 * \class Monster
 *
 * \brief Monster class
 *
 * This class declares the Monster object, which has four parameters. This is an inherit class from Character. The Monster has the same datas, including his/her healthpoint, damage, name, attackspeed. He can do all of the methods as the Character. It has an own parseUnit method, which reads the Monster's JSON file and returns with the Monster parameters.
 *
 * \author NullPointerException
 *
 * \version 1.0
 *
 * \date 2020/11/05 19:00
 *
 */

#ifndef Monster_h
#define Monster_h
#include "Character.h"
#include "JSON.h"

class Monster : public Character{
public:
    Monster(const std::string& name, int healthpoints, int damage, double attackcooldown); ///< This is the constructor. The constructor sets the parameters of the Monster
    
    /**
     * \brief Monster parsing from a JSON File.
     *
     * \param The string of the filename
     *
     * \return Returns with the Monster's parameters.
     */
    static Monster parse(const std::string& filename);
    
};

#endif /* Monster_h */
