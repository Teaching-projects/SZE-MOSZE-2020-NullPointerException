#include "Hero.h"
#include <iostream>
#include <cmath>

Hero::Hero(const std::string& name, int hp, int dmg, double as, int xpHatar, int hpBonus, int dmgBonus, double CDBonus) : Character(name, hp, dmg, as){
    maxHp = hp;
    this->xpHatar = xpHatar;
    this->hpBonus = hpBonus;
    this->dmgBonus = dmgBonus;
    this->CDBonus = CDBonus;
}

Hero Hero::parse(const std::string& filename){
    JSON map = JSON::parseFromFile(filename);
    return Hero(map.get<std::string>("name"),
                            map.get<int>("base_health_points"),
                            map.get<int>("base_damage"),
                            map.get<double>("base_attack_cooldown"),
                            map.get<int>("experience_per_level"),
                            map.get<int>("health_point_bonus_per_level"),
                            map.get<int>("damage_bonus_per_level"),
                            map.get<double>("cooldown_multiplier_per_level"));
}

void Hero::damaging(Hero &enemy){
    xp += std::min(dmg, enemy.getHealthPoints());
    levelup(this->xp / xpHatar);
}

void Hero::levelup(int levelcount){
    for(int i=0; i<levelcount; i++){
        hp = maxHp += hpBonus;
        dmg += dmgBonus;
        attackspeed *= CDBonus;
        lvl++;
        xp -= xpHatar;
    }
}

std::string Hero::status() const{
        
    return name + ": HP:" + std::to_string(hp) + " DMG: " + std::to_string(dmg)
    + " XP: " + std::to_string(xp) + " LVL: " + std::to_string(lvl) + "AS: " + std::to_string(attackspeed);
}
