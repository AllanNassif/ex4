

#include "Barfight.h"



Barfight::Barfight() : Card("Barfight") {}

void Barfight::applyEncounter(Player& player) const{

    bool isWarrior = true;
    const Warrior* warrior = dynamic_cast<const Warrior*>(&player);
    if( warrior == nullptr){
        isWarrior = false;
        player.damage(DEFAULT_HP_TO_REDUCE);
    }
    printBarfightMessage(isWarrior);
    
}

