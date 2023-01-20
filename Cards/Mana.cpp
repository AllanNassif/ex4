


#include "Mana.h"


Mana::Mana() : Card("Mana") {}

void Mana::applyEncounter(Player& player) const{
    
    bool isHealer = false;
    const Healer* healer = dynamic_cast<const Healer*>(&player);
    if( healer != nullptr){
        isHealer = true;
        player.heal(DEFAULT_HP_TO_INCREASE);
    }
    printManaMessage(isHealer);
}

