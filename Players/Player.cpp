
#include "Player.h"
#include "../utilities.h"


void Player::levelUp(){
    if(getLevel() >= MAX_LEVEL){
        return;
    }
    m_level++;

}

const std::string& Player::getName() const{
    return m_name;
}

int Player::getLevel() const{
    return m_level;
}

int Player::getForce() const{
    return m_force;
}

int Player::getHP() const{
    return m_HP;
}

int Player::getCoins() const{
    return m_coins;
}

void Player::buff(int forceToAdd){
    if(forceToAdd <= 0){
        return;
    }
    m_force += forceToAdd;
}

void Player::unBuff(int forceToReduce){
    if(forceToReduce <= 0){
        return;
    }
    m_force -= forceToReduce;
    if(m_force < 0 ) {
        m_force = 0;
    }
    
}

void Player::heal(int hpToAdd){
    if(m_HP == m_maxHP ||  hpToAdd <=0){
        return;
    }
    m_HP+= hpToAdd;
    if(m_HP > m_maxHP){
        m_HP = m_maxHP;
    }
}

void Player::damage(int hpToReduce){
    if(hpToReduce <=0){
        return;
    }
    m_HP -= hpToReduce;
    if(m_HP < 0){
        m_HP = 0;
    }

}

bool Player::isKnockedOut() const{
    if(m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd){
    if(coinsToAdd<= 0){
        return;
    }
    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToReduce){
    if(coinsToReduce <= 0){
        return true;
    }
    if(m_coins >= coinsToReduce){
        m_coins -= coinsToReduce;
        return true;
    }
    return false;
}
int Player::getAttackStrength() const{
    return m_force + m_level;
}

void Player::printInfo(std::ostream& stream) const{
        printPlayerDetails(stream,getName(),getJobName(),getLevel(),getForce(),getHP(),getCoins());

}

Player::Player(const std::string& name) : m_name(name),m_level(INITIAL_LEVEL),
    m_force(INITIAL_FORCE),m_maxHP(DEFAULT_MAX_HP),m_HP(DEFAULT_MAX_HP),m_coins(INITIAL_COINS) {}


std::ostream& operator<<(std::ostream& stream, const Player& player){
    player.printInfo(stream);
    return stream;
}


