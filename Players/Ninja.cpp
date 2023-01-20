

#include "Ninja.h"


Ninja::Ninja(const std::string& name) : Player(name) {}

void Ninja::addCoins(int coinsToAdd){

    Player::addCoins(2*coinsToAdd);

}

std::string Ninja::getJobName() const{
    return "Ninja";
}

