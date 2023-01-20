
#include "Healer.h"


Healer::Healer(const std::string& name) : Player(name) {}

void Healer::heal(int hpToAdd){

    Player::heal(hpToAdd*2);

}

std::string Healer::getJobName() const{
    return "Healer";
}
