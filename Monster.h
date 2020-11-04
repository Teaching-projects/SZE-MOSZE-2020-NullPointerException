#ifndef Monster_h
#define Monster_h
#include "Character.h"
#include "JSON.h"

class Monster : public Character{
public:
    Monster(const std::string& name, int healthpoints, int damage, double attackcooldown);
    static Monster parse(const std::string& filename);
    
};

#endif /* Monster_h */
