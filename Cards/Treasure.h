

#ifndef TREASURE_H_
#define TREASURE_H_

#include "Card.h"

class Treasure : public Card {

public:
    
    /*
     * C'tor for Treasure class
     * 
     * @return
     * New Treasure Card with loot of 10 coins
     * 
    */
    Treasure();

    /*
     * Handling the player's applyEncounter with treasure card:
     * Adding the treasure loot to the player
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Treasure(const Treasure&) = default;
    virtual ~Treasure() = default;
    Treasure& operator=(const Treasure&) = default;

private:

    /* default coins on treasure card */
    static const int DEFAULT_LOOT = 10;

    
};


#endif //TREASURE_H_