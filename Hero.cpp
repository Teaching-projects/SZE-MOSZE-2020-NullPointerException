#include "Hero.h"
#include "JsonParser.h"



Hero::Hero(const std::string& name, int hp, const int dmg, const double attackspeed) : name(name), hp(hp), dmg(dmg), attackspeed(attackspeed){}

//Getter of Hero's name
const std::string& Hero::getName() const{
    return name;   
}

//Getter of HP
int Hero::getHP() const{
    return hp;   
}

//Getter of Damage
int Hero::getDmg() const{
    return dmg;
}

//Returns with boolean if the Hero's HP is zero or lower.
bool Hero::isDead(){
    if(getHP()<=0){
        return true;
    }else{
        return false;
    }
}

//Taking damage to an enemy Hero if the HP is not zero.
void Hero::damaging(Hero *enemy){
    if(hp > 0){
        if((enemy->hp - dmg) > 0){
            enemy->hp -= dmg;
        }else{
            enemy->hp = 0;
        }
    }   
}

//Automatized battle method, according to the attackspeed
void Hero::Battle(Hero* target){
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
double Hero::getAttackCooldown() const{
    return attackspeed;
}

//Parsing an Unit from JSON file
Hero Hero::parseUnit(const std::string& fileName){
    std::map<std::string, std::string> Map;
    Map = JsonParser::parser(fileName);
    if(Map.find("name") != Map.end() && Map.find("hp") != Map.end() && Map.find("dmg") != Map.end() && Map.find("attackcooldown") != Map.end()){
        return Hero(Map["name"],stoi(Map["hp"]),stoi(Map["dmg"]), stod(Map["attackcooldown"]));
    }else{
        throw std::runtime_error("Bad mapping");
    }
    
    
}
