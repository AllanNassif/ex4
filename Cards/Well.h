

#ifndef WELL_H_
#define WELL_H_

#include "Card.h"
#include "../Players/Ninja.h"


class Well : public Card {

public:
    
    /*
     * C'tor for Well class
     * 
     * @return
     * New Well Card with 10 health points to decrease
     * 
    */
    Well();

    /*
     * Handling the player's applyEncounter with Well card:
     * if the player is a ninja type nothing will happen
     * if the player is warrior or healer type, hp will be reduced.
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Well(const Well&) = default;
    virtual ~Well() = default;
    Well& operator=(const Well&) = default;


private:


    /* default hp to reduce in well card */
    static const int DEFAULT_HP_TO_REDUCE = 10;
    
};


#endif //WELL_H_