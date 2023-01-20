

#include "Well.h"


Well::Well() :Card("Well") {}

void Well::applyEncounter(Player& player) const{
    bool isNinja = true;
    const Ninja* ninja = dynamic_cast<const Ninja*>(&player);
    if( ninja == nullptr){
        isNinja = false;
        player.damage(DEFAULT_HP_TO_REDUCE);
    }
    printWellMessage(isNinja);
    
}

