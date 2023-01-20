
#ifndef Warrior_H_
#define Warrior_H_

#include "Player.h"

class Warrior : public Player {

public:

    /*
     * C'tor for Warrior class
     * 
     * @param name - The name of the player.
     * @return
     * New player of type Warrior - level 1 , with 10 coins, with 5 force , with full hp(100)
     * 
    */
    Warrior(const std::string& name);

    /*
     * getAttackStrength - gets the attack strength of Warrior type player
     * the attack strength of Warrior player is defined to be the twice the force of the player added with the level
     * of the player
     * 
     * @return
     * Attack strength - twice the player force + player level.
    */
    int getAttackStrength() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Warrior(const Warrior&) = default;
    virtual ~Warrior() = default;
    Warrior& operator=(const Warrior&) = default;  

protected:

    /*
     * getJobName - gets the name of the job.
     * 
     * @return
     * string with the name of the Warrior job.
    */
    virtual std::string getJobName() const override;

    
};




#endif // Warrior_H_