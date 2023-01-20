

#ifndef NINJA_H_
#define NINJA_H_

#include "Player.h"

class Ninja : public Player {

public:

    /*
     * C'tor for Ninja class
     * 
     * @param name - The name of the player.
     * @return
     * New player of type Ninja - level 1 , with 10 coins, with 5 force , with full hp(100)
     * 
    */
    Ninja(const std::string& name);

    /*
     * addCoins - adds double the amount of coins of the player
     * 
     * @param coinsToAdd - the amount of coins to add to the player
     * @return
     *     void
    */
    void addCoins(int coinsToAdd) override;  

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Ninja(const Ninja&) = default;
    virtual ~Ninja() = default;
    Ninja& operator=(const Ninja&) = default;

protected:

    /*
     * getJobName - gets the name of the job.
     * 
     * @return
     * string with the name of the Ninja job.
    */
    virtual std::string getJobName() const override;

    
};




#endif // NINJA_H_