#include <iostream>
#include <string>
#include "Hero.h"

using namespace std;

int main(int argc, const char * argv[]) {
    //Hős1 és Hős2 létrehozása
    Hero *warrior1;
    Hero *warrior2;
    
    
    try {
        if(argc == 7){
            warrior1 = new Hero(argv[1], stoi(argv[2]), stoi(argv[3]));
            warrior2 = new Hero(argv[4], stoi(argv[5]), stoi(argv[6]));
        }else{
            cout << "Bad inputs. Initializing default parameters." << endl;
            warrior1 = new Hero("Superman", 150, 20);
            warrior2 = new Hero("Batman", 200, 30);
        }
    } catch (exception e) {
        cout << "Bad inputs. Initializing default parameters.";
        warrior1 = new Hero("Superman", 150, 20);
        warrior2 = new Hero("Batman", 200, 30);
    }
    
    
    
    
    //A hősök tulajdonságainak kiiratása a játék kezdetén
    cout << "Warrior 1: "<< warrior1->getName() << endl
    << "Health: " << warrior1->getHP() << endl
    << "Damage: " << warrior1->getDmg() << endl << endl;
    
    cout << "Warrior 2: "<< warrior2->getName() << endl
    << "Health: " << warrior2->getHP() << endl
    << "Damage: " << warrior2->getDmg() << endl << endl;
    
    
    //A játék lefolyása
    while(!warrior2->isDead() || !warrior1->isDead()){
        
        warrior1->damaging(warrior2);
        cout << warrior1->getName() << " HP: " << warrior1->getHP() << endl;
        cout << warrior2->getName() << " HP: " << warrior2->getHP() << endl;
        
        warrior2->damaging(warrior1);
        cout << warrior1->getName() << " HP: " << warrior1->getHP() << endl;
        cout << warrior2->getName() << " HP: " << warrior2->getHP() << endl;
        
        if(warrior1->isDead()){
            cout << warrior1->getName() << " is dead. " << warrior2->getName() << " wins. " << endl;
            break;
        }
        if(warrior2->isDead()){
            cout << warrior2->getName() << " is dead. " << warrior1->getName() << " wins. " << endl;
            break;
        }
        
    }
    
    
    delete warrior1;
    delete warrior2;
    
    return 0;
    
}
