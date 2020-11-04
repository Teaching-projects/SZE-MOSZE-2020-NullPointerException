#include <stdio.h>
#include "Monster.h"

Monster::Monster(const std::string& name, int hp, int dmg, double as) : Character(name, hp,  dmg, as) {}

Monster Monster::parse(std::string& filename){
    JSON MonsterMap = JSON::parseFromFile(filename);
    
    return Monster(MonsterMap.get<std::string>("name"), MonsterMap.get<int>("health_points"), MonsterMap.get<int>("damage"), MonsterMap.get<int>("attack_cooldown"));
}
