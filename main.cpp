#include "Hero.h"
#include <iostream>

void firstCoutStatus(const Hero& warrior){
    std::cout << "Warrior: "<< warrior.getName() << std::endl
    << "Health: " << warrior.getHP() << std::endl
    << "Damage: " << warrior.getDmg() << std::endl << std::endl;
}

int main(int argc, const char * argv[]) {
    //Hős1 és Hős2 létrehozása
    Hero *warrior1;
    Hero *warrior2;
    
    try {
        if(argc == 3){
            
            warrior1 = new Hero(Hero::parseUnit(argv[1]));
            warrior2 = new Hero(Hero::parseUnit(argv[2]));
        }else{
            std::cout << "Bad arg inputs. Initializing default parameters." << std::endl;
            warrior1 = new Hero("Superman", 150, 20);
            warrior2 = new Hero("Batman", 200, 30);
        }
    } catch (std::exception& e) {
        std::cout << "Bad inputs or file not exists. Initializing default parameters."
        << std::endl;
        warrior1 = new Hero("Superman", 150, 20);
        warrior2 = new Hero("Batman", 200, 30);
    }
    
    //A hősök tulajdonságainak kiiratása a játék kezdetén
    firstCoutStatus(*warrior1);
    firstCoutStatus(*warrior2);
    
    //A játék lefolyása
    while(!warrior2->isDead() && !warrior1->isDead()){
        warrior1->damaging(warrior2);
        warrior2->damaging(warrior1);
    }
    
    
    if(warrior1->isDead()){
        std::cout << warrior1->getName() << " is dead. " << warrior2->getName() << " wins. " << std::endl;
    }else{
        std::cout << warrior2->getName() << " is dead. " << warrior1->getName() << " wins. " << std::endl;
    }
    
    
    delete warrior1;
    delete warrior2;
    
    return 0;
    
}
