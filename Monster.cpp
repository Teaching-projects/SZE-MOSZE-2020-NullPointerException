#include <stdio.h>
#include "Monster.h"

Monster::Monster(const std::string& name, int hp, int dmg, double attackspeed) : Character(name, hp, dmg, attackspeed) {}

Monster Monster::parse(const std::string& filename){
    JSON MonsterMap = JSON::parseFromFile(filename);
    
    return Monster(MonsterMap.get<std::string>("name"), MonsterMap.get<int>("health_points"), MonsterMap.get<int>("damage"), MonsterMap.get<double>("attack_cooldown"));
}
