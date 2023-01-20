

#include "Dragon.h"


Dragon::Dragon() : Battle("Dragon",DEFAULT_LOOT,DEFAULT_FORCE,DEFAULT_HP_TO_DECREASE) {}


void Dragon::printCardInfo(std::ostream& stream) const{
    
    printCardDetails(stream,getCardName());
    printMonsterDetails(stream,getForce(),getDamage(),getLoot(),true);
    printEndOfCardDetails(stream);
}