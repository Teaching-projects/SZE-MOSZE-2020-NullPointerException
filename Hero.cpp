#include "Hero.h"
#include "JsonParser.h"



Hero::Hero(const std::string& name, int hp, const int dmg) : name(name), hp(hp), dmg(dmg){}

const std::string& Hero::getName() const{
    return name;
    
}

int Hero::getHP() const{
    return hp;
    
}

int Hero::getDmg() const{
    return dmg;
}

bool Hero::isDead(){
    if(getHP()<=0){
        return true;
    }else{
        return false;
    }
    
}

void Hero::damaging(Hero *enemy){
    if(hp > 0){
        if((enemy->hp - dmg) > 0){
            enemy->hp -= dmg;
        }else{
            enemy->hp = 0;
        }
    }
    
}

Hero Hero::parseUnit(const std::string& fileName){
    std::map<std::string, std::string> Map;
    Map = JsonParser::parser(fileName);
    return Hero(Map["name"],stoi(Map["hp"]),stoi(Map["dmg"]));
    
}



