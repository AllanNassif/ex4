

#ifndef WITCH_H_
#define WITCH_H_

#include "Battle.h"

class Witch : public Battle {

public:
    
    /*
     * C'tor for Witch class
     * 
     * @return
     * New Witch Card with 11 force, 2 coins loot, and 10 health points to decrease
     * 
    */
    Witch();

    /*
     * applyDefeat - updating the player stats if the player lost the battle
     * 
     * @param player - the player to update the stats
     * @return  
     *     void
     * 
    */
    virtual void applyDefeat(Player &player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Witch(const Witch&) = default;
    virtual ~Witch() = default;
    Witch& operator=(const Witch&) = default;


private:

    /* default foce in Witch Card*/
    static const int DEFAULT_FORCE = 11;
    
    /* default loot in Witch Card */
    static const int DEFAULT_LOOT = 2;
    
    /* default hp to decrease in Witch card in case losing */
    static const int DEFAULT_HP_TO_DECREASE = 10;

    /* default force to reduce in witch card in case losing */
    static const int DEFAULT_FORCE_TO_REDUCE = 1;
    
};


#endif //WITCH_H_