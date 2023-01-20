
#include "Warrior.h"


Warrior::Warrior(const std::string& name) : Player(name) {}

int Warrior::getAttackStrength() const{

    return 2*getForce() + getLevel();

}

std::string Warrior::getJobName() const{
    return "Warrior";
}