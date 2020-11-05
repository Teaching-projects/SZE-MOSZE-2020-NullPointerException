#include "Character.h"
#include "JSON.h"



Character::Character(const std::string& name, int hp, int dmg, double attackspeed) : name(name), hp(hp), dmg(dmg), attackspeed(attackspeed){}

//Getter of Character's name
const std::string& Character::getName() const{
    return name;   
}

//Getter of HP
int Character::getHealthPoints() const{
    return hp;   
}

//Getter of Damage
int Character::getDamage() const{
    return dmg;
}

//Returns with boolean if the Character's HP is zero or lower.
bool Character::isAlive(){
    if(getHealthPoints()>=0){
        return true;
    }else{
        return false;
    }
}

//Taking damage to an enemy Character if the HP is not zero.
void Character::damaging(Character &enemy){
    if(hp > 0){
        if((enemy.hp - dmg) > 0){
            enemy.hp -= dmg;
        }else{
            enemy.hp = 0;
        }
    }   
}

//Automatized battle method, according to the attackspeed
void Character::fightTilDeath(Character &target){
    double w1 = this->getAttackCoolDown();
    double w2 = target.getAttackCoolDown();
    double tempw1 = 0;
    double tempw2 = 0;
    
    this->damaging(target);
    
    while(hp > 0 && target.getHealthPoints() > 0){
        w1 = this->getAttackCoolDown();
        w2 = target.getAttackCoolDown();
        
        if(w1+tempw1 < w2+tempw2){
            tempw1 += w1;
            this->damaging(target);
        }else if(w1+tempw1 > w2+tempw2){
            tempw2 += w2;
            target.damaging(*this);
        }else{ //Alapertelmezett utes ha mindkettojuknek egyforma az attackspeed
            tempw1 += w1;
            this->damaging(target);
        }
    }
}

//Getter of attackspeed
double Character::getAttackCoolDown() const{
    return attackspeed;
}


