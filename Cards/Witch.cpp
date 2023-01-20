

#include "Witch.h"


Witch::Witch() : Battle("Witch",DEFAULT_LOOT,DEFAULT_FORCE,DEFAULT_HP_TO_DECREASE) {}

void Witch::applyDefeat(Player &player) const{
    printLossBattle(player.getName(),getCardName());
    player.damage(getDamage());
    player.unBuff(DEFAULT_FORCE_TO_REDUCE);
}