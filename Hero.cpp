#include "Hero.h"
#include <fstream>



Hero::Hero(const std::string& name, int hp, const int dmg, const double attackspeed) : name(name), hp(hp), dmg(dmg), attackspeed(attackspeed){}

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

void Hero::Battle(Hero* target){
    double w1 = this->getAttackSpeed();
    double w2 = target->getAttackSpeed();
    double tempw1 = 0;
    double tempw2 = 0;

    this->damaging(target);
}

Hero Hero::parseUnit(const std::string& fileName){
    std::fstream file;
    file.open(fileName);
    std::string readline, name, hp, dmg, line;
    
    if(file.is_open()){
        while (getline(file, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (isalnum(line[i])) {
                    if (readline == "name"){
                        name += line[i];
                    }
                    else if (readline == "hp"){
                        hp += line[i];
                    }
                    else if (readline == "dmg"){
                        dmg += line[i];
                    }
                    else readline += line[i];
                }
            }
            readline = "";
        }
        file.close();
        return Hero(name,stoi(hp),stoi(dmg));
    }else{
        throw std::runtime_error(fileName + " not exist.");
    }
    
    
    
}



