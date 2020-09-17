#include "Hero.h"



const void firstCoutStatus(Hero& warrior){
    std::cout << "Warrior: "<< warrior.getName() << std::endl
    << "Health: " << warrior.getHP() << std::endl
    << "Damage: " << warrior.getDmg() << std::endl << std::endl;
}

const void getBattleStatus(Hero& warrior1, Hero& warrior2){
    std::cout << warrior1.getName() << " HP: " << warrior1.getHP() << std::endl;
    std::cout << warrior2.getName() << " HP: " << warrior2.getHP() << std::endl;
}

int main(int argc, const char * argv[]) {
    //Hős1 és Hős2 létrehozása
    Hero *warrior1;
    Hero *warrior2;
    
    try {
        if(argc == 7){
            warrior1 = new Hero(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
            warrior2 = new Hero(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
        }else{
            std::cout << "Bad inputs. Initializing default parameters." << std::endl;
            warrior1 = new Hero("Superman", 150, 20);
            warrior2 = new Hero("Batman", 200, 30);
        }
    } catch (std::exception& e) {
        std::cout << "Bad inputs. Initializing default parameters.";
        warrior1 = new Hero("Superman", 150, 20);
        warrior2 = new Hero("Batman", 200, 30);
    }
    
    //A hősök tulajdonságainak kiiratása a játék kezdetén
    firstCoutStatus(*warrior1);
    firstCoutStatus(*warrior2);
    
    //A játék lefolyása
    while(!warrior2->isDead() && !warrior1->isDead()){
        
        if(!warrior1->isDead()){
            warrior1->damaging(warrior2);
            std::cout << warrior1->getName() << " is damaging "<< warrior2->getName() << " with: " << warrior1->getDmg() << " dmg" << std::endl;
            getBattleStatus(*warrior1, *warrior2);
        }
        
        
        if(!warrior2->isDead()){
            warrior2->damaging(warrior1);
            std::cout << warrior1->getName() << " is damaging "<< warrior2->getName() << " with: " << warrior1->getDmg() << " dmg" << std::endl;
            getBattleStatus(*warrior1, *warrior2);
        }
    
    }
    
    if(warrior1->isDead()){
        std::cout << warrior1->getName() << " is dead. " << warrior2->getName() << " wins. " << std::endl;
    }
    
    if(warrior2->isDead()){
        std::cout << warrior2->getName() << " is dead. " << warrior1->getName() << " wins. " << std::endl;
    }
    
    
    delete warrior1;
    delete warrior2;
    
    return 0;
    
}
