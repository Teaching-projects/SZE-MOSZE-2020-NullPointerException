#include "Hero.h"
#include <iostream>
#include "AdvancedHero.h"

int main(int argc, const char * argv[]) {
    try {
        if(argc == 3){
            AdvancedHero *warrior1 = new AdvancedHero(AdvancedHero::parseUnit(argv[1]));
            AdvancedHero *warrior2 = new AdvancedHero(AdvancedHero::parseUnit(argv[2]));
            
            while(!warrior2->isDead() && !warrior1->isDead()){
                warrior1->advancedDamage(warrior2);
                warrior2->advancedDamage(warrior1);
            }
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
