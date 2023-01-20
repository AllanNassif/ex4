

#ifndef BARFIGHT_H_
#define BARFIGHT_H_

#include "Card.h"
#include "../Players/Warrior.h"

class Barfight : public Card {

public:
    
    /*
     * C'tor for Barfight class
     * 
     * @return
     * New Barfight Card with 8 health points to decrease
     * 
    */
    Barfight();

    /*
     * Handling the player's applyEncounter with Barfight card:
     * if the player is a warrior type nothing will happen
     * else if the player is ninja or healer type, hp will be reduced.
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Barfight(const Barfight&) = default;
    virtual ~Barfight() = default;
    Barfight& operator=(const Barfight&) = default;

private:

    /* default hp to reduce in Barfight card */
    static const int DEFAULT_HP_TO_REDUCE = 10;
    

};


#endif //BARFIGHT_H_