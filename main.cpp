#include "Hero.h"
#include <iostream>



int main(int argc, const char * argv[]) {
    try {
        if(argc == 3){
            Hero *warrior1 = new Hero(Hero::parseUnit(argv[1]));
            Hero *warrior2 = new Hero(Hero::parseUnit(argv[2]));
            
            warrior1->Battle(warrior2);
            
            if(warrior1->isDead()){
                std::cout << warrior2->getName() << " wins. Remaining HP: " << warrior2->getHP() << std::endl;
            }else{
                std::cout << warrior1->getName() << " wins. Remaining HP: " << warrior1->getHP() << std::endl;
            }       
            delete warrior1;
            delete warrior2;
            return 0;
        }else{
            std::cout << "Bad arg inputs." << std::endl;
            return 1;
        }
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what()
        << std::endl;
        return 2;
    }   
}