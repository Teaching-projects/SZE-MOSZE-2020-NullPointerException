#include "Character.h"
#include "JSON.h"



Character::Character(const std::string& name, int hp, const int dmg, const double attackspeed) : name(name), hp(hp), dmg(dmg), attackspeed(attackspeed){}

//Getter of Character's name
const std::string& Character::getName() const{
    return name;   
}

//Getter of HP
int Character::getHP() const{
    return hp;   
}

//Getter of Damage
int Character::getDmg() const{
    return dmg;
}

//Returns with boolean if the Character's HP is zero or lower.
bool Character::isDead(){
    if(getHP()<=0){
        return true;
    }else{
        return false;
    }
}

//Taking damage to an enemy Character if the HP is not zero.
void Character::damaging(Character *enemy){
    if(hp > 0){
        if((enemy->hp - dmg) > 0){
            enemy->hp -= dmg;
        }else{
            enemy->hp = 0;
        }
    }   
}

//Automatized battle method, according to the attackspeed
void Character::Battle(Character* target){
    double w1 = this->getAttackCooldown();
    double w2 = target->getAttackCooldown();
    double tempw1 = 0;
    double tempw2 = 0;
    
    this->damaging(target);
  
    while(!this->isDead() && !target->isDead()){
        if(w1+tempw1 < w2+tempw2){
            tempw1 += w1;
            this->damaging(target);
        }else if(w1+tempw1 > w2+tempw2){
            tempw2 += w2;
            target->damaging(this);
        }else{ //Alapertelmezett utes ha mindkettojuknek egyforma az attackspeed
            tempw1 += w1;
            this->damaging(target);
        }
    }
}

//Getter of attackspeed
double Character::getAttackCooldown() const{
    return attackspeed;
}

//Parsing an Unit from JSON file
Character Character::parseUnit(const std::string& fileName){
    std::map<std::string, std::string> Map;
    Map = JSON::parser(fileName);
    if(Map.find("name") != Map.end() && Map.find("hp") != Map.end() && Map.find("dmg") != Map.end() && Map.find("attackcooldown") != Map.end()){
        return Character(Map["name"],stoi(Map["hp"]),stoi(Map["dmg"]), stod(Map["attackcooldown"]));
    }else{
        throw std::runtime_error("Bad mapping");
    }
    
    
}