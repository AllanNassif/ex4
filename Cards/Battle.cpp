#include "Battle.h"

Battle::Battle(const std::string& name,int loot,int force ,int damage) : Card(name) ,m_loot(loot),
    m_force(force) , m_damage(damage) {}

bool Battle::battleResult(Player& player) const {

    if(player.getAttackStrength() >= getForce()){
        return true;
    }
    else{
        return false;
    }

}

void Battle::applyEncounter(Player& player) const {
    
   if (battleResult(player)){
        applyVictory(player);
   }
   else{
        applyDefeat(player);
   }
}

void Battle::applyVictory(Player& player) const{
    printWinBattle(player.getName(),getCardName());
    player.levelUp();
    player.addCoins(getLoot());
}

void Battle::applyDefeat(Player &player) const {
    printLossBattle(player.getName(),getCardName());
    player.damage(getDamage());
}

void Battle::printCardInfo(std::ostream& stream) const{

    printCardDetails(stream,getCardName());
    printMonsterDetails(stream,getForce(),getDamage(),getLoot(),false);
    printEndOfCardDetails(stream);
    
}

Battle::~Battle() {}


int Battle::getLoot() const {
    return m_loot;
}

int Battle::getDamage() const {
    return m_damage;
}

int Battle::getForce() const {
    return m_force;
}


