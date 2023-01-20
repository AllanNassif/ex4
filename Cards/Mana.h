

#ifndef MANA_H_
#define MANA_H_

#include "Card.h"
#include "../Players/Healer.h"

class Mana : public Card {

public:
    
    /*
     * C'tor for Mana class
     * 
     * @return
     * New Mana Card with 10 health points to increase
     * 
    */
    Mana();

    /*
     * Handling the player's applyEncounter with Mana card:
     * if the player is a healer type the card will give increase his healthpoint by 10
     * (in fact, he will get 20 since its healer type),
     * else if the player is ninja or warrior type, nothing will happen.
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Mana(const Mana&) = default;
    virtual ~Mana() = default;
    Mana& operator=(const Mana&) = default;


private:


    /* default hp to increase in Mana card */
    static const int DEFAULT_HP_TO_INCREASE = 10;

    
};


#endif //MANA_H_